#include <iostream>
#include <list>
using namespace std;
typedef struct BookType
{
	int  _BookNumber;//编号
	int _BookCapicity;//书籍存量
	char _BookName[20];//书名
	char _BookAuther[20];//作者
	char _BookPress[20];//出版社
	char _BookClassification[20];//分类
};

typedef struct SlistNode
{
	BookType data;
	struct BookType* next;
}SlistNode;




class BookManagement
{
public:
	
	SlistNode* AddBook(SlistNode** pphead)
	{
		SlistNode* res = new SlistNode;
		cout << "请输入书籍编号：" << endl;
		cin >> res->data._BookNumber;
		cout << "请输入书名：" << endl;
		cin >> res->data._BookName;
		cout << "请输入书籍作者：" << endl;
		cin >> res->data._BookAuther;
		cout << "请输入书籍的出版社：" << endl;
		cin >> res->data._BookPress;
		cout << "请输入书籍分类：" << endl;
		cin >> res->data._BookClassification;
		cout << "请输入书籍存量：" << endl;
		cin >> res->data._BookCapicity;
		res->next = nullptr;
	}
	void SListPushFront(SlistNode** pphead)
	{
		SlistNode* tmp = AddBook(pphead);
		tmp->next = *pphead;
		*pphead = tmp;
	}
	
};

int main()
{
	return 0;
}