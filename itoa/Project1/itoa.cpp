#include<stdio.h>
#include<stdlib.h>
void reverse(char *left, char *right)
{
	int tmp = 0;
	while (left < right)
	{
		tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
char *itoa(int m, char arr[100])
{
	int k = 0;
	char flag = 0;
	char *p = arr;
	char *left = NULL;
	char *right = NULL;
	if (((m >> 31) & 1) == 1)
	{
		flag = '-';
		m = 0 - m;
	}
	else
		flag = '+';
	*p = flag;
	p++;
    while (m)
	{
		k = m % 10;
		m = m / 10;
		*p = k + '0';
		p++;
	}
	*p = '\0';
	left = arr+1;
	right = p - 1;
	reverse(left,right);
	return arr;
}

int main()
{
	int k = 0;
	char arr[100];
	scanf_s("%d", &k);
	itoa(k, arr);
	printf("%s\n", arr);
    system("pause");
	return 0;
}