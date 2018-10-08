#pragma once

#include<iostream>
using namespace std;

typedef struct node{
	char data;
	int ltag, rtag;
	struct node *lchild, *rchild;
}BinThrNode;
typedef BinThrNode *BinThrTree;

void InOrderThread(BinThrTree bt){
	static BinThrNode*pre = NULL;
	if (bt != NULL)
	{
		InOrderThread(bt->lchild);
		if (bt->lchild == NULL)
		{
			bt->ltag = 1;

		}
		else
		{
			bt->ltag = 0;
		}
		if (bt->rchild == NULL)
		{
			bt->rtag = 1;
		}
		else
		{
			bt->rtag = 0;
		}
		if (pre)
		{
			if (pre->rtag == 1)
			{
				pre->rchild = bt;
			}
			if (bt->ltag == 1)
			{
				bt->lchild = pre;
			}
		}
		pre = bt;
		InOrderThread(bt->rchild);
	}
}


BinThrTree CreateBinThrTreeFromArray(char * str){

	BinThrTree	bt = NULL;

	BinThrNode*Q[100];
	int front, rear;
	front = 1;
	rear = 0;

	BinThrNode*s;


	char ch;
	int j = 0;
	ch = str[j];


	while (ch != '\0')
	{
		s = NULL;
		if (ch != '@')
		{
			s = (BinThrNode*)malloc(sizeof(BinThrNode));
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


			}

			if (rear % 2 != 0)
			{
				front++;
			}
		}
		ch = str[++j];
	}
	return bt;
}

void Inorder(BinThrTree bt)
{
	if (bt != NULL)
	{
		Inorder(bt->lchild);
		printf("%c", bt->data);
		Inorder(bt->rchild);
	}
}

BinThrNode *InOrderNext(BinThrNode*p){
	if (p->rtag == 1)
	{
		return p->rchild;
	}
	else
	{
		p = p->rchild;
		while (p->ltag == 0)
		{
			p = p->lchild;
		}
		return p;
	}
}

int found = 0;
BinThrNode *pfound;
void FindBT(BinThrTree bt, char x){
	if ((bt != NULL) && (!found))
	{
		if (bt->data == x)
		{
			pfound = bt;
			found = 1;
		}
		else
		{
			FindBT(bt->lchild, x);
			FindBT(bt->rchild, x);
		}
	}
}
void TInOrderThrTree(BinThrTree bt){
	BinThrNode *p;
	if (bt != NULL)
	{
		p = bt;
		//查找出中序遍历的第一个节点
		while (p->ltag == 0)
		{
			p = p->lchild;
		}
		do
		{
			printf("%c", p->data);
			p = InOrderNext(p);
		} while (p != NULL);
	}
}
void Test_BinThrTree(){

	char*str = "ABE@CFG@@D@@H@@";
	BinThrTree	bt = CreateBinThrTreeFromArray(str);
	cout << "中序遍历bt1:";
	Inorder(bt);
	cout << endl;

	cout << "中序线索化二叉树，TInOrderThrTree:";
	InOrderThread(bt);
	cout << endl;

	//不能这样查找，因为节点指针域已经填上前继和后续节点地址
	/*cout << "前序查找E，FindBT:";
	FindBT(bt, 'F');
	cout << pfound << "," << pfound->data << endl;*/

	cout << "遍历线索二叉树，TInOrderThrTree:";
	TInOrderThrTree(bt);
	cout << endl;
}