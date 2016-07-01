#pragma once
#include<iostream>
using namespace std;
template<class K,class V>
struct BSTreeNode
{
	K _key;
	V _value;
	BSTreeNode<K, V>* _left;
	BSTreeNode<K, V>* _right;
	BSTreeNode(const K& key,const V& value)
		:_key(key)
		, _value(value)
		,_left(NULL)
		, _right(NULL)
		
	{}

};
template<class K,class V>
class BSTree
{
	typedef BSTreeNode<K, V> Node;
public:
	BSTree()
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
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}
		if (parent->_key >key)
		{
			parent->_left = new Node(key, value);
		}
		else
		{
			parent->_right = new Node(key, value);
		}
		return true;
	}
	bool InsertR(const K& key, const V& value)
	{
		return _InsertR(_root, key, value);
	}
	void InOder()
	{
		_InOder(_root);
		cout << endl;
		return;
	}
	Node* Find(const K& key)
	{
		if (_root == NULL)
			return NULL;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key>key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}
		return cur;
	}
	Node* FindR(const K& key)
	{
		return _FindR(_root, key);
	}
	bool Remove(const K& key)
	{
		if (_root == NULL)
			return false;
		Node* parent = NULL;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
				break;
		}
		if (cur == NULL)
			return false;
		else
		{
			if (cur->_left == NULL)
			{
				if (parent == NULL)
				{
					_root = cur->_right;
				}
				else
				{
					if (parent->_left == cur)
					{
						parent->_left = cur->_right;
					}
					else
					{
						parent->_right = cur->_right;
					}
				}
				delete cur;
			}
			else if (cur->_right == NULL)
			{
				if (parent == NULL)
				{
					_root = cur->_left;
				}
				else
				{
					if (parent->_left == cur)
					{
						parent->_left = cur->_left;
					}
					else
					{
						parent->_right = cur->_left;
					}
				}
				delete cur;
			}
			else
			{
				parent = cur;
				Node* subL = cur->_right;
				while (subL->_left)
				{
					parent = subL;
					subL = subL->_left;
				}
				swap(subL, cur);
				parent->_left = cur->_right;
				delete cur;
			}
			return true;
		}
	}
	bool RemoveR(const K& key)
	{
		return _RemoveR(_root, key);
	}
	void ToMirror()
	{
		_ToMirror(_root);
		return;
	}
	bool IsBlanceTree()
	{
		return _IsBlanceTree(_root);
	}
	bool _IsBlanceTree(Node* root)
	{
		if (root == NULL)
			return true;
		int left = Hight(root->_left);
		int right = Hight(root->_right);
		if (abs(left - right) > 1)
		{
			return false;
		}
		return true;
	}
protected:
	int Hight(Node* root)
	{
		if (root == NULL)
			return 0;
		int left =1+ Hight(root->_left);
		int right =1+ Hight(root->_right);
		return left > right ? left : right;
	}
	void _ToMirror(Node* root)
	{
		if (root == NULL)
			return;
		swap(root->_left, root->_right);
		_ToMirror(root->_left);
		_ToMirror(root->_right);
	}
	bool _RemoveR(Node*& root, const K& key)
	{
		if (root == NULL)
			return false;
		if (root->_key == key)
		{
			Node* cur = root;
			if (root->_left == NULL)
			{
				root = root->_right;
			}
			else if (root->_right==NULL)
			{
				root = root->_left;
			}
			else
			{
				Node* subL = cur->_right;
				while (subL->_left)
				{
					root = subL;
					subL = subL->_left;
				}
				swap(cur, subL);
				root->_left = cur->_right;
			}
			delete cur;
			return true;
		}
		if (root->_key > key)
		{
			return _RemoveR(root->_left, key);
		}
		if (root->_key < key)
		{
			return _RemoveR(root->_right, key);
		}
	}
	Node* _FindR(Node* root, const K& key)
	{
		if (root == NULL||root->_key==key)
			return root;
		if (root->_key < key)
			return _FindR(root->_right, key);
		if (root->_key>key)
			return _FindR(root->_left, key);
	

	}
	bool _InsertR(Node*& root, const K& key, const V& value)
	{
		if (root == NULL)
		{
			root = new Node(key, value);
			return true;
		}
		if (root->_key == key)
			return false;
		if (root->_key > key)
			return _InsertR(root->_left, key, value);
		if (root->_key < key)
			return _InsertR(root->_right, key, value);

	}
	void _InOder(Node* root)
	{
		if (root == NULL)
			return;
		_InOder(root->_left);
		cout << root->_key << " ";
		_InOder(root->_right);
	
	}
protected:
	Node* _root;
};