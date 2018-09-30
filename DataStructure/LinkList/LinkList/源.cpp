#include<iostream>
using namespace std;

//typedef char DataType;
typedef int DataType;

typedef struct node{
	DataType data;
	struct node * next;
}ListNode;

typedef ListNode* LinkList;

///头插法
LinkList CreateListF(){
	LinkList	head;
	ListNode* p;
	DataType ch;
	head = NULL;
	ch = getchar();
	while (ch != '\n')
	{
		p = (ListNode*)malloc(sizeof(ListNode));
		p->data = ch;
		p->next = head;
		head = p;
		ch = getchar();
	}
	return head;

}
//尾插法
LinkList CreateListR(){
	LinkList head, rear;
	ListNode*p;
	DataType ch;
	head = NULL; rear = NULL;
	ch = getchar();
	while (ch != '\n')
	{
		p = (ListNode*)malloc(sizeof(ListNode));
		p->data = ch;
		if (head == NULL)
		{
			head = p;
		}
		else
		{
			rear->next = p;
		}
		rear = p;
		ch = getchar();
	}
	//分配的初始地址为不确定值，所以要置空
	if (rear != NULL)
	{
		rear->next = NULL;
	}
	return head;
}
//尾插法，引入头结点
LinkList CreateListRWithHeadNode(){
	LinkList head = (ListNode*)malloc(sizeof(ListNode));//申请头结点
	ListNode*p, *r;
	DataType ch;
	r = head;
	while ((ch = getchar()) != '\n')
	{
		p = (ListNode*)malloc(sizeof(ListNode));
		p->data = ch;
		r->next = p;
		r = p;
	}
	r->next = NULL;
	return head;
}
//创建带有头结点的空列表
LinkList CreateListRWithHeadNodeNULL(){
	LinkList head = (ListNode*)malloc(sizeof(ListNode));//申请头结点
	head->next = NULL;
	return head;
}
//尾插法，带头结点，整型
LinkList CreateListRWithHeadNodeInt(){
	LinkList head = (ListNode*)malloc(sizeof(ListNode));//申请头结点
	ListNode*p, *r;
	DataType data;
	r = head;

	cout << "请输入数字：";
	while (cin >> data && data != 'q')
	{
		p = (ListNode*)malloc(sizeof(ListNode));
		p->data = data;

		r->next = p;
		r = p;

		cout << "请输入数字：";
	}




	r->next = NULL;
	return head;
}
//尾插法，带头结点，整型
LinkList CreateListRWithHeadNodeIntCycle(){
	LinkList head = (ListNode*)malloc(sizeof(ListNode));//申请头结点
	ListNode*p, *r;
	DataType data;
	r = head;

	cout << "请输入数字：";
	while (cin >> data && data != 'q')
	{
		p = (ListNode*)malloc(sizeof(ListNode));
		p->data = data;

		r->next = p;
		r = p;

		cout << "请输入数字：";
	}




	r->next = head;
	return head;
}

//按结点序号插找
//head为带头结点的单链表的头指针，i为要查找的节点序号
//若查找成功，返回查找节点的地址，否者返回NULL
ListNode* GetNodei(LinkList head, int i){
	ListNode*p; int j;
	p = head->next; j = 1;//使p指向第一个节点，j置1
	while (p != NULL&&j < i)
	{
		p = p->next; ++j;
	}
	if (j == i)
	{
		return p;
	}
	else
	{
		return NULL;
	}

}
//按结点查找
ListNode*LocateNodek(LinkList head, DataType k, int *index){
	ListNode*p = head->next;
	*index = 1;
	while (p&&p->data != k)
	{
		p = p->next;
		(*index)++;
	}
	return p;
}
//插入
void InsertList(LinkList head, int i, DataType x){
	ListNode *p, *s;
	int j;
	p = head; j = 0;
	while (p != NULL&&j < i - 1)
	{
		p = p->next; ++j;
	}
	if (p == NULL)
	{
		printf("ERROR\n"); return;
	}
	else
	{
		s = (ListNode*)malloc(sizeof(ListNode));
		s->data = x; s->next = p->next;
		p->next = s;
	}
}

void DisplayList(LinkList list){
	ListNode*p = list->next;
	while (p != NULL)
	{
		printf("%c", p->data);
		p = p->next;
	}
	printf("\n");
}
void DisplayListInt(LinkList list){
	ListNode*p = list->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}

	cout << endl;
}

void DisplayListIntCycle(LinkList list){
	ListNode*p = list->next;

	while (p != list)
	{
		cout << p->data << " ";
		p = p->next;
	}

	cout << endl;
}
//删除
DataType DeleteList(LinkList head, int i){
	ListNode*p, *s;
	DataType x; int j;
	p = head; j = 0;
	while (p != NULL&&j < i - 1)
	{
		p = p->next; ++j;
	}
	if (p == NULL)
	{
		printf("位置错误\n");
		exit(0);
	}
	else
	{
		s = p->next;
		p->next = s->next;
		x = s->data;
		free(s);
		return x;

	}
}

void split(LinkList a, LinkList	b)
{
	ListNode*p, *r, *s;
	p = a->next; //p指向表头结点
	r = a;		 //r指向A表的当前结点
	s = b;	     //s指向B表的当前结点
	while (p != NULL)
	{
		r->next = p;//序号为奇数的的节点连接在A表上
		r = p;//r总是指向A链表的最后一个节点
		p = p->next;
		if (p)
		{
			s->next = p;//序号是偶数的节点连接大B表上
			s = p;//s总是指向B链表的最后一个节点
			p = p->next;//p指向原链表A的偶数序号的节点
		}
	}
	r->next = s->next = NULL;
}

LinkList MergeList(LinkList la, LinkList lb)
{
	ListNode *pa, *pb, *pc;
	LinkList lc;
	pa = la->next;
	pb = lb->next;
	lc = pc = la;//用la的头结点作为lc的头结点

	while (pa != NULL &&pb != NULL)
	{
		if (pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}

	pc->next = pa != NULL ? pa : pb;

	free(lb);

	return	 lc;
}

void InsertList(LinkList L, int x)
{
	ListNode *s, *p, *q;
	s = (ListNode*)malloc(sizeof(ListNode));
	s->data = x;
	p = L;
	q = p->next;
	while (q->data > x && q != L)
	{
		p = p->next;
		q = p->next;
	}

	p->next = s;
	s->next = q;
}
int main(){

	////头插法
	//LinkList list = CreateListF();

	//ListNode*p = list;
	//while (p != NULL)
	//{
	//	printf("%c", p->date);
	//	p = p->next;
	//}
	//printf("%c", '\n');

	////尾插法
	//LinkList list = CreateListR();

	//ListNode*p = list;
	//while (p != NULL)
	//{
	//	printf("%c", p->date);
	//	p = p->next;
	//}
	//printf("%c", '\n');


	////尾插法引入头结点
	//LinkList list = CreateListRWithHeadNode();

	//ListNode*p = list->next;
	//while (p != NULL)
	//{
	//	printf("%c", p->date);
	//	p = p->next;
	//}
	//printf("%c", '\n');

	////按结点序号插找
	//LinkList list = CreateListRWithHeadNode();
	//ListNode*p = list->next;
	//while (p != NULL)
	//{
	//	printf("%c", p->date);
	//	p = p->next;
	//}
	//printf("%c", '\n');
	//p = GetNodei(list, 3);
	//if (p != NULL)
	//{
	//	printf("%c", p->date);
	//}
	//printf("%c", '\n');

	////按结点查找
	//LinkList list = CreateListRWithHeadNode();
	//ListNode*p = list->next;
	//while (p != NULL)
	//{
	//	printf("%c", p->date);
	//	p = p->next;
	//}
	//printf("%c", '\n');

	//printf("%s", "输入要查找的字符:");
	//char ch = getchar();

	//int index;
	//p = LocateNodek(list, ch, &index);
	//if (p == NULL)
	//{
	//	printf("%s", "未找到");
	//}
	//else
	//{
	//	printf("找到索引是：%d", index);
	//}

	////插入
	//printf("创建链表：");
	//LinkList list = CreateListRWithHeadNode();
	//printf("输出创建的链表：");
	//DisplayList(list);
	//printf("输入插入字符：");
	//char ch = getchar();
	//printf("输入插入位置：");
	//int index;
	//scanf("%d", &index);
	//InsertList(list, index, ch);
	//printf("输出插入后的链表：");
	//DisplayList(list);

	////删除
	//printf("创建链表：");
	//LinkList list = CreateListRWithHeadNode();
	//printf("输出创建的链表：");
	//DisplayList(list);
	//printf("输入删除索引位置：");
	//int index;
	//scanf("%d", &index);

	//DataType ch = DeleteList(list, index);
	//printf("输出删除后的链表：");
	//DisplayList(list);

	//printf("创建链表：\n");
	//LinkList list = CreateListRWithHeadNodeInt();
	//printf("输出创建的链表：");
	//DisplayListInt(list);

	////奇偶分解
	//printf("创建链表a：");
	//LinkList lista = CreateListRWithHeadNode();
	//printf("输出创建的链表a：");
	//DisplayList(lista);
	//printf("创建空链表b：");
	//LinkList listb = CreateListRWithHeadNodeNULL();
	//split(lista, listb);
	//printf("输出链表a：");
	//DisplayList(lista);
	//printf("输出链表a：");
	//DisplayList(listb);


	////合并
	//printf("创建链表a：");
	//LinkList lista = CreateListRWithHeadNode();
	//printf("输出a：");
	//DisplayList(lista);
	//printf("创建链表b：");
	//LinkList listb = CreateListRWithHeadNode();
	//printf("输出b：");
	//DisplayList(listb);
	//LinkList listc = MergeList(lista, listb);
	//printf("输出c：");
	//DisplayList(listc);

	//例子2.7
	printf("创建链表：\n");
	LinkList list = CreateListRWithHeadNodeIntCycle();
	printf("输出创建的链表：");
	DisplayListIntCycle(list);

	char str[20];
	scanf("%s", str);//对去q字符 
	printf("输入插入的数据：");
	int x;
	scanf("%d", &x);
	InsertList(list, x);
	DisplayListIntCycle(list);
}