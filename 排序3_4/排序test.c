#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//冒泡排序
void sortArr(int arr[],int size)//升序
{
	for (int i = 0; i < size-1; i++)//size-1轮大循环
	{
		for (int j = 0; j < size-1; j++)
		{
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}


}

//快速排序算法
void 


int main()
{
	int arr[10] = { 9,8,7,6,5,4,3,2,1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	sortArr(arr,size);
	printf("\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	
	return 0;
}