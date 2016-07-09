#pragma once
#include<iostream>
using namespace std;
enum Color
{
	RED,
	BLACK,
};
template<class K,class V>
struct RBTreeNode
{
	K _key;
	V _value;
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	Color _color;
	RBTreeNode(const K& key, const V& value)
		: _key(key)
		, _value(value)
		, _left(NULL)
		, _right(NULL)
		, _parent(NULL)
		, _color(RED)
	{}
};
template<class K,class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	RBTree()
		:_root(NULL)
	{}
	bool Insert(const K& key, const V& value)
	{
		if (_root == NULL)
		{
			_root = new Node(key, value);
			_root->_color = BLACK;
			return true;
		}
			Node* cur = _root;
			Node* parent = NULL;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key>key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}
			cur = new Node(key, value);
			if (parent->_key > key)
			{
				parent->_left = cur;
				cur->_parent = parent;
			}
			else
			{
                parent->_right = cur;
				cur->_parent = parent;
			}
			while (cur!=_root&&cur->_color==RED)
			{
				if (parent->_color == RED)
				{
					Node* grandfather = parent->_parent;
					Node* uncle;

					if (grandfather->_left == parent)
						uncle = grandfather->_right;
					else
						uncle = grandfather->_left;
					if (uncle&&uncle->_color == RED)
					{
						parent->_color = uncle->_color = BLACK;
						grandfather->_color = RED;
						cur = grandfather;
						parent = grandfather->_parent;
					}
					else if (uncle == NULL || uncle->_color == BLACK)
					{
						if (parent == grandfather->_left)
						{
							if (cur == parent->_left)
							{
								_RvateR(grandfather);
								parent->_color = BLACK;
								grandfather->_color = RED;
							}
							else
							{
								_RvateLR(grandfather);
								swap(cur, parent);
								parent->_color = BLACK;
								grandfather->_color = RED;
							}
						}
						else
						{
							if (cur == parent->_right)
							{
								_RvateL(grandfather);
								parent->_color = BLACK;
								grandfather->_color = RED;
							}
							else
							{
								_RvateRL(grandfather);
								swap(cur, parent);
								parent->_color = BLACK;
								grandfather->_color = RED;
							}
						}
						break;
					}
				}
				break;
			}
			if (cur == _root)
				_root->_color = BLACK;
	}
	bool IsBlance()
	{
		Node* cur = _root;
		int count = 0;
		int countL = 0;
		while (cur)
		{
			if (cur->_color == BLACK)
				countL++;
			cur = cur->_left;
		}
		return _IsBlance(_root,countL,count);
	}
protected:
	bool _IsBlance(Node* root,int& countL,int count)
	{
		if (root == NULL)
		{
			if (countL == count)
				return true;
			else
				return false;
		}
		if (root->_color == BLACK)
			count++;
		return _IsBlance(root->_left, countL, count) && _IsBlance(root->_right, countL, count);
	}
	void _RvateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		Node* ppNode = parent->_parent;
		parent->_left = subLR;
		subL->_right = parent;
		if (subLR)
			subLR->_parent = parent;
		parent->_parent = subL;
		if (ppNode != NULL)
		{
			if (ppNode->_left == parent)
				ppNode->_left = subL;
			else
				ppNode->_right = subL;
			
		}
		else
			_root = subL;
		subL->_parent = ppNode;
		return;
	}
	void _RvateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		Node* ppNode = parent->_parent;
		parent->_right = subRL;
		subR->_left = parent;
		if (subRL)
			subRL->_parent = parent;
		parent->_parent = subR;
		if (ppNode != NULL)
		{
			if (ppNode->_left == parent)
				ppNode->_left = subR;
			else
				ppNode->_right = subR;
			
		}
		else
		{
			_root = subR;
		}
		subR->_parent = ppNode;
		return;
	}
	void _RvateRL(Node* parent)
	{
		_RvateR(parent->_right);
		_RvateL(parent);
		return;
	}
	void _RvateLR(Node* parent)
	{
		_RvateL(parent->_left);
		_RvateR(parent);
		return;
	}
protected:
	Node* _root;
};