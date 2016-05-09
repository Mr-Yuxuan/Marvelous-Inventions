#include<iostream>
#include<assert.h>
using namespace std;
void AdjustDone(int *a, size_t parent,const size_t size)
{
	int child = 2 * parent + 1;
	while (child < size)
	{
		if ((child + 1 < size)&&a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child]>a[parent])
		{
			int tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}
void SortOfHeap(int *a, const size_t size)
{
	assert(a);
	for (int i = (size - 2) / 2; i >= 0; --i)
	{
		AdjustDone(a, i, size);
	}
	for (int i = size - 1; i >= 0; --i)
	{
		swap(a[0], a[i]);
		AdjustDone(a, 0, i);
	}
}
int main()
{
	int a[] = { 13, 4, 5, 9, 11, 23, 444, 55, 0, 34 };
	SortOfHeap(a, sizeof(a) / sizeof(a[0]));
	for (size_t i = 0; i < 10; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	system("pause");
	return 0;
}