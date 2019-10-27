#include <iostream>
using namespace std;

#define MAXSIZE 100 
typedef struct
{
	int *base;
	int *top;
	int stacksize;
}SqStack;
int InitStack(SqStack &S)
{
	S.base = new int[MAXSIZE];/*(int*)malloc(MAXSIZE * sizeof(int));*/
	if (!S.base) return -1;
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return 0;
}
int Push(SqStack& S, int e)
{
	if (S.top - S.base == S.stacksize) return -1;
	*S.top++ = e;
	return 0;
}
int Pop(SqStack& S)
{
	if (S.top == S.base) return -1;
	int e = *(S.top-1);
	S.top--;
	cout << "The out of stack element is:" << e << endl;
	cout << "The element at the top of the stack is:" << *(S.top-1) << endl;
	return 0;
}
int	PrintStack(SqStack &S)
{
	int *tmp = S.top;
	while (tmp != S.base)
	{
		tmp--;
		cout << *tmp << endl;

	}

	return 0;
}
int IsEmpty(SqStack& S)
{
	if (S.top != S.base)
	{
		cout << "Stack is not empty" << endl;
	}
	else
	{
		cout << "Stack is empty" << endl;
		delete[]S.base;
	}
	return 0;
}
int main()
{
	int temp = 0;
	SqStack S;
	InitStack(S);
	Push(S, 1);
	Push(S, 2);
	Push(S, 3);
	Push(S, 4);
	Push(S, 5);
	Push(S, 6);
	Pop(S);
	//Pop(S);
	PrintStack(S);
	IsEmpty(S);
	system("pause");
	return 0;
}