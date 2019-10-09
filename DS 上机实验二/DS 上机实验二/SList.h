#ifndef _SLIST_H_
#define _SLIST_H_


typedef struct
{
	char no[8];//学号
	char name[20];//姓名
	int score;//分数
}Student;

typedef struct SListNode{
	Student data;       //数据域
	struct LNode  *next;   //指针域
}SListNode, *LinkList;
void SListInit(SListNode** pphead);
void SListDestory(SListNode** pphead);
void SListPrint(SListNode* phead);

#endif

//#ifndef _SLIST_H_
//#define _SLIST_H_
//
//typedef int SLTDataType;
//
//typedef struct SListNode {
//	SLTDataType data;
//	struct SListNode* next;
//}SListNode;
//
//
//
//
//
//void SListPushFront(SListNode** pphead, SLTDataType x);
//void SListPopFront(SListNode** pphead);
//void SListInsertAfter(SListNode* pos, SLTDataType x);
//void SListEraseAfter(SListNode* pos);
//SListNode* SListFind(SListNode* phead, SLTDataType x);
//void SListRemove(SListNode** pphead, SLTDataType x);
//
//
//
//void SListReverse(SListNode **pphead);
//void SListReverse2(SListNode **pphead);
//
//SListNode *getIntersectionNode(SListNode *headA, SListNode *headB);
//SListNode *detectCycle(SListNode *head);
//#endif /*_SLIST_H_*/ //_SLIST_H_