#pragma once

#include<iostream>
#include"Node.h"
#include"SeqStack.h"
#include"CirQueue.h"

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

//利用栈的非递归中序遍历
void InOrder1(BinTree bt){
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
//利用指针数组的非递归中序遍历
void InOrder2(BinTree bt){
	BinTNode *ST[100];
	int top = 0;
	ST[top] = bt;
	do
	{
		while (ST[top] != NULL)
		{
			top++;
			ST[top] = ST[top - 1]->lchild;
		}
		top--;
		if (top >= 0)
		{
			printf("%c", ST[top]->data);
			ST[top] = ST[top]->rchild;
		}
	} while (top != -1);
}

//利用栈的非递归前序遍历
void PreOrder1(BinTree bt){
	SeqStack S;
	InitStack(&S);
	Push(&S, bt);
	while (!StackEmpty(&S))
	{
		bt = Pop(&S);
		if (bt != NULL)
		{
			printf("%c", bt->data);
			Push(&S, bt->lchild);
			Push(&S, bt->rchild);
		}
	}
}
//非递归按层遍历
void TransLevel(BinTree bt){
	CirQueue Q;
	InitQueue(&Q);
	if (bt == NULL)
	{
		return;
	}
	else
	{
		printf("%c", bt->data);
		EnQueue(&Q, bt);
		while (!QueueEmpty(&Q))
		{
			bt = DeQueue(&Q);
			if (bt->lchild != NULL)
			{
				printf("%c", bt->lchild->data);
				EnQueue(&Q, bt->lchild);
			}
			if (bt->rchild != NULL)
			{
				printf("%c", bt->rchild->data);
				EnQueue(&Q, bt->rchild);
			}
		}
	}
}
//求二叉树的深度
int BinTreeDepth(BinTree bt){
	int depl, depr;
	if (bt == NULL)
	{
		return 0;
	}
	else
	{
		depl = BinTreeDepth(bt->lchild);
		depr = BinTreeDepth(bt->rchild);
		if (depl > depr)
		{
			return depl + 1;
		}
		else
		{
			return depr + 1;
		}
	}
}

int found = 0;
BinTNode *pfound;
void FindBT(BinTree bt, char x){
	if (bt != NULL&&!found)
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
int Level(BinTree bt, BinTNode *p, int lh){
	static int h = 0;
	if (bt == NULL)
	{
		h = 0;
	}
	else if (bt == p)
	{
		h = lh;
	}
	else
	{
		Level(bt->lchild, p, lh + 1);
		if (h == 0)
		{
			Level(bt->rchild, p, lh + 1);
		}

	}
	return h;
}



void Test_notrecursive(){

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

	cout << "中序遍历，非递归，利用栈，Inorder2:";
	InOrder1(bt);
	cout << endl;

	cout << "中序遍历，非递归，利用指针数组，Inorder2:";
	InOrder2(bt);
	cout << endl;

	cout << "前序遍历，非递归，利用栈，PreOrder1:";
	PreOrder1(bt);
	cout << endl;

	cout << "按层遍历，非递归，利用队列，TransLevel:";
	TransLevel(bt);
	cout << endl;

	cout << "求二叉树的深度，BinTreeDepth:";
	cout << BinTreeDepth(bt) << endl;

	cout << "前序查找E，FindBT:";
	FindBT(bt, 'E');
	cout << pfound << "," << pfound->data << endl;

	cout << "求节点E所在层，Level:";
	cout << Level(bt, pfound, 1) << endl;

	char*str1 = "ABE@CFG@@D@@H@@";
	BinTree	bt1 = CreateBinTreeFromArray(str1);
	cout << "中序遍历bt1:";
	Inorder(bt1);
	cout << endl;
	cout << "按层遍历，非递归，利用队列，TransLevelbt1:";
	TransLevel(bt1);
	cout << endl;
}