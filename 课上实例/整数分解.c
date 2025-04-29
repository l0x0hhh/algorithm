#define _CRT_SECURE_NO_WARNINGS
#include"�ݹ����.h"

// ��ӡ�ֽ���
void printPartition(const int* result, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d", result[i]);
        if (i != length - 1) {
            printf("+");
        }
    }
    printf("\n");
}

// �ݹ鸨���������Ż��棩
void integerPartitionHelper(int n, int max, int* result, int pos) {
    if (n == 0) {
        printPartition(result, pos);
        return;
    }
    // �Ż���i �� max �ݼ������ٵݹ����
    for (int i = max; i >= 1; i--) {
        if (i > n) continue; // ������Ч���
        result[pos] = i;
        integerPartitionHelper(n - i, i, result, pos + 1);
    }
}

// ���������Ż��ڴ����
void integerPartition(int n) {
    if (n <= 0) {
        printf("��������������\n");
        return;
    }
    int* result = (int*)malloc(n * sizeof(int));
    if (!result) {
        perror("malloc");
        return;
    }
    integerPartitionHelper(n, n, result, 0);
    free(result);
}


void primeFactorization(int n)//�������ֽ� 
{
    printf("%d = ", n);
    if (n <= 1) {
        printf("%d", n);
        return;
    }

    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            printf("%d", i);
            n /= i;
            if (n != 1) printf(" * ");
        }
    }
    if (n > 1) {
        printf("%d", n); // ����ʣ�������
    }
}
