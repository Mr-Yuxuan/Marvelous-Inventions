#include<iostream>
#include<vector>
using namespace std;
template<class T>
struct Triple
{
	Triple()
	{}
	Triple(const T& d, size_t row, size_t col)
		:_value(d)
		, _row(row)
		, _col(col)
	{}
	T _value;
	size_t _row;
	size_t _col;
};
template<class T>
class SparseMatrix
{
public:
	SparseMatrix(T* a, size_t row, size_t col, const int invalue)
		: _rowsize(row)
		, _colsize(col)
		, _invalue(invalue)
	{
		for (size_t i = 0; i < _rowsize; ++i)
		{
			for (size_t j = 0; j < _colsize; ++j)
			{
				if (a[i*_colsize + j] != _invalue)
				{
					_a.push_back(Triple<T>(a[i*_colsize + j], i, j));
				}
			}
		}
	}
	SparseMatrix()
		:_rowsize(0)
		, _colsize(0)
		, _invalue(0)
	{}
	void Display()
	{
		size_t index = 0;
		for (size_t i = 0; i < _rowsize; ++i)
		{
			for (size_t j = 0; j < _colsize; ++j)
			{
				if ((index < _a.size()) && (_a[index]._row == i) && (_a[index]._col == j))
				{
					cout << _a[index]._value << " ";
					++index;
				}
				else
				{
					cout << _invalue << ' ';
				}
			}
			cout << endl;
		}
	}
	SparseMatrix<T> FastTransport()
	{
		size_t n = _a.size();
		size_t *count = new size_t[_colsize];
		memset(count, 0, sizeof(T)* _colsize);
		size_t *start = new size_t[_colsize];
		memset(start, 0, sizeof(T)* _colsize);
		//统计每列非零元素的个数
		for (size_t i = 0; i < n; ++i)
		{
			++count[_a[i]._col];
		}
		//统计非零元素在压缩矩阵中的起始位置
		start[0] = 0;
		for (size_t i = 1; i < _colsize; ++i)
		{
			start[i] = start[i - 1] + count[i - 1];
		}
		//确定转置后压缩矩阵的存储
		vector<Triple<T>> t;
		t.resize(n);
		for (size_t i = 0; i < n; i++)
		{
			size_t j = _a[i]._col;
			size_t& q = start[j];
			t[q++] = Triple<T>(_a[i]._value, j, _a[i]._row);
		}
		//交换行列
		SparseMatrix<T> tmp;
		tmp._a = t;
		tmp._colsize = _rowsize;
		tmp._invalue = _invalue;
		tmp._rowsize = _colsize;

		delete[] count;
		delete[] start;
		return tmp;
	}
	SparseMatrix<T> Transport()//普通逆置
	{

		vector<Triple<T>> t;
		//按列优先对三元组进行排列
		for (size_t i = 0; i < _colsize; ++i)
		{

			for (size_t j = 0; j<_a.size(); j++)
			{
				if (_a[j]._col == i)
				{
					t.push_back(Triple<T>(_a[j]._value, _a[j]._col, _a[j]._row));

				}

			}
		}

		//交换原来的行列
		SparseMatrix<T> tmp;
		tmp._a = t;
		tmp._colsize = _rowsize;
		tmp._invalue = _invalue;
		tmp._rowsize = _colsize;


		return tmp;
	}
protected:
	vector<Triple<T>> _a;
	size_t _rowsize;
	size_t _colsize;
	int _invalue;
};
int main()
{
	int a[3][5] = { { 1, 0, 0, 0, 4 }, { 2, 0, 0, 0, 8 }, { 0, 3, 0, 0, 0 } };
	SparseMatrix<int> s((int*)a, 3, 5, 0);
	s.Display();
	SparseMatrix<int> s1;
	cout << "普通转置：" << endl;
	s1 = s.Transport();
	s1.Display();
	SparseMatrix<int> s2;
	cout << "快速转置：" << endl;
	s2 = s1.FastTransport();
	s2.Display();
	system("pause");
	return 0;
}