#define _CRT_SECURE_NO_WARNINGS

#include"递归分治.h"

//  -----------------递归-----------------
void test01()//整数划分问题
{
	int num;
	printf("输入一个正整数: ");
	scanf("%d", &num);
	integerPartition(num);

	//int num;
	//printf("输入一个正整数: ");
	//scanf("%d", &num);
	//primeFactorization(num);
}

void test02()//Hanoi塔问题
{
	int n;
	scanf("%d", &n);
	hanoi(n, 'A', 'B', 'C');
}

void test03()//全排列问题
{
	int arr[] = { 1, 1, 1};
	int length = sizeof(arr) / sizeof(arr[0]);
	permute(arr, 0, length - 1);  // 从第一个元素开始生成全排列
}

//  -----------------分治-----------------
void test10()
{
	int n = 8; // n 必须是2的幂

	int** A = createMatrix(n);
	int** B = createMatrix(n);
	int** C = createMatrix(n);

	// 填入样例数据
	int count = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			A[i][j] = count++, B[i][j] = count++;

	printf("Matrix A:\n");
	printMatrix(A, n);

	printf("Matrix B:\n");
	printMatrix(B, n);

	strassen(A, B, C, n);

	printf("Matrix C = A * B (Strassen):\n");
	printMatrix(C, n);

	// 释放
	freeMatrix(A, n);
	freeMatrix(B, n);
	freeMatrix(C, n);

}

int main()
{
	//test01();
	//test02();
	//test03();

	test10();
	return 0;
}