#include<iostream>
#include "Node.h"
using namespace std;

void select(HuffmanTree T, int k, int *s1, int *s2){
	//在HT[1..k]中选择parent为0且权值最小的两个根节点
	//其序号分别存储到s1和s2指向的对应变量中

	int i, j;
	int min1 = 101;

	for (i = 1; i <= k; i++)
	{
		if (T[i].weight < min1 && T[i].parent == 0)
		{
			j = i;
			min1 = T[i].weight;
		}
	}
	*s1 = j;

	min1 = 32767;
	for (i = 1; i <= k; i++)
	{
		if (T[i].weight < min1 && T[i].parent == 0 && i != *s1)
		{
			j = i;
			min1 = T[i].weight;
		}
	}
	*s2 = j;
}

void ChuffmanTree(HuffmanTree HT){
	int s1, s2;
	for (int i = 0; i <= m; i++)
	{
		HT[i].lchild = 0;
		HT[i].rchild = 0;
		HT[i].parent = 0;
		HT[i].weight = 0;
	}

	for (int i = 1; i <= n; i++)
	{
		scanf("%f", &HT[i].weight);
	}
	for (int i = n + 1; i <= m; i++)
	{
		select(HT, i - 1, &s1, &s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}

	for (int i = 0; i <= m; i++)
	{
		cout << HT[i].weight << " " << endl;
	}
}