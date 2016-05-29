#define _CRT_SECURE_NO_WARNINGS
//传统写法
//#include<iostream>
//
//using namespace std;
//class String
//{
//public:
//	String(char *str = "")
//		:_str(new char[strlen(str)+1])
//	{
//		strcpy(_str, str);
//	}
//	String(const String &str)
//	{
//		
//			delete[] _str;
//			_str = new char[strlen(str._str) + 1];
//			strcpy(_str, str._str);
//		
//		
//	}
//	String& operator=(const String& str)
//		
//	{
//		if (this != &str)
//		{
//			delete[] _str;
//			_str = new char[strlen(str._str) + 1];
//			strcpy(_str, str._str);
//		}
//		return *this;
//	}
//	~String()
//	{
//		delete[] _str;
//      _str = NULL;
//	}
//private:
//	char *_str;
//};
//
//int main()
//{
//	String str1("abc");
//	String strl2(str1);
//	String str3;
//	str3 = strl2;
//	return 0;
//}
//现代写法
#include<iostream>
#include<assert.h>
using namespace std;
int my_strlen(const char *src)
{
	int count = 0;
	while (*src)
	{
		count++;
		src++;
	}
	return count;
}
void my_strcpy(char *dest,const char *src)
{
	assert(src);
	char *q = dest;

	while (*q = *src)
	{
		q++;
		src++;
	}
}
class String
{
public:
	String(char *str = "")
		:_str(new char[strlen(str) + 1])
	{
		strcpy(_str, str);
	}
	String(const String& str)
		:_str(NULL)
	{
		String tmp(str._str);
		swap(_str, tmp._str);
	}
	String& operator=( String str)

	{
		swap(_str, str._str);
		return *this;
	}
	~String()
	{
		delete[] _str;
	}
public:
	bool operator==(const String &str)
	{
		
		char *q = _str;
		char *p = str._str;
		while (*q == *p)
		{
			q++;
			p++;
		}
		if ((*q == NULL)&&(*p==NULL))
			return true;
		else
			return false;
	}
	bool operator<(const String &str)
	{
		char *p = _str;
		char *q = str._str;
		if (p == q)
			return false;
		else
		{
			while (*p||*q)
			{
				if (*p < *q)
					return true;
				else if (*p == *q)
				{
					p++;
					q++;
				}
				else
					return false;
			}
		}
	}
	bool operator>(const String& str)
	{
		char *p = _str;
		char*q = str._str;
		if (p == q)
			return false;
		else
			return !(operator<(str));
	}
	void insert(int pos, char ch)
	{
		String tmp(_str);
		delete[] _str;
		char *p = tmp._str;
		int stl = my_strlen(p);
        _str = new char[stl+2];
		my_strcpy(_str, tmp._str);
		int i = 0;
		 for (; i <(stl+2-pos); i++)
		 {
			 _str[stl-i + 1] = _str[stl-i];
		 }
		 _str[pos-1] = ch;
	}
	void insert(int pos, char *str)
	{
		String tmp(_str);
		delete[] _str;
		char *q = tmp._str;
		char *p = str;
		int stl1 = my_strlen(q);
		int stl2 = my_strlen(p);
		int n = stl1 - stl2+1;
		int i = 0;
		int j = 0;
		_str = new char[stl1 + 1 + stl2];
		my_strcpy(_str, tmp._str);
		for (i=0; i <=n; i++)
		{
			_str[stl1+stl2 - i] = _str[stl1 - i];
		}
		for (j=0; j < stl2; j++)
		{
			_str[pos-1 + j] = *(str + j);
		}
	}
	void insert(int pos, const String& str)
	{
		String tmp(_str);
		delete[] _str;
		char *q = tmp._str;
		char *p = str._str;
		int stl1 = my_strlen(q);
		int stl2 = my_strlen(p);
		int n = stl1 - stl2 + 1;
		int i = 0;
		int j = 0;
		_str = new char[stl1 + 1 + stl2];
		my_strcpy(_str, tmp._str);
		for (i = 0; i <= n; i++)
		{
			_str[stl1 + stl2 - i] = _str[stl1 - i];
		}
		for (j = 0; j < stl2; j++)
		{
			_str[pos - 1 + j] = *(str._str + j);
		}
	}
	void PushBack(int ch)
	{
		String tmp(_str);
		delete[] _str;
		char *p = tmp._str;
		int stl = my_strlen(p);

		_str = new char[stl + 2];
		my_strcpy(_str, tmp._str);
		_str[stl+1] = _str[stl];
		_str[stl] = ch;
	}
	void Print()
	{
		cout << _str << endl;
	}
private:
	char *_str;
};

int main()
{
	String str1("a");
	String strl2("abc");
	strl2.PushBack('a');
	strl2.Print();
	strl2.insert(1, 's');
	strl2.Print();
	strl2.insert(2, "ft");
	strl2.Print();
	strl2.insert(2, str1);
	strl2.Print();
	String str3;
	bool b=(str1>strl2);
	system("pause");
	return 0;
}