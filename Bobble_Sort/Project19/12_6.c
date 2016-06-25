#include<stdio.h>
#include<assert.h>
swap(void *buf1, void *buf2, int sz)
{
	int i = 0;
	char tmp=0;
	for (i = 0; i < sz; i++)
	{
		tmp = *((char *)buf1 + i);
		*((char *)buf1 + i) =*((char *)buf2 + i);
		*((char *)buf2 + i) = tmp;
	}
}
Bobble_sort(void *base, int n, int size, int(*cmp)(const void *n1, const void *n2))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (cmp(((char *)base+j*size), ((char *)base+(j+1)*size))>0)
			swap((char *)base + j*size, (char *)base + (j + 1)*size, size);
		}
	}
}
int cmpint(const void *elem1, const void *elem2)
{
	return (*(int *)elem1) - (*(int *)elem2);
}
int cmpchar(const void *elem1, const void *elem2)
{
	return my_strcmp((char *)(*(int *)elem1) , (char *)(*(int *)elem2));
}
int my_strcmp(const char *buf1, const char *buf2)
{
	assert(buf1);
	assert(buf2);
	while ((*buf1++ == *buf2++) && (*buf1 != '\0'))
	{
		;
	}
	return *buf1 - *buf2;
}
int main()
{
	int arr[10] = {1,3,5,7,9,2,4,6,8,0,};
	char *brr[] = { "aa", "cc", "dd", "bb" };
	int size1 = sizeof(arr) / sizeof(arr[0]);
	int size2 = sizeof(brr) / sizeof(brr[0]);
	int i = 0;
	Bobble_sort(arr, size1, sizeof(int), cmpint);
	for (i = 0; i < size1; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	Bobble_sort(brr, size2, sizeof(char *), cmpchar);
	for (i = 0; i < size2; i++)
	{
		printf("%s ", brr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}