#pragma once

#include "DataType.h"
#include"CirQueue.h"
#include"SeqStackInt.h"
#include"SeqStack.h"

int Priority(DataType op){
	switch (op)
	{
	case '(':
	case '#':return 0;
	case'-':
	case'+':return 1;
	case'*':
	case'/':return 2;

	}
	return -1;
}

void CTPostExp(CirQueue *Q){
	SeqStack S;//运算符栈
	char c, t;
	InitStack(&S);//初始化栈
	Push(&S, '#');//压入栈底元素‘#’
	do
	{
		c = getchar();
		switch (c)
		{
		case' ':break;//去空格
		case'0':
		case'1':
		case'2':
		case'3':
		case'4':
		case'5':
		case'6':
		case'7':
		case'8':
		case'9':EnQueue(Q, c); break;
		case'(':Push(&S, c); break;
		case ')':
		case'#':
			do
			{
				t = Pop(&S);
				if (t != '('&&t != '#')
				{
					EnQueue(Q, t);
				}
			} while (t != '('&&S.top != -1); break;
		case'-':
		case'+':
		case'*':
		case'/':
			while (Priority(c) <= Priority(GetTop(&S)))
			{
				t = Pop(&S);
				EnQueue(Q, t);
			}
			Push(&S, c);
			break;
		}

	} while (c != '#');

}

int CPostExp(CirQueue q){

	SeqStackInt S;
	char ch = ' ';
	int x, y;
	InitStack(&S);
	while (!QueueEmpty(&q))
	{
		ch = DeQueue(&q);
		if (ch >= '0'&&ch <= '9')
		{
			Push(&S, ch - '0');
		}
		else
		{
			y = Pop(&S);
			x = Pop(&S);
			switch (ch)
			{
			case'+':Push(&S, x + y); break;
			case'-':Push(&S, x - y); break;
			case'*':Push(&S, x * y); break;
			case'/':Push(&S, x / y); break;
			}
		}
	}
	return GetTop(&S);
}