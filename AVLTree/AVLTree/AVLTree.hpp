#pragma once
#include<iostream>
using namespace std;
template<class K,class V>
struct AVLTreeNode
{
	K _key;
	V _value;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	int _bf;
	AVLTreeNode(const K& key,const V& value)
		:_key(key)
		, _value(value)
		, _left(NULL)
		, _right(NULL)
		, _parent(NULL)
		, _bf(0)
	{}
};
template<class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	AVLTree()
		:_root(NULL)
	{}
	bool Insert(const K& key, const V& value)
	{
		if (_root == NULL)
		{
			_root = new Node(key, value);
			return true;
		}
		Node* parent = NULL;
		Node* cur = _root;
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
		if (parent->_key >key)
		{
			parent->_left = cur;
			cur->_parent = parent;
			
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
			
		}
		while (parent) 
		{
			if (cur == parent->_left)
			{
				parent->_bf--;
			}
			else if (cur == parent->_right)
			{
				parent->_bf++;
			}
			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				if (parent->_bf == 2)
				{
					if (cur->_bf == 1)
						_RoateL(parent);
					else
					_RoateRL(parent);
				}
				if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
						_RoateR(parent);
					else
						_RoateLR(parent);
				}
				break;
			}
			cur = parent;
			parent = parent->_parent;
	     }
		return true;
	}
	void InOder()
	{
		_InOder(_root);
		cout << endl;
		return;
	}
	bool IsBlance()
	{
		return _IsBlance(_root);
	}

protected:
	int Height(Node* root)
	{
		if (root == NULL)
			return 0;
		
		int left = Height(root->_left);
		int right = Height(root->_right);
		return left < right ? right + 1 : left + 1;
	}
	bool _IsBlance(Node* root)
	{
		if (root == NULL)
			return true;
		int left = Height(root->_left);
		int right = Height(root->_right);
		if (right - left != root->_bf)
		{
			cout << root->_key << endl;
			return false;
		}
		else
			return _IsBlance(root->_left) && _IsBlance(root->_right);

	}
	void _InOder(Node*& root)
	{
		if (root == NULL)
			return;
		_InOder(root->_left);
		cout << root->_key << " ";
		_InOder(root->_right);
		
	}
	void _RoateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		Node* ppNode = parent->_parent;
		parent->_right = subRL;
		subR->_left = parent;
		if (subRL)
			subRL->_parent = parent;
		parent->_parent = subR;
		if (ppNode == NULL)
		{
			_root = subR;
		}
        else if (ppNode->_left == parent)
			ppNode->_left = subR;
		else
			ppNode->_right = subR;
		subR->_parent = ppNode;
		subR->_bf = parent->_bf = 0;
		return;

	}
	void _RoateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		Node* ppNode = parent->_parent;
		parent->_left = subLR;
		subL->_right = parent;
		if (subLR)
			subLR->_parent = parent;
		parent->_parent = subL;
		if (ppNode == NULL)
		{
			_root = subL;
		}
		else if (ppNode->_left == parent)
			ppNode->_left = subL;
		else
			ppNode->_right = subL;
		subL->_parent = ppNode;
		subL->_bf = parent->_bf = 0;
		return;
	}
	void _RoateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;
		_RoateL(parent->_left);
		_RoateR(parent);
		if (bf == 1)
		{
			subL->_bf = -1;
			parent->_bf = 0;
		}
		else if (bf == -1)
		{
			subL->_bf = 0;
			parent->_bf = 1;
		}
	}
	void _RoateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;
		_RoateR(parent->_right);
		_RoateL(parent);
		if (bf == 1)
		{
			subR->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == -1)
		{
			subR->_bf = 1;
			parent->_bf = 0;
		}
	}



protected:
	Node* _root;
};