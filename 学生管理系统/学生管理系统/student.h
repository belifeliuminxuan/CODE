#ifdef  _STUDENT_H_
#define _STUDENT_H_

struct Student
{
	char Bookname[20];
	long long _ISBN;
	char Author[20];
	char Press[20];
	int PublicationTime;
	int StorageTime;
	int Inventory;
	int BorrowingNumber;
}Stu,*pstu;

#endif