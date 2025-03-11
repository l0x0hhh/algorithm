#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//ð������
void sortArr(int arr[],int size)//����
{
	for (int i = 0; i < size-1; i++)//size-1�ִ�ѭ��
	{
		for (int j = 0; j < size-1-i; j++)
		{
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//����
void swap(int* a, int* b)
{
	int temp=*a;
	*a = *b;
	*b = temp;
}

//// ��������
//int partition(int arr[], int low, int high) {
//	int pivot = arr[low];  // ѡ��һ��Ԫ��Ϊ��׼
//	int left = low + 1;    // ��ָ��ӻ�׼��һ��λ�ÿ�ʼ
//	int right = high;      // ��ָ���ĩβ��ʼ
//
//	while (left <= right) {
//		// ��ָ���ұȻ�׼���Ԫ��
//		while (left <= right && arr[left] <= pivot) left++;
//		// ��ָ���ұȻ�׼С��Ԫ��
//		while (left <= right && arr[right] > pivot) right--;
//		// ��������ָ���Ԫ��
//		if (left < right) {
//			swap(&arr[left], &arr[right]);
//			left++;
//			right--;
//		}
//	}
//	// ����׼�ŵ���ȷλ��
//	swap(&arr[low], &arr[right]);
//	return right;  // ���ػ�׼������λ��
//}

// ��������
int partition(int arr[], int low, int high) {
	int randomIndex = low + rand() % (high - low + 1);
	swap(&arr[low], &arr[randomIndex]);

	int pivot = arr[low];  // ѡ��һ��Ԫ��Ϊ��׼
	
	int left = low;    // ��ָ��ӻ�׼��һ��λ�ÿ�ʼ
	int right = high;      // ��ָ���ĩβ��ʼ

	while (left != right) {
		// ��ָ���ұȻ�׼С��Ԫ��
		while (left < right && arr[right] > pivot)
		{
			right--;
		}
		// ��������ָ���Ԫ��
		if (left < right) {
			swap(&arr[left], &arr[right]);
			left++;
		}

		// ��ָ���ұȻ�׼���Ԫ��
		while (left < right && arr[left] <= pivot) left++;
		// ��������ָ���Ԫ��
		if (left < right) {
			swap(&arr[left], &arr[right]);
			right--;
		}
	}
	// ����׼�ŵ���ȷλ��
	swap(&pivot, &arr[right]);
	return right;  // ���ػ�׼������λ��
}

//����
void quickSort(int arr[], int low, int high) {
	if (low < high) {  // �ݹ���ֹ�����������鳤��=1
		int pivotIndex = partition(arr, low, high);  // ����
		quickSort(arr, low, pivotIndex - 1);         // �ݹ�������벿��
		quickSort(arr, pivotIndex + 1, high);        // �ݹ������Ұ벿��
	}
}

//��ӡ����
void printArr(int arr[],int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void inital_arr(int* arr, int sz)
{
	printf("���������������֣����ÿո�ָ�:\n");
	for (int i = 0; i < sz; i++)
	{
		scanf("%d", &arr[i]);
	}
}
void meau()
{
	printf("------------����-------------\n");
	printf("|---- 1.ð��      2.���� ----|\n");
	printf("|---------  0.�˳�  ---------|\n");
	printf("-----------------------------\n");
}
int main()
{
	int input = 0;
	int sz = 0;

	do {
		meau();
		printf("��ѡ����:>");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("��ӭ�´�ʹ��\n");
			break;
		case 1:
			printf("����������������ֵĸ���:>");
			scanf("%d", &sz);
			int* arr = (int*)malloc(sz * sizeof(int));
			inital_arr(arr, sz);
			printf("����ǰ������: \n");
			printArr(arr, sz);
			sortArr(arr, sz);
			printf("����������: \n");
			printArr(arr, sz);
			break;
		case 2:
			printf("����������������ֵĸ���:>");
			scanf("%d", &sz);
			int* arr2 = (int*)malloc(sz * sizeof(int));
			inital_arr(arr2, sz);
			printf("����ǰ������: \n");
			printArr(arr2, sz);
			quickSort(arr2, 0, sz - 1);
			printf("����������: \n");
			printArr(arr2, sz);
			break;
		default:
			printf("ѡ�������������\n");
			break;
		}
	} while (input);
	return 0;
}

//-------------------------------------------------------

////���������㷨
//void quickSort(int arr[], int low,int high)
//{
//	int i = low;
//	int j = high;
//	if (i >= j) {
//		return;
//	}
//
//	int temp = arr[low];
//	while (i != j) {
//		while (arr[j] >= temp && i < j) {
//			j--;
//		}
//		while (arr[i] <= temp && i < j) {
//			i++;
//		}
//		if (i < j) {
//			swap(&arr[i], &arr[j]);
//		}
//	}
//
//	//����׼temp�����Լ���λ�ã�����i��λ�ã�
//	swap(&arr[low], &arr[i]);
//	quickSort(arr, low, i - 1);
//	quickSort(arr, i + 1, high);
//
//}

//-------------------------------------------------------

////ai
//// �������������ػ�׼Ԫ�ص�����λ��
//int partition(int arr[], int low, int high) {
//	int pivot = arr[high];  // ѡ�����һ��Ԫ����Ϊ��׼
//	int i = low - 1;        // i ���ڱ��С�� pivot ������
//
//	for (int j = low; j < high; j++) {
//		if (arr[j] < pivot) {  // С�ڻ�׼��Ԫ�ؽ�����ǰ��
//			i++;
//			swap(&arr[i], &arr[j]);
//		}
//	}
//	swap(&arr[i + 1], &arr[high]);  // �� pivot �ŵ���ȷλ��
//	return i + 1;  // ���� pivot ������
//}
//
//// ����������
//void quickSort(int arr[], int low, int high) {
//	if (low < high) {
//		int pi = partition(arr, low, high); // ��ȡ��������
//		quickSort(arr, low, pi - 1);  // �ݹ������󲿷�
//		quickSort(arr, pi + 1, high); // �ݹ������Ҳ���
//	}
//}