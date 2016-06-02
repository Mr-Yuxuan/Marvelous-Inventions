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
//”≈ªØ∞Ê±æ
void SelectSortII(int *a, size_t n)
{
	assert(a);
	int start = 0;
	int end = n - 1;
	while (start < end)
	{
		int max = end;
		int min = start;
		for (size_t i = start; i <= end; i++)
		{
			if (a[i] <= a[min])
				min = i;
			if (a[i]>=a[max])
				max = i;
		}
		if (max == start)
		{
			max = min;
		}
		swap(a[start], a[min]);
		if (min == end)
		{
			min = max;
		}
		swap(a[end], a[max]);
		
		
		
		start++;
		end--;
	}
	return;
}
int main()
{
	int a[] = {  4, 6, 3, 8, 2, 4,  7, 7,1,0 };
	SelectSort(a, 10);
	SelectSortII(a, 10);
	system("pause");
    return 0;
}