#define _CRT_SECURE_NO_WARNINGS 1

#include"contast.h"
int main()
{
	Book book;
	init(&book);
	int input = 1;
	while (input)
	{
		
		menu();
		printf("ÇëÑ¡ÔñÑ¡Ïî:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			add(&book);
			break;
		case DEL:
			del(&book);
			break;
		case SEARCH:
			serach(&book);
			break;
		case MODEFY:
			modefy(&book);
			break;
		case SHOW:
			show(&book);
			break;
		case CLR:
			clear(&book);
			break;
		case SORT:
			sort(&book);
			break;
		case EXIT:
			exit(0);
			break;
		default:
			break;
		}
		/*system("cls");*/
	}
	free(book.peo);
	return 0;
}
