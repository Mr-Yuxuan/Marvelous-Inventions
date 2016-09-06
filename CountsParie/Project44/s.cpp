#include<iostream>
#include<assert.h>
#include<stdlib.h>
using namespace std;
int CountsOfParie(int n,int *moutons)
{
	assert(moutons);
	if ((n < 3)&&(n>10*10*10*10*10*10))
		return -1;
	for (int i = 0; i < n; ++i)
	{
		if (moutons[i]<1 && (moutons[i]>10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10))
			return -1;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; j++)
		{
			if (moutons[i]>moutons[j])
			{
				int tmp = moutons[i];
				moutons[i] = moutons[j];
				moutons[j] = tmp;
			}
		}
	}
	int flag = 0;
	int counts = n;
	int start = 1;
	int end = n - 1;
	while (start + 1 != end)
	{
		for (int i = 0; i < start; ++i)
		{
			if (moutons[i] < moutons[start] && moutons[i] < moutons[end])
			{
				flag = 1;
				continue;
			}
			break;
		}
		if (flag)
		{
			counts++;
			flag = 0;
		}
		for (int i = start+1; i < end; ++i)
		{
			if (moutons[i] < moutons[start] && moutons[i] < moutons[end])
			{
				flag = 1;
				continue;
			}
			break;
		}
		if (flag)
		{
			counts++;
			flag = 0;
		}
		start++;
	}
	return counts;
}
int main()
{
	
	int a = 0;
	cin>>a;
	int *arr = new int[a];
	for (int i = 0; i < a; ++i)
	{
		cin >>arr[i];
	}
	
	cout << CountsOfParie(a, arr) << endl;
	delete arr;
	system("pause");
	return 0;
}