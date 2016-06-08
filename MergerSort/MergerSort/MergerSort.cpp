#include<iostream>
using namespace std;
void mergearray(int *a, int left, int mid, int right, int *tmp)
{
	int i = left;
	int j = mid + 1;
	int k = 0;

	while (i <= mid && j <= right)
	{
		if (a[i] <= a[j])
			tmp[k++] = a[i++];
		else
			tmp[k++] = a[j++];
	}

	while (i <= mid)
		tmp[k++] = a[i++];

	while (j <= right)
		tmp[k++] = a[j++];

	for (size_t i = 0; i < k; i++)
		a[left + i] = tmp[i];
}
void mergesort(int *a, int left, int right, int *tmp)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		mergesort(a, left, mid, tmp);    //左边有序  
		mergesort(a, mid + 1, right, tmp); //右边有序  
		mergearray(a, left, mid, right, tmp); //再将二个有序数列合并  
	}
}

void MergeSort(int *a, int n)
{
	int *p = new int[n];
	if (p == NULL)
		return;
	mergesort(a, 0, n - 1, p);
	delete[] p;
	return ;
}
int main()
{
	int a[] = { 1, 5, 7, 88, 3, 4, 6 };
	MergeSort(a, 7);
	return 0;
}