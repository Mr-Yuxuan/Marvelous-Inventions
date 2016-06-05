#include<iostream>
#include<string>
using namespace std;

template<typename T>
class SeqList
{
public:
	SeqList()
		:_data(NULL)
		, _size(0)
		, _capacity(0)
	{}
	SeqList<T>& operator=(const SeqList<T>& s)
	{
		if (this != &s)
		{
			delete[] _data;
			_data = new T[s._capacity];
			_size = s._size;
			_capacity = s._capacity;
			/*memcpy(_data, s._data, _size*sizeof(T));*/
			int i = 0;
			for (i = 0; i < _size; i++)
			{
				_data[i] = s._data[i];
			}
		}
		return *this;
	}
	SeqList(const SeqList<T>& s)
		:_data(new T[s._capacity])
		, _size(s._size)
		, _capacity(s._capacity)
	{
		/*memcpy(_data, s._data, _size*sizeof(T));*/
		int i = 0;
		for (i = 0; i < _size; i++)
		{
			_data[i] = s._data[i];
		}
	}
	~SeqList()
	{
		if (_data != NULL)
		{
			delete[] _data;
			_size = 0;
			_capacity = 0;
		}

	}
public:
	void Pushback(const T& d)
	{
		CheckCapacity();
		_data[_size] = d;
		_size++;
	}
	void PopBack()
	{
		_size--;
	}
	void PushFornt(const T& d)
	{
		CheckCapacity();
		int i = _size;
		for (; i > 0; i--)
		{
			_data[i] = _data[i - 1];
		}
		_data[0] = d;
		_size++;
	}
	void PopFront()
	{
		int i = 0;
		for (; i < _size; i++)
		{
			_data[i] = _data[i + 1];
		}
		_size--;
	}
	void Insert(const int pos, const T& d)
	{
		CheckCapacity();
		int i = _size;
		for (; i>=pos; i--)
		{
			_data[i] = _data[i - 1];
		}
		_data[pos - 1] = d;
		_size++;
	}
	void Sort()
	{
		int n = _size;
		int i = 0;
		while (n--)
		{
			for (i=0; i < _size-1; i++)
			{
				if (_data[i]>_data[i + 1])
				{
					T tmp = _data[i];
					_data[i] = _data[i+1];
					_data[i+1] = tmp;
				}
			}
			
		}
	}
public:
	void CheckCapacity()
	{
		if (_size == _capacity)
		{
			T *tmp = new T[2 * _capacity + 3];
			memcpy(tmp, _data, _size*sizeof(T));
			/*int i = 0;
			for (i = 0; i < _size; i++)
			{
				tmp[i] = _data[i];
			}*/
			delete[] _data;
			_data = tmp;
			_capacity = 2 * _capacity + 3;
		}
	}
	void Print()
	{
		int i = 0;
		for (; i < _size; i++)
		{
			cout << _data[i] << " ";
		}
		cout << endl;
	}
private:
	T*_data;
	int _size;
	int _capacity;
};
int main()
{
	SeqList<string> s;
	s.Pushback("111");
	s.Pushback("222");
	s.Pushback("333");
	s.Pushback("444");
	s.Print();
	SeqList<string> s3(s);
	s.Print();
	SeqList<string> s2;
	s2 = s;
	s2.Print();
	system("pause");
	return 0;
}