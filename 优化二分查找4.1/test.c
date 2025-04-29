#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
typedef int Datetype;
//�����������
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
//ֱ�Ӳ�������  ����
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
                //end--;��if��������涼һ��
            }
            else
            {
                break;
            }
            end--;
        }
    }
}

// �Ľ�����ֲ��ң��ݹ�ʵ�֣������ص�һ�γ��ֵ�λ��
int improvedBinarySearch(int arr[], int left, int right, int target) {
    if (left > right) return -1;  // �߽�����

    int mid = left + (right - left) / 2;

    // �ݹ���β���
    if (arr[mid] == target) {
        // ����Ƿ��ǵ�һ�����ֵ�λ��//�������������
        if (mid == left || arr[mid - 1] != target) {
            return mid;
        }
        else {
            return improvedBinarySearch(arr, left, mid - 1, target);//right��left����
        }
    }
    else if (arr[mid] < target) {
        return improvedBinarySearch(arr, mid + 1, right, target);  // �Ұ벿��
    }
    else {
        return improvedBinarySearch(arr, left, mid - 1, target);   // ��벿��
    }
}

//��ӡ
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

    int num = 0;//��С
    printf("���������ж������ֵ�����:>");
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
    printf("�����:>\n");
    printarr(arr, num);

    printf("�������Ŀ��: ");
    scanf("%d", &target);

    // ��������
    int result = improvedBinarySearch(arr, 0, num - 1, target);

    // ������
    if (result != -1) {
        printf("Ŀ���״γ���������: %d\n", result);
        printf("��֤����arr[%d] = %d\n", result, arr[result]);
    }
    else {
        printf("Ŀ�겻������������\n");
    }

    return 0;
}