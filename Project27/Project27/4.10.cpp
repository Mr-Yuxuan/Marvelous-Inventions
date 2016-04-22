#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

#include<stack>
#include<assert.h>
#define N 10
using namespace std;
struct Pos
{
	Pos(int row,int col)
	:_row(row)
	, _col(col)
	{}
	int _row;
	int _col;
};
void PrintMaze(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i*n + j] << ' ';
		}
		cout << endl;
	}

}
void GetMaze(int* a,int n)
{
	FILE* fout = fopen("MazeMap.txt", "r");
	assert(fout);
	size_t ch;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; )
		{
			ch = fgetc(fout) - '0';
			if (ch == 1 || ch == 0)
			{
				a[i*n + j] = ch;
				j++;
			}
			else
				continue;
		}
	}
	PrintMaze(a, n);
		fclose(fout);
}
bool IsVaild(int* a,Pos& cur, int n)
{
	if ((a[cur._row*n + cur._col] == 0 )&& (cur._col < n)&&(cur._row < n)&&(cur._col>=0)&&(cur._row>=0))
		return true;
	else
		return false;
}
bool FindPath(int* a,int n,Pos& entry,stack<Pos>& path)
{
	Pos cur = entry;
	path.push(cur);
	Pos next(0,0);
	while (!path.empty())
	{
		if (cur._row == n - 1)
			return true;
		a[cur._row*n + cur._col] = 2;
		next = cur;
		next._col++;
		if (IsVaild(a, next, n))
		{
			cur = next;
			path.push(cur);
			continue;
		}
		next = cur;
		next._col--;
		if (IsVaild(a, next, n))
		{
			cur = next;
			path.push(cur);
			continue;
		}
		next = cur;
		next._row++;
		if (IsVaild(a, next, n))
		{
			cur = next;
			path.push(cur);
			continue;
		}
		next = cur;
		next._row--;
		if (IsVaild(a, next, n))
		{
			cur = next;
			path.push(cur);
			continue;
		}
		else
		{
			cur = path.top();
			path.pop();
		}
	}
}

int main()
{
	int a[N][N] = {};
	GetMaze((int*)a, N);
	Pos enrty(2, 0);
	stack<Pos> path;
	bool ret = FindPath((int*)a, N, enrty, path);
	cout << "-------------------------" << endl;
	PrintMaze((int*)a, N);
	system("pause");
	return 0;
}