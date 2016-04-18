#include<iostream>
using namespace std;
template<class T>
class SymmetricMatrix
{
public:
	SymmetricMatrix(T* a,size_t n)
	:_a(new T[n*(n+1)/2])
	, _n(n)
	, _size(0)
	{
		for (size_t i = 0; i < _n; ++i)
		{
			for (size_t j = 0; j < _n; ++j)
			{
				if (j <= i)
				{
					_a[_size++] = a[i*_n + j];
				}
				else
					break;
			}
		}
	}
	T& Access(size_t i, size_t j)
	{
		if (j <= i)
		{
			return _a[i*(i + 1) / 2 + j];
		}
		else
			return _a[j*(j + 1) / 2 + i];
	}
	~SymmetricMatrix()
	{
		if (_a)
		{
			delete[] _a;
		}
	}
	void Print()
	{
		for (size_t i = 0; i < _n; ++i)
		{
			for (size_t j = 0; j < _n; ++j)
			{
				if (j <= i)
				{
					cout << _a[i*(i + 1) / 2 + j] << ' ';
				}
				else
				{
					cout << _a[j*(j + 1) / 2 + i] << ' ';
				}
			}
			cout << endl;
		}
	}
private:
	T* _a;
	size_t _size;
	size_t _n;
};
int main()
{
	int a[4][4] = { { 0, 1, 2, 3 }, 
	                { 1, 0, 2, 3 }, 
	                { 2, 2, 0, 1 }, 
	                { 3, 3, 1, 0 } };
	SymmetricMatrix<int> s((int*)a, 4);
	s.Print();
	cout <<"(0,3):"<< s.Access(0, 3) << endl;;
	
	system("pause");
	return 0;
}

