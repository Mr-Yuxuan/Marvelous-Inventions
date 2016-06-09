#include<iostream>
using namespace std;

typedef int DateType;
class Array
{
public:
	Array(int sz = 10)
		:size(sz)
		, parr(new DateType[sz])
	{}
	Array(const Array& arr)
	{
		parr = new DateType[size];
		memcpy(parr, arr.parr, size);
	}
	~Array()
	{
		if (*parr != NULL)
		{
			delete[] parr;
		}
	}
	DateType& operator[](int index)
	{
		return parr[index];
	}
	Array operator=(const Array& arr)
	{
		memcpy(parr, arr.parr, size);
		return *parr;
	}

private:
	DateType *parr;
	int size;
};

int main()
{
	DateType arr1;
	getchar();
	return 0;
}


