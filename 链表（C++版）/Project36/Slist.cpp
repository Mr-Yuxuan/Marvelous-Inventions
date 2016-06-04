#include "Slist.h"
ostream& operator<<(ostream& os, const Slist& s)
{
	Node* cur =s._head;
	while (cur)
	{
		os << cur->_data << "->";
		cur = cur->next;
	}
	os << "over";
	return os;
}
void Slist::PushBack(const DataType& d)
{
	Node* newNode = new Node(d);
	if (_head == NULL)
	{
		_head = newNode;
		_tail = _head;
	}
	else
	{
		_tail->next = newNode;
		_tail = newNode;
	}
}
void Slist::PopBack()
{
	if (_head == NULL)
		return;
	Node* cur = _head;
	while (cur->next != _tail)
	{
		cur = cur->next;
	}
	delete _tail;
	_tail = cur;
	_tail->next = NULL;
}
void Slist::PushFront(const DataType& d)
{
	Node* newNode = new Node(d);
	if (_head == NULL)
	{
		_head = newNode;
		_tail = _head;
	}
	else
	{
		newNode->next = _head;
		_head = newNode;
	}
}
void Slist::PopFront()
{
	if (_head == NULL)
		return;
	Node* del = _head;
	_head = _head->next;
	delete del;

}
Node* Slist::Find(const DataType& d)
{
	Node* cur = _head;
	while (cur)
	{
		if (d == cur->_data)
			return cur;
		if (cur->next != NULL)
		{
			cur = cur->next;
		}
		
	}
	return NULL;
}
void Slist::Insert(Node* pos, const DataType& d)
{
	Node* newNode = new Node(d);
	newNode->next = pos->next;
	pos->next = newNode;
}
void Slist::Reverse()
{
	Node* newHead = NULL;
	Node* pre = NULL;
	Node* cur = _head;
	while (cur)
	{
		pre = cur;
		cur = cur->next;
		pre->next = newHead;
		newHead = pre;
	}
	_tail = _head;
	_head = newHead;
}
void Slist::Sort()
{
	if (_head == NULL || (_head->next == NULL))
		return;
	Node* cur1 = _head;
	Node* cur2 = _head->next;
	Node* end = NULL;
	while (cur1!=end)
	{
		while ((cur2!=end)&&cur1)
		{
			if ((cur1->_data) > (cur2->_data))
			{
				DataType tmp = cur1->_data;
				cur1->_data = cur2->_data;
				cur2->_data = tmp;
			}
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		end = cur1;
		cur1 = _head;
	    cur2 = _head->next;
	}
}
void Slist::Remove(const DataType& d)
{
	if (_head == NULL)
		return;
	Node* pos = Find(d);
	Node* del = pos->next;
	DataType tmp = pos->_data;
	pos->_data = pos->next->_data;
	pos->next->_data = tmp;
	pos->next = del->next;
	delete del;
}
void Slist::RemoveAll(const DataType& d)
{
	if (_head == NULL)
		return;
	Node* pos = NULL;
	while ((pos = Find(d)) != NULL)
	{
		Remove(d);
	}
}
void Slist::EarseNotTail(Node* pos)
{
	if (_head == NULL)
		return;
	if (_head->next == NULL)
	{
		delete _head;
		_head == NULL;
		_tail = _head;
	}
	else
	{
		Node* del = pos->next;
		DataType tmp = pos->_data;
		pos->_data = pos->next->_data;
		pos->next->_data = tmp;
		pos->next = del->next;
		delete del;
	}
}


Node* Slist::FindMidNode()
{
	if (_head == NULL || (_head->next == NULL))
		return NULL;
	else
	{
		Node* fast = _head;
		Node* slow = _head;
		while (fast->next)
		{
			if (fast == NULL || fast->next == NULL)
				return NULL;
			fast = fast->next->next;
			slow = slow->next;
		}
		return slow;
	}
}
//删除倒数第k结点
void Slist::DelKNode(int k)
{
	if (k < 0 || _head == NULL)
		return;
	Node* frist = _head;
	Node* second = _head;
	while ((--k)&&(frist))
	{
		frist = frist->next;
	}
	if (frist == NULL)
	{
		cout << "k超出范围" << endl;
		return;
	}
	else
	{
		while (frist->next)
		{
			frist = frist->next;
			second = second->next;
		}
		Node* del = second->next;
		DataType tmp = second->_data;
		second->_data = second->next->_data;
		second->next->_data = tmp;
		second->next = del->next;
		delete del;
	}
}
////是否带环
int Slist::CheckCycle()
{
	if (_head == NULL)
		return -1;
	if (_tail->next != NULL)
		return 1;
	else
		return 0;
}
int Slist::GetCycleLength()
{
	Node* cur = _tail;
	int len = 0;
	while (cur->next != cur)
	{
		len++;
		cur = cur->next;
	}
	return len + 1;
}
//获取环入口点
Node* Slist::GetCycleEoryNode()
{
	return _tail->next;
}
////是否相交
int CheckCross(const Slist& l1,const Slist& l2)
{
	if (l1._head == NULL || l2._head == NULL)
		return 0;
	if (l1._tail == l2._tail)
		return 1;
	else
		return 0;
}
////合并
Slist& Slist::_Merge(Slist& l1, Slist& l2)
{
	if (l1._head == NULL)
		return l2;
	if (l2._head == NULL)
		return l1;
	if (l1._head == l2._head)
		return l1;
	Node* cur1 = l1._head;
	Node* cur2 = l2._head;
	
	while ((cur1)&&(cur2))
	{
		if (cur1->_data > cur2->_data)
		{
			PushBack(cur2->_data);
			cur2 = cur2->next;
		}
		else
		{
			PushBack(cur1->_data);
			cur1 = cur1->next;
			
		}
	}
	if (cur1 == NULL)
	{
		while (cur2)
		{
			PushBack(cur2->_data);
			cur2 = cur2->next;
		}
	}
	else
	{
		while (cur1)
		{
			PushBack(cur1->_data);
			cur1 = cur1->next;
		}
	}
	return *this;
	
}
int LenthOfSlist(const Slist& s)
{
	int len = 0;
	Node* cur = s._head;
	while (cur)
	{
		len++;
		cur = cur->next;
	}
	return len;
}
////求交点
Node* GetLinkCross(Slist& l1, Slist& l2)
{
	int len1 = LenthOfSlist(l1);
	int len2 = LenthOfSlist(l2);
	Node* frist = NULL;
	Node* second = NULL;
	int n = 0;
	if (len1 < len2)
	{
		n = len2 - len1;
		frist = l2._head;
		second = l1._head;
	}
	else
	{
		n = len1 - len2;
		frist = l1._head;
		second = l2._head;
	}
	while (n--)
	{
		frist = frist->next;
	}
	while (frist != second)
	{
		frist = frist->next;
		second = second->next;
	}
	return second;
}
