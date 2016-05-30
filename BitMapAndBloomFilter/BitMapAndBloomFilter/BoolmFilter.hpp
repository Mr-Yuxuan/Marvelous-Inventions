#pragma once
#include"BitMap.hpp"
struct HashFunc1
{
	size_t operator()(const char* str)
	{
		register size_t hash = 0;
		while (size_t ch = (size_t)*str++)
		  {
			hash = hash * 131 + ch;
		  }
		  return hash;

	}
};
struct HashFunc2
{
	size_t operator()(const char* str)
	{
		register size_t hash = 0;
		 while (size_t ch = (size_t)*str++)
		   {
		     hash = 65599 * hash + ch;
		   }
		return hash;

	}
};
struct HashFunc3
{
	size_t operator()(const char* str)
	{
		register size_t hash = 0;
		size_t magic = 63689;
		while (size_t ch = (size_t)*str++)
		{
			  hash = hash * magic + ch;
			  magic *= 378551;
		}
		  return hash;

	}
};
struct HashFunc4
{
	size_t operator()(const char* str)
	{
		register size_t hash = 0;
		size_t ch;
		for (long i = 0; ch = (size_t)*str++; i++)
		  {
			if ((i & 1) == 0)
			{
				 hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
		    }
			 else
			{
				 hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
		    }
	     }
		 return hash;

	}
};
struct HashFunc5
{
	size_t operator()(const char* str)
	{
		if (!*str)          
		   return 0;
		 register size_t hash = 1315423911;
		  while (size_t ch = (size_t)*str++)
		  {
		       hash ^= ((hash << 5) + ch + (hash >> 2));
		   }
		    return hash;

	}
};

class BoolmFilter
{
public:
	BoolmFilter(long long size)
		:_bt(size),
		_campatiy(GetNextPrime(size))
	{}
	void Set(const string& k)
	{
		int index1 = HashFunc1()((char*)k.c_str())%_campatiy;
		int index2 = HashFunc2()((char*)k.c_str()) % _campatiy;
		int index3 = HashFunc3()((char*)k.c_str()) % _campatiy;
		int index4 = HashFunc4()((char*)k.c_str()) % _campatiy;
		int index5 = HashFunc5()((char*)k.c_str()) % _campatiy;

		_bt.Set(index1);
		_bt.Set(index2);
		_bt.Set(index3);
		_bt.Set(index4);
		_bt.Set(index5);
	}
	bool Test(const string& k)
	{
		int index1 = HashFunc1()((char*)k.c_str()) % _campatiy;
		int index2 = HashFunc2()((char*)k.c_str()) % _campatiy;
		int index3 = HashFunc3()((char*)k.c_str()) % _campatiy;
		int index4 = HashFunc4()((char*)k.c_str()) % _campatiy;
		int index5 = HashFunc5()((char*)k.c_str()) % _campatiy;

		if (!(_bt.Test(index1)))
			return false;
		if (!(_bt.Test(index2)))
			return false;
		if (!(_bt.Test(index3)))
			return false;
		if (!(_bt.Test(index4)))
			return false;
		if (!(_bt.Test(index5)))
			return false;
		return true;
	}
protected:
	BitMap _bt;
	size_t _campatiy;
};