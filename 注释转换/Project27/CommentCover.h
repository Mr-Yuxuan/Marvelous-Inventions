#define  _CRT_SECURE_NO_WARNINGS 1
#ifndef __COMMENTCOVER_H__
#define  _CRT_SECURE_NO_WARNINGS 1
#define __COMMENTCOVER_H__
#define ReadFile "input.c"
#define WriteFile "output.c"
#include<stdio.h>
#include<stdlib.h>
typedef enum State
{
	_NULL,
	_C,
	_CPP,
	_END

}state;
void CommetCover();
void DoCoverWork(char *read_file,char *write_file);
void DoNULL(FILE *read_file,FILE *write_file);
void DoC(FILE *read_file, FILE *write_file);
void DoCpp(FILE *read_file, FILE *write_file);
void DoEnd(FILE *read_file, FILE *write_file);
#endif