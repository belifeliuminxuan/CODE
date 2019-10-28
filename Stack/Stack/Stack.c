#define _CRT_SECURE_NO_WARNINGS 0
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
	printf("The element at the top of the stack is[%d]\n", e);
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
	for (int i = 0; i < MAXSIZE; ++i)
	{
		int elem = 0;
		printf("Input elements:\n");
		scanf("%d", &elem);
		if (S.top-S.base==S.stacksize)
		{
			printf("The stack is full.\n");
			break;
		}
		else if (elem != -1)
		{
			Push(&S, elem);
		}
		else
		{
			Pop(&S);
			break;
		}
	}
	system("pause");
	return 0;
}