#define _CRT_SECURE_NO_WARNINGS
// ��������������ֵ
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ��ӡ����Ԫ��
void printArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ����ȫ���еĺ��ĵݹ麯��
void permute(int arr[], int start, int end) {
    if (start == end) {  // �������һ��Ԫ�أ���ӡ��ǰ����
        printArray(arr, end + 1);
    }
    else {
        for (int i = start; i <= end; i++) {
            swap(&arr[start], &arr[i]);  // ������ǰԪ������ʼԪ��
            permute(arr, start + 1, end);  // �ݹ鴦����һ��λ��
            swap(&arr[start], &arr[i]);  // ���ݣ��ָ�����ԭ״
        }
    }
}
