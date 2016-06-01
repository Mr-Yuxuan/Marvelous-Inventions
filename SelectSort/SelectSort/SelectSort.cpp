#include<iostream>
#include<assert.h>
using namespace std;
void SelectSort(int *a, size_t n)
{
	assert(a);
	int end = n - 1;
	
	while (end)
	{
		int MaxIndex = 0;
		for (size_t i = 0; i <= end; ++i)
		{
			if (a[i]>a[MaxIndex])
				MaxIndex = i;
		}
		swap(a[end], a[MaxIndex]);
		end--;
	}
	return;
}
int main()
{
	int a[] = { 1, 1, 6, 3, 0, 2, 4, 9, 7, 7 };
	SelectSort(a, 10);
	system("pause");
    return 0;
}