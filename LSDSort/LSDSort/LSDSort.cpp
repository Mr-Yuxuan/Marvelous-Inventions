#include<iostream>
using namespace std;
int GetDight(int *a, size_t size)
{
	int d = 1;
	int k = 10;
	for (size_t i = 0; i < size; ++i)
	{
		while (a[i]>k)
		{
			d++;
			k *= 10;
		}
	}
	return d;
}
void LSD(int *a,size_t size)
{
	int dight = GetDight(a, size);
	int t = 1;
	int* tmp = new int[size];
	memset(tmp, 0, sizeof(tmp)*size);
	while (dight)
	{
		int count[10] = { 0 };
		int start[10] = { 0 };
		for (size_t i = 0; i < size; ++i)
		{
			int k = a[i]/t % 10;
			count[k]++;
		}
		for (size_t i = 1; i < 10; ++i)
		{
			start[i] = count[i - 1] + start[i - 1];
		}
		for (size_t i = 0; i < size; ++i)
		{
			int k = a[i]/t % 10;
			tmp[start[k]] = a[i];
			start[k]++;
			
		}
		memcpy(a, tmp, sizeof(int)*size);
		
		t *= 10;
		dight--;
	}
	delete[] tmp;
	return;
}
int main()
{
	int a[] = { 16,11, 33,  26, 88, 77 };
	LSD(a, 6);
	return 0;
}