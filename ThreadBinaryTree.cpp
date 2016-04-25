#include<iostream>
#include<assert.h>
using namespace std;
enum Threadtag
{
	THREAD,
	LINK
};
template<class T>
struct ThreadBinaryNode
{
	T _data;
	ThreadBinaryNode<T>* _left;
	ThreadBinaryNode<T>* _right;
	Threadtag  _lefttag;
	Threadtag  _righttag;
	ThreadBinaryNode()
	{}
	ThreadBinaryNode(const T& x)
	     :_data(x)
	     , _left(NULL)
		 , _right(NULL)
		 , _lefttag(LINK)
		 , _righttag(LINK)
	{}
};
template<class T>
class ThreadBinaryTree
{
public:
	ThreadBinaryTree(T *data, const size_t size, const T& invaliue )
	{
		size_t index = 0;
		_root = _ThreadBinaryTree(data, size, invaliue, index);
	}
	void PervoderThread()
	{
		ThreadBinaryNode<T>* pre = NULL;
		_PeroderTherad(_root,pre);
	}
//前序线索化遍历
	void PreThreadPrint()
	{
		ThreadBinaryNode<T>* cur = _root;
		while (cur)
		{
			cout << cur->_data << ' ';
			if (cur->_lefttag == LINK)
			{
				cur = cur->_left;
				continue;
			}
			if (cur->_lefttag == THREAD)
			{
				cur = cur->_right;
			}
		}
	}
	void InOderThread()
	{
		ThreadBinaryNode<T>* pre = NULL;
		_InOderThread(_root, pre);
	}
//中序线索化遍历
	void InThreadPrint()
	{
		ThreadBinaryNode<T>* cur = _root;
		while (cur)
		{
			while (cur->_left&&cur->_lefttag==LINK)
			{
				cur = cur->_left;
			}
			cout << cur->_data << ' ';
			if (cur->_righttag == THREAD)
			{
				cur = cur->_right;
				cout << cur->_data << ' ';
			}
			cur = cur->_right;
			
		}
	}
	void PostOderThread()
	{
		ThreadBinaryNode<T>* pre = NULL;
		_PostOderThread(_root, pre);
	}
	/*void PostThreadPrint()
	{
		ThreadBinaryNode<T>* cur1 = _root;
		ThreadBinaryNode<T>* cur2 = root;
		while (cur1)
		{
			while (cur1->_left&&cur1->_lefttag==LINK)
			{
				cur1 = cur1->_left;
			}
			
			cout << cur1->_data << ' ';
			if (cur->_righttag == THREAD)
			{
				cur = cur->_right;
				cout << cur->_data << ' ';
			}
		}
	}*/
protected:
	//后序线索化
	void _PostOderThread(ThreadBinaryNode<T>* root, ThreadBinaryNode<T>*& pre)
	{
		if (root == NULL)
			return;
		_PostOderThread(root->_left, pre);
		_PostOderThread(root->_right, pre);
		if (root->_left == NULL&&root->_lefttag != THREAD)
		{
			root->_lefttag = THREAD;
			root->_left = pre;

		}
		if (pre&&pre->_right == NULL)
		{
			pre->_righttag = THREAD;
			pre->_right = root;
			
		}
		pre = root;
	}
	//中序线索化
	void _InOderThread(ThreadBinaryNode<T>* root, ThreadBinaryNode<T>*& pre)
	{
		if (root == NULL)
			return;

		_InOderThread(root->_left, pre);
		if (root->_left == NULL&&root->_lefttag != THREAD)
		{
			root->_lefttag = THREAD;
			root->_left = pre;
		}
		if (pre&&pre->_right == NULL)
		{
			pre->_righttag = THREAD;
			pre->_right = root;
		}
		pre = root;
		_InOderThread(root->_right, pre);
		
	}
	//前序线索化
	void _PeroderTherad(ThreadBinaryNode<T>* root, ThreadBinaryNode<T>*& pre)
	{
		if (root == NULL)
		{
			return;
		}
		if (pre&&pre->_right==NULL)
		{
			pre->_righttag = THREAD;
			pre->_right = root;
        }
		if (root->_left)
		{
			pre = root;
		}
		_PeroderTherad(root->_left,pre);
		if (root->_left == NULL&&root->_lefttag != THREAD)
		{
			root->_lefttag = THREAD;
			root->_left = pre;
			pre = root;
		}
		if (root->_right&&root->_righttag!=THREAD)
		{
			_PeroderTherad(root->_right, pre);
		}
	}
	ThreadBinaryNode<T>* _ThreadBinaryTree(T* data, const size_t size, const T& invaliue, size_t& index)
	{
		assert(data);
		ThreadBinaryNode<T>* root = NULL;
		if ((index<size)&&(data[index] != invaliue))
		{
			root = new ThreadBinaryNode<T>(data[index]);
			root->_left = _ThreadBinaryTree(data, size, invaliue, ++index);
			root->_right = _ThreadBinaryTree(data, size, invaliue, ++index);
		}
		return root;
	}
	
private:
	ThreadBinaryNode<T>* _root;

};
int main()
 {
	int array[13] = { 1, 2, 3, '#', '#', 4, '#', '#', 5,6,'#','#','#'};
	int array1[17] = { 1, 2, '#', 3, '#', '#', 4, 5, '#', 6, '#', 7, '#', '#', 8,'#','#' };
	ThreadBinaryTree<int> t(array1, 17, '#');
	/*t.PervoderThread();*/
	
	/*t.PreThreadPrint();*/
	/*t.InOderThread();
	t.InThreadPrint();*/
	t.PostOderThread();
	t.PostThreadPrint();
	system("pause");
	return 0;
}