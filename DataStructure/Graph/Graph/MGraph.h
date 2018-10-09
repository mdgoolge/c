#include<iostream>

#define MaxVertexNum 50
typedef struct{
	char vexs[MaxVertexNum];
	int arcs[MaxVertexNum][MaxVertexNum];
}MGraph;

void CreateMGraph(MGraph *G, int n, int e){
	int i, j, k, w;
	scanf("%d,%d", &n, &e);
	scanf("%c");
	for (i = 0; i < n; i++)
	{
		scanf("%c", &G->vexs[i]);
		scanf("%c");
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			G->arcs[i][j] = INT_MAX;
		}

	}

	for (k = 0; k < e; k++)
	{
		scanf("%d,%d,%d", &i, &j, &w);
		G->arcs[i][j] = w;
		G->arcs[j][i] = w;

	}

}

void Test_CreateMGraph(){
	int n=0;
	int e=0;
	MGraph G;
	CreateMGraph(&G, n, e);
}