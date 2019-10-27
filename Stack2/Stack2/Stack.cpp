#include <iostream>
#define  MAXSIZE 100
using namespace std;

typedef int T;
typedef struct 
{
	T* top;
	T* base;
	T stacksize;
}Stack;

T InitStack(Stack &S)
{
	S.base = new T[MAXSIZE];
	if (S.base)
		return -1;
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return 0;
}
T Push(Stack& S, int e)
{
	if (S.top - S.base == S.stacksize) return -1;
	*S.top= e;
	*S.top++;
	return 0;
}
T Pop(Stack& S)
{
	if (S.top == S.base) return -1;
	T e = *S.top--;
	cout << *S.top << endl;
	return 0;
}
T	PrintStack(Stack &S)
{
	T *tmp = S.top;
	while (tmp != S.base)
	{
		tmp--;
		cout << *tmp << endl;

	}

	return 0;
}



int main()
{
	Stack S;
	InitStack(S);
	Push(S, 1);
	Push(S, 2);
	Push(S, 3);
	Push(S, 4);
	Push(S, 5);
	Push(S, 6);
	PrintStack(S);
	system("pause");
	return 0;
}