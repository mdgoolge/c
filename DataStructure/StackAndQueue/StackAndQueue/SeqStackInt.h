#pragma once

#include<iostream>

typedef int DataTypeInt;

#define StackSize 100 
typedef struct{
	DataTypeInt data[StackSize];
	int top;
}SeqStackInt; 

///�ÿ�ջ
void InitStack(SeqStackInt *S)
{
	S->top = -1;
}

//��ջ��
int StackEmpty(SeqStackInt*s){
	return s->top == -1;
}

//��ջ��
int StackFull(SeqStackInt *s){
	return	s->top == StackSize - 1;
}

//��ջ
void Push(SeqStackInt *s, DataTypeInt x){
	if (StackFull(s))
	{
		printf("stack overflow");
	}
	else
	{
		s->top++;
		s->data[s->top] = x;
	}

}

//��ջ
DataTypeInt Pop(SeqStackInt*s){
	if (StackEmpty(s))
	{
		printf("stack underflow");
		exit(0);
	}
	else
	{
		return s->data[s->top--];
	}
}

//ȡջ��Ԫ��
DataTypeInt GetTop(SeqStackInt*s)
{
	if (StackEmpty(s))
	{
		printf("stack empty");
		exit(0);
	}
	else
	{
		return s->data[s->top];
	}
}