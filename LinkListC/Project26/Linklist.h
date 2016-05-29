#ifndef __LINKLIST_H__
#define __LINKLIST_H__
#define DataType int
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct LinkNode
{
	DataType data;
	struct LinkNode *next;
}LinkNode,*pList,*pLinkNode;
void InitLinkList(pList *pHead);
void PrintLinkList(pLinkNode Head);

void PushBack(pList *pHead, DataType x);
void PopBack(pList *pHead);
void PushFront(pList *pHead, DataType x);
void PopFront(pList *pHead);


void Insert(pList *pHead, pLinkNode pos, DataType x);//
void Remove(pList *pHead, DataType x);
void RemoveAll(pList *pHead, DataType x);
int GetLenth(pList Head);
pLinkNode Find(pLinkNode Head, DataType x);
void Erase(pList *pHead, pLinkNode pos);

void DestoryList(pList *pHead);
void EarseNotTail(pLinkNode pos);
void ReverseList(pList *pHead);
void BubbleSort(pList *pHead);
void InsrtFrontNode(pLinkNode pos, DataType x);
pLinkNode Merge(pList l1, pList l2);
pLinkNode JosephCycle(pList *pHead, int num);
pLinkNode FindMidNode(pList pHead);
void DelKNode(pList *pHead, int k);
pLinkNode CheckCycle(pList pHead);
int GetCycleLength(pLinkNode meet);
pLinkNode GetCycleEoryNode(pList pHead,pLinkNode meet);
int CheckCross(pList l1, pList l2);
pLinkNode _Merge(pList l1, pList l2);
pLinkNode GetLinkCross(pList l1, pList l2);
pLinkNode CheckCrossCycle(pList l1, pList l2);
pLinkNode GetCrossCycleCross(pLinkNode eroy, pList l1, pList l2);
pLinkNode _GetCycleEoryNode(pList pHead, pLinkNode meet);
#endif //__LINKLIST_H__
