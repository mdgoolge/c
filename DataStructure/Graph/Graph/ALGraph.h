#include<iostream>
#define MaxVertexNum 20
typedef char VertexType;
typedef struct node{//边表节点类型
	int adjvex;//定点序号
	struct node *next;//指向下一条边的指针
}EdgeNode;
typedef struct vnode{ //定点表节点
	VertexType vertex;//定点域
	EdgeNode * link;//边表头指针
}VNode,Adjlist[MaxVertexNum	];//邻接表
typedef Adjlist ALGraph;//定义为图类型

void CreateGraph(ALGraph GL, int n, int e){
	//n 为定点数，e为图的边数
	int i, j, k;
	EdgeNode*p;
	for (i = 0; i < n; i++)//建立定点表
	{
		GL[i].vertex = getchar();//读入定点信息
		GL[i].link = NULL;//边表头指针置空
	}

	for (i = 0; i < k; i++)//使用头插法建立每个定点的邻接表
	{
		scanf("%d,%d", &i, &j);//读入边<vi,vj>的顶点序号
		p = (EdgeNode*)malloc(sizeof(EdgeNode));//生成新的边表节点
	}
}

void CreateGraph(ALGraph GL){

}