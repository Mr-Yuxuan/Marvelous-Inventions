#include<iostream>
#include<assert.h>
using namespace std;
#define N 10
#define K 5
void AdjustDone(int *a, size_t parent,size_t size)
{
	int child = 2 * parent + 1;
	while (child < size)
	{
		if ((child + 1 < size) && a[child + 1] < a[child])
		{
			++child;
		}
		if (a[child] < a[parent])
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
void FindMaxKOfArry(int a[],const size_t size,int arr[])
{
	assert(a);
	
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = a[i];
	}
	for (int i = (size - 2) / 2; i >= 0; --i)
	{
		AdjustDone(arr, i,size);
	}
	for (size_t i = K; i < N; ++i)
	{
		if (a[i]>arr[0])
		{
			swap(arr[0], a[i]);
			AdjustDone(arr, 0, size);
		}
	}
}
int main()
{
	int a[N] = { 2, 3, 99, 1, 56, 78, 34, 22, 1, 9 };
	int arr[K];
	FindMaxKOfArry(a,K,arr);
	for (size_t i = 0; i < K; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
	system("pause");
	return 0;
}