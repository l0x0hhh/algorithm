#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
// 改进版二分查找（递归实现）：返回第一次出现的位置
int improvedBinarySearch(int arr[], int left, int right, int target) {
    if (left > right) return -1;  // 基线条件

    int mid = left + (right - left) / 2;

    // 递归分治策略
    if (arr[mid] == target) {
        // 检查是否是第一个出现的位置//升序，所以在左边
        if (mid == left || arr[mid - 1] != target) {
            return mid;
        }
        else {
            return improvedBinarySearch(arr, left, mid - 1, target);
        }
    }
    else if (arr[mid] < target) {
        return improvedBinarySearch(arr, mid + 1, right, target);  // 右半部分
    }
    else {
        return improvedBinarySearch(arr, left, mid - 1, target);   // 左半部分
    }
}

int main() {
    int n, target;

    // 数据输入
    printf("输入数组大小: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n);
    if (arr == NULL)
    {
        perror("malloc");
    }
    printf("输入%d个有序整数（空格分隔）:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("输入查找目标: ");
    scanf("%d", &target);

    // 处理数据
    int result = improvedBinarySearch(arr, 0, n - 1, target);

    // 输出结果
    if (result != -1) {
        printf("目标首次出现在索引: %d\n", result);
        printf("验证数组[%d] = %d\n", result, arr[result]);
    }
    else {
        printf("目标不存在于数组中\n");
    }

    return 0;
}