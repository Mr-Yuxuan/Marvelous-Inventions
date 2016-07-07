#pragma once
#include<iostream>
#include<vector>
#include<assert.h>


using namespace std;
template<class T>
class MinHeap
{
public:
	MinHeap()
	{}
	MinHeap(T* a, size_t size)
	{
		for (size_t i = 0; i < size; ++i)
		{
			_hp.push_back(a[i]);
		}
		for (int i =(_hp.size()-2)/2 ; i>=0 ; --i)
		{
			_AdDone(i);
		}
	}
	void Pop()
	{
		swap(_hp[0], _hp[_hp.size()-1]);
		_hp.pop_back();
		_AdDone(0);
		return;
	}
	void PushBack(T value)
	{
		_hp.push_back(value);
		for (int i = _hp.size() - 1; i > 0; i = (i - 1) / 2)
		{
			_AdUp(i);
		}
		return;
	}
	T Top()
	{
		assert(!_hp.empty());
		return _hp[0];
	}
	int Size()
	{
		return _hp.size();
	}
protected:
	void _AdUp(int child)
	{
		int parent = (child - 1) / 2;
		
		if (_hp[child] < _hp[parent])
		{
			swap(_hp[child], _hp[parent]);
		}
		return;
	}
	void _AdDone(size_t parent)
	{
		int child = parent * 2 + 1;
		while ((parent < _hp.size())&&(child<_hp.size()))
		{
			if ((child+1<_hp.size())&&(_hp[child] > _hp[child + 1]))
				child += 1;
			if (_hp[child] < _hp[parent])
			{
				swap(_hp[child], _hp[parent]);
			}
			parent = child;
			child = parent * 2 + 1;

		}
		return;
	}
protected:
	vector<T> _hp;
};
void test1()
{
	int a[] = { 10, 11, 13, 12, 16, 18, 15, 17, 14, 9 };
	MinHeap<int> hp(a, 10);
	hp.PushBack(3);
	return;
}