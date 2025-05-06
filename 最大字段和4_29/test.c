//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
////打印dp数组
//void printmax(int* dp,int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", dp[i]);
//	}
//	printf("\n");
//}
//
////打印最大字段
//void printnum(int*arr,int* dp, int end)
//{
//	int begin = -1;
//	int flag = 1;
//	for (int i = end; i >= 0; i--)
//	{
//		if (dp[i] > 0)//没有等于是为了确保字段为最小
//		{
//			begin = i;
//			flag = 0;
//		}
//		else
//		{
//			break;
//		}
//	}
//	if (flag) {
//		begin = end;
//	}
//	printf("对应子段 arr[%d..%d]：", begin, end);
//	for (int i = begin; i <= end; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
////构建dp数组
//int* createmaxnum(int* arr, int size)
//{
//	//dp[i]维护的是以i为结尾的最大字段和
//	int* dp = (int*)malloc(size * sizeof(int));
//	if (dp == NULL)
//	{
//		perror("malloc");
//		exit(1);
//	}
//	dp[0] = arr[0];
//	for (int i = 1; i < size; i++)
//	{
//		//找以i结尾的最大字段和
//		dp[i] = dp[i - 1] > 0 ? dp[i - 1] + arr[i] : arr[i];//这一段无非就是要么前一个最大字段和加上当前数字，要么丢弃前面最大字段和直接当前数字。即 dp[i] = max(dp[i-1]+arr[i],arr[i])
//	}
//	return dp;
//}
//
////在dp数组里挑数据最大
//int maxnums(int* dp, int size)
//{
//	int maxnum = dp[0];
//	int end = 0;
//	for (int i = 1; i < size; i++)
//	{
//		if (maxnum < dp[i])
//		{
//			maxnum = dp[i];
//			end = i;
//		}
//	}
//	return end;
//}
//
//
//
//int main()
//{
//	int size = 0;
//	printf("输入多少个数字:>");
//	scanf("%d", &size);
//
//	//arr[i]存的字段
//	int* arr = (int*)malloc(size * sizeof(int));
//	if (arr == NULL)
//	{
//		perror("malloc");
//		exit(1);
//	}
//	printf("依次输入数字，中间用空格隔开\n");
//	for (int i = 0; i < size; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	int*dp= createmaxnum(arr, size);
//	int index = maxnums(dp, size);//找到最大字段和
//	printf("最大字段和为:>%d\n", dp[index]);
//	//printmax(dp, size);//打印dp数组
//	printnum(arr,dp, index);
//
//	free(arr);
//	arr = NULL;
//	return 0;
//}