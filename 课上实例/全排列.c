#define _CRT_SECURE_NO_WARNINGS
// 交换两个整数的值
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 打印数组元素
void printArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 生成全排列的核心递归函数
void permute(int arr[], int start, int end) {
    if (start == end) {  // 到达最后一个元素，打印当前排列
        printArray(arr, end + 1);
    }
    else {
        for (int i = start; i <= end; i++) {
            swap(&arr[start], &arr[i]);  // 交换当前元素与起始元素
            permute(arr, start + 1, end);  // 递归处理下一个位置
            swap(&arr[start], &arr[i]);  // 回溯，恢复数组原状
        }
    }
}
