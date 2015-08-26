#include <iostream>
using namespace std;
/**
 * 算法思想：
 * 1、求解next[i]数组：next[i]=max{k|pattern[0..k-1]..pattern[i-k+1..i]}
 * 2、用i，j分别指向text和pattern，i和j依次往前移动，当text[i+1] != pattern[j+1]的时候，
 *    i停止移动，另j=next[j]，如果动作令text[i+1] == pattern[j+1]，则i、j继续往前移动，
 *    否则，再令j=next[j]，直至text[i+1] == pattern[j+1]，如果当j=0时也无法使
 *    text[i+1] == pattern[j+1]，则保持j不变，移动i。
 * 3、当j = length(pattern)的时候匹配成功;
 */
int KMPMatch(char *text, char *pattern)
{
  /**
   * 求next数组
   */
  int size = strlen(pattern);
  int *next = new int[size+1];
  //初始化为0,假设所有的位置均无法找到满足next[i]=max{k|pattern[0..k-1]..pattern[i-k+1..i]}的,所以next[i] = 0;
  for(int i = 0; i < size+1; i++)
  {
    next[i] = 0;
  }
  //next[0],next[1]均为0，只需要求next[2]..next[size+1]
for(i = 1; i < size; i++)
  {
    int j = i;
    while(j > 0)
    {
      j = next[j];
      if(pattern[j] == pattern[i])
      {
        next[i+1] = j+1;
        break;
      }
    }
  }
  /**
   * 开始匹配
   */
  i = 0;
  int j = 0;
  while(i < strlen(text))
  {
    //如果当前字符匹配，则往前走
    if(text[i] == pattern[j])
    {
      i++;
      j++;
    }
    //如果pattern中找不到满足next[i]=max{k|pattern[0..k-1]..pattern[i-k+1..i]}的,则i往前走，pattern从头匹配（j=0）
    else if(j == 0)
    {
      i++;
    }
    else
    //寻找next[i]=max{k|pattern[0..k-1]..pattern[i-k+1..i]}
    {
      j = next[j];
    }
    //匹配成功
    if(j == size)
    {
      return i - j;
    }
  }
  return -1;
}

void main()
{
  char *text = "ABC ABCDAB ABCDABCDABDE";
  char *pattern = "ABCDABD";
  cout << KMPMatch(text, pattern);
}
