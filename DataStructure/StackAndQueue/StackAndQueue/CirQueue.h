#pragma once

#include<iostream>
#include "DataType.h"
using namespace std;

#define QueueSize 100
typedef struct {
	DataType data[QueueSize];
	int front, rear;
}CirQueue;

//置空队列
void InitQueue(CirQueue*Q){
	Q->front = Q->rear = 0;
}

//判队空
int QueueEmpty(CirQueue *q){
	return q->rear == q->front;
}

//判队满
int QueueFull(CirQueue *q){
	return (q->rear + 1) % QueueSize == q->front;
}

//入队列
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

//取对头元素
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

//出队列
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

//出队显示
void CirQueueDiplayDeQueue(CirQueue*q){

	if (!QueueEmpty(q))
	{
		cout << DeQueue(q);
	}
}
//显示队列元素，从对头到对尾
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