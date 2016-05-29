#include"Linklist.h"
void test()
{
	pLinkNode myLink;
	pList pos;
	int ret = 0;
	InitLinkList(&myLink);
	PushBack(&myLink, 1);
	PushBack(&myLink, 2);
	PushBack(&myLink, 3);
	PushBack(&myLink, 2);
	ret = GetLenth(myLink);
	PrintLinkList(myLink);
	printf("lenth=%d\n", ret);
	PopBack(&myLink);
	PrintLinkList(myLink);
	PushFront(&myLink, 5);
	PrintLinkList(myLink);
	PopFront(&myLink);
	PrintLinkList(myLink);
	pos = Find(myLink, 2);
	Insert(&myLink, pos, 7);
	PrintLinkList(myLink);
	pos = Find(myLink, 7);
	Erase(&myLink, pos);
	PrintLinkList(myLink);
	RemoveAll(&myLink, 2);
	PrintLinkList(myLink);
	DestoryList(&myLink);

}
void test1()
{
	pLinkNode myLink;
	pList pos;
	int ret = 0;
	InitLinkList(&myLink);
	PushBack(&myLink, 1);
	PushBack(&myLink, 2);
	PushBack(&myLink, 3);
	PushBack(&myLink, 2);
	pos = Find(myLink, 2);
	EarseNotTail(pos);
	PrintLinkList(myLink);
	DestoryList(&myLink);
}
void test2()
{
	pLinkNode myLink;
	pList pos;
	int ret = 0;
	InitLinkList(&myLink);
	PushBack(&myLink, 1);
	PushBack(&myLink, 2);
	PushBack(&myLink, 3);
	PushBack(&myLink, 5);
	pos = Find(myLink, 2);
	ReverseList(&myLink);
	PrintLinkList(myLink);
	DestoryList(&myLink);
}
void test3()
{
	pLinkNode myLink;
	pList pos;
	int ret = 0;
	InitLinkList(&myLink);
	PushBack(&myLink, 6);
	PushBack(&myLink, 4);
	PushBack(&myLink, 3);
	PushBack(&myLink, 5);
	BubbleSort(&myLink);
	PrintLinkList(myLink);
	DestoryList(&myLink);
}
void test4()
{
	pLinkNode myLink;
	pList pos;
	int ret = 0;
	InitLinkList(&myLink);
	PushBack(&myLink, 6);
	PushBack(&myLink, 4);
	PushBack(&myLink, 3);
	PushBack(&myLink, 5);
	pos = Find(myLink, 3);
	InsrtFrontNode(pos, 7);
	PrintLinkList(myLink);
	DestoryList(&myLink);
}
void test5()
{
	pLinkNode l1;
	pList l2;
	pLinkNode newHead = NULL;
	int ret = 0;
	InitLinkList(&l1);
	PushBack(&l1, 1);
	PushBack(&l1, 3);
	PushBack(&l1, 5);
	PushBack(&l1, 7);
	InitLinkList(&l2);
	PushBack(&l2, 2);
	PushBack(&l2, 4);
	PushBack(&l2, 6);
	PushBack(&l2, 8);
	newHead=_Merge(l1, l2);
	PrintLinkList(newHead);
	DestoryList(&newHead);
}
void test6()
{
	pLinkNode myLink;
	pList pos;
	int ret = 0;
	InitLinkList(&myLink);
	PushBack(&myLink, 6);
	PushBack(&myLink, 4);
	PushBack(&myLink, 3);
	PushBack(&myLink, 5);
	pos = Find(myLink, 5);
	pos->next = myLink;
	pos= JosephCycle(&myLink, 3);
	printf("%d\n", pos->data);
	pos->next = NULL;
	free(pos);
	pos = NULL;
}
void test7()
{
	pLinkNode myLink;
	pList pos;
	int ret = 0;
	InitLinkList(&myLink);
	PushBack(&myLink, 6);
	PushBack(&myLink, 4);
	PushBack(&myLink, 3);
	PushBack(&myLink, 5);
	PushBack(&myLink, 2);
	pos = FindMidNode(myLink);
	printf("%d\n", pos->data);
	DestoryList(&myLink);
}
void test8()
{
	pLinkNode myLink;
	pList pos;
	int ret = 0;
	InitLinkList(&myLink);
	PushBack(&myLink, 6);
	PushBack(&myLink, 4);
	PushBack(&myLink, 3);
	PushBack(&myLink, 5);
	PushBack(&myLink, 2);
	DelKNode(&myLink, 3);
	PrintLinkList(myLink);
	DestoryList(&myLink);
}
void test9()
{
	pLinkNode myLink;
	pList pos1 = NULL;
	pList pos2 = NULL;
	pList meet = NULL;
	int len = 0;
	InitLinkList(&myLink);
	PushBack(&myLink, 6);
	PushBack(&myLink, 4);
	PushBack(&myLink, 3);
	PushBack(&myLink, 5);
	PushBack(&myLink, 2);
	PushBack(&myLink, 7);
	PushBack(&myLink, 8);
	PushBack(&myLink, 9);
	PushBack(&myLink, 10);
	PushBack(&myLink, 1);
	pos1 = Find(myLink, 8);
	pos2 = Find(myLink, 1);
	pos2->next = pos1;
	meet = CheckCycle(myLink);
	printf("%d\n", meet->data);
	len = GetCycleLength(meet);
	printf("len= %d\n", len);
	pos2->next = NULL;
	DestoryList(&myLink);
}
void test10()
{
	pLinkNode myLink;
	pList pos1 = NULL;
	pList pos2 = NULL;
	pList meet = NULL;
	pList eory = NULL;
	InitLinkList(&myLink);
	PushBack(&myLink, 6);
	PushBack(&myLink, 4);
	PushBack(&myLink, 3);
	PushBack(&myLink, 5);
	PushBack(&myLink, 2);
	PushBack(&myLink, 7);
	PushBack(&myLink, 8);
	PushBack(&myLink, 9);
	PushBack(&myLink, 10);
	PushBack(&myLink, 1);
	pos1 = Find(myLink, 8);
	pos2 = Find(myLink, 1);
	pos2->next = pos1;
	meet = CheckCycle(myLink);
	eory = _GetCycleEoryNode(myLink, meet);
	//eory = GetCycleEoryNode(myLink, meet);
	printf("%d\n", eory->data);
	pos2->next = NULL;
	DestoryList(&myLink);
}
void test11()
{
	pList l1;
	pList l2;
	pLinkNode pos1 = NULL;
	pLinkNode pos2 = NULL;
	pLinkNode cross = NULL;
	int ret = 0;
	InitLinkList(&l1);
	PushBack(&l1, 1);
	PushBack(&l1, 3);
	PushBack(&l1, 5);
	PushBack(&l1, 7);
	InitLinkList(&l2);
	PushBack(&l2, 2);
	PushBack(&l2, 4);
	PushBack(&l2, 6);
	PushBack(&l2, 8);
	pos1 = Find(l1, 5);
	pos2 = Find(l2, 8);
	pos2->next = pos1;
	ret = CheckCross(l1, l2);
	printf("%d\n", ret);
	cross = GetLinkCross(l1, l2);
	printf("交点为：%d\n", cross->data);
	DestoryList(&l1);
	pos2->next = NULL;
	DestoryList(&l2);
}
void test12()
{
	pList l1;
	pList l2;
	pLinkNode pos1 = NULL;
	pLinkNode pos2 = NULL;
	pLinkNode pos3 = NULL;
	pLinkNode pos4 = NULL;
	pLinkNode eory = NULL;
	pLinkNode pos5 = NULL;
	InitLinkList(&l1);
	PushBack(&l1, 1);
	PushBack(&l1, 3);
	PushBack(&l1, 5);
	PushBack(&l1, 7);
	PushBack(&l1, 9);
	PushBack(&l1, 10);
	PushBack(&l1, 11);
	InitLinkList(&l2);
	PushBack(&l2, 2);
	PushBack(&l2, 4);
	PushBack(&l2, 6);
	PushBack(&l2, 8);
	pos1 = Find(l1, 5);
	pos2 = Find(l2, 8);
	pos3 = Find(l1, 11);
	pos4 = Find(l1, 9);
	pos2->next = pos1;
	pos3->next = pos4;
	eory = CheckCrossCycle(l1, l2);
	if (eory != NULL)
	{
		printf("环入口点为：%d\n", eory->data);
		pos5 = GetCrossCycleCross(eory, l1, l2);
		printf("链表交点为：%d\n", pos5->data);
	}
	else
	{
		printf("不是带环相交\n");
	}
	pos3->next = NULL;
	DestoryList(&l1);
	pos2->next = NULL;
	DestoryList(&l2);
}
int main()
{
	test12();
	system("pause");
	return 0;
}