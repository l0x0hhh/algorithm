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

}

//  -----------------分治-----------------
void test10()
{

}

int main()
{
	test01();
	//test02();
	return 0;
}