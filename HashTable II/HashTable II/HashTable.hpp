#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
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
	size_t operator()(string s)
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
template<class K,class V>
struct HashNode
{
	K _key;
	V _value;
	HashNode* _next;
	HashNode()
		:_next(NULL)
	{}
	HashNode(const K& key,const V& value)
		:_key(key),
		_value(value),
		_next(NULL)
	{}
};
template<class K,class V>
class HashTable
{
	typedef HashNode<K,V> Node;
	typedef HashTable<K,V> Table;
public:
	HashTable()
		:_size(0)
	{
		_tables.resize(_PrimeList[0]);
	}
	HashTable(const size_t& capacity)
		:_size(0)
	{
		for (size_t i = 0; i < _PrimeSize; ++i)
		{
			if (capacity < _PrimeList[i])
			{
				_tables.resize(_PrimeList[i]);
				break;
			}
		}
	}
	HashTable(const Table& ht)
		:_size(0)
	{
		_tables.resize(ht._tables.size());
		for (size_t i = 0; i < ht._tables.size(); ++i)
		{
			Node* cur = ht._tables[i];
			while (cur)
			{
				Insert(cur->_key, cur->_value);
				cur = cur->_next;
			}
		}
	}
	HashTable& operator=(const Table& ht)
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
		Check();
		size_t index = _HashFunc(key);
		Node* tmp = new Node(key, value);
		if (_tables[index]&&_tables[index]->_key == key)
		{
			tmp->_next = _tables[index]->_next;
		}
		_tables[index] = tmp;
		_size++;
		return true;
	}
	Node* Find(const K& key)
	{
		if (_size == 0)
			return NULL;
		size_t index = _HashFunc(key);
		Node* cur = _tables[index];
		while (cur)
		{
			if (cur->_key == key)
			{
				return cur;
			}
			cur = cur->_next;
		}
		return NULL;
	}
	bool Remove(const K& key)
	{
		if (_size == 0)
			return false;
		size_t index = _HashFunc(key);
		if ((_tables[index]->_next==NULL)&&(_tables[index]->_key == key))
		{
			delete _tables[index];
			_tables[index] = NULL;
			--_size;
			return true;
		}
		Node* cur = _tables[index];
		Node* per = cur;
		cur = cur->_next;
		while (cur)
		{
			if (cur->_key == key)
			{
				Node* del = cur;
				cur = cur->_next;
				delete del;
				del = NULL;
				per->_next = cur;
				--_size;
				return true;
			}
			per = cur;
			cur = cur->_next;
		}
		return false;
	}
	~HashTable()
	{
		for (size_t i = 0; i < _tables.size(); ++i)
		{
			Node* cur = _tables[i];
			while (cur)
			{
				Node* del = cur;
				cur = cur->_next;
				delete del;
				del = NULL;
			}
			_tables[i] = NULL;
		}
	}
protected:
	size_t _HashFunc(const K& key)
	{
		HashFunc<K> hf;
		return hf(key)%_tables.size();
	}
	void Check()
	{
		if (_size == _tables.size())
		{
			Table ht;
			for (size_t i = 0; i < _PrimeSize; ++i)
			{
				if (_size < _PrimeList[i])
				{
					ht._tables.resize(_PrimeList[i]);
					break;
				}
			}
			for (size_t i = 0; i < _size; ++i)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					ht.Insert(cur->_key, cur->_value);
					cur = cur->_next;
				}
			}
			Swap(ht);
		}
	}
	void Swap(Table& ht)
	{
		_tables.swap(ht._tables);
		swap(_size, ht._size);
		return;
	}
private:
	vector<Node*> _tables;
	size_t _size;
};
void test()
{
	HashTable<string, string> ht;
	ht.Insert("q", "989");
	cout << ht.Find("q")->_value << endl;
	return;
}