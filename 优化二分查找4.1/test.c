#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
typedef int Datetype;
//创建随机数组
void creatarr(Datetype* arr, int size)
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < size; i++)
    {
        arr[i] = (Datetype)(rand() % 100 + 1);//1--100
    }
}

void Swap(int* x, int* y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
//直接插入排序  升序
void InsertSort(int* arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int end = i;
        int temp = arr[end];
        while (end > 0)
        {
            if (arr[end - 1] > temp)
            {
                Swap(&arr[end], &arr[end - 1]);
                //end--;放if里面或外面都一样
            }
            else
            {
                break;
            }
            end--;
        }
    }
}

// 改进版二分查找（递归实现）：返回第一次出现的位置
int improvedBinarySearch(int arr[], int left, int right, int target) {
    if (left > right) return -1;  // 边界条件

    int mid = left + (right - left) / 2;

    // 递归分治策略
    if (arr[mid] == target) {
        // 检查是否是第一个出现的位置//升序，所以在左边
        if (mid == left || arr[mid - 1] != target) {
            return mid;
        }
        else {
            return improvedBinarySearch(arr, left, mid - 1, target);//right朝left靠近
        }
    }
    else if (arr[mid] < target) {
        return improvedBinarySearch(arr, mid + 1, right, target);  // 右半部分
    }
    else {
        return improvedBinarySearch(arr, left, mid - 1, target);   // 左半部分
    }
}

//打印
void printarr(Datetype* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i % 10 == 0 && i != 0)
        {
            printf("\n");
        }
        printf("%d\t", arr[i]);
    }
    printf("\n\n");
}

int main() {
    int target;

    int num = 0;//大小
    printf("输入你想有多少数字的数组:>");
    scanf("%d", &num);
    Datetype* arr = (Datetype*)malloc(num * sizeof(Datetype));
    if (arr == NULL)
    {
        perror("malloc");
        return 1;
    }

    creatarr(arr, num);
    printarr(arr, num);

    InsertSort(arr, num);
    printf("排序后:>\n");
    printarr(arr, num);

    printf("输入查找目标: ");
    scanf("%d", &target);

    // 处理数据
    int result = improvedBinarySearch(arr, 0, num - 1, target);

    // 输出结果
    if (result != -1) {
        printf("目标首次出现在索引: %d\n", result);
        printf("验证数组arr[%d] = %d\n", result, arr[result]);
    }
    else {
        printf("目标不存在于数组中\n");
    }

    return 0;
}