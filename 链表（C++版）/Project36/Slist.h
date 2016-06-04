#pragma once
#include<iostream>
using namespace std;
typedef int DataType;
struct Node
{
	Node(const DataType& d)
	:_data(d)
	, next(NULL)
	{

	}
	DataType _data;
	Node* next;
};
class Slist
{
	friend ostream& operator<<(ostream& os, const Slist& s);
public:
	Slist()
		:_head(NULL)
		, _tail(NULL)
	{

	}
	Slist(const Slist& s)
		:_head(NULL)
		, _tail(NULL)
	{
		Node* cur = s._head;
		while (cur)
		{
			cur = cur->next;
			PushBack(cur->_data);
		}
		
	}
	Slist& operator=(Slist s)
	{
		swap(_head, s._head);
		swap(_tail, s._tail);
		return *this;
	}
	~Slist()
	{
		if (_head != NULL)
		{
			Node* cur = _head;
			while (cur)
			{
				_head = _head->next;
				delete cur;
				cur = _head;
			}
			
		}
	}
public:
	void PushBack(const DataType& d);
	void PopBack();
	void PushFront(const DataType& d);
	void PopFront();
	Node* Find(const DataType& d);
	void Insert(Node* pos,const DataType& d);
	void Reverse();
	void Sort();
	void Remove(const DataType& d);
	void RemoveAll(const DataType& d);
	void EarseNotTail(Node* pos);
	friend int LenthOfSlist(const Slist& s);
	
	
	
	Node* FindMidNode();
	//ɾ��������k���
	void DelKNode(int k);
	//�Ƿ����
	int CheckCycle();
	int GetCycleLength();
	//��ȡ����ڵ�
	Node* GetCycleEoryNode();
	//�Ƿ��ཻ
	friend int CheckCross(const Slist& l1,const Slist& l2);
	//�ϲ�
	 Slist& _Merge(Slist& l1, Slist& l2);
	//�󽻵�
	 friend Node* GetLinkCross(Slist& l1, Slist& l2);
	
private:
	Node* _head;
	Node* _tail;
};