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

}

//  -----------------����-----------------
void test10()
{

}

int main()
{
	test01();
	//test02();
	return 0;
}