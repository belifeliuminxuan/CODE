//#define _CRT_SECURE_NO_WARNINGS 0
//
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct Book
//{
//	int  _BookNumber;//编号
//	char _BookName[20];//书名
//	char _BookAuther[20];//作者
//	char _BookPress[20];//出版社
//	char _BookClassification[20];//分类
//	char _BookISBN[20];//ISBN号码
//	struct Book *next;
//}Book;
//
//void BookInit(Book** pphead)
//{
//	*pphead = NULL;
//}
//Book* CreatBookNode()
//{
//	Book* res = (Book*)malloc(sizeof(Book));
//	printf("Please enter the book number:\n");
//	scanf("%d", &res->_BookNumber);
//	printf("Please enter the name of the book:\n");
//	scanf("%s", &res->_BookName);
//	printf("Please enter the author of the book:\n");
//	scanf("%s", &res->_BookAuther);
//	printf("Please enter the publisher of the book:\n");
//	scanf("%s", &res->_BookPress);
//	printf("Please enter the classification of the book:\n");
//	scanf("%s", &res->_BookClassification);
//	printf("Please enter ISBN of book:\n");
//	scanf("%s", &res->_BookISBN);
//	res->next = NULL;
//	return res;
//}
//void BookPushFront(Book** pphead)
//{
//	Book* tmp = CreatBookNode();
//	tmp->next = *pphead;
//	*pphead = tmp;
//}
//Book* AddBook()
//{
//	int flag = 1;
//	Book* pphead1;
//	BookInit(&pphead1);
//	while (flag==1&&flag!=-1)
//	{
//		BookPushFront(&pphead1);
//		printf("Enter 1 to continue, - 1 to exit\n");
//		scanf("%d", &flag);
//    }
//	return pphead1;
//}
//void PrintBook()
//{
//	Book* phead = AddBook();
//	Book* tmp;
//	printf("BookNumber BookName BookAuther BookPress BookClassification BookISBN\n");
//	for (tmp = phead; tmp; tmp = tmp->next)
//	{
//		printf("%d", tmp->_BookNumber);
//		printf("%s", tmp->_BookName);
//		printf("%s", tmp->_BookAuther);
//		printf("%s", tmp->_BookPress);
//		printf("%s", tmp->_BookClassification);
//		printf("%s", tmp->_BookISBN);
//	}
//}
//
//
//int main()
//{
//	AddBook();
//	PrintBook();
//	return 0;
//}