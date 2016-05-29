#include"Linklist.h"
const int lenNodetoNode(pLinkNode start, pLinkNode end)
{
	int count = 0;
	while (start != end)
	{
		count++;
		start = start->next;
	}
	return count+1;
}
const pLinkNode BuyNode(DataType x)
{
	pLinkNode newNode = (pLinkNode)malloc(sizeof(LinkNode));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
void InitLinkList(pList *pHead)
{
	assert(pHead);
	*pHead = NULL;

}
void PrintLinkList(pLinkNode Head)
{
	pLinkNode cur = Head;
	while (cur)
	{
		printf("%d-> ", cur->data);
		cur = cur->next;
	}
	printf("over\n");
}

void PushBack(pList *pHead, DataType x)
{
	pLinkNode newNode = BuyNode(x);
	pLinkNode cur = *pHead;
	assert(pHead);
	if (*pHead == NULL)
	{
		*pHead = newNode;
	}
	else
	{
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}

}
void PopBack(pList *pHead)
{
	pLinkNode cur = *pHead;
	pLinkNode del;
	assert(pHead);
	if (*pHead == NULL)
	{
		printf("链表已空");
	}
	else if (cur->next == NULL)
	{
		free(cur);
		*pHead = NULL;
	}
	else
	{
		while (cur->next->next)
		{
			cur = cur->next;
		}
		del = cur->next;
		cur->next = NULL;
		free(del);
	}
}
void PushFront(pList *pHead, DataType x)
{
	pLinkNode newNode = BuyNode(x);
	pLinkNode cur = *pHead;
	assert(pHead);
	if (*pHead == NULL)
	{
		*pHead = newNode;
	}
	else
	{
		newNode->next = *pHead;
		*pHead = newNode;
	}
}
void PopFront(pList *pHead)
{
	pLinkNode cur = *pHead;
	assert(pHead);
	if (*pHead == NULL)
	{
		printf("链表已空");
	}
	else
	{
		*pHead = (*pHead)->next;
		free(cur);
	}
}


void Insert(pList *pHead, pLinkNode pos, DataType x)
{
	pLinkNode newNode = BuyNode(x);
	pLinkNode cur = *pHead;
	
	assert(pHead);
	assert(pos);
	while ((cur->next) != pos)
	{
		cur = cur->next;
	}
	newNode->next = cur->next;
	cur->next = newNode;
}
void Remove(pList *pHead, DataType x)
{
	pLinkNode ret = Find(*pHead, x);
	pLinkNode cur = *pHead;
	assert(pHead);
	while ((cur->next) != ret)
	{
		cur = cur->next;
	}
	cur->next = ret->next;
	free(ret);
}
void RemoveAll(pList *pHead, DataType x)
{
	pLinkNode ret = Find(*pHead, x);
	pLinkNode cur = *pHead;
	assert(pHead);
	while (ret)
	{
		while ((cur->next) != ret)
		{
			cur = cur->next;
		}
		cur->next = ret->next;
		free(ret);
		ret = Find(*pHead, x);
	}
}

pLinkNode Find(pLinkNode Head, DataType x)
{
	pLinkNode cur = Head;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
			cur = cur->next;
	}
	return NULL;
}


void DestoryList(pList *pHead)
{
	pLinkNode cur = *pHead;
	pLinkNode del = NULL;
	assert(pHead);
	if (cur == NULL)
	{
		free(cur);
		*pHead = NULL;
	}
	while (cur)
	{
		del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
	
}
int GetLenth(pList Head)
{
	int count = 0;
	pLinkNode cur = Head;
	while (cur)
	{
		count++;
		cur=cur->next;
	}
	return count;
}
void Erase(pList *pHead, pLinkNode pos)
{
	pLinkNode cur = *pHead;
	assert(pHead);
	assert(pos);
	while ((cur->next)!=pos)
	{
		cur = cur->next;
	}
	cur->next = pos->next;
	
	free(pos);
}
void EarseNotTail(pLinkNode pos)
{
	assert(pos);
	pLinkNode cur = pos->next;
	pos->data = cur->data;
	pos->next = cur->next;
	free(cur);
	cur = NULL;
}
void ReverseList(pList *pHead)
{
	pLinkNode newHead = NULL;
	pLinkNode pre = NULL;
	pLinkNode cur = *pHead;
	assert(pHead);
	while (cur)
	{
		pre = cur;
		cur = cur->next;
		pre->next = newHead;
		newHead = pre;
	}
	*pHead = newHead;
	
}
void BubbleSort(pList *pHead)
{
	pLinkNode cur = *pHead;
	pLinkNode end = NULL;
	DataType tmp = 0;
	assert(pHead);
	while (cur != end)
	{
		while ((cur->next!=end)&&cur)
		{
			if ((cur->data) > (cur->next->data))
			{
				tmp = cur->data;
				cur->data = cur->next->data;
				cur->next->data = tmp;
			}
			cur = cur->next;
         }
		end = cur;
		cur = *pHead;
	}
}
void InsrtFrontNode(pLinkNode pos,DataType x)
{
	pLinkNode newNode = BuyNode(x);
	DataType tmp = 0;
	assert(pos);
	newNode->next = pos->next;
	pos->next = newNode;
	tmp = pos->data;
	pos->data = newNode->data;
	newNode->data = tmp;
}
pLinkNode Merge(pList l1, pList l2)
{
	pLinkNode newHead = NULL;
	pLinkNode cur = NULL;
	if (l1 == NULL&&l2)
	{
		return l2;
	}
	if (l2 == NULL&&l1)
	{
		return l1;
	}
	if (l1 == l2)
	{
		return l1;
	}
	if ((l1->data) > (l2->data))
	{
		newHead = l2;
		l2 = l2->next;
	}
	else
	{
		newHead = l1;
		l1 = l1->next;
	}
	cur = newHead;
	while(l1&&l2)
	{
		if ((l1->data) > (l2->data))
		{
			cur->next = l2;
			l2 = l2->next;
		}
		else
		{
			cur->next = l1;
			l1 = l1->next;
		}
		cur = cur->next;
	}
	if (l1 == NULL)
	{
		cur->next = l2;
	}
	else
	{
		cur->next = l1;
	}
	return newHead;
}
pLinkNode JosephCycle(pList *pHead, int num)
{
	pLinkNode cur = *pHead;
	pLinkNode del = NULL;
	int ret = num;
	assert(pHead);
	while (1)
	{
		if (cur->next == cur)
		{
			break;
		}
		else
		{
			ret = num;
			while (--ret)
			{
				cur = cur->next;
			}
			del = cur->next;
			cur->data = cur->next->data;
			cur->next = cur->next->next;
			free(del);
		}
	}
	return cur;
}
pLinkNode FindMidNode(pList pHead)
{
	pLinkNode fast = pHead;
	pLinkNode slow = pHead;
	if ((pHead == NULL) || (pHead->next == NULL))
		return NULL;
	else
	{
		while (fast->next)
		{
			if ((fast == NULL) || (fast->next == NULL))
				return NULL;
			fast = fast->next->next;
			slow = slow->next;
		}
		return slow;
	}
}
void DelKNode(pList *pHead, int k)
{
	pLinkNode cur1 = *pHead;
	pLinkNode cur2 = *pHead;
	pLinkNode del = NULL;
	assert(pHead);
	assert(k > 1);
	if ((cur1 == NULL) || (cur1->next == NULL))
		return;
	else
	{
		while ((--k)&&(cur1->next))
		{
			cur1 = cur1->next;
		}
		if (k <= 0)
		{
			while (cur1->next)
			{
				cur1 = cur1->next;
				cur2 = cur2->next;
			}
			del = cur2->next;
			cur2->data = cur2->next->data;
			cur2->next = cur2->next->next;
			free(del);
			del = NULL;
		}
		else
		{
			printf("给出的数 超出链表范围\n");
		}
	}

}
pLinkNode CheckCycle(pList pHead)
{
	pLinkNode fast = pHead;
	pLinkNode slow = pHead;
	if ((fast == NULL) && (fast->next == NULL))
		return NULL;
	else
	{
		fast = fast->next->next;
		slow = slow->next;
		while (fast != slow)
		{
			if ((fast == NULL) || (fast->next == NULL))
				return NULL;
			fast = fast->next->next;
			slow = slow->next;
		}
		
		return slow;
		
	}
}
int GetCycleLength(pLinkNode meet)
{
	pLinkNode cur = meet;
	int count = 0;
	while (cur->next != meet)
	{
		count++;
		cur = cur->next;
	}
	return count + 1;
}
pLinkNode GetCycleEoryNode(pList pHead, pLinkNode meet)
{
	pLinkNode cur1 = pHead;
	pLinkNode cur2 = meet;
	
	while (cur1 != cur2)
	{
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return cur2;
}
int CheckCross(pList l1, pList l2)
{
	pLinkNode cur1 = l1;
	pLinkNode cur2 = l2;
	if (cur1 == NULL || cur2 == NULL)
		return 0;
	else
	{
		while (cur1->next)
		{
			cur1 = cur1->next;
        }
		while (cur2->next)
		{
			cur2 = cur2->next;
		}
		if (cur1 == cur2)
		{
			return 1;
		}
		else
			return -1;
	}
}
pLinkNode _Merge(pList l1, pList l2)
{
	pLinkNode newHead = NULL;
	pLinkNode cur = NULL;
	if (l1 == NULL&&l2)
	{
		return l2;
	}
	if (l2 == NULL&&l1)
	{
		return l1;
	}
	if (l1 == l2)
	{
		return l1;
	}
	if ((l1->data) > (l2->data))
	{
		newHead = l2;
		l2 = l2->next;
		newHead->next = _Merge(l1, l2);
	}
	else
	{
		newHead = l1;
		l1 = l1->next;
		newHead->next = _Merge(l1, l2);
	}
	
	return newHead;
}
pLinkNode GetLinkCross(pList l1, pList l2)
{
	pLinkNode cur1 = l1;
	pLinkNode cur2 = l2;
	int len1 = GetLenth(l1);
	int len2 = GetLenth(l2);
	int k = 0;
	if (len1 == len2)
	{
		while (cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur1;
	}
	else if (len1 > len2)
	{
		k = len1 - len2;
		while (k--)
		{
			cur1 = cur1->next;
		}
		while (cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur1;
	}
	else
	{
		k = len2 - len1;
		while (k--)
		{
			cur2 = cur2->next;
		}
		while (cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur2;
	}
}
pLinkNode CheckCrossCycle(pList l1, pList l2)
{
	pLinkNode meet1 = CheckCycle(l1);
	pLinkNode meet2 = CheckCycle(l2);
	pLinkNode eory1 = NULL;
	pLinkNode eory2 = NULL;
	if (meet1 == NULL || meet2 == NULL)
		return NULL;
	else
	{
		eory1 = GetCycleEoryNode(l1, meet1);
		eory2 = GetCycleEoryNode(l2, meet2);
		if (eory1 == eory2)
		{
			return eory1;
		}
		else
			return NULL;
	}
}
pLinkNode GetCrossCycleCross(pLinkNode eroy, pList l1, pList l2)
{
	pLinkNode cur1 = l1;
	pLinkNode cur2 = l2;
	int len1 = lenNodetoNode(l1, eroy);
	int len2 = lenNodetoNode(l2, eroy);
	int k = 0;
	if (len1 == len2)
	{
		while (cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur1;
	}
	else if (len1 > len2)
	{
		k = len1 - len2;
		while (k--)
		{
			cur1 = cur1->next;
		}
		while (cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur1;
	}
	else
	{
		k = len2 - len1;
		while (k--)
		{
			cur2 = cur2->next;
		}
		while (cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur2;
	}
}
pLinkNode _GetCycleEoryNode(pList pHead, pLinkNode meet)
{
	pLinkNode cur1 = pHead;
	pLinkNode cur2 = meet;
	int len1 = lenNodetoNode(cur1, cur2)-1;
	int len2 = GetCycleLength(cur2);
	int k = 0;
	if (len1 == len2)
	{
		while (cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur1;
	}
	else if (len1 > len2)
	{
		k = len1 - len2;
		while (k--)
		{
			cur1 = cur1->next;
		}
		while (cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur1;
	}
	else
	{
		k = len2 - len1;
		while (k--)
		{
			cur2 = cur2->next;
		}
		while (cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur2;
	}
}