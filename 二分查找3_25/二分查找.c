#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int Datetype;

//创建随机数组
void creatarr(Datetype* arr, int size)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < size; i++)
	{
		arr[i] = (Datetype)(rand() % 100 + 1);//1--100
	}
}

//冒泡排序  升序
void bublesort(Datetype* arr, int size)
{
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size-1-i; j++)
		{
			if (arr[j] > arr[j + 1]) 
			{
				Datetype temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//迭代
////二分查找
//int findnum(Datetype* arr, Datetype wantnum, int size, int* found)
//{
//	int left = 0;
//	int right = size - 1;
//	
//	while (left <= right)
//	{
//		int mid = left + (right - left) / 2;
//		if (arr[mid] < wantnum)//值在右边
//		{
//			left = mid + 1;
//		}
//		else if(arr[mid] > wantnum)//值在左边
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			*found = 1;//找到了
//			return mid;
//		}
//	}
//	return left;
//}

//递归二分查找
//二分查找
int findnum(Datetype* arr, Datetype wantnum,int left, int right, int* found)
{
	if (left > right) {
		return left;
	}

	int mid = left + (right - left) / 2;
	if (arr[mid] < wantnum)//值在右边
	{
		return findnum(arr, wantnum, mid + 1, right,found);
	}
	else if (arr[mid] > wantnum)//值在左边
	{
		return findnum(arr, wantnum, left, mid-1, found);
	}
	else
	{
		*found = 1;//找到了
		return mid;
	}

}

int Del(int* nums,int size)//删除重复元素
{
	int i = 0;
	for (int j = 1; j < size; j++)//快指针
	{
		if (nums[j] != nums[i])
		{
			i++;
			nums[i] = nums[j];
		}
	}
	return i + 1;//数量
}

//打印
void printarr(Datetype* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if(i % 10 == 0&&i!=0)
		{
			printf("\n");
		}
		printf("%d\t", arr[i]);
	}
	printf("\n\n");
}

int main()
{
	int num=0;//大小
	printf("输入你想有多少数字的数组:>");
	scanf("%d", &num);
	Datetype* arr = (Datetype*)malloc(num * sizeof(Datetype));
	if (arr == NULL)
	{
		perror("malloc");
		return 1;
	}

	creatarr(arr,num);
	printarr(arr, num);

	bublesort(arr, num);
	printf("排序后:>\n");
	printarr(arr, num);

	printf("删除重复元素后:>\n");
	int size=Del(arr, num);
	printarr(arr, size);

	Datetype numwant = 0;
	printf("请输入你想查找的值,我来告诉下标（从0开始）:>");
	scanf("%d", &numwant);

	int found = 0;
	//int pos = findnum(arr, numwant, num,&found);
	int pos = findnum(arr, numwant, 0, size-1, &found);//递归
	if (found) {
		printf("该数 %d 在数组中的下标为 %d\n", numwant, pos);
	}
	else
	{
		printf("该数 %d 不在数组中，正在插入...\n", numwant);

		// 扩展数组（使用 realloc）
		Datetype* new_arr = (Datetype*)realloc(arr, 2*num * sizeof(Datetype));
		if (new_arr == NULL) {
			perror("realloc");
			free(arr);
			arr = NULL;
			return 1;
		}

		arr = new_arr;

		for (int i = num; i > pos; i--)
		{
			arr[i] = arr[i - 1];
		}

		arr[pos] = numwant; // 插入新元素
		num++; // 数组大小 +1

		printf("插入后的数组:>\n");
		printarr(arr, num);
	}
	
	free(arr);
	arr = NULL;
	return 0;
}