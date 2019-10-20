#define _CRT_SECURE_NO_WARNINGS 0
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char _number[8];
	char _name[20];
	int score;
}Student;
typedef struct LNode
{
	Student data;
	struct LNode* next;
}LNode;

	LNode* InitList(LNode* L)
{
		L = (LNode*)malloc(sizeof(LNode));
		printf("Please enter student ID:\n");
		scanf("%s", &L->data._number);
		printf("Please enter the student's name;:\n");
		scanf("%s", &L->data._name);
		printf("Please enter the student's score:\n");
		scanf("%d,",&L->data.score);
		L->next = NULL;
		return L;
}
	int  DestroyList(LNode* L)
	{

	}
	int main()
	{




		return 0;
	}
