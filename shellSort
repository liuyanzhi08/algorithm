#include <iostream>
using namespace std;
/**
 * 算法思想：1、把数组arr以gap大小进行分组，对每一组分别进行插入排序；
 *			 2、当每一组的排序完成后，更改将gap的大小变为原来的一半，再
 *			    执行步骤1，直到gap < 1
 */
void shellSort(int *arr, int size)
{
	//分组进行排序
	for(int gap = size/2; gap > 0; gap /= 2)
	{
		//遍组中的数据，用插入法排序
		for(int i = gap; i < size ; i++)
		{
			int ele = arr[i];
			int j = 0;
			//寻找插入点
			for(j = i - gap; j >= 0 && ele < arr[j]; j -= gap)
			{
				arr[j+gap] = arr[j];
			}
			//插入
			arr[j+gap] = ele;
		}			
	}
}

void main()
{
	int arr[] = {1, 3, 2, 6, 8, 9, 4, 7, 5, 0};
	const int SIZE = 10;
	shellSort(arr, SIZE);
	for(int k = 0; k < SIZE; k++)
	{
		cout << arr[k] << ", ";
	}

}
