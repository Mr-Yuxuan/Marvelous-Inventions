#include<iostream>
#include<assert.h>
using namespace std;
enum Type
{
	HEAD,
	VALUE,
	SUB,
};
struct GeneralizeNode
{

	GeneralizeNode(Type type = HEAD, char value = 0)
	:_type(type)
	, _next(NULL)
	{
		if (type == VALUE)
		{
			_value = value;
		}
		else if (type == SUB)
		{
			_sublink = NULL;
		}
	}

	Type _type;
	GeneralizeNode* _next;
	union
	{
		char _value;
		GeneralizeNode* _sublink;
	};
};
class Generalized
{
public:
	Generalized()
		:_head(NULL)
	{

	}
	Generalized(const char* str)
		:_head(NULL)
	{
		_head = _GreateList(str);
	}
	Generalized(const Generalized& g)
	{
		_head = _Copy(g._head);

	}
	Generalized& operator=(const Generalized& g)
	{
		if (this != &g)
		{
			if (_head)
			{
				_Destory(_head);
			}
			_head = _Copy(g._head);
		}
		return *this;
	}
	~Generalized()
	{
		_Destroy(_head);
	}
	void Print()
	{
		_Print(_head);
		cout << endl;
	}
	size_t Size()
	{
		size_t count = _Size(_head);
		return count;
	}
	size_t Depth()
	{
		size_t deep = _Depth(_head);
		return deep;
	}
protected:
	//表的拷贝
	GeneralizeNode* _Copy(GeneralizeNode* head)
	{
		GeneralizeNode* newhead = new GeneralizeNode(HEAD);
		GeneralizeNode* cur = head;
		GeneralizeNode* tmp = newhead;

		while (cur)
		{
			if (cur->_type == VALUE)
			{
				tmp->_next = new GeneralizeNode(VALUE, cur->_value);
				tmp = tmp->_next;
				cur = cur->_next;
				continue;
			}
			else if (cur->_type == SUB)
			{
				tmp->_next = new GeneralizeNode(SUB);
				tmp = tmp->_next;
				tmp->_sublink = _Copy(cur->_sublink);
				cur = cur->_next;
			}
			else
				cur = cur->_next;
		}
		return newhead;
	}
	//表的销毁
	void _Destory(GeneralizeNode* head)
	{
		if (head != NULL)
		{
			GeneralizeNode* cur = head;
			GeneralizeNode* del = NULL;
			while (cur)
			{
				del = cur;
				if (cur->_type == SUB)
				{
					_Destory(cur->_sublink);
					cur = cur->_next;
					delete del;
				}
				cur = cur->_next;
				delete del;
			}
		}
	}
	//每个子表的深度
	size_t _DepthofEverySUB(GeneralizeNode* sub)
	{
		size_t deep = 1;
		GeneralizeNode* cur = sub;
		while (cur)
		{
			if (cur->_type == SUB)
			{
				deep += _DepthofEverySUB(cur->_sublink);
				cur = cur->_next;
			}
			else
				cur = cur->_next;
		}
		return deep;
	}
	//表的深度
	size_t _Depth(GeneralizeNode* head)
	{
		size_t deep = 1;
		size_t deepth = 0;
		GeneralizeNode* cur = head;
		while (cur)
		{
			if (cur->_type == SUB)
			{
				deep += _DepthofEverySUB(cur->_sublink);
				if (deepth < deep)
				{

					deepth = deep;
					deep = 1;
				}
				cur = cur->_next;
			}
			else
				cur = cur->_next;
		}
		return deepth;
	}
	//统计value
	size_t _Size(GeneralizeNode* head)
	{
		size_t count = 0;
		GeneralizeNode* cur = head;
		while (cur)
		{
			if (cur->_type == VALUE)
			{
				++count;
				cur = cur->_next;
			}
			else if (cur->_type == SUB)
			{
				count += _Size(cur->_sublink);
				cur = cur->_next;
			}
			else
			{
				cur = cur->_next;
			}
		}
		return count;
	}
	//检测字符
	bool _Value(const char& c)
	{
		if (((c <= '9') && (c >= '0')) || ((c <= 'z') && (c >= 'a')) || ((c <= 'Z') && (c >= 'A')))
			return true;
		else
			return false;
	}
	//构造函数
	GeneralizeNode* _GreateList(const char*& str)
	{
		assert(str&&*str == '(');
		++str;
		GeneralizeNode* head = new GeneralizeNode(HEAD);
		GeneralizeNode* cur = head;

		while (*str)
		{
			if (*str == '(')
			{
				cur->_next = new GeneralizeNode(SUB);
				cur = cur->_next;
				cur->_sublink = _GreateList(str);
			}
			else if (_Value(*str) == 1)
			{
				cur->_next = new GeneralizeNode(VALUE, *str);
				cur = cur->_next;
				++str;
				continue;

			}
			else if (*str == ')')
			{
				cur->_next = NULL;
				return head;
			}
			++str;
		}
		assert(false);
		return head;
	}
	//打印函数
	void _Print(GeneralizeNode* head)
	{
		GeneralizeNode* cur = head;
		while (cur)
		{
			if (cur->_type == HEAD)
			{
				cout << '(';
			}
			else if ((cur->_type == VALUE) && (cur->_next))
			{
				cout << cur->_value << ',';
			}
			else if ((cur->_type == VALUE) && (cur->_next == NULL))
			{
				cout << cur->_value;
			}
			else if ((cur->_type == SUB) && (cur->_next))
			{
				_Print(cur->_sublink);
				cout << ',';
			}
			else if ((cur->_type == SUB) && (cur->_next == NULL))
			{
				_Print(cur->_sublink);

			}
			cur = cur->_next;
		}
		cout << ')';

	}
protected:
	GeneralizeNode* _head;
};
int main()
{
	Generalized g("(a,(b,q),(a,s,(w,d)),c)");
	g.Print();
	size_t s = g.Size();
	cout << "Size:" << s << endl;
	size_t d = g.Depth();
	cout << "Deep:" << d << endl;
	Generalized g1(g);
	g1.Print();
	Generalized g2;
	g2 = g;
	g2.Print();
	system("pause");
	return 0;
}