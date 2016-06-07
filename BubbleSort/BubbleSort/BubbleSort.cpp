#include<iostream>
#include<assert.h>
using namespace std;
void BubbleSort(int *a, size_t n)
{
	assert(a);
	for (size_t i = 0; i < n; ++i)
	{
		bool state = false;
		for (size_t j = 0; j < n-i-1; j++)
		{
			if (a[j]>a[j + 1])
			{
				swap(a[j], a[j + 1]);
				state = true;
			}
		}
		if (state == false)
			break;
	}
	return;
}
int main()
{
	int a[] = {3,4,6,6,0,1,6,8,9 };
	BubbleSort(a, 9);
	return 0;
}