//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
////��ӡdp����
//void printmax(int* dp,int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", dp[i]);
//	}
//	printf("\n");
//}
//
////��ӡ����ֶ�
//void printnum(int*arr,int* dp, int end)
//{
//	int begin = -1;
//	int flag = 1;
//	for (int i = end; i >= 0; i--)
//	{
//		if (dp[i] > 0)//û�е�����Ϊ��ȷ���ֶ�Ϊ��С
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
//	printf("��Ӧ�Ӷ� arr[%d..%d]��", begin, end);
//	for (int i = begin; i <= end; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
////����dp����
//int* createmaxnum(int* arr, int size)
//{
//	//dp[i]ά��������iΪ��β������ֶκ�
//	int* dp = (int*)malloc(size * sizeof(int));
//	if (dp == NULL)
//	{
//		perror("malloc");
//		exit(1);
//	}
//	dp[0] = arr[0];
//	for (int i = 1; i < size; i++)
//	{
//		//����i��β������ֶκ�
//		dp[i] = dp[i - 1] > 0 ? dp[i - 1] + arr[i] : arr[i];//��һ���޷Ǿ���Ҫôǰһ������ֶκͼ��ϵ�ǰ���֣�Ҫô����ǰ������ֶκ�ֱ�ӵ�ǰ���֡��� dp[i] = max(dp[i-1]+arr[i],arr[i])
//	}
//	return dp;
//}
//
////��dp���������������
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
//	printf("������ٸ�����:>");
//	scanf("%d", &size);
//
//	//arr[i]����ֶ�
//	int* arr = (int*)malloc(size * sizeof(int));
//	if (arr == NULL)
//	{
//		perror("malloc");
//		exit(1);
//	}
//	printf("�����������֣��м��ÿո����\n");
//	for (int i = 0; i < size; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	int*dp= createmaxnum(arr, size);
//	int index = maxnums(dp, size);//�ҵ�����ֶκ�
//	printf("����ֶκ�Ϊ:>%d\n", dp[index]);
//	//printmax(dp, size);//��ӡdp����
//	printnum(arr,dp, index);
//
//	free(arr);
//	arr = NULL;
//	return 0;
//}