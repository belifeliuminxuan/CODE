#include <stdio.h>

typedef struct BookType
{
	int  _BookNumber;//���
	int _BookCapicity;//�鼮����
	char _BookName[20];//����
	char _BookAuther[20];//����
}BookType;
typedef struct SListNode
{
	BookType data;
	struct BookType* next;
};





void menu()
{
	
}
int main()
{
	return 0;
}