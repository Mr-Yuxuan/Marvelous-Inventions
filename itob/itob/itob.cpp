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
char *itob(int n, char arr[], int b)
{
	char *p = arr;
	int k = 0;
	char *left = NULL;
	char *right = NULL;
	
	while (n)
	{
		k = n%b;
		if (k > 9)
		{
			*p = k - 10 + 'A';
		}
		else
	        *p = k+'0';
		n = n / b;
		p++;
	}
	*p = '\0';
	left = arr;
	right = p - 1;
	reverse(left, right);
	return arr;
}
int main()
{
	int n = 0;
	char arr[100];
	int b = 0;
	scanf_s("%d%d", &n, &b);
	itob(n, arr, b);
	printf("%s\n", arr);
    system("pause");
	return 0;
}