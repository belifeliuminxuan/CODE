#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define MAXSIZE	100
typedef struct SqStack
{
	int *base;
	int *top;
	int stacksize;
}SqStack;

int InitStack(SqStack* S)
{
	S->base = (int*)malloc(sizeof(int)*MAXSIZE);
	if (S->base == NULL)
	{
		printf("error\n");
		return -1;
	}
	S->top = S->base;
	S->stacksize = MAXSIZE;
	return 0;
}

int Push(SqStack *S, int x)
{
	if (S->top - S->base == S->stacksize)
	{
		printf("error\n");
		return -1;
	}
	*S->top++ = x;
	return 0;
}
int Pop(SqStack* S)
{
	if (S->top == S->base) return -1;
	int e = *(S->top-1);
	S->top--;
	printf("%d\n", e);
	return 0;
}
int	PrintStack(SqStack *S)
{
	int *tmp = S->top;
	while (tmp != S->base)
	{
		tmp--;
		printf("%d\n", *tmp);

	}
	return 0;
}
int IsEmpty(SqStack *S)
{
	if (S->top == S->base)
	{
		printf("Stack is Empty\n");
		free(S->base);
		return 0;
	}
	else
	{
		printf("Stack is not Empty\n");
		return -1;
	}
}
int GetTop(SqStack* S)
{
	int Getop = 0;
	Getop = *S->top;
	printf("%d\n", Getop);
	return 0;
}

int main()
{
	SqStack S;
	InitStack(&S);
	Push(&S, 1);
	Push(&S, 2);
	Push(&S, 3);
	Push(&S, 4);
	Push(&S, 5);
	Push(&S, 6);
	//PrintStack(&S);
	/*printf("_____________________________\n");
	Pop(&S);
	Pop(&S);
	Pop(&S);
	printf("_____________________________\n");
	PrintStack(&S);
	printf("_____________________________\n");*/
	Pop(&S);
	Pop(&S);
	Pop(&S);
	Pop(&S);
	Pop(&S);
	Pop(&S);
	IsEmpty(&S);
	system("pause");
	return 0;
}