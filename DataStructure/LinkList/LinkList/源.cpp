#include<iostream>
using namespace std;

//typedef char DataType;
typedef int DataType;

typedef struct node{
	DataType data;
	struct node * next;
}ListNode;

typedef ListNode* LinkList;

///ͷ�巨
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
//β�巨
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
	//����ĳ�ʼ��ַΪ��ȷ��ֵ������Ҫ�ÿ�
	if (rear != NULL)
	{
		rear->next = NULL;
	}
	return head;
}
//β�巨������ͷ���
LinkList CreateListRWithHeadNode(){
	LinkList head = (ListNode*)malloc(sizeof(ListNode));//����ͷ���
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
//��������ͷ���Ŀ��б�
LinkList CreateListRWithHeadNodeNULL(){
	LinkList head = (ListNode*)malloc(sizeof(ListNode));//����ͷ���
	head->next = NULL;
	return head;
}
//β�巨����ͷ��㣬����
LinkList CreateListRWithHeadNodeInt(){
	LinkList head = (ListNode*)malloc(sizeof(ListNode));//����ͷ���
	ListNode*p, *r;
	DataType data;
	r = head;

	cout << "���������֣�";
	while (cin >> data && data != 'q')
	{
		p = (ListNode*)malloc(sizeof(ListNode));
		p->data = data;

		r->next = p;
		r = p;

		cout << "���������֣�";
	}




	r->next = NULL;
	return head;
}
//β�巨����ͷ��㣬����
LinkList CreateListRWithHeadNodeIntCycle(){
	LinkList head = (ListNode*)malloc(sizeof(ListNode));//����ͷ���
	ListNode*p, *r;
	DataType data;
	r = head;

	cout << "���������֣�";
	while (cin >> data && data != 'q')
	{
		p = (ListNode*)malloc(sizeof(ListNode));
		p->data = data;

		r->next = p;
		r = p;

		cout << "���������֣�";
	}




	r->next = head;
	return head;
}

//�������Ų���
//headΪ��ͷ���ĵ������ͷָ�룬iΪҪ���ҵĽڵ����
//�����ҳɹ������ز��ҽڵ�ĵ�ַ�����߷���NULL
ListNode* GetNodei(LinkList head, int i){
	ListNode*p; int j;
	p = head->next; j = 1;//ʹpָ���һ���ڵ㣬j��1
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
//��������
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
//����
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
//ɾ��
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
		printf("λ�ô���\n");
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
	p = a->next; //pָ���ͷ���
	r = a;		 //rָ��A��ĵ�ǰ���
	s = b;	     //sָ��B��ĵ�ǰ���
	while (p != NULL)
	{
		r->next = p;//���Ϊ�����ĵĽڵ�������A����
		r = p;//r����ָ��A��������һ���ڵ�
		p = p->next;
		if (p)
		{
			s->next = p;//�����ż���Ľڵ����Ӵ�B����
			s = p;//s����ָ��B��������һ���ڵ�
			p = p->next;//pָ��ԭ����A��ż����ŵĽڵ�
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
	lc = pc = la;//��la��ͷ�����Ϊlc��ͷ���

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

	////ͷ�巨
	//LinkList list = CreateListF();

	//ListNode*p = list;
	//while (p != NULL)
	//{
	//	printf("%c", p->date);
	//	p = p->next;
	//}
	//printf("%c", '\n');

	////β�巨
	//LinkList list = CreateListR();

	//ListNode*p = list;
	//while (p != NULL)
	//{
	//	printf("%c", p->date);
	//	p = p->next;
	//}
	//printf("%c", '\n');


	////β�巨����ͷ���
	//LinkList list = CreateListRWithHeadNode();

	//ListNode*p = list->next;
	//while (p != NULL)
	//{
	//	printf("%c", p->date);
	//	p = p->next;
	//}
	//printf("%c", '\n');

	////�������Ų���
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

	////��������
	//LinkList list = CreateListRWithHeadNode();
	//ListNode*p = list->next;
	//while (p != NULL)
	//{
	//	printf("%c", p->date);
	//	p = p->next;
	//}
	//printf("%c", '\n');

	//printf("%s", "����Ҫ���ҵ��ַ�:");
	//char ch = getchar();

	//int index;
	//p = LocateNodek(list, ch, &index);
	//if (p == NULL)
	//{
	//	printf("%s", "δ�ҵ�");
	//}
	//else
	//{
	//	printf("�ҵ������ǣ�%d", index);
	//}

	////����
	//printf("��������");
	//LinkList list = CreateListRWithHeadNode();
	//printf("�������������");
	//DisplayList(list);
	//printf("��������ַ���");
	//char ch = getchar();
	//printf("�������λ�ã�");
	//int index;
	//scanf("%d", &index);
	//InsertList(list, index, ch);
	//printf("�������������");
	//DisplayList(list);

	////ɾ��
	//printf("��������");
	//LinkList list = CreateListRWithHeadNode();
	//printf("�������������");
	//DisplayList(list);
	//printf("����ɾ������λ�ã�");
	//int index;
	//scanf("%d", &index);

	//DataType ch = DeleteList(list, index);
	//printf("���ɾ���������");
	//DisplayList(list);

	//printf("��������\n");
	//LinkList list = CreateListRWithHeadNodeInt();
	//printf("�������������");
	//DisplayListInt(list);

	////��ż�ֽ�
	//printf("��������a��");
	//LinkList lista = CreateListRWithHeadNode();
	//printf("�������������a��");
	//DisplayList(lista);
	//printf("����������b��");
	//LinkList listb = CreateListRWithHeadNodeNULL();
	//split(lista, listb);
	//printf("�������a��");
	//DisplayList(lista);
	//printf("�������a��");
	//DisplayList(listb);


	////�ϲ�
	//printf("��������a��");
	//LinkList lista = CreateListRWithHeadNode();
	//printf("���a��");
	//DisplayList(lista);
	//printf("��������b��");
	//LinkList listb = CreateListRWithHeadNode();
	//printf("���b��");
	//DisplayList(listb);
	//LinkList listc = MergeList(lista, listb);
	//printf("���c��");
	//DisplayList(listc);

	//����2.7
	printf("��������\n");
	LinkList list = CreateListRWithHeadNodeIntCycle();
	printf("�������������");
	DisplayListIntCycle(list);

	char str[20];
	scanf("%s", str);//��ȥq�ַ� 
	printf("�����������ݣ�");
	int x;
	scanf("%d", &x);
	InsertList(list, x);
	DisplayListIntCycle(list);
}