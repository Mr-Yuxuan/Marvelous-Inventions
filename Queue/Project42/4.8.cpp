#include<iostream>
using namespace std;
template<class T>
struct Node
{
	Node(const T& d)
	:_data(d)
	, _next(NULL)
	{}
    T _data;
	Node<T> *_next;
};
template<class T>
class Queue
{
public:
	Queue()
	:_head(NULL)
	, _tail(NULL)
	{}
	Queue(const Queue<T>& q)
	{
		Node<T>* cur = q._head;
		while (cur)
		{
			Push(cur->_data);
			cur = cur->_next;
		}
	}
	Queue<T>& operator=(const Queue<T>& q)
	{
		if (this != &q)
		{
			Node<T>* cur = q._head;
			if (_head == NULL)
			{
				while (cur)
				{
					Push(cur->_data);
					cur = cur->_next;
				}
			}
			else
			{
				Node<T>* del = _head;
				while (_head)
				{
					Pop();
				}
				while (cur)
				{
					Push(cur->_data);
					cur = cur->_next;
				}
			}
		}
		return *this;
	}
	bool Empty()
	{
		return (_head == NULL);
	}
	void Push(const T& d)
	{
		Node<T> *cur = new Node<T>(d);
		if (_head == NULL)
		{
			_head = cur;
			_tail = cur;
		}
		else
		{
			_tail->_next = cur;
			_tail = cur;
		}
	}
	void Pop()
	{
		if (_head == NULL)
			return;
		else
		{
			Node<T> *cur = _head;
			_head = _head->_next;
			delete cur;
		}
	}
	T& Front()
	{
		return (_head->_data);
	}
	T& Back()
	{
		return (_tail->_data);
	}
	size_t Size()
	{
		size_t size = 0;
		Node<T>* cur = _head;
		while (cur)
		{
			++size;
			cur = cur->_next;
		}
		return size;
	}
	void Print()
	{
		Node<T>* cur = _head;
		while (cur)
		{
			cout << (cur->_data) <<"->";
			cur = cur->_next;
		}
		cout << endl;
	}
	~Queue()
	{
		if (_head != NULL)
		{
			Node<T> *cur = _head;
			while (_head)
			{
				_head = _head->_next;
				delete cur;
				cur = _head;
			}
		}
	
	}
private:
	Node<T> *_head;
	Node<T> *_tail;
};
int main()
{
	Queue<int> q;
	
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	q.Push(5);
	q.Print();
	Queue<int> q6(q);
	Queue<int> q2;
	q2 = q;
	q2.Print();
	q6.Print();
	q.Pop();
	q.Print();
	system("pause");
	return 0;
}
