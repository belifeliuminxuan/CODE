#include <iostream>
#include <list>
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
}Book;

Book* CreatBook()
{
	Book *BookList= new Book;
}
int Add()
{
	 
	 
	//std::list<Book> BOOK;
	//BOOK.push_back();
}

void menu()
{	
	cout << "********************************************" << endl;
	cout << "**Welcome to the library management system**" << endl;
	cout << "********************************************" << endl;
	cout << "******1.AddBook******2.DelBook**************" << endl;
	cout << "******3.FindBook*****4.ChangeBook***********" << endl;
	cout << "******5.OutToFile****6.DestoryBook**********" << endl;
	cout << "********************************************" << endl;
	cout << "********************************************" << endl;
	cout << "Please choose:" << endl;
	
}

int main()
{
	menu();
	return 0;
}