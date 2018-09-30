
#include<iostream>
using namespace std;


#include "SeqStack.h"
#include "LinkStack.h"
#include"PostExp.h"
#include "SeqStackInt.h"

int Expr(){
	SeqStack s;
	DataType ch, x;
	InitStack(&s);
	ch = getchar();
	while (ch != '\n')
	{
		if (ch == '(')
		{
			Push(&s, ch);
		}
		else
		{
			if (ch == ')')
			{
				if (StackEmpty(&s))
				{
					return 0;
				}
				else
				{
					x = Pop(&s);
				}
			}
		}

		ch = getchar();
	}
	if (StackEmpty(&s))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void Test_Expr(){
	int result = Expr();
	cout << result << endl;
}

int sysmetry(char str[]){
	SeqStack s;
	int j, k, i = 0;
	InitStack(&s);
	while (str[i] != '\0')
	{
		i++;
	}
	for (j = 0; j < i / 2; j++)
	{
		Push(&s, str[j]);
	}
	k = (i + 1) / 2;
	for (j = k; j < i; j++)
	{
		if (str[j] != Pop(&s))
		{
			return	0;
		}
	}
	return 1;
}
void Testsysmetry(){

	char str[] = "asdfasdf";

	scanf("%s", str);
	cout << sysmetry(str) << endl;
}
void conversion(int N, int d){
	SeqStack s;
	InitStack(&s);
	while (N)
	{
		Push(&s, N%d);
		N = N / d;
	}
	while (!StackEmpty(&s))
	{
		int i = Pop(&s);
		printf("%d", i);
	}
}
//typedef char DataType;
void Test_convertion(){
	printf("输入要转的数:");
	int N;
	scanf("%d", &N);//将回车读取掉了

	printf("输入进制数：");
	int d;
	scanf("%d", &d);

	cout << "转换后的" << d << "进制数是:";
	conversion(N, d);
	cout << endl;

}

long int fact(int n){
	int temp;
	if (n == 0)
	{
		return 1;

	}
	else
	{
		temp = n *fact(n - 1);
	}
r12:return temp;
}
void Test_fact(){
	long int n;
	n = fact(5);
r11:printf("5!=%ld", n);
}
void Test_PostExp(){
	//9-(2+4*7)/5+3#
	CirQueue q;
	InitQueue(&q);

	CTPostExp(&q);

	CirQueueDiplay(&q);

	int result = CPostExp(q);
	cout << result << endl;
}

int main()
{

}