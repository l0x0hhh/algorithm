#define _CRT_SECURE_NO_WARNINGS
#include"递归分治.h"

// 打印分解结果
void printPartition(const int* result, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d", result[i]);
        if (i != length - 1) {
            printf("+");
        }
    }
    printf("\n");
}

// 递归辅助函数（优化版）
void integerPartitionHelper(int n, int max, int* result, int pos) {
    if (n == 0) {
        printPartition(result, pos);
        return;
    }
    // 优化：i 从 max 递减，减少递归次数
    for (int i = max; i >= 1; i--) {
        if (i > n) continue; // 跳过无效情况
        result[pos] = i;
        integerPartitionHelper(n - i, i, result, pos + 1);
    }
}

// 主函数（优化内存管理）
void integerPartition(int n) {
    if (n <= 0) {
        printf("请输入正整数！\n");
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


void primeFactorization(int n)//质因数分解 
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
        printf("%d", n); // 处理剩余的质数
    }
}
