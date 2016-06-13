
#include<iostream>
using namespace std;
template<class T>
struct Free
{
public:
	void operator()(void* ptr)
	{
		free(ptr);
	}
};
template<class T>
struct Fclose
{
public:
	void operator()(void* ptr)
	{
		fclose((FILE*)ptr);
	}
};
template<class T>
struct Delete
{
public:
	void operator()(void* ptr)
	{
		delete ptr;
	}
};
template<class T,class D>
class SharedPtr
{
public:
	SharedPtr(T* ptr,D d)
		:_ptr(ptr)
		, _pcount(new int(1))
		, _d(d)
	{}
	SharedPtr(const SharedPtr<T,D>& sp)
		:_ptr(sp._ptr)
		, _pcount(sp._pcount)
	{
		++(*_pcount);
	}
	SharedPtr<T,D>& operator=(SharedPtr<T,D> sp)
	{
		swap(_ptr, sp._ptr);
		swap(_pcount, sp._pcount);
		return *this;
	}
	~SharedPtr()
	{
		Release();
	}
	void Release()
	{
		if ((--*(_pcount)) == 0)
		{
			_d(_ptr);
			delete _pcount;
		}
	}
private:
	T* _ptr;
	int *_pcount;
	D _d;
};
int main()
{
	int* p = (int*)malloc(sizeof(int));
	SharedPtr<int, Free<int>> sp1(p,Free<int>());
	return 0;
}