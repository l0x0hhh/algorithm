#define _CRT_SECURE_NO_WARNINGS
#include"递归分治.h"
// 创建 n x n 的矩阵并初始化为 0
int** createMatrix(int n) {
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)calloc(n, sizeof(int));
    }
    return matrix;
}

// 释放矩阵内存
void freeMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// 矩阵加法 C = A + B
void addMatrix(int** A, int** B, int** C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// 矩阵减法 C = A - B
void subMatrix(int** A, int** B, int** C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// Strassen 算法主函数
void strassen(int** A, int** B, int** C, int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;
    // 创建子矩阵
    int** A11 = createMatrix(k), ** A12 = createMatrix(k), ** A21 = createMatrix(k), ** A22 = createMatrix(k);
    int** B11 = createMatrix(k), ** B12 = createMatrix(k), ** B21 = createMatrix(k), ** B22 = createMatrix(k);
    int** C11 = createMatrix(k), ** C12 = createMatrix(k), ** C21 = createMatrix(k), ** C22 = createMatrix(k);

    int** M1 = createMatrix(k), ** M2 = createMatrix(k), ** M3 = createMatrix(k), ** M4 = createMatrix(k);
    int** M5 = createMatrix(k), ** M6 = createMatrix(k), ** M7 = createMatrix(k);

    int** tempA = createMatrix(k), ** tempB = createMatrix(k);

    // 划分子矩阵
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    // M1 = (A11 + A22) * (B11 + B22)
    addMatrix(A11, A22, tempA, k);
    addMatrix(B11, B22, tempB, k);
    strassen(tempA, tempB, M1, k);

    // M2 = (A21 + A22) * B11
    addMatrix(A21, A22, tempA, k);
    strassen(tempA, B11, M2, k);

    // M3 = A11 * (B12 - B22)
    subMatrix(B12, B22, tempB, k);
    strassen(A11, tempB, M3, k);

    // M4 = A22 * (B21 - B11)
    subMatrix(B21, B11, tempB, k);
    strassen(A22, tempB, M4, k);

    // M5 = (A11 + A12) * B22
    addMatrix(A11, A12, tempA, k);
    strassen(tempA, B22, M5, k);

    // M6 = (A21 - A11) * (B11 + B12)
    subMatrix(A21, A11, tempA, k);
    addMatrix(B11, B12, tempB, k);
    strassen(tempA, tempB, M6, k);

    // M7 = (A12 - A22) * (B21 + B22)
    subMatrix(A12, A22, tempA, k);
    addMatrix(B21, B22, tempB, k);
    strassen(tempA, tempB, M7, k);

    // 组合 C11 = M1 + M4 - M5 + M7
    addMatrix(M1, M4, tempA, k);
    subMatrix(tempA, M5, tempB, k);
    addMatrix(tempB, M7, C11, k);

    // C12 = M3 + M5
    addMatrix(M3, M5, C12, k);

    // C21 = M2 + M4
    addMatrix(M2, M4, C21, k);

    // C22 = M1 - M2 + M3 + M6
    subMatrix(M1, M2, tempA, k);
    addMatrix(tempA, M3, tempB, k);
    addMatrix(tempB, M6, C22, k);

    // 合并 C11 ~ C22 到 C
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }

    // 释放所有子矩阵
    int** allMatrices[] = { A11, A12, A21, A22, B11, B12, B21, B22,
                           C11, C12, C21, C22,
                           M1, M2, M3, M4, M5, M6, M7,
                           tempA, tempB };
    for (int i = 0; i < 20; i++) {
        freeMatrix(allMatrices[i], k);
    }
}

// 打印矩阵
void printMatrix(int** M, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d ", M[i][j]);
        }
        printf("\n");
    }
}