#include<stdio.h>
#include<stdlib.h>
void print(int a[3][3])
{
	int i;
	for (i = 0; i < 3; i++)
	{
		printf(" %c | %c | %c \n", a[i][0], a[i][1], a[i][2]);
		if (i != 2)
			printf("---|---|---\n");
	}
}

void show(int (*p)[3])
{     
	int i;
	for (i = 0; i < 3; i++){
		printf(" %c | %c | %c \n", p[i][0], p[i][1], p[i][2]);
		if (i != 2)
			printf("---|---|---\n");
		}
}

 void  player(int (*p)[3])
{
	
	int i,j;
	printf("请输入格子数下子：");
	scanf_s("%d%d", &i,&j);
	p[i-1][j-1] =1;
}
 void comp(int (*p)[3])
 {
	 int i,j;
	 for (i = 0; i < 3; i++)
	 
		 for (j = 0; j < 3; j++)
		 {
			 if (p[i][j] == ' ')
			 {
				 p[i][j] = 2;
				 goto S;
			 }
		 }
	 S:;
 }       
 int win(int(*p)[3],int *k)
 {
	 
	 int i = 0;
	 int j = 0;
	 int flag =2;
	 for (i = 0; i < 3; i++)
	 {
	       j=j+p[i][i];
		   
		 if (j == 3)
			 flag=1;
		 else if (j == 6)
			 flag=0;
	 }
	 for (i = 0; i < 3; i++)
	 {
		 if (p[i][0] == 1 && p[i][1] == 1 && p[i][2] == 1)
			 flag=1;
		 else if (p[i][0] == 2 && p[i][1] == 2 && p[i][2] == 2)
			 flag=0;
	 }
	 for (j = 0; j < 3; j++)
	 {
		 if (p[0][j]==1&&p[1][j]==1&&p[2][j]==1)
			 flag=1;
		 else if (p[0][j] == 2 && p[1][j] == 2 && p[2][j] == 2)
			 flag=0;
	 }
	 if (flag == 1)
	 {
		 printf("player win\n");
		 *k = 0;
	 }
	 else if (flag == 0)
	 {
		 printf("comp win\n");
		 *k = 0;
	 }
	 return  *k;
 }


int main()
{
	int arr[3][3] = { 0 };
	int i = 0;
	int j = 0;
	int m = 1;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			arr[i][j] =' ';
	}
	
	
	  print(arr);
	while (m){

		player(arr);
		comp(arr);
		show(arr);
		win(arr,&m);
		
		
	}
		system("pause");
	
	return 0;
}