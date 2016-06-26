#define _CRT_SECURE_NO_WARNINGS 1
#include"contast.h"

void menu()
{
	printf("*****************************************************\n");
	printf("     1.add      2.del     3.search      4.modefy     \n");
	printf("     5.show     6.clear   7.name_sort   0.exit       \n");
	printf("*****************************************************\n");
}
void init(Book *book)
{
	book->peo = P;
	book->count = 0;
}
void add(Book *book)
{
	if (book->count <= MAX)
	{
		if ((book->count % 100 == 0)&&(book->count!=0))
		{
			book->peo = (Peo *)realloc(book->peo, sizeof(Peo)*((book->count / 100) + 1) * 100);
		}
		printf("��������Ϣ��\n");
		printf("����:>");
		scanf("%s", book->peo[book->count].name);
		printf("����:>");
		scanf("%d", &book->peo[book->count].age);
		printf("�Ա�:>");
		scanf("%s", book->peo[book->count].sex);
		printf("�绰:>");
		scanf("%s", book->peo[book->count].tel);
		printf("��ַ:>");
		scanf("%s", book->peo[book->count].adder);
		book->count++;
        printf("��ӳɹ���\n");
	}
	else
	{
		("��������\n");
		return;
	}
}
static int find(Book *book,const char *p)
{
	int i;
	for (i = 0; i < book->count; i++)
	{
		if (strcmp(p, book->peo[i].name) == 0)
			return i;
	}
	return -1;
}
void del(Book *book)
{
	char name[MAX_NAME];
	int ret = 0;
	int i = 0;
	printf("������Ҫɾ���˵�����:>");
	scanf("%s", name);
	ret=find(book, name);
	if (ret == -1)
	{
		printf("Ҫɾ�����˲�����");
		return;
	}
	else
	{
		for (i = ret; i < book->count-1; i++)
		{
			book->peo[i] = book->peo[i + 1];
		}
		book->count--;
		printf("ɾ���ɹ���\n");
	}
}
void modefy(Book *book)
{
	char name[MAX_NAME];
	int ret = 0;
	printf("������Ҫ�޸��˵�����:>");
	scanf("%s", name);
	ret = find(book, name);
	if (ret == -1)
	{
		printf("Ҫ�޸ĵ��˲�����");
		return;
	}
	else
	{
		printf("��������Ϣ��\n");
		printf("����:>");
		scanf("%s", book->peo[ret].name);
		printf("����:>");
		scanf("%d", &book->peo[ret].age);
		printf("�Ա�:>");
		scanf("%s", book->peo[ret].sex);
		printf("�绰:>");
		scanf("%s", book->peo[ret].tel);
		printf("��ַ:>");
		scanf("%s", book->peo[ret].adder);
		printf("�޸ĳɹ���\n");
	}
}
void serach(Book *book)
{
	char name[MAX_NAME];
	int ret = 0;
	printf("������Ҫ�����˵�����:>");
	scanf("%s", name);
	ret = find(book, name);
	if (ret == -1)
	{
		printf("Ҫ���ҵ��˲�����");
		return;
	}
	else
	{
		printf("%10s  %5d  %5s  %10s  %10s\n", book->peo[ret].name, book->peo[ret].age, book->peo[ret].sex, book->peo[ret].tel, book->peo[ret].adder);
	}
}
void clear(Book *book)
{
	book->count = 0;
}
void sort(Book *book)
{
	int i, j = 0;
	for (i = 0; i < book->count - 1; i++)
	{
		for (j = 0; j < book->count - i - 1; j++)
		{
			if (strcmp(book->peo[j].name, book->peo[j + 1].name)>0)
			{
				Peo tmp = book->peo[j];
				book->peo[j] = book->peo[j + 1];
				book->peo[j + 1] = tmp;
			}
		}
	}
}
void show(Book *book)
{
	int i = 0;
	for (i = 0; i < book->count; i++)
	{
		printf("%10s  %5d  %5s  %10s  %10s\n", book->peo[i].name, book->peo[i].age, book->peo[i].sex, book->peo[i].tel, book->peo[i].adder);
	}
}
