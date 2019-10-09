#include "sqlist.h"

void CreatList(plist L)//创建顺序表
{
	
	int TempData=0;
	int TempNode=1;
	do{
	printf("请输入顺序表第[%d]个元素：", TempNode);
	scanf_s("%d", &TempData);
	if (TempData != -1)
	{
		L->SqlistData[TempNode - 1] = TempData;
		L->SqlistLast = TempNode-1;
		TempNode++;
	}
	else if (TempData == -1)
	{
		break;
	}
	}while (TempNode <= MAXSIZE && TempNode != -1);
}
void InsertList(plist L, int node, int data)//顺序表中插入元素
{
	assert(node > 0 && node < MAXSIZE - 1);
	/*if (node<0 || node>L->SqlistLast+1)
	{
		printf("Parameter error!");
	}*/
	
	/*else if (node > MAXSIZE - 1)
	{
		printf("Parameter error!");
	}*/
	for (int i = L->SqlistLast; i >=node; i--)
		{
			L->SqlistData[i + 1] = L->SqlistData[i];
		}
		L->SqlistData[node] = data;
		L->SqlistLast++;

}
void DeleteList(plist L,int node)//删除节点元素
{
	/*if (node <0 || node>L->SqlistLast + 1);*/
	assert(node > 0 && node < L->SqlistLast + 1);
	for (int j = node+1; j <=L->SqlistLast; j++)
	{
		L->SqlistData[j - 1] = L->SqlistData[j];
	}
	L->SqlistLast--;
}
void PrintList(plist L)//打印节点元素
{

	for (int i = 0; i <L->SqlistLast+1;i++)
	{	
		printf("—>[%d]", L->SqlistData[i]);
	}
	printf("\n");
}
void GetList(plist L, int node)//取表中元素
{
	int tempData = 0;
	tempData = L->SqlistData[node - 1];
	return tempData;
}
void LocatList(plist L, int data)//查找
{
	for (int i = 0; i < L->SqlistLast; i++)
	{
		if (data == L->SqlistData[i])
		{
			printf("[%d]->[%d]\n", i, data);
			break;
		}
	}


}
void MergeList(plist La, plist Lb, plist Lc)
{
	int  maxsize = (La->SqlistLast + 1) + (Lb->SqlistLast + 1);
	for (int i = 0; i < maxsize; i++)
	{
		Lc->SqlistData[i] = La->SqlistData[i];
		while (i >= La->SqlistLast+1 && i!=maxsize)
		{
			for (int j = 0; j < maxsize+1; j++)
			{
				Lc->SqlistData[i] = Lb->SqlistData[j];
				i++;
				if (i == maxsize) break;
			}
		}
	}
	for (int i = 0; i < maxsize; i++)
	{
		int temp = 0;
		for (int j = maxsize; j > i; j--)
		{
			if (Lc->SqlistData[j - 1] <Lc->SqlistData[j])
			{
				temp = Lc->SqlistData[j - 1];
				Lc->SqlistData[j - 1] = Lc->SqlistData[j];
				Lc->SqlistData[j] = temp;
			}
		}
	}
	for (int k = 0; k < maxsize; k++)
	{
		printf("->[%d]", Lc->SqlistData[k]);
	}
}