#include <iostream>
#include <list>
using namespace std;
typedef struct BookType
{
	int  _BookNumber;//���
	int _BookCapicity;//�鼮����
	char _BookName[20];//����
	char _BookAuther[20];//����
	char _BookPress[20];//������
	char _BookClassification[20];//����
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
		cout << "�������鼮��ţ�" << endl;
		cin >> res->data._BookNumber;
		cout << "������������" << endl;
		cin >> res->data._BookName;
		cout << "�������鼮���ߣ�" << endl;
		cin >> res->data._BookAuther;
		cout << "�������鼮�ĳ����磺" << endl;
		cin >> res->data._BookPress;
		cout << "�������鼮���ࣺ" << endl;
		cin >> res->data._BookClassification;
		cout << "�������鼮������" << endl;
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