#pragma once
#include<stdio.h>
#include<stdlib.h>

//��������
void integerPartition(int n);
void integerPartitionHelper(int n, int max, int* result, int pos);
void printPartition(const int* result, int length);

void primeFactorization(int n);


//��ŵ��
void move(char pos1, char pos2);

void hanoi(int n, char pos1, char pos2, char pos3);