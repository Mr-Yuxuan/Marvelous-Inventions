#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
long long GetNextPrime(long long &n)
{
	const int _PrimeSize = 28;
	static const unsigned long _PrimeList[_PrimeSize] =
	{
		53ul, 97ul, 193ul, 389ul, 769ul,
		1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
		49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
		1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
		50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
		1610612741ul, 3221225473ul, 4294967291ul
	};
	for (size_t i = 0; i < _PrimeSize; ++i)
	{
		if (n < _PrimeList[i])
			return _PrimeList[i];
	}
}




class BitMap
{
public:
	BitMap(long long n)
		:_size(0)
	{
		_bp.resize((GetNextPrime(n)>>5)+1);
	}
	void Set(const size_t& k)
	{
		int index = k>>5;
		int num = k%32;
		if (!(_bp[index] & (1 << num )))
		{
			_bp[index] = _bp[index] | (1 << num );
			_size++;
		}
	}
	void Reset(const size_t& k)
	{
		int index = k>>5;
		int num = k%32;
		if (_bp[index] & (1 << num ))
		{
			_bp[index] = _bp[index] & (~(1 << num));
			_size--;
		}
	}
	bool Test(const size_t& k)
	{
		int index = k>>5;
		int num =k%32;
		if ((_bp[index] & (1 << num )))
			return true;
		else
			return false;
	}
protected:
	vector<size_t> _bp;
	size_t _size;
};