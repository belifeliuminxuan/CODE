//Ԥ���庯�����״̬����
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100
//��������ֵ���ͣ���ֵ�Ǻ��������״̬����
typedef int Status;
typedef int ElemType;  //������������ElemType������

// ˳������Ͷ���
typedef struct {
	ElemType* elem;
	int length;
}SqList;

//���ֲ�����������,������Ҫ�����б�д
//��ʼ������
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
		cout << "������˳����е�" << TempNode << "��Ԫ�أ�";
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

//���˳���
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

//�ж��Ƿ�Ϊ��
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

// ȡ���е�i��Ԫ��
Status GetElem(SqList L, int i, ElemType& e)
{
	if (i<1 || i>L.length)
	{
		return ERROR;
	}
	e = L.elem[i - 1];
	return OK;
}

// ����
int LocateElem(SqList L, ElemType e)//���ص���Ҫ����Ԫ�ص��ڱ��е����
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e)
			return i - 1;
	}
	return 0;
}

//����
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
// ɾ��
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

//�ϲ�����������������Ա��ɲο�P43���㷨2.16
void MergeList_Sq(SqList  LA, SqList LB, SqList& LC)
{

}

//main����
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
