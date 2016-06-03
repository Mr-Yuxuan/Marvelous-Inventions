#include<iostream>
using namespace std;
typedef int DataType;
#define CAPACITY 7
#define DEFULT_CAPACITY 3
class Sqlist
{
	friend ostream& operator<<(ostream& os, const Sqlist& s);
public:
	Sqlist(int capacity = DEFULT_CAPACITY)
		:_size(0)
		, _capacity(capacity)
		, _pdata(0)
	{
		_pdata = new DataType[_capacity];
	}
	Sqlist(const Sqlist& s)
		:_size(s._size)
		, _capacity(s._capacity)
	{
		_pdata = new DataType[_capacity];
		memcpy(_pdata, s._pdata, _size*sizeof(DataType));
	}
	~Sqlist()
	{
		if (_pdata != NULL)
		{
			delete[] _pdata;
		}
	}
public:
	DataType& operator[](int index)
	{
		return _pdata[index-1];
	}
	void Insert(int pos, const DataType& d)
	{
		Checkcapacity();
		int i = 0;
		for (i = _size; i >= _size - pos-1; i--)
		{
			_pdata[i] = _pdata[i - 1];
		}
		_pdata[pos - 1] = d;
		_size++;
	}
	void Reverse()
	{
		DataType* start=_pdata;
		DataType* end = _pdata + _size-1;
		while (start < end)
		{
			DataType tmp = *start;
			*start = *end;
			*end=tmp;
			start++;
			end--;
		}
		
	}
	void Remove(const DataType& d)
	{
		int ret = Find(d);
		if (ret == -1)
		{
			cout << "要删除的值不在顺序表中" << endl;
		}
		else
		{
			int i = ret;
			for (i = ret; i < _size; i++)
			{
				_pdata[i] = _pdata[i + 1];
			}
			_size--;
		}
	}
	int Find(const DataType& d)
	{
		int i = 0;
		for (i = 0; i < _size; i++)
		{
			if (d == _pdata[i])
			{
				cout << "Find!" << endl;
				return i;
			}
		}
		cout << "NO Find!" << endl;
		return -1;
	}
	void PopBack()
	{
		_size--;
	}
	void PopFront()
	{
		int i = 0;
		for (i = 0; i < _size; i++)
		{
			_pdata[i] = _pdata[i + 1];
			
		}
		_size--;
	}
	void PushBack(const DataType& d)
	{
		Checkcapacity();
		_pdata[_size] = d;
		_size++;
	}
	void PushFront(const DataType& d)
	{
		Checkcapacity();
		int i = _size;
		for (i = _size; i > 0; i--)
		{
			_pdata[i] = _pdata[i - 1];
		}
		_pdata[0] = d;
		_size++;
	}
public:
	void Checkcapacity()
	{
		if (_size == _capacity)
		{
			DataType *tmp = _pdata;
			_pdata = new DataType[_capacity + CAPACITY];
			memcpy(_pdata, tmp, _size*sizeof(DataType));
			_capacity = _capacity + CAPACITY;
		}
	}
private:
	DataType *_pdata;
	int _size;
	int _capacity;
};
ostream& operator<<(ostream& os, const Sqlist& s)
{
	int i = 0;
	for (i = 0; i < s._size; i++)
	{
		os << s._pdata[i]<<" ";
	}
	os<< endl;
	return os;
}
int main()
{
	Sqlist s(3);
	s.PushBack(1);
	s.PushBack(2);
	s.PushBack(3);
	s.PushBack(4);
	s.PushBack(5);
	s.PushBack(6);
	s.PushFront(7);
	s.PopBack();
	s.PopFront();
	s.Find(8);
	s.Remove(8);
	s.Reverse();
	s.Insert(2, 8);
	s[2] = 1;
	cout << s;
	system("pause");
	return 0;
}