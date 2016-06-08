#include<iostream>
using namespace std;
void MidOfNum(int *a, int begin, int end)
{
	int mid = (begin + end) / 2;
	if (a[begin]<a[mid] && a[begin]>a[end])
		swap(a[begin], a[end]);
	if (a[mid]<a[begin] && a[mid]>a[end])
		swap(a[mid], a[end]);
}
int _QuickSort(int *a, int begin, int end)
{
	MidOfNum(a, begin, end);
	int key = end;
	while (begin < end)
	{
		while (begin<end&&a[begin] <= a[key])
			begin++;
		while (begin<end&&a[end]>=a[key])
			end--;
		if (begin < end)
		{
			swap(a[begin], a[end]);
		}
	}
	swap(a[key], a[begin]);
	return begin;
}
//ÍÚ¿Ó·¨
int _QuickSort1(int *a,int begin, int end)
{
	MidOfNum(a, begin, end);
	int key = end;
	int tmp = a[key];
	while (begin < end)
	{
		while (begin < end&&a[begin] <= tmp)
			begin++;
		if (begin < end)
		{
			a[key] = a[begin];
			key = begin;
		}
		while (begin < end&&a[end] >= tmp)
			--end;
		if (begin < end)
		{
			a[key] = a[end];
			key = end;
		}
	}
	a[key] = tmp;
	return key;
}
int _QuickSort2(int *a, int begin, int end)
{
	MidOfNum(a, begin, end);
	int key = end;
	int cur = begin;
	int per = cur - 1;
	while (cur < end)
	{
		while (cur < end&&a[cur]>=a[key])
			++cur;
		if(cur < end && ((per + 1) == cur))
		{
			++cur;
			++per;
			continue;
		}
		if (cur < end)
		{
			++per;
			swap(a[cur], a[per]);
		}
	}
	swap(a[per + 1], a[key]);
	key = per + 1;
	return key;
}
void QuickSort(int*a,int left,int right)
{
	if (left < right)
	{
		int key = _QuickSort2(a, left, right);
		QuickSort(a, left, key - 1);
		QuickSort(a, key + 1, right);
	}
}
int main()
{
	int a[] = { 2, 8, 5, 5, 3, 7, 6, 4, 0};
	QuickSort(a, 0, 8);

	return 0;
}