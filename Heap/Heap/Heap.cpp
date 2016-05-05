#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;
template<class T>
class Heap
{
public:
	Heap()
	{}
	Heap(const T* a,const size_t size)
	{
		for (size_t i = 0; i < size; ++i)
		{
			_a.push_back(a[i]);
		}
		for (int i = (_a.size() - 2) / 2; i >= 0; --i)
		{
			_AdDone(i);
		}
	}
	//插入
	void Push(const size_t x)
	{
		_a.push_back(x);
		for (int i = _a.size()-1; i > 0; i = (i - 1) / 2)
		{
			_AdUp(i);
		}
	}
	//删除
	void Pop()
	{
		assert(!_a.empty());
		swap(_a[_a.size() - 1], _a[0]);
		_a.pop_back();
		_AdDone(0);
	}
protected:
	//向上调整
	void _AdUp(size_t child)
	{
		size_t parent = (child - 1) / 2;
		if (_a[child] > _a[parent])
		{
			swap(_a[child], _a[parent]);
		}
		return;
	}
	//向下调整
	void _AdDone(size_t parent)
	{
		
		while (parent < _a.size())
		{
			size_t child = 2 * parent + 1;
			if (child+1<_a.size()&&_a[child] < _a[child+1])
			{
				++child;
			}
			if (child < _a.size() && _a[child]>_a[parent])
			{
				swap(_a[child], _a[parent]);
			}
			parent = child;
		}
		return;
	}
protected:
	vector<T> _a;
};
int main()
{
	int arr[] = { 10, 11, 13, 12, 16, 18, 15, 17, 14, 19 };
	Heap<int> m(arr, sizeof(arr) / sizeof(arr[0]));
	m.Push(20);
	m.Pop();
	return 0;
}