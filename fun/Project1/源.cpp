#include<stdio.h>
#include<stdlib.h>
#include<assert.h>;
void Odd_First(int *p,int len)
{
	assert(p);
	assert(len);
	int start = 0;
	int end = len - 1;
	int tmp = 0;
	while (start < end)
	{
		if (p[start] % 2 == 0)
		{
			if (p[end] % 2 == 1)
			{
				tmp = p[start];
				p[start] = p[end];
				p[end] = tmp;
				start++;
				end--;
				continue;
			}
			end--;
		}
		else
		if (p[end] % 2 == 0)
		{
			start++;
			end--;
		}
		else start++;
		
	}
	

}
int main()
{
	int arr[10] = { 0 };
	int i = 0;
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("ÇëÊäÈë10¸öÊı×Ö£º\n");
	for (i = 0; i < size; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	Odd_First(arr,size);
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;

}