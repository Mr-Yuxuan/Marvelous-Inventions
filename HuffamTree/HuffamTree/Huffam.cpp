#pragma once
#include<iostream>
#include"HeapOfMin.hpp"
using namespace std;
template<class T>
struct HuffamTreeNode
{
	HuffamTreeNode<T>* _left;
	HuffamTreeNode<T>* _right;

	T _weight;
	HuffamTreeNode(const T v)
		:_left(NULL)
		, _right(NULL)
		, _weight(v)
	{}
	bool operator<(HuffamTreeNode<T> ci)
	{
		return _weight < ci._weight ? 1 : 0;
	}


};
template<class T>
class HuffamTree{
	typedef HuffamTreeNode<T> Node;
public:

	HuffamTree(T* a, size_t size, T invalte)
	{
		MinHeap<Node*> _hp;
		for (size_t i = 0; i<size; ++i)
		{
			if (a[i] == invalte)
				continue;
			_hp.PushBack(new Node(a[i]));
		}
		while (_hp.Size()>1)
		{
			Node* child1 = _hp.Top();
			_hp.Pop();
			Node* child2 = _hp.Top();
			_hp.Pop();
			Node* parent = new Node(child1->_weight + child2->_weight);
			parent->_left = child1;
			parent->_right = child2;
			_hp.PushBack(parent);

		}
		_root = _hp.Top();
	}

	bool Empty()
	{
		if (root == NULL)
			return true;
		return false;
	}

	Node* _root;
};