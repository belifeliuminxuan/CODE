#include <iostream>
#include <list>
#include <Windows.h>
using namespace std;
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

class 

int main()
{
	
	system("pause");
	return 0;
}