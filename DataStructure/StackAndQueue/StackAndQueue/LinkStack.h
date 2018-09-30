#pragma once

#include<iostream>
#include "DataType.h"

typedef struct stacknode{
	DataType data;
	struct stacknode *next;
}StackNode;
typedef  StackNode* LinkStack;
LinkStack top;

//�п�
int StackEmpty(LinkStack top){
	return top == NULL;
}

//��ջ
LinkStack Push(LinkStack top, DataType x){
	StackNode *p;
	p = (StackNode*)malloc(sizeof(StackNode));
	p->data = x;
	p->next = top;
	top = p;
	return top;
}

//��ջ
LinkStack Pop(LinkStack top, DataType *x){
	StackNode*p = top;
	if (StackEmpty(top))
	{
		printf("stack empty");
		exit(0);
	}
	else
	{
		*x = p->data;
		top = p->next;
		free(p);
		return top;
	}
}

//ȡջ��Ԫ��
DataType GetTop(LinkStack top){
	if (StackEmpty(top))
	{
		printf("stack empty");
		exit(0);
	}
	else
	{
		return	top->data;
	}
}