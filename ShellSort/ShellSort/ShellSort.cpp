#include<iostream>
#include<assert.h>
using namespace std;
void ShellSort(int *a,size_t n)
{
	assert(a);
	int grap = n;
	while (grap)
	{
		grap = grap / 3 + 1;
		for (size_t i = 0; i < n - grap; ++i)
		{
			int end = i;
			int tmp = a[end + grap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + grap] = a[end];
					a[end] = tmp;
				}
				end -= grap;
			}
		}
		grap--;
	}
	return;
}
int main()
{
	int a[] = { 1, 4, 4, 6, 2, 8, 7, 9, 3, 3};
	ShellSort(a, 10);
	system("pause");
	return 0;
}