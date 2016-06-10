
struct A
{
	int _a;
};

template<typename T>
class AutoPtr
{
public:
	AutoPtr(T* ptr=NULL)
		:_ptr(ptr)
	{}
	AutoPtr(AutoPtr<T>& a)
		:_ptr(a._ptr)
	{
		a._ptr = NULL;
	}
	AutoPtr<T>& operator=(AutoPtr<T>& a)
	{
		_ptr = a._ptr;
		a._ptr = NULL;
		return *this;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
	~AutoPtr()
	{
		if (_ptr != NULL)
		{
			delete _ptr;
		}
	}
protected:
	T* _ptr;
};
template<typename T>
class ScopedPtr
{
public:
	ScopedPtr(T* ptr = NULL)
		:_ptr(ptr)
	{}
	~ScopedPtr()
	{
		if (_ptr != NULL)
		{
			delete _ptr;
		}
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
protected:
	ScopedPtr(const ScopedPtr<T>& s);
	ScopedPtr<T>& operator=(const ScopedPtr<T>& s);
protected:
	T* _ptr;
};
template<typename T>
class SharedPtr
{
public:
	SharedPtr(T* ptr=NULL)
		:_ptr(ptr)
		, _pcount(new int(1))
	{}
	SharedPtr(SharedPtr<T>& s)
		:_ptr(s._ptr)
		, _pcount(s._pcount)
	{
		
		++(*_pcount);
	}
	SharedPtr<T>& operator=(SharedPtr<T> s)
	{
		swap(_ptr, s._ptr);
		swap(_pcount, s._pcount);
		/*if (_ptr != s._ptr)
		{
			Reservs();
			_ptr = s._ptr;
			_pcount = s._pcount;
			++(*_pcount);
		}*/
		return *this;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
	~SharedPtr()
	{
		Reservs();
	}
public:
	void Reservs()
	{
		if (--(*_pcount) == 0)
		{
			delete _ptr;
			delete _pcount;
		}
	}
protected:
	T* _ptr;
	int* _pcount;
};
template<typename T>
class ScopedArry
{
public:
	ScopedArry(T* ptr = NULL)
		:_ptr(ptr)
	{}
	~ScopedArry()
	{
		if (_ptr != NULL)
		{
			delete[] _ptr;
		}
	}
	T& operator[](int index)
	{
		return _ptr[index];
	}
protected:
	ScopedArry(const ScopedPtr<T>& s);
	ScopedArry<T>& operator=(const ScopedArry<T>& s);
protected:
	T* _ptr;
};
template<typename T>
class SharedArry
{
public:
	SharedArry(T* ptr = NULL)
		:_ptr(ptr)
		, _pcount(new int(1))
	{}
	SharedArry(SharedArry<T>& s)
		:_ptr(s._ptr)
		, _pcount(s._pcount)
	{

		++(*_pcount);
	}
	SharedArry<T>& operator=(SharedArry<T> s)
	{
		swap(_ptr, s._ptr);
		swap(_pcount, s._pcount);
		/*if (_ptr != s._ptr)
		{
		if (--(*(_pcount)) == 0)
		{
		delete[] _ptr;
		delete _pcount;
		}
		_ptr = s._ptr;
		_pcount = s._pcount;
		++(*_pcount);
		}*/
		return *this;
	}
	T& operator[](int index)
	{
		return _ptr[index];
	}
	~SharedArry()
	{
		if (--(*_pcount) == 0)
		{
			delete[] _ptr;
		}
	}
protected:
	T* _ptr;
	int* _pcount;
};