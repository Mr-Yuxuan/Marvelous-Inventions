#include<stdio.h>
#include<string.h>
int main(char *p, int a, int b)
{
	char arr[5] = { 0 };
	gets_s(arr, 3);
	p = arr;
	scanf_s("%d%d", &a, &b);
	if (strcmp(p, "-a") == 0)
		printf("%d+%d=%d\n", a, b, a + b);
	else if (strcmp(p, "-s") == 0)
		printf("%d-%d=%d\n", a, b, a - b);
	else if (strcmp(p, "-m") == 0)
		printf("%d*%d=%d\n", a, b, a*b);
	else if (strcmp(p, "-d") == 0)
		printf("%d/%d=%d\n", a, b, a / b);
	system("pause");
	return 0;
}