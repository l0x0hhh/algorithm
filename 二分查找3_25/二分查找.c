#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
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

//ð������  ����
void bublesort(Datetype* arr, int size)
{
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size-1-i; j++)
		{
			if (arr[j] > arr[j + 1]) 
			{
				Datetype temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//����
////���ֲ���
//int findnum(Datetype* arr, Datetype wantnum, int size, int* found)
//{
//	int left = 0;
//	int right = size - 1;
//	
//	while (left <= right)
//	{
//		int mid = left + (right - left) / 2;
//		if (arr[mid] < wantnum)//ֵ���ұ�
//		{
//			left = mid + 1;
//		}
//		else if(arr[mid] > wantnum)//ֵ�����
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			*found = 1;//�ҵ���
//			return mid;
//		}
//	}
//	return left;
//}

//�ݹ���ֲ���
//���ֲ���
int findnum(Datetype* arr, Datetype wantnum,int left, int right, int* found)
{
	if (left > right) {
		return left;
	}

	int mid = left + (right - left) / 2;
	if (arr[mid] < wantnum)//ֵ���ұ�
	{
		return findnum(arr, wantnum, mid + 1, right,found);
	}
	else if (arr[mid] > wantnum)//ֵ�����
	{
		return findnum(arr, wantnum, left, mid-1, found);
	}
	else
	{
		*found = 1;//�ҵ���
		return mid;
	}

}

int Del(int* nums,int size)//ɾ���ظ�Ԫ��
{
	int i = 0;
	for (int j = 1; j < size; j++)//��ָ��
	{
		if (nums[j] != nums[i])
		{
			i++;
			nums[i] = nums[j];
		}
	}
	return i + 1;//����
}

//��ӡ
void printarr(Datetype* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if(i % 10 == 0&&i!=0)
		{
			printf("\n");
		}
		printf("%d\t", arr[i]);
	}
	printf("\n\n");
}

int main()
{
	int num=0;//��С
	printf("���������ж������ֵ�����:>");
	scanf("%d", &num);
	Datetype* arr = (Datetype*)malloc(num * sizeof(Datetype));
	if (arr == NULL)
	{
		perror("malloc");
		return 1;
	}

	creatarr(arr,num);
	printarr(arr, num);

	bublesort(arr, num);
	printf("�����:>\n");
	printarr(arr, num);

	printf("ɾ���ظ�Ԫ�غ�:>\n");
	int size=Del(arr, num);
	printarr(arr, size);

	Datetype numwant = 0;
	printf("������������ҵ�ֵ,���������±꣨��0��ʼ��:>");
	scanf("%d", &numwant);

	int found = 0;
	//int pos = findnum(arr, numwant, num,&found);
	int pos = findnum(arr, numwant, 0, size-1, &found);//�ݹ�
	if (found) {
		printf("���� %d �������е��±�Ϊ %d\n", numwant, pos);
	}
	else
	{
		printf("���� %d ���������У����ڲ���...\n", numwant);

		// ��չ���飨ʹ�� realloc��
		Datetype* new_arr = (Datetype*)realloc(arr, 2*num * sizeof(Datetype));
		if (new_arr == NULL) {
			perror("realloc");
			free(arr);
			arr = NULL;
			return 1;
		}

		arr = new_arr;

		for (int i = num; i > pos; i--)
		{
			arr[i] = arr[i - 1];
		}

		arr[pos] = numwant; // ������Ԫ��
		num++; // �����С +1

		printf("����������:>\n");
		printarr(arr, num);
	}
	
	free(arr);
	arr = NULL;
	return 0;
}