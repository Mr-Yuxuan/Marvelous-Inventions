#pragma once
#include<iostream>
#include"Heap.hpp"
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
	bool operator<=(HuffamTreeNode<T> ci) const
	{
		return _weight <= ci._weight ? 1 : 0;
	}
	

};
template<class T>
class HuffamTree{
	typedef HuffamTreeNode<T> Node;
public:
	
	HuffamTree(T* a,size_t size,T invalte)
	{
		Node** tmp = new Node*[size];
		int index = 0;
		/*Heap<Node*,NodeCom_Less> _hp;*/
		for (size_t i = 0; i<size; ++i)
		{
			if (a[i] == invalte)
				continue;
			tmp[index++]=new Node(a[i]);
		}
		Heap<Node*, NodeCom_Less> _hp(tmp, index);
		while (_hp.Size()>1)
		{
			Node* child1 = _hp.Top();
			_hp.Pop();
			Node* child2 = _hp.Top();
			_hp.Pop();
			Node* parent = new Node(child1->_weight + child2->_weight);
			parent->_left = child1;
			parent->_right = child2;
			_hp.Push(parent);

		}
		_root = _hp.Top();
	}
	
	bool Empty()
	{
		if (root == NULL)
			return true;
		return false;
	}
	struct NodeCom_Less
	{
		bool operator()(const Node* l,const Node* r) const
		{
			return l->_weight <= r->_weight;
		}
	};
	Node* _root;
};
void test2()
{
	int a[] = { 10, 11, 13, 12, 16, 18, 15, 17, 14, 9 };
	/*HuffamTree<int> hp(a, 10);*/
	
	return;
}