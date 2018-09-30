#pragma once

#include<iostream>
#include"Node.h"
#include"SeqStack.h"
using namespace std;

///从广义表创建二叉树
BinTNode * CreateTreeFromGList(char*str){
	BinTNode *st[100];
	BinTNode *p = NULL;
	int top, k, j = 0;
	top = -1;
	char ch = str[j];
	BinTNode*b = NULL;
	while (ch != '\0')
	{
		switch (ch)
		{
		case '(':
			top++;
			st[top] = p;
			k = 1;
			break;
		case')':
			top--;
			break;
		case',':
			k = 2;
			break;
		default:
			p = (BinTNode*)malloc(sizeof(BinTNode));
			p->data = ch;
			p->lchild = p->rchild = NULL;
			if (b == NULL)
			{
				b = p;
			}
			else
			{
				switch (k)
				{
				case 1:st[top]->lchild = p; break;
				case 2:st[top]->rchild = p; break;
				}
			}
		}
		j++; ch = str[j];
	}

	return	b;
}

void Test_CreateTree(){
	char*str = "(A(B(,D(E,F)),C))";
	BinTNode* b = CreateTreeFromGList(str);
}

BinTree CreateBinTree(){
	BinTNode*Q[100];
	BinTNode*s;
	int front, rear;
	char ch;
	ch = getchar();
	BinTree	bt = NULL;
	front = 1;
	rear = 0;
	while (ch != '#')
	{
		s = NULL;
		if (ch != '@')
		{
			s = (BinTNode*)malloc(sizeof(BinTNode));
			s->data = ch;
			s->lchild = s->rchild = NULL;
		}
		rear++;
		Q[rear] = s;
		if (rear == 1)
		{
			bt = s;
		}
		else
		{
			if (s != NULL && Q[front] != NULL)
			{
				if (rear % 2 == 0)
				{
					Q[front]->lchild = s;
				}
				else
				{
					Q[front]->rchild = s;
				}

				if (rear % 2 != 0)
				{
					front++;
				}
			}
		}
		ch = getchar();
	}
	return bt;
}
BinTree CreateBinTreeFromArray(char * str){

	BinTree	bt = NULL;

	BinTNode*Q[100];
	int front, rear;
	front = 1;
	rear = 0;

	BinTNode*s;


	char ch;
	int j = 0;
	ch = str[j];


	while (ch != '\0')
	{
		s = NULL;
		if (ch != '@')
		{
			s = (BinTNode*)malloc(sizeof(BinTNode));
			s->data = ch;
			s->lchild = s->rchild = NULL;
		}
		rear++;
		Q[rear] = s;
		if (rear == 1)
		{
			bt = s;
		}
		else
		{
			if (s != NULL && Q[front] != NULL)
			{
				if (rear % 2 == 0)
				{
					Q[front]->lchild = s;
				}
				else
				{
					Q[front]->rchild = s;
				}

				if (rear % 2 != 0)
				{
					front++;
				}
			}
		}
		ch = str[++j];
	}
	return bt;
}
void Test_CreateBinTree(){

	BinTree	bt = CreateBinTree();
}

void Preorder(BinTree bt)
{
	if (bt != NULL)
	{
		printf("%c", bt->data);
		Preorder(bt->lchild);
		Preorder(bt->rchild);
	}
}

void Inorder(BinTree bt)
{
	if (bt != NULL)
	{
		Inorder(bt->lchild);
		printf("%c", bt->data);
		Inorder(bt->rchild);
	}
}

void Postorder(BinTree bt)
{
	if (bt != NULL)
	{
		Postorder(bt->lchild);
		Postorder(bt->rchild);
		printf("%c", bt->data);
	}
}

void Test_traversal(){

	/*cout << "创建树，以@为空，以#结束:" << endl;
	BinTree	bt = CreateBinTree();*/

	char*str = "ABCDE@F";
	BinTree	bt = CreateBinTreeFromArray(str);

	/*char*str = "(A(B(D,E),(C(,F)))";
	BinTNode* bt = CreateTree(str);*/

	cout << "前序遍历:";
	Preorder(bt);
	cout << endl;

	cout << "中序遍历:";
	Inorder(bt);
	cout << endl;

	cout << "后续遍历:";
	Postorder(bt);
	cout << endl;
}

void Inorder1(BinTree bt){
	SeqStack S;
	BinTNode *p;
	InitStack(&S);
	Push(&S, bt);
	while (!StackEmpty(&S))
	{
		while (GetTop(&S))
		{
			Push(&S, GetTop(&S)->lchild);//直到左子树为空为止
		}
		p = Pop(&S);
		if (!StackEmpty(&S))
		{
			printf("%c", GetTop(&S)->data);//访问根节点
			p = Pop(&S);
			Push(&S, p->rchild);//右子树进栈
		}
	}
}