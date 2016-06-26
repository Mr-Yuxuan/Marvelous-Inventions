#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TEL 12
#define MAX_ADDR 15
#define MAX 1000
typedef struct Peo
{
	char name[MAX_NAME];
	int  age;
	char sex[MAX_SEX];
	char tel[MAX_TEL];
	char adder[MAX_ADDR];
}Peo;
#define P (Peo *)malloc(sizeof(Peo)*100)

typedef struct Book
{
	Peo *peo;
	int count;
}Book;
enum 
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODEFY,
	SHOW,
	CLR,
	SORT
};
void init(Book *book);
void add(Book *book);
void del(Book *book);
void modefy(Book *book);
void serach(Book *book);
void clear(Book *book);
void sort(Book *book);
void show(Book *book);
void menu();