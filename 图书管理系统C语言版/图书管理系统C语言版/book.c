#define _CRT_SECURE_NO_WARNINGS 0
#include<stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef struct Book
{
	int  _BookNumber;//编号
	char _BookName[20];//书名
	char _BookAuther[20];//作者
	char _BookPress[20];//出版社
	char _BookClassification[20];//分类
	char _BookISBN[20];//ISBN号码
	struct Book *next;
}Elemtype;
typedef struct SListNode
{
	Elemtype data;
	struct SListNode* next;
}SListNode;

SListNode* CreatSListNode()
{
	SListNode* res = (SListNode*)malloc(sizeof(SListNode));
	printf("Please enter the book number:\n");
		scanf("%d", &res->data._BookNumber);
		printf("Please enter the name of the book:\n");
		scanf("%s", &res->data._BookName);
		printf("Please enter the author of the book:\n");
		scanf("%s", &res->data._BookAuther);
		printf("Please enter the publisher of the book:\n");
		scanf("%s", &res->data._BookPress);
		printf("Please enter the classification of the book:\n");
		scanf("%s", &res->data._BookClassification);
		printf("Please enter ISBN of book:\n");
		scanf("%s", &res->data._BookISBN);
	res->next = NULL;
	return res;
}
void InitSList(SListNode** pphead)
{
	*pphead = NULL;
}

void SListPushFront(SListNode** pphead)
{
	SListNode* tmp = CreatSListNode();
	tmp->next = *pphead;
	*pphead = tmp;
}
void SListPopFront(SListNode** pphead)
{
	if (*pphead == NULL)
	{
		return;
	}
	SListNode* tmp = (*pphead)->next;
	free(*pphead);
	*pphead = tmp;
}
SListNode* SListFind(SListNode* phead, int x)
{
	SListNode* tmp;
	for (tmp = phead; tmp; tmp = tmp->next)
	{
		if (tmp->data._BookNumber == x)
		{

			printf("%d\n", tmp->data._BookNumber);
			printf("%s\n", tmp->data._BookName);
			printf("%s\n", tmp->data._BookAuther);
			printf("%s\n", tmp->data._BookPress);
			printf("%s\n", tmp->data._BookClassification);
			printf("%s\n", tmp->data._BookISBN);
			return tmp;
		}
		else
		{
			printf("Non-existent");
		}
	}
	return NULL;
}
void SListInsertAfter(SListNode* pos)
{
	SListNode* tmp = CreatSListNode();
	tmp->next = pos->next;
	pos->next = tmp;
}
void SListEraseAfter(SListNode* pos)
{
	SListNode* tmp = pos->next;
	if (tmp == NULL)
	{
		return;
	}
	pos->next = tmp->next;
	free(tmp);
}
void SListPrint(SListNode* phead)
{
	SListNode* tmp;
	for (tmp = phead; tmp; tmp = tmp->next)
	{
		printf("BookNumber:[%d]\n", tmp->data._BookNumber);
		printf("BookName:[%s]\n", tmp->data._BookName);
		printf("BookAuther:[%s]\n", tmp->data._BookAuther);
		printf("BookPress:[%s]\n", tmp->data._BookPress);
		printf("BookClassification:[%s]\n", tmp->data._BookClassification);
		printf("BookISBN:[%s]\n", tmp->data._BookISBN);
	}
}

void BookManagement()
{
	int choose =0;
	SListNode* pphead1;
	InitSList(&pphead1);
	printf("Welcome to the library management system\n");
	printf("1.BookAdd\n");
	printf("2.BookFind\n");
	printf("3.BookDel\n");
	printf("4.PrintBookInfo\n");
	scanf("%d", &choose);
	switch (choose)
	{
		char str[2] = "y";
	case 1:
	{
		
		while (str == "y")
		{
			SListPushFront(&pphead1);
			printf("Continue to add?(y/n)\n");
			scanf("%s", &str);
		}	
	}
	break;
	/*case 2:
	{
		break;
	}
	case 3:
	{

		break;
	}
	case 4:
	{

	}*/
	}
}
	/*int flag =1;
	int pflag = 1;
	while (flag == 1)
	{

		printf("Continue to add?   1 continue Any key exit\n");
		scanf("%d", &flag);
	}
	printf("Whether to print the entered information?  1 continue,Any key exit\n");
	scanf("%d", &pflag);
	if (pflag == 1)
	{
		SListPrint(pphead1);
	}

}
	void Find()
{
		int x = 0;
		SListNode* res = BookAdd();
		printf("Please enter the serial number of the search:\n");
		scanf("%d", &x);
		SListFind(res, x);

}
*/
int main()
{
	/*SListNode* pphead;
	InitSList(&pphead);
	SListPushFront(&pphead);*/
	BookManagement();


	system("pause");
	return 0;
}