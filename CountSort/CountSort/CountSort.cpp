#include<iostream>
using namespace std;
int GetMax(int*a,size_t size)
{
	int max = 0;
	for (size_t i = 0; i < size; ++i)
	{
		if (a[i]>a[max])
			max = i;
	}
	return a[max];
}
int GetMin(int *a,size_t size)
{
	int min = 0;
	for (size_t i = 0; i < size; ++i)
	{
		if (a[i]<a[min])
			min = i;
	}
	return a[min];
}
void CountSort(int* a,size_t size)
{
	int max = GetMax(a,size);
	int min = GetMin(a,size);
	int count_size = max - min + 1;
	int *count = new int[count_size];
	memset(count, 0, sizeof(count)*count_size);
	for (size_t i = 0; i < size; ++i)
	{
		int k = a[i] - min;
		count[k]++;
	}
	for (size_t i = 0,k=0; i < count_size; ++i)
	{
		
		while (count[i] != 0)
		{
			a[k++] = i + min;
			count[i]--;
		}
	}
	delete[] count;
	return;
}
int main()
{
	int a[] = { 1, 5, 6, 6, 0, 3, 4 };
	CountSort(a, 7);
	return 0;
}