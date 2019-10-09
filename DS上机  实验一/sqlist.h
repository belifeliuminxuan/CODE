#ifndef _SQLIST_H_
#define _SQLIST_H_
#include <stdio.h>
#include <assert.h>
#define MAXSIZE 20
typedef struct
{	
	int SqlistData[MAXSIZE];
	int SqlistLast;
}sqlist,*plist;

void CreatList(plist L);//����˳���
void PrintList(plist L);//��ӡ˳���
void InsertList(plist L, int node, int data);//����Ԫ��
void DeleteList(plist L,int node);//ɾ��Ԫ��
void GetList(plist L, int node);//ȡ��ĳһ��Ԫ��
void LocatList(plist L, int data);//����
void MergeList(plist LA, plist LB, plist LC);

#endif // !_SQLIST_H_
