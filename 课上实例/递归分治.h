#pragma once
#include<stdio.h>
#include<stdlib.h>

//整数划分
void integerPartition(int n);
void integerPartitionHelper(int n, int max, int* result, int pos);
void printPartition(const int* result, int length);

//质因数分解 
void primeFactorization(int n);


//汉诺塔
void move(char pos1, char pos2);

void hanoi(int n, char pos1, char pos2, char pos3);


// 生成全排列的核心递归函数
void permute(int arr[], int start, int end);


//矩阵连乘
int** createMatrix(int n);
// 释放矩阵内存
void freeMatrix(int** matrix, int n);
// 矩阵加法 C = A + B
void addMatrix(int** A, int** B, int** C, int n);
// 矩阵减法 C = A - B
void subMatrix(int** A, int** B, int** C, int n);
// Strassen 算法主函数
void strassen(int** A, int** B, int** C, int n);
// 打印矩阵
void printMatrix(int** M, int n);
