//1. 建立顺序表，基本操作包括：建立并初始化顺序表、输出顺序表、判断是否为空、取表中第i个元素、查找、插入和删除。并在主函数中完成对各种函数的测试。
//测试用例为：L = （3, 6, 9, 0, -2, 89, 77
#include "sqlist.h"

int main()
{ 
	plist La = (plist)malloc(sizeof(sqlist));
	plist Lb = (plist)malloc(sizeof(sqlist));
	plist Lc = (plist)malloc(sizeof(sqlist));

	/*int  maxsize = (La->SqlistLast + 1) + (Lb->SqlistLast + 1);*/
	/*plist Lc = (plist)malloc(maxsize * sizeof(int));*/
	CreatList(La);
	CreatList(Lb);
	PrintList(La);
	PrintList(Lb);
	MergeList(La, Lb, Lc);
	//LocatList(L, 5);
	//PrintList(L);
	/*InsertList(L, 4, 100);
	PrintList(L);*/
	//DeleteList(L, 4);
	//PrintList(L);
	return 0;

}