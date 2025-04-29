#define _CRT_SECURE_NO_WARNINGS

#include"�ݹ����.h"

//  -----------------�ݹ�-----------------
void test01()//������������
{
	int num;
	printf("����һ��������: ");
	scanf("%d", &num);
	integerPartition(num);

	//int num;
	//printf("����һ��������: ");
	//scanf("%d", &num);
	//primeFactorization(num);
}

void test02()//Hanoi������
{
	int n;
	scanf("%d", &n);
	hanoi(n, 'A', 'B', 'C');
}

void test03()//ȫ��������
{
	int arr[] = { 1, 1, 1};
	int length = sizeof(arr) / sizeof(arr[0]);
	permute(arr, 0, length - 1);  // �ӵ�һ��Ԫ�ؿ�ʼ����ȫ����
}

//  -----------------����-----------------
void test10()
{
	int n = 8; // n ������2����

	int** A = createMatrix(n);
	int** B = createMatrix(n);
	int** C = createMatrix(n);

	// ������������
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

	// �ͷ�
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