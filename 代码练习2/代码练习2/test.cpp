#define _CRT_SECURE_NO_WARNINGS 0
#include <iostream>
using namespace std;
#include <vector>
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
//class Student
//{
//public:
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
//private:
//	char _name[20];
//	char _gender[20];
//	int _age;
//};
//int main()
//{
//	
//	Student s1 ,S;
//	s1.SetStudent("123", "456", 789);
//	s1.PrintStudent();
//	return 0;
//}
//主流编译器中空类的大小为1
//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//
//	FILE *fp;
//	fp = fopen("hello.txt", "a");
//
//	
//	return 0;
//}

#include<stdio.h>

void BubbleSort(int *a, int len)//
{
	int i, j, k, temp;
	for (i=0;i<len;i++)
	{
		for (j = len - 1; j > i; j++)
		{
			if (a[j - 1] > a[j])
			{
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
		}
		printf("第[%d]步的排序结果为：", i);
		for (k = 0; k < len; k++)
		{
			printf("%d", a[k]);
		}
		printf("\n");
	}
}

int  main()
{
	int v[] = { 7,8,4,1,9,12,45,12,5,14,24,22 };
	BubbleSort(v, sizeof(v)/sizeof(int));
	return 0;
}