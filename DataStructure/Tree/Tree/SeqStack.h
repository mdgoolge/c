
typedef DataTypeSeqStack DataType;

///�ÿ�ջ
void InitStack(SeqStack *S)
{
	S->top = -1;
}

//��ջ��
int StackEmpty(SeqStack*s){
	return s->top == -1;
}

//��ջ��
int StackFull(SeqStack *s){
	return	s->top == StackSize - 1;
}

//��ջ
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

//��ջ
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

//ȡջ��Ԫ��
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