
typedef DataTypeSeqStack DataType;

///ÖÃ¿ÕÕ»
void InitStack(SeqStack *S)
{
	S->top = -1;
}

//ÅÐÕ»¿Õ
int StackEmpty(SeqStack*s){
	return s->top == -1;
}

//ÅÐÕ»Âú
int StackFull(SeqStack *s){
	return	s->top == StackSize - 1;
}

//½øÕ»
void Push(SeqStack *s, DataType x){
	if (StackFull(s))
	{
		printf("stack overflow");
	}
	else
	{
		s->top++;
		s->data[s->top] = x;
	}

}

//ÍËÕ»
DataType Pop(SeqStack*s){
	if (StackEmpty(s))
	{
		printf("stack underflow");
		exit(0);
	}
	else
	{
		return s->data[s->top--];
	}
}

//È¡Õ»¶¥ÔªËØ
DataType GetTop(SeqStack*s)
{
	if (StackEmpty(s))
	{
		printf("stack empty");
		exit(0);
	}
	else
	{
		return s->data[s->top];
	}
}