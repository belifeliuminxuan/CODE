#define _CRT_SECURE_NO_WARNINGS 0
#include <iostream>
using namespace std;
//struct Sudent
//{
//	//成员方法
//	void SetStudent(char* name, char* gender, int age)
//	{
//		strcpy(_name, name);
//		strcpy(_gender, gender);
//		_age = age;
//	}
//	void PrintStudent()
//	{
//		cout << _name << ":" << _gender << ":" << _age << endl;
//	}
//	char _name[20];
//	char _gender[20];
//	int _age;
//
//};
//int main()
//{
//	Sudent s;
//	s.SetStudent("hello", "h", 299);
//		s.PrintStudent();
//	return 0;
//}
//C++实现封装，继承，多态
class Student
{
public:
	void SetStudent(char* name, char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	void PrintStudent()
	{
		cout << _name << ":" << _gender << ":" << _age << endl;
	}
private:
	char _name[20];
	char _gender[20];
	int _age;
};
int main()
{
	
	Student s1 ,S;
	s1.SetStudent("123", "456", 789);
	s1.PrintStudent();
	return 0;
}
//主流编译器中空类的大小为1
