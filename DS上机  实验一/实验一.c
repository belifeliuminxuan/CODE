//1. ����˳�������������������������ʼ��˳������˳����ж��Ƿ�Ϊ�ա�ȡ���е�i��Ԫ�ء����ҡ������ɾ������������������ɶԸ��ֺ����Ĳ��ԡ�
//��������Ϊ��L = ��3, 6, 9, 0, -2, 89, 77
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