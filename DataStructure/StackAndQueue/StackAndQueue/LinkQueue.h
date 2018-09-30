#pragma once

#include<iostream>
#include"DataType.h"

typedef struct qnode{
	DataType data;
	struct qnode *next;
}QueueNode;
typedef struct{
	QueueNode*front;//��ͷָ��
	QueueNode*rear;//��βָ��
}LinkQueue;

//��ͷ����������

//����ն���
void InitQueue(LinkQueue*q){
	q->front = (QueueNode*)malloc(sizeof(QueueNode));
	q->rear = q->front;
	q->rear->next = NULL;
}

//�жӿ�
int QueueEmpty(LinkQueue*q){
	return q->rear == q->front;//ͷβָ����ȶ���Ϊ��
}

//�����
void EnQueue(LinkQueue*q, DataType x){
	QueueNode *p = (QueueNode*)malloc(sizeof(QueueNode));
	p->data = x;
	p->next = NULL;

	q->rear->next = p;
	q->rear = p;
}

//ȡ����Ԫ��
DataType GetFront(LinkQueue *q){
	if (QueueEmpty(q))
	{
		printf("Queue underflow");
		exit(0);
	}
	else
	{
		return q->front->data;
	}
}

//����
DataType DeQueue(LinkQueue*q){
	QueueNode *p;
	if (QueueEmpty(q))
	{
		printf("Queue underflow");
		exit(0);

	}
	else
	{
		p = q->front;//pָ��ͷ���
		q->front = q->front->next;//ͷָ��ָ��ԭ��ͷ���
		free(p);//�ͷ�ԭͷ���
		return q->front->data;//����ԭ��ͷ��������ֵ
	}
}