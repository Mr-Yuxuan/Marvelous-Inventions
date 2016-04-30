#include<iostream>
#include<assert.h>
using namespace std;
template<class T>
struct Stack
{
public:
	Stack()
		:_a(NULL)
		, _top(0)
		, _capacity(0)
	{}
	Stack(const Stack<T>& s)
	{
		_a = new T[s._top];
		for (size_t i = 0; i < s._top; i++)
		{
			_a[i] = s._a[i];
		}
		_top = s._top;
		_capacity = _top;
	}
	Stack<T>& operator=(Stack<T> s)
	{
		if (this != &s._a)
		{
			swap(_a, s._a);
			_top = s._top;
			_capacity = s._capacity;
		}
		return *this;
	}
	~Stack()
	{
		if (_a)
		{
			delete[] _a;
		}
	}
	void Pop()
	{
		assert(_top > 0);
		_top--;
	}
	void Push(const T& d)
	{
		_CheckCapacity();
		_a[_top++]= d;
	}
	T& Top()
	{
		return _a[_top - 1];
	}
	bool Empty()
	{
		return (_a == NULL);
	}
	size_t Size()
	{
		return _top;
	}
public:
	T* _a;
	size_t _top;
	size_t _capacity;
protected:
	void _CheckCapacity()
	{
		if (_a==NULL)
		{
			_capacity = 3;
			_a = new T[_capacity];
		}
		if (_top == _capacity)
		{
			_capacity = 2 * _capacity;
			T* tmp = new T[_capacity];
			for (size_t i = 0; i < _top; i++)
			{
				tmp[i] = _a[i];
			}
			delete[] _a;
			_a = tmp;
		}
	}
};
template<class T>
class Queue
{
public:
	void Push(const T& d)
	{
		s1.Push(d);
		return;
	}
	void Pop()
	{
		if (!s2.Empty())
		{
			s2.Pop();
		}
		else if (s2.Empty() && !s1.Empty())
		{
			size_t n = s1.Size();
			while (n - 1)
			{
				T tmp = s1.Top();
				s2.Push(tmp);
				s1.Pop();
				cout << s2.Top() << ' ';
				n--;
			}

			s1.Pop();

		}
		else
			return;
	}

protected:
	Stack<T> s1;
	Stack<T> s2;
};
int main()
{
	/*Stack<int> s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	size_t e = s.Size();
	for (size_t i = 0; i < e; i++)
	{
		cout << (s.Top())<<' ';
		s.Pop();
	}*/
	Queue<int> q1;
	q1.Push(1);
	q1.Push(2);
	q1.Push(3);
	q1.Push(4);
	q1.Pop();
	q1.Pop();
	system("pause");
	return 0;
}