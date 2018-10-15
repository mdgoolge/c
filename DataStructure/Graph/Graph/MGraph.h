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
	int n = 0;
	int e = 0;
	MGraph G;
	CreateMGraph(&G, n, e);
}

void CreateMGraph1(MGraph *G, int vn, int en, char* v, int(*e)[3])
{
	for (int i = 0; i < vn; i++)
	{
		G->vexs[i] = v[i];
	}

	for (int i = 0; i < vn; i++)
	{
		for (int j = 0; j < vn; j++)
		{
			G->arcs[i][j] = INT_MAX;
		}
	}

	for (int k = 0; k < en; k++)
	{
		G->arcs[e[k][0]][e[k][1]] = e[k][2];
		G->arcs[e[k][1]][e[k][0]] = e[k][2];

	}

}
void Test_CreateMGraph1(){
	
	char a[5] = { '0', '1', '2', '3', '4' };
	int b[7][3] = {
		{ 0, 1 ,1},
		{ 0, 2, 1 },
		{ 0, 3, 1 },
		{ 1, 2, 1 },
		{ 2, 3, 1 },
		{ 2, 4, 1 },
		{ 3, 4, 1 }
	};
	MGraph G;
	CreateMGraph1(&G, 5, 7, a, b);
}



int visted[20];
void DFS(MGraph G, int i, int n){
	//从定点vi出发，深度优先搜索遍历图G（邻接矩阵结构）
	int j;
	printf("v%d->", i);
	visted[i] = 1;
	for ( j = 0; j < n; j++)
	{
		if (G.arcs[i][j] == 1 && !visted[j])
		{
			DFS(G, j, n);
		}
	}
}
void Test_DFS(){

	char a[5] = { '0', '1', '2', '3', '4' };
	int b[7][3] = {
		{ 0, 1, 1 },
		{ 0, 2, 1 },
		{ 0, 3, 1 },
		{ 1, 2, 1 },
		{ 2, 3, 1 },
		{ 2, 4, 1 },
		{ 3, 4, 1 }
	};
	MGraph G;
	CreateMGraph1(&G, 5, 7, a, b);

	DFS(G, 3, 5);
}