#pragma once
#define  _CRT_SECURE_NO_WARNINGS 1

#include"Heap.hpp"
#include"HuffamTree.hpp"
#include<string>
#define FileC "Input.BIG"
#define SET "SettingFile.txt"
using namespace std;
typedef long long LongType;
struct CharInfor
{
	CharInfor(LongType count=0)
	:count(count)
	, _ch(0)
	{}
	unsigned char _ch;
	LongType count;
	string _code;
	/*bool operator>(CharInfor ci) const
	{
		return count > ci.count ? 1 : 0;
	}*/
	bool operator<=(const CharInfor& ci) const 
	{
		return count <= ci.count ? 1 : 0;
	}
	bool operator==(const CharInfor& ci) const
	{
		if (count == ci.count)
			return true;
		return false;
	}
	 LongType operator+(const CharInfor& ci)
	{
		return count + ci.count;
	}
};
class HuffamCompress
{
public:
	HuffamCompress()
	{
		for (size_t i = 0; i < 256; ++i)
		{
			_infor[i]._ch = i;
			_infor[i].count = 0;
		}
		
	}
	
	void FileCompress(const char* fc)
	{
		FILE* _fc = fopen(fc, "rb");
		size_t _count = 0;
		unsigned char fread = fgetc(_fc);
		while (!feof(_fc))
		{
			
			_infor[fread].count++;
			fread = fgetc(_fc);
		}
		CharInfor invalid;
		HuffamTree<CharInfor> _huf(_infor, 256, invalid);
		_count = _huf._root->_weight.count;
		string s;
		GreatCode(_huf._root,s);
		FILE* fcc = fopen("FileCo.hum", "wb");
		if (fcc == NULL)
		{
			cout << ferror(fcc) << endl;

		}
		rewind(_fc);
		fread = fgetc(_fc);
		char* str = (char*)_infor[fread]._code.c_str();
		unsigned char c = 0;
		int size = 0;
		while (!feof(_fc))
		{
			 while (*str != '\0'&&size!=8)
			{
				if (*str == '0')
					++size;
				else
				{
					c |= 1 << (7 - size);
					++size;
				}
				str++;
			}
			if (size == 8)
			{
				fputc(c, fcc);
				size = 0;
				c = 0;
			}
			if (*str == '\0')
			{
				fread = fgetc(_fc);
				str = (char*)_infor[fread]._code.c_str();
			}
		}
		if (size != 0)
			fputc(c, fcc);
		FILE* set = fopen("SettingFile.txt", "wb");
		for (size_t i = 0; i < 256; ++i)
		{
			if (_infor[i].count != 0)
			{
				char s[100];
				char* str = _itoa(_infor[i].count, s, 10);
				fputc(_infor[i]._ch, set);
				fputc(':', set);
				fputs(str, set);
				fputc('\n', set);
			}
		}
		
		fclose(set);
		fclose(_fc);
		fclose(fcc);
		return;
	}
	void GreatCode(HuffamTreeNode<CharInfor>* _root, string s)
	{
		if (_root==NULL)
			return;
		if (_root->_left == NULL&&_root->_right == NULL)
		{
			_root->_weight._code = (char*)s.c_str();
			_infor[_root->_weight._ch]._code = (char*)s.c_str();
		}
		GreatCode(_root->_left, s + '0');
		GreatCode(_root->_right, s + '1');
		

	}
	bool GetLine(FILE* fset, string& str)
	{
		unsigned char c = fgetc(fset);
		if (feof(fset))
			return false;
		
		if (c == '\n')
		{
			str += c;
			c = fgetc(fset);
		}
		while (c != '\n')
		{
			str += c;
			c = fgetc(fset);
		}
		return true;
	}
	void UnCompress(const char *fuc)
	{
		FILE* fset = fopen(fuc, "rb");
		string str;
		while (GetLine(fset,str))
		{
			//__Trace(str.c_str());
			_infor[(unsigned char)str[0]].count = atoi((char*)str.c_str() + 2);
			str.clear();
		}
		CharInfor invalid;
		HuffamTree<CharInfor> _hu(_infor, 256, invalid);
		size_t count = _hu._root->_weight.count;
		
		FILE *fc = fopen("FileCo.hum", "rb");
		FILE *fucc = fopen("FileUc.BIG", "wb");
		int index = 7;
		unsigned char ch = fgetc(fc);
		unsigned char t = 1;
		
		HuffamTreeNode<CharInfor>* cur = _hu._root;
		while (1)
		{
            while ((index + 1) && count != 0)
			{
				//»Øµ½root
			    t = ch&(t << index--);
				if (t == 0)
				{
					cur = cur->_left;
					t = 1;
				}
				else 
				{
					cur = cur->_right;
					t = 1;
				}
				if ((cur->_left == NULL) && (cur->_right == NULL))
				{
					fputc(cur->_weight._ch, fucc);
					count--;
					cur = _hu._root;
				}
			}
			if (index+1 == 0)
			{
				ch = fgetc(fc);
				
				index = 7;
				
			}
			if (count == 0)
				break;
		}
		fclose(fset);
		fclose(fc);
		fclose(fucc);
	}
	
protected:
	CharInfor _infor[256];
};
void test3()
{
	HuffamCompress s;
	s.FileCompress(FileC);
	
}
void test4()
{
	HuffamCompress s1;
	s1.UnCompress(SET);

}