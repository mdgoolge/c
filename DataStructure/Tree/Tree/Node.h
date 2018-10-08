
#pragma once

typedef char DataTypeBinT;
typedef struct node{
	DataTypeBinT data;
	struct  node*lchild, *rchild;
}BinTNode;

typedef BinTNode* BinTree;



#define StackSize 100 
typedef BinTree DataTypeSeqStack;
typedef struct{
	DataTypeSeqStack data[StackSize];
	int top;
}SeqStack;
SeqStack S;

//��
//˫�ױ�ʾ��
#define MaxTreeSize 100
typedef struct{
	char data;
	int parent;//˫��λ����
}PTNode;
typedef struct 
{
	PTNode nodes[MaxTreeSize];
	int n;
}Ptree;

//��������
typedef struct cnode{
	int child;
	struct cnode *next;
}CNode;
typedef struct{
	char data;
	CNode* firstchild;
}PANode;
typedef struct{
	PANode nodes[MaxTreeSize];
	int n, r;
}CTree;

//�������Ĵ洢�ṹ
#define n 4
#define m 2*n-1
typedef struct{
	float weight;
	int lchild ,rchild, parent;
}HTNode;
typedef HTNode HuffmanTree[m + 1];//0�ŵ�Ԫ����