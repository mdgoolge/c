#pragma once

#include<iostream>
#include "DataType.h"
using namespace std;

#define QueueSize 100
typedef struct {
	DataType data[QueueSize];
	int front, rear;
}CirQueue;

//�ÿն���
void InitQueue(CirQueue*Q){
	Q->front = Q->rear = 0;
}

//�жӿ�
int QueueEmpty(CirQueue *q){
	return q->rear == q->front;
}

//�ж���
int QueueFull(CirQueue *q){
	return (q->rear + 1) % QueueSize == q->front;
}

//�����
void EnQueue(CirQueue*q, DataType x){
	if (QueueFull(q))
	{
		printf("Queue overflow");
	}
	else
	{
		q->data[q->rear] = x;
		q->rear = (q->rear + 1) % QueueSize;
	}
}

//ȡ��ͷԪ��
DataType GetFront(CirQueue*q){
	if (QueueEmpty(q))
	{
		printf("Queue empty");
	}
	else
	{
		return q->data[q->front];
	}

}

//������
DataType DeQueue(CirQueue*q){
	DataType x;
	if (QueueEmpty(q))
	{
		printf("Queue empty");
		exit(0);
	}
	else
	{
		x = q->data[q->front];
		q->front = (q->front + 1) % QueueSize;
		return x;
	}
}

//������ʾ
void CirQueueDiplayDeQueue(CirQueue*q){

	if (!QueueEmpty(q))
	{
		cout << DeQueue(q);
	}
}
//��ʾ����Ԫ�أ��Ӷ�ͷ����β
void CirQueueDiplay(CirQueue*q){

	int front = q->front;
	int rear = q->rear;
	while ((rear + 1) % QueueSize != front)
	{
		cout << q->data[front];
		front++;
	}
	cout << endl;
}