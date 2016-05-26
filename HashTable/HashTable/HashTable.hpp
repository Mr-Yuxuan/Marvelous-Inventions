#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
enum State
{
	EMPTY,
	DELETE,
	EXITS,
};
template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return key;
	}
};
template<>
struct HashFunc<string>
{
	size_t operator()(const string& s)
	{
		char* str = (char*)s.c_str();
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
const int _PrimeSize = 28;
static const unsigned long _PrimeList[28] =
{
	53ul, 97ul, 193ul, 389ul, 769ul,
	1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
	49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
	1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
	50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
	1610612741ul, 3221225473ul, 4294967291ul
};
template<class K, class V>
struct HashTableNode
{
	
	K _key;
	V _value;
	State _state;
	HashTableNode()
		:_state(EMPTY)
	{}
	HashTableNode(const K& key, const V& value)
		:_key(key),
		_value(value),
		_state(EXITS)
	{}
	};

template<class K,class V>
class HashTable
{
	typedef HashTableNode<K, V> Node;
	typedef HashTable<K, V> Table;

public:
	HashTable(const size_t& capacity=_PrimeList[0])
		:_size(0)
	{
		for (size_t i = 0; i < _PrimeSize; ++i)
		{
			if (capacity>_PrimeList[i])
			{
				continue;
			}
			else
			{
				_tatbles.resize(_PrimeList[i]);
				break;
			}
		}
	}
	HashTable(const Table& ht)
		:_size(0)
	{
		_tatbles.resize(ht._tatbles.size());
		for (size_t i = 0; i < _tatbles.size(); ++i)
		{
			if ((ht._tatbles[i]!=NULL)&&(ht._tatbles[i]->_state == EXITS))
			{
				Insert(ht._tatbles[i]->_key, ht._tatbles[i]->_value);
			}
		}
	}
	HashTable operator=(const Table& ht)
	{
		if (this != &ht)
		{
			Table tmp(ht);
			Swap(tmp);
		}
		return *this;
	}
	bool Insert(const K& key, const V& value)
	{
		CheckCampacity();
		size_t index = _HashFunc(key);
		size_t tmp = index;
		size_t i = 1;
		while ((_tatbles[index]!=NULL)&&(_tatbles[index]->_state==EXITS))
		{
			index = (tmp + i*i)%(_tatbles.size());
			++i;
		}
		if ((_tatbles[index] != NULL)&&(_tatbles[index]->_state == DELETE))
		{
			delete _tatbles[index];
		}
		_tatbles[index] =new Node(key, value);
		++_size;
		return true;
	}
	bool Remove(const K& key)
	{
		if (_size == 0)
			return false;
		size_t index = _HashFunc(key);
		size_t tmp = index;
		size_t i = 0;
		while (_tatbles[index]&&_tatbles[index]->_key != key)
		{
			index = (tmp + i*i) % (_tatbles.size());
			++i;

		}
		if (_tatbles[index] == NULL)
			return false;
		else
		{
			_tatbles[index]->_state = DELETE;
			--_size;
		}
	}
	bool Find(const K& key)
	{
		if (_size == 0)
			return false;
		size_t index = _HashFunc(key);
		size_t tmp = index;
		size_t i = 1;
		while (_tatbles[index] && _tatbles[index]->_key != key)
		{
			index = (tmp + i*i)%(_tatbles.size());
			++i;
		}
		if (_tatbles[index] == NULL || _tatbles[index]->_state == DELETE)
		{
			return false;
		}
		return true;
	}
	void Print()
	{
		for (size_t i = 0; i < _tatbles.size(); ++i)
		{
			if (_tatbles[i]&&_tatbles[i]->_state == EXITS)
			{
				cout << "[" << _tatbles[i]->_key << ":" << _tatbles[i]->_value << "]";
				cout << "->";
			}
		}
		cout <<"END"<< endl;
	}
	~HashTable()
	{
		for (size_t i = 0; i < _tatbles.size(); ++i)
		{
			if (_tatbles[i])
			{
				delete _tatbles[i];
				_tatbles[i] = NULL;
			}
		}
	}
protected:
	void CheckCampacity()
	{
		if ((_size * 10) /( _tatbles.size()) > 6)
		{
			Table tmp;
			for (size_t i = 0; i < _PrimeSize; ++i)
			{
				if (_tatbles.size() < _PrimeList[i])
				{
					tmp._tatbles.resize(_PrimeList[i]);
					break;
				}
			}
			for (size_t i = 0; i < _tatbles.size(); ++i)
			{
				if (_tatbles[i] && _tatbles[i]->_state == EXITS)
				{
					tmp.Insert(_tatbles[i]->_key, _tatbles[i]->_value);
				}
			}
			Swap(tmp);
		}
		return;
	}
	void Swap(Table& tmp)
	{
		_tatbles.swap(tmp._tatbles);
		swap(_size, tmp._size);
	}
		
	
	size_t _HashFunc(const K& key)
	{
		HashFunc<K> hf;
		return hf(key)%_tatbles.size();
	}
private:
	vector<Node*> _tatbles;
	size_t _size;
	

};
