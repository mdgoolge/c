#include<iostream>
#define MaxVertexNum 20
typedef char VertexType;
typedef struct node{//�߱�ڵ�����
	int adjvex;//�������
	struct node *next;//ָ����һ���ߵ�ָ��
}EdgeNode;
typedef struct vnode{ //�����ڵ�
	VertexType vertex;//������
	EdgeNode * link;//�߱�ͷָ��
}VNode,Adjlist[MaxVertexNum	];//�ڽӱ�
typedef Adjlist ALGraph;//����Ϊͼ����

void CreateGraph(ALGraph GL, int n, int e){
	//n Ϊ��������eΪͼ�ı���
	int i, j, k;
	EdgeNode*p;
	for (i = 0; i < n; i++)//���������
	{
		GL[i].vertex = getchar();//���붨����Ϣ
		GL[i].link = NULL;//�߱�ͷָ���ÿ�
	}

	for (i = 0; i < k; i++)//ʹ��ͷ�巨����ÿ��������ڽӱ�
	{
		scanf("%d,%d", &i, &j);//�����<vi,vj>�Ķ������
		p = (EdgeNode*)malloc(sizeof(EdgeNode));//�����µı߱�ڵ�
	}
}

void CreateGraph(ALGraph GL){

}