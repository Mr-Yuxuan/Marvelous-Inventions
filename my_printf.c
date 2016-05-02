#include<stdio.h>
#include<stdarg.h>
void my_printf(const char *p, ...)
{
	char c;
	char *s;
	va_list arg;
	va_start(arg, p);
	while (*p)
	{
		if ((*p != 'c')&&(*p != 's'))
		{
			putchar(*p);
			p++;
		}
		
		else  if (*p == 'c')
		{
			c = (char)va_arg(arg, int);
			putchar(c);
			p++;
			
		}
		else if (*p == 's')
		{
			s = va_arg(arg, char*);
			puts(s);
			p++;
		}
	}
	va_end(arg);
}
int main()
{
	my_printf("scccc\n","hello",'w','o','r','d');
	system("pause");
	return 0;
}