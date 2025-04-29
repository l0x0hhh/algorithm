#pragma once
#include<stdio.h>
#include<stdlib.h>

//��������
void integerPartition(int n);
void integerPartitionHelper(int n, int max, int* result, int pos);
void printPartition(const int* result, int length);

//�������ֽ� 
void primeFactorization(int n);


//��ŵ��
void move(char pos1, char pos2);

void hanoi(int n, char pos1, char pos2, char pos3);


// ����ȫ���еĺ��ĵݹ麯��
void permute(int arr[], int start, int end);


//��������
int** createMatrix(int n);
// �ͷž����ڴ�
void freeMatrix(int** matrix, int n);
// ����ӷ� C = A + B
void addMatrix(int** A, int** B, int** C, int n);
// ������� C = A - B
void subMatrix(int** A, int** B, int** C, int n);
// Strassen �㷨������
void strassen(int** A, int** B, int** C, int n);
// ��ӡ����
void printMatrix(int** M, int n);
