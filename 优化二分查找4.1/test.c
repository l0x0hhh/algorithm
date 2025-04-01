#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
// �Ľ�����ֲ��ң��ݹ�ʵ�֣������ص�һ�γ��ֵ�λ��
int improvedBinarySearch(int arr[], int left, int right, int target) {
    if (left > right) return -1;  // ��������

    int mid = left + (right - left) / 2;

    // �ݹ���β���
    if (arr[mid] == target) {
        // ����Ƿ��ǵ�һ�����ֵ�λ��//�������������
        if (mid == left || arr[mid - 1] != target) {
            return mid;
        }
        else {
            return improvedBinarySearch(arr, left, mid - 1, target);
        }
    }
    else if (arr[mid] < target) {
        return improvedBinarySearch(arr, mid + 1, right, target);  // �Ұ벿��
    }
    else {
        return improvedBinarySearch(arr, left, mid - 1, target);   // ��벿��
    }
}

int main() {
    int n, target;

    // ��������
    printf("���������С: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n);
    if (arr == NULL)
    {
        perror("malloc");
    }
    printf("����%d�������������ո�ָ���:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("�������Ŀ��: ");
    scanf("%d", &target);

    // ��������
    int result = improvedBinarySearch(arr, 0, n - 1, target);

    // ������
    if (result != -1) {
        printf("Ŀ���״γ���������: %d\n", result);
        printf("��֤����[%d] = %d\n", result, arr[result]);
    }
    else {
        printf("Ŀ�겻������������\n");
    }

    return 0;
}