#include "CommentCover.h"
state g_state = _NULL;
void CommentCover()
{
	DoCoverWork(ReadFile, WriteFile);
}
void DoCoverWork(char *read_file, char *write_file)
{
	printf("×ª»»¿ªÊ¼\n");
	FILE *pfread = fopen(read_file, "r");
	if (pfread == NULL)
	{
		perror("Read File");
		exit(EXIT_FAILURE);
	}
	FILE *pfwrite = fopen(write_file, "w");
	if (pfwrite == NULL)
	{
		perror("Write File");
		fclose(pfread);
		exit(EXIT_FAILURE);
	}
	while (g_state != _END)
	{

		switch (g_state)
		{
		case _NULL:
			DoNULL(pfread, pfwrite);
			break;
		case _C:
			DoC(pfread, pfwrite);
			break;
		case _CPP:
			DoCpp(pfread, pfwrite);
			break;
        default:
			break;
		}
	}
	
}
void DoNULL(FILE *read_file, FILE *write_file)
{
	int frist = 0;
	int scend = 0;
	while (((frist = fgetc(read_file)) != '/') && (frist != EOF))
	{
		fputc(frist, write_file);
	}
	if (frist == EOF)
	{
		g_state = _END;
	}
	else 
	{
		scend = fgetc(read_file);
		switch (scend)
		{
		case '*':
			fputc(frist, write_file);
			fputc('/', write_file);
			g_state = _C;
			break;
		case '/':
			fputc(frist, write_file);
			fputc(scend, write_file);
			g_state = _CPP;
			break;
		default:
			fputc(frist, write_file);
			fputc(scend, write_file);
			break;
		}
	}
}
void DoC(FILE *read_file, FILE *write_file)
{
	int frist = 0;
	int scend = 0;
	int third = 0;
	frist = fgetc(read_file);
	switch (frist)
	{
	case '*':
		scend = fgetc(read_file);
		if (scend == '/')
		{
			third = fgetc(read_file);
			if (third != '\n')
			{
				fputc('\n', write_file);
				
			}
			ungetc(third, read_file);
            g_state = _NULL;
		}
		else
		{
			fputc(frist, write_file);
			fputc(scend, write_file);
		}
		break;
	case '\n':
		fputc(frist, write_file);
		fputc('/', write_file);
		fputc('/', write_file);
		break;
	case EOF:
		g_state = _END;
		break;
	default:
		fputc(frist, write_file);
		break;
	}
	   
	
}
void DoCpp(FILE *read_file, FILE *write_file)
{
	int frist = 0;
	while (((frist = fgetc(read_file)) != '\n')&&(frist!=EOF))
	{
		fputc(frist, write_file);
	}
	if (frist == '\n')
	{
        fputc('\n', write_file);
		g_state = _NULL;
	}
	else
	{
		g_state = _END;
	}
}
void DoEnd(FILE *read_file, FILE *write_file)
{
	fclose(read_file);
	fclose(write_file);
}