//预定义函数结果状态代码
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100
//函数返回值类型，其值是函数结果的状态代码
typedef int Status;
typedef int ElemType;  //可以自行设置ElemType的类型

// 顺序表类型定义
typedef struct {
	ElemType* elem;
	int length;
}SqList;

//各种操作函数定义,按内容要求自行编写
//初始化函数
Status InitList(SqList& L)
{
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	return OK;
}
void CreatList(SqList L)
{
	int TempNode = 1;
	int TempData;
	/*InitList(L);*/
	do
	{
		cout << "请输入顺序表中第" << TempNode << "个元素：";
		cin >> TempData;
		if (TempData == -1)
		{
			break;
		}
		L.elem[TempNode - 1] = TempData;
		L.length = TempNode;
		TempNode++;


	} while (TempNode < MAXSIZE);
}

//输出顺序表
Status PrintList(SqList L)
{
	cout << "head";
	for (int i = 0; i < L.length; i++)
	{
		cout << "->" << "[" << L.elem[i] << "]";
	}
	cout << endl;
	return 0;
}

//判断是否为空
bool IsEmpty(SqList L)
{
	if (L.length == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// 取表中第i个元素
Status GetElem(SqList L, int i, ElemType& e)
{
	if (i<1 || i>L.length)
	{
		return ERROR;
	}
	e = L.elem[i - 1];
	return OK;
}

// 查找
int LocateElem(SqList L, ElemType e)//返回的是要查找元素的在表中的序号
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e)
			return i - 1;
	}
	return 0;
}

//插入
Status ListInsert(SqList& L, int i, ElemType e)
{
	if ((i < 1) || i > (L.length + 1))
		return ERROR;
	for (int j = L.length - 1; j >= i - 1; j--)
	{
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i - 1] = e;
	++L.length;
	return OK;
}
// 删除
Status ListDelete(SqList& L, int i)
{
	if ((i < 1) || (i > L.length))
		return ERROR;
	for (int j = i; j <= L.length - 1; j++)
	{
		L.elem[j - 1] = L.elem[j];
	}
	--L.length;
	return OK;
}

//合并两个递增有序的线性表，可参考P43，算法2.16
void MergeList_Sq(SqList  LA, SqList LB, SqList& LC)
{

}

//main函数
int main()
{
	SqList L;
	InitList(L);
	CreatList(L);
	PrintList(L);

	////ListInsert(L, 0, 1);
	//ListInsert(L, 1, 1);
	//ListInsert(L, 2, 2);
	//ListInsert(L, 3, 3);
	//ListInsert(L, 4, 4);
	//PrintList(L);
	return 0;
}
