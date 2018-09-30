#pragma once

#include<iostream>
#include"DataType.h"

typedef struct qnode{
	DataType data;
	struct qnode *next;
}QueueNode;
typedef struct{
	QueueNode*front;//队头指针
	QueueNode*rear;//队尾指针
}LinkQueue;

//带头结点的链队列

//构造空队列
void InitQueue(LinkQueue*q){
	q->front = (QueueNode*)malloc(sizeof(QueueNode));
	q->rear = q->front;
	q->rear->next = NULL;
}

//判队空
int QueueEmpty(LinkQueue*q){
	return q->rear == q->front;//头尾指针相等队列为空
}

//入队列
void EnQueue(LinkQueue*q, DataType x){
	QueueNode *p = (QueueNode*)malloc(sizeof(QueueNode));
	p->data = x;
	p->next = NULL;

	q->rear->next = p;
	q->rear = p;
}

//取队列元素
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

//出对
DataType DeQueue(LinkQueue*q){
	QueueNode *p;
	if (QueueEmpty(q))
	{
		printf("Queue underflow");
		exit(0);

	}
	else
	{
		p = q->front;//p指向头结点
		q->front = q->front->next;//头指针指向原对头结点
		free(p);//释放原头结点
		return q->front->data;//返回原对头结点的数据值
	}
}