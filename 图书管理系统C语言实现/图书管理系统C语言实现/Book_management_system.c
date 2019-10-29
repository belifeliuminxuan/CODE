#include <stdio.h>

typedef struct BookType
{
	int  _BookNumber;//编号
	int _BookCapicity;//书籍存量
	char _BookName[20];//书名
	char _BookAuther[20];//作者
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