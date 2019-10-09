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

void CreatList(plist L);//创建顺序表
void PrintList(plist L);//打印顺序表
void InsertList(plist L, int node, int data);//插入元素
void DeleteList(plist L,int node);//删除元素
void GetList(plist L, int node);//取出某一个元素
void LocatList(plist L, int data);//查找
void MergeList(plist LA, plist LB, plist LC);

#endif // !_SQLIST_H_
