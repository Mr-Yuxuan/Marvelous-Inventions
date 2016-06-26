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
		printf("请输入信息：\n");
		printf("姓名:>");
		scanf("%s", book->peo[book->count].name);
		printf("年龄:>");
		scanf("%d", &book->peo[book->count].age);
		printf("性别:>");
		scanf("%s", book->peo[book->count].sex);
		printf("电话:>");
		scanf("%s", book->peo[book->count].tel);
		printf("地址:>");
		scanf("%s", book->peo[book->count].adder);
		book->count++;
        printf("添加成功！\n");
	}
	else
	{
		("人已满！\n");
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
	printf("请输入要删除人的名字:>");
	scanf("%s", name);
	ret=find(book, name);
	if (ret == -1)
	{
		printf("要删除的人不存在");
		return;
	}
	else
	{
		for (i = ret; i < book->count-1; i++)
		{
			book->peo[i] = book->peo[i + 1];
		}
		book->count--;
		printf("删除成功！\n");
	}
}
void modefy(Book *book)
{
	char name[MAX_NAME];
	int ret = 0;
	printf("请输入要修改人的名字:>");
	scanf("%s", name);
	ret = find(book, name);
	if (ret == -1)
	{
		printf("要修改的人不存在");
		return;
	}
	else
	{
		printf("请输入信息：\n");
		printf("姓名:>");
		scanf("%s", book->peo[ret].name);
		printf("年龄:>");
		scanf("%d", &book->peo[ret].age);
		printf("性别:>");
		scanf("%s", book->peo[ret].sex);
		printf("电话:>");
		scanf("%s", book->peo[ret].tel);
		printf("地址:>");
		scanf("%s", book->peo[ret].adder);
		printf("修改成功！\n");
	}
}
void serach(Book *book)
{
	char name[MAX_NAME];
	int ret = 0;
	printf("请输入要查找人的名字:>");
	scanf("%s", name);
	ret = find(book, name);
	if (ret == -1)
	{
		printf("要查找的人不存在");
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
