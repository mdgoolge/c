#include<iostream>

typedef char DataType;
typedef enum{ atom, list } NodeTag;
typedef struct GLNode{
	NodeTag tag;
	union
	{
		DataType data;
		GLNode*slink;
	};
	GLNode*next;
}*GList;

GList CreatGList(GList gl){
	char ch;
	scanf("%c", &ch);
	if (ch != ' ')
	{
		gl = (GLNode*)malloc(sizeof(GLNode));
		if (ch == '(')
		{
			gl->tag = list;
			gl->slink = CreatGList(gl->slink);
		}
		else
		{
			gl->tag = atom;
			gl->data = ch;
		}
	}
	else
	{
		gl = NULL;
	}
	scanf("%c", &ch);
	if (gl != NULL)
	{
		gl->slink = CreatGList(gl->slink);
	}
	else
	{
		gl->slink = NULL;
	}
	return gl;
}

void PrintGList(GList gl){
	if (gl!=NULL)
	{
		if (gl->tag==list)
		{
			printf("(");
			if (gl->slink==NULL)
			{
				printf(" ");
			}
			else
			{
				PrintGList(gl->slink);
			}
		}
		else
		{
			printf("%c", gl->data);
			
		}
		if (gl->tag==list)
		{
			printf(")");
		}
		if (gl->next!=NULL)
		{
			printf(",");
			PrintGList(gl->next);
		}
	}
}