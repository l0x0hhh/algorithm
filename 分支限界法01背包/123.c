//#include<stdio.h>
//#include<assert.h>
//#include<stdlib.h>
//typedef int QDataType;
////队列结点的结构
//typedef struct QueueNode
//{
//	QDataType data;
//	struct QueueNode* next;
//}QueueNode;
//
////队列的结构
//typedef struct Queue
//{
//	QueueNode* phead;
//	QueueNode* ptail;
//	//int size; //队列中有效数据个数
//}Queue;
//void QueueInit(Queue* pq)
//{
//	assert(pq);
//	pq->phead = pq->ptail = NULL;
//	//pq->size=0;
//}
////入队——队尾  尾插
//void QueuePush(Queue* pq, QDataType x)
//{
//	assert(pq);
//	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
//	if (newnode == NULL)
//	{
//		perror("malloc");
//		exit(1);
//	}
//	newnode->next = NULL;
//	newnode->data = x;
//	if (pq->phead == NULL)
//	{
//		pq->phead = pq->ptail = newnode;
//	}
//	else
//	{
//		pq->ptail->next = newnode;
//		pq->ptail = newnode;
//	}
//	//pq->size++;
//}
////销毁队列
//void QueueDestroy(Queue* pq)
//{
//	assert(pq);//没必要是!QueueEmpty(pq)。因为空的队列也可以销毁
//	QueueNode* pcur = pq->phead;
//	while (pcur)
//	{
//		QueueNode* next = pcur->next;
//		free(pcur);
//		pcur = next;
//	}
//	pq->phead = pq->ptail = NULL;
//	//pq->size=0;
//}
//int main()
//{
//	Queue* q= (Queue*)malloc(sizeof(Queue));
//	QueueInit(q);
//	QueuePush(q, 1);
//	QueuePush(q, 2);
//	QueuePush(q, 3);
//	QueuePush(q, 4);
//	QueueNode* pcur = q->phead;
//	for (int i = 0; i < 4; i++)
//	{
//		if (pcur)
//		{
//			printf("%d->", pcur->data);
//			pcur = pcur->next;
//		}
//	}
//	QueueDestroy(q);
//	free(q);
//	q = NULL;
//}