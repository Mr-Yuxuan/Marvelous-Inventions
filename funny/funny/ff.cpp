#include<stdio.h>
#include<stdlib.h>
int main()
{
	int ch = 0;
	int arr[10] = { 0 };
	int space = 0;
	int other = 0;
	int i = 0;
	while ((ch = getchar()) != EOF)
	{
		if ((ch >= '0') && (ch <= '9'))
			arr[ch - '0'-1]++;
		else if (ch == ' '||ch=='\n'||ch=='\t')
			space++;
		else
			other++;
	}
	printf("0~9�����ֳ��ֵĴ�����\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("�հ��ַ����ִ�����%d\n", space);
	printf("������%d\n", other);
	system("pause");
	return 0;
}