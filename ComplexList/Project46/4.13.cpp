#include<iostream>
using namespace std;
template<class T>
struct ComplexNode
{
	ComplexNode(const T& d)
	:_data(d)
	, _next(NULL)
	, _random(NULL)
	{}
	T _data;
	struct ComplexNode* _next;
	struct ComplexNode* _random;
};
template<class T>
class ComplexList
{
public:
	ComplexList()
	:_phead(NULL)
	{}
	ComplexList(const ComplexList<T>& l)
	{
		CopyList(l);
	}
	ComplexList<T>& operator=(const ComplexList<int>& l)
	{
		if (this != &l)
		{
			if (_phead != NULL)
			{
				_Del();
			}
			CopyList(l);
			
		}
		
			return *this;
		
	}
	void Push(const T& d)
	{
		ComplexNode<T>* cur = new ComplexNode<T>(d);
		if (_phead == NULL)
		{
			_phead = cur;
		}
		else
		{
			ComplexNode<T>* c = _phead;
			while (c->_next)
			{
				c = c->_next;
			}
			c->_next = cur;
		}
	}
	void RandomInit(const T& d,const T& s)
	{
		ComplexNode<T>* cur1 = _phead;
		ComplexNode<T>* cur2 = _phead;
		while (cur1->_data != d)
		{
			cur1 = cur1->_next;
		}
		while (cur2)
		{
			if (cur2->_data == s)
			{
				break;
			}
			
			cur2 = cur2->_next;
		}
		cur1->_random = cur2;
	}
	void Print()
	{
		ComplexNode<T>* cur = _phead;
		while (cur)
		{
			cout << cur->_data;
			if (cur->_random != NULL)
			{
				cout << '(' << cur->_random->_data << ')';
			}
			cout <<"-->";
			cur = cur->_next;
		}
		cout << "over";
		cout << endl;
	}
	~ComplexList()
	{
		_Del();
	}
protected:
	void _Del()
	{
		ComplexNode<T>* cur = _phead;
		while (cur)
		{
			cur->_random = NULL;
			cur = cur->_next;
		}
		while (_phead)
		{
			cur = _phead;
			_phead = _phead->_next;
			delete cur;
		}
	}
	void CopyList(const ComplexList<T>& l)
	{
		ComplexNode<T>* cur = l._phead;
		while (cur)
		{
			Push(cur->_data);
			cur = cur->_next;
		}
		cur = l._phead;
		while (cur)
		{
			if (cur->_random != NULL)
			{
				RandomInit(cur->_data, cur->_random->_data);
			}
			cur = cur->_next;
		}
	}
private:
	ComplexNode<T>* _phead;

};
int main()
{
	ComplexList<int> l1;
	l1.Push(1);
	l1.Push(2);
	l1.Push(3);
	l1.Push(4);
	l1.Push(5);
	l1.RandomInit(5, 2);
	l1.RandomInit(1, 4);
	l1.RandomInit(2, 4);
	l1.Print();
	ComplexList<int> l2(l1);
	l2.Print();
	ComplexList<int> l3;
	l3 = l2;
	l3.Print();
	system("pause");
	return 0;
}