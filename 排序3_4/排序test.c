#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//冒泡排序
void sortArr(int arr[],int size)//升序
{
	for (int i = 0; i < size-1; i++)//size-1轮大循环
	{
		for (int j = 0; j < size-1-i; j++)
		{
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//交换
void swap(int* a, int* b)
{
	int temp=*a;
	*a = *b;
	*b = temp;
}

//// 分区函数
//int partition(int arr[], int low, int high) {
//	int pivot = arr[low];  // 选第一个元素为基准
//	int left = low + 1;    // 左指针从基准下一个位置开始
//	int right = high;      // 右指针从末尾开始
//
//	while (left <= right) {
//		// 左指针找比基准大的元素
//		while (left <= right && arr[left] <= pivot) left++;
//		// 右指针找比基准小的元素
//		while (left <= right && arr[right] > pivot) right--;
//		// 交换左右指针的元素
//		if (left < right) {
//			swap(&arr[left], &arr[right]);
//			left++;
//			right--;
//		}
//	}
//	// 将基准放到正确位置
//	swap(&arr[low], &arr[right]);
//	return right;  // 返回基准的最终位置
//}

// 分区函数
int partition(int arr[], int low, int high) {
	int randomIndex = low + rand() % (high - low + 1);
	swap(&arr[low], &arr[randomIndex]);

	int pivot = arr[low];  // 选第一个元素为基准
	
	int left = low;    // 左指针从基准下一个位置开始
	int right = high;      // 右指针从末尾开始

	while (left != right) {
		// 右指针找比基准小的元素
		while (left < right && arr[right] > pivot)
		{
			right--;
		}
		// 交换左右指针的元素
		if (left < right) {
			swap(&arr[left], &arr[right]);
			left++;
		}

		// 左指针找比基准大的元素
		while (left < right && arr[left] <= pivot) left++;
		// 交换左右指针的元素
		if (left < right) {
			swap(&arr[left], &arr[right]);
			right--;
		}
	}
	// 将基准放到正确位置
	swap(&pivot, &arr[right]);
	return right;  // 返回基准的最终位置
}

//快排
void quickSort(int arr[], int low, int high) {
	if (low < high) {  // 递归终止条件：子数组长度=1
		int pivotIndex = partition(arr, low, high);  // 分区
		quickSort(arr, low, pivotIndex - 1);         // 递归排序左半部分
		quickSort(arr, pivotIndex + 1, high);        // 递归排序右半部分
	}
}

//打印数组
void printArr(int arr[],int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void inital_arr(int* arr, int sz)
{
	printf("请输入待排序的数字，请用空格分隔:\n");
	for (int i = 0; i < sz; i++)
	{
		scanf("%d", &arr[i]);
	}
}
void meau()
{
	printf("------------排序-------------\n");
	printf("|---- 1.冒泡      2.快排 ----|\n");
	printf("|---------  0.退出  ---------|\n");
	printf("-----------------------------\n");
}
int main()
{
	int input = 0;
	int sz = 0;

	do {
		meau();
		printf("请选择功能:>");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("欢迎下次使用\n");
			break;
		case 1:
			printf("输入你想待排序数字的个数:>");
			scanf("%d", &sz);
			int* arr = (int*)malloc(sz * sizeof(int));
			inital_arr(arr, sz);
			printf("排序前的数组: \n");
			printArr(arr, sz);
			sortArr(arr, sz);
			printf("排序后的数组: \n");
			printArr(arr, sz);
			break;
		case 2:
			printf("输入你想待排序数字的个数:>");
			scanf("%d", &sz);
			int* arr2 = (int*)malloc(sz * sizeof(int));
			inital_arr(arr2, sz);
			printf("排序前的数组: \n");
			printArr(arr2, sz);
			quickSort(arr2, 0, sz - 1);
			printf("排序后的数组: \n");
			printArr(arr2, sz);
			break;
		default:
			printf("选择错误，重新输入\n");
			break;
		}
	} while (input);
	return 0;
}

//-------------------------------------------------------

////快速排序算法
//void quickSort(int arr[], int low,int high)
//{
//	int i = low;
//	int j = high;
//	if (i >= j) {
//		return;
//	}
//
//	int temp = arr[low];
//	while (i != j) {
//		while (arr[j] >= temp && i < j) {
//			j--;
//		}
//		while (arr[i] <= temp && i < j) {
//			i++;
//		}
//		if (i < j) {
//			swap(&arr[i], &arr[j]);
//		}
//	}
//
//	//将基准temp放于自己的位置，（第i个位置）
//	swap(&arr[low], &arr[i]);
//	quickSort(arr, low, i - 1);
//	quickSort(arr, i + 1, high);
//
//}

//-------------------------------------------------------

////ai
//// 分区函数，返回基准元素的最终位置
//int partition(int arr[], int low, int high) {
//	int pivot = arr[high];  // 选择最后一个元素作为基准
//	int i = low - 1;        // i 用于标记小于 pivot 的区域
//
//	for (int j = low; j < high; j++) {
//		if (arr[j] < pivot) {  // 小于基准的元素交换到前面
//			i++;
//			swap(&arr[i], &arr[j]);
//		}
//	}
//	swap(&arr[i + 1], &arr[high]);  // 将 pivot 放到正确位置
//	return i + 1;  // 返回 pivot 的索引
//}
//
//// 快速排序函数
//void quickSort(int arr[], int low, int high) {
//	if (low < high) {
//		int pi = partition(arr, low, high); // 获取分区索引
//		quickSort(arr, low, pi - 1);  // 递归排序左部分
//		quickSort(arr, pi + 1, high); // 递归排序右部分
//	}
//}