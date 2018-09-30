#pragma once

#include<iostream>

typedef int DataTypeInt;

#define StackSize 100 
typedef struct{
	DataTypeInt data[StackSize];
	int top;
}SeqStackInt; 

///ÖÃ¿ÕÕ»
void InitStack(SeqStackInt *S)
{
	S->top = -1;
}

//ÅÐÕ»¿Õ
int StackEmpty(SeqStackInt*s){
	return s->top == -1;
}

//ÅÐÕ»Âú
int StackFull(SeqStackInt *s){
	return	s->top == StackSize - 1;
}

//½øÕ»
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

//ÍËÕ»
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

//È¡Õ»¶¥ÔªËØ
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