#include<iostream>
#include<queue>
#include<stack>
using namespace std;
template<class T>
struct BinaryNode
{
	
	BinaryNode<T>* _left;
	BinaryNode<T>* _right;
	T _data;
	BinaryNode(const T& d)
		:_data(d)
		, _left(NULL)
		, _right(NULL)
	{}
};
template<class T>
class BinaryTree
{
public:
	BinaryTree()
		:_root(NULL)
	{}
	BinaryTree(const T* t, size_t size,const T invalue)
	{
		T index = 0;
		_root = _GreateTree(t,size,invalue,index);
	}
	BinaryTree(const BinaryTree<T>& t)
	{
		_root = _Copy(t._root);
	}
	BinaryTree<T>& operator=(BinaryTree<T> b)
	{
		swap(_root, b._root);
		return *this;
	}
	void PrevOder()
	{
		/*_PrevOder(_root);*/
		_PrevOder_NonR(_root);
		cout << endl;
	}
	void InOder()
	{
		/*_InOder(_root);*/
		_InOder_NoR(_root);
		cout << endl;
	}
	void PostOder()
	{
		/*_PostOder(_root);*/
		_PostOder_NoR(_root);
		cout << endl;
	}
	void LevelOder()
	{
		_LevelOder(_root);
		cout << endl;
	}
	size_t Size()
	{
		return _Size(_root);
	}
	size_t Depth()
	{
		return _Depth(_root);
	}
	size_t LeafSize()
	{
		return _LeafSize(_root);
	}
	~BinaryTree()
	{
		_Destory(_root);
	}
protected:
	//叶子节点的数目
	size_t _LeafSize(BinaryNode<T>* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		else
		{
			size_t size = 0;
			if ((root->_left == NULL) && (root->_right == NULL))
			{
				size = 1 + _LeafSize(root->_left);
				size = size + _LeafSize(root->_right);
			}
			else
			{
				size += _LeafSize(root->_left);
				size += _LeafSize(root->_right);
			}
			return size;
		}
	}
	//拷贝二叉树
	BinaryNode<T>* _Copy(const BinaryNode<T>* root)
	{
		BinaryNode<T>* cur = NULL;
		if (root != NULL)
		{
			cur = new BinaryNode<T>(root->_data);
			cur->_left = _Copy(root->_left);
			cur->_right = _Copy(root->_right);
		}
		return cur;
	}
	//二叉树的销毁
	void _Destory(BinaryNode<T>* root)
	{
		if (root == NULL)
		{
			return;
		}
		BinaryNode<T>* cur = root;
		_Destory(root->_left);
		_Destroy(root->_right);
		delete cur;
	}
	//二叉树的创建
	BinaryNode<T>* _GreateTree(const T* t,size_t size,const T& invalue, T& index)
	{
		BinaryNode<T>* cur=NULL;
		
		if ((index<size)&&(t[index] != invalue))
		{
			cur = new BinaryNode<T>(t[index]);
			cur->_left = _GreateTree(t, size, invalue, ++index);
			cur->_right = _GreateTree(t, size, invalue, ++index);
		}
		return cur;
	}
	void _PrevOder(BinaryNode<T>* root) //前序遍历
	{
		if (root == NULL)
		{
			return;
		}
		else
		{
			//先根，后左，再右
			cout << root->_data << ' ';
			_PrevOder(root->_left);
			_PrevOder(root->_right);
		}
	}
	void _InOder(BinaryNode<T>* root) //中序遍历
	{
		if (root == NULL)
		{
			return;
		}
		else
		{
			//先左，后根，再右
			_InOder(root->_left);
			cout << root->_data << ' ';
			_InOder(root->_right);
		}
	}
	void _PostOder(BinaryNode<T>* root) //后序遍历
	{
		if (root == NULL)
		{
			return;
		}
		else
		{
			//先左，后右，再根
			_PostOder(root->_left);
			_PostOder(root->_right);
			cout << root->_data << ' ';
		}
	}
	void _PrevOder_NonR(BinaryNode<T>* root)//前序遍历（非递归）
	{
		if (root == NULL)
		{
			return;
		}
		stack<BinaryNode<T>*> s;
		s.push(root);
		
		while (!s.empty())
		{
			BinaryNode<T>* tmp = s.top();
			s.pop();
			cout << tmp->_data << ' ';
			if (tmp->_right)
			{
				s.push(tmp->_right);
			}
			if (tmp->_left)
			{
				s.push(tmp->_left);
			}
		}
	}
	void _InOder_NoR(BinaryNode<T>* root)//中序遍历（非递归）
	{
		if (root == NULL)
		{
			return;
		}
		stack<BinaryNode<T>*> s;
		s.push(root);
		BinaryNode<T>* cur = root;
		BinaryNode<T>* per = NULL;
		while (!s.empty())
		{
			while ((cur->_left)&&(cur!=per))
			{
				s.push(cur->_left);
				cur = cur->_left;
			}
			cur = s.top();
			cout << cur->_data << ' ';
			per = cur;
			s.pop();
			
			if (cur->_right)
			{
				s.push(cur->_right);
				cur = cur->_right;
			}
		}
	}
	void _PostOder_NoR(BinaryNode<T>* root)//后序遍历（非递归）
	{
		if (root == NULL)
		{
			return;
		}
		stack<BinaryNode<T>*> s;
		BinaryNode<T>* cur = root;
		BinaryNode<T>* pre = root;
		s.push(root);
		while (!s.empty())
		{
			
			while ((cur->_left)&&(cur->_left!=pre))
			{
				if (cur->_right == pre)
					break;
				s.push(cur->_left);
				cur = cur->_left;
			}
			if ((cur->_right)&&(cur->_right!=pre))
			{
				s.push(cur->_right);
				cur = cur->_right;
			}
			if ((cur->_left == NULL&&cur->_right == NULL) || (cur->_left == pre || cur->_right == pre))
			{
				
				cout << cur->_data << ' ';
				pre = cur;
				s.pop();
				if (s.size())
				{
					cur = s.top();
				}
			}
		}

	}
	//层序遍历
	void _LevelOder(BinaryNode<T>* root)
	{
		queue<BinaryNode<T>*> q;
		q.push(root);
		while (q.size())
		{
			BinaryNode<T>* tmp = q.front();
			cout << tmp->_data << ' ';
			q.pop();
			if (tmp->_left)
				q.push(tmp->_left);
			if (tmp->_right)
				q.push(tmp->_right);
		}
	}
	size_t _Size(BinaryNode<T>* root)  //树的大小
	{
		if (root == NULL)
		{
			return 0;
		}
		else
		{
			size_t count = 1;
			count += _Size(root->_left);
			count += _Size(root->_right);
			return count;
		}
	}
	//树的深度
	size_t _Depth(BinaryNode<T>* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		else
		{
			size_t left = 1;
			size_t right = 1;
		    left += _Depth(root->_left);
			right += _Depth(root->_right);
		
			
			return left>right?left:right;
		}
	}
private:
	BinaryNode<T>* _root;
};
int main()
{
	int c[21] = { 1, 2, '#', 3, '#', '#', 4, 5, '#', 6, '#', 7, '#', '#', 8, 9, '#', '#', 10, '#', '#' };
	BinaryTree<int> b1(c,21, '#');
	b1.PrevOder();
	b1.InOder();
	b1.PostOder();
	b1.LevelOder();
	cout <<"LeafSize:"<< b1.LeafSize() << endl;
	cout <<"Size:"<< b1.Size() << endl;
	cout <<"Depth:"<< b1.Depth() << endl;
	BinaryTree<int> b2(b1);
	b2.PrevOder();
	BinaryTree<int> b3;
	b3 = b1;
	b3.PrevOder();
	system("pause");
	return 0;

}