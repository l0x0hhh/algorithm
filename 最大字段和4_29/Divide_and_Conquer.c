#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int maxnum;
    int begin;
    int end;
}SubarrayResult;


SubarrayResult max3(SubarrayResult a, SubarrayResult b, SubarrayResult c) 
{
    SubarrayResult max_ab = a.maxnum > b.maxnum ? a : b;
    return max_ab.maxnum > c.maxnum ? max_ab : c;
}

// 分治实现：返回 arr[left...right] 范围内的最大子段和
SubarrayResult maxSubArrayDivide(int* arr, int left, int right) {
    if (left == right)
    {
        SubarrayResult base = { arr[left],left,left };
        return base;
    }
    
    int mid = left + (right - left) / 2;

    //左区间
    SubarrayResult leftmax = maxSubArrayDivide(arr, left, mid);
    //右区间
    SubarrayResult rightmax = maxSubArrayDivide(arr, mid + 1, right);

    //跨越中间的最大子段和
    SubarrayResult crossMax;
    int leftCross = arr[mid];
    int sum = 0;
    crossMax.begin = mid;//必须初始化为这个数，因为防止从未进if判断里
    for (int i = mid; i >= left; i--)
    {
        sum += arr[i];
        if (sum > leftCross)
        {
            leftCross = sum;
            crossMax.begin = i;
        }
    }

    int rightCross= arr[mid+1];
    sum = 0;
    crossMax.end = mid+1;//必须初始化为这个数，因为防止从未进if判断里
    for (int i = mid+1; i <= right; i++)
    {
        sum += arr[i];
        if (sum > rightCross)
        {
            rightCross = sum;
            crossMax.end = i;
        }
    }
    crossMax.maxnum = leftCross + rightCross;
    return max3(leftmax, rightmax, crossMax);
}

int main() {
    int size = 0;
    printf("输入多少个数字:>");
    scanf("%d", &size);

    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        perror("malloc");
        exit(1);
    }

    printf("依次输入数字，中间用空格隔开\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    SubarrayResult result = maxSubArrayDivide(arr, 0, size - 1);
    printf("最大字段和为:>%d\n", result.maxnum);
    printf("对应子段下标 [%d..%d]：", result.begin, result.end);
    for (int i = result.begin; i <= result.end; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    arr = NULL;
    return 0;
}
