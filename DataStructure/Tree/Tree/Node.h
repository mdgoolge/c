
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