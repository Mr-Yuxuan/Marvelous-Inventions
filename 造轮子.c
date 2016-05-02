//简单strstr的实现
#include<stdio.h>
#include<assert.h>
char *my_strstr(char *dest, const char *src)
{
	assert(dest);
	assert(src);
	char *p = NULL;
	while (*dest)
	{
		while (*src)
		{
			if (*dest == *src)
			{
				dest++;
				src++;
			}
			else
				break;
		}
		if (*src == 0)
		{
			return p;
		}
		else
		{
			dest++;
			p = dest;
		}
	}
	return p;
}
int main()
{
	char arr[] = "abcdef";
	char brr[] = "cd";
	char *q=my_strstr(arr, brr);
	printf("%s\n", q);
	system("pause");
	return 0;
}
//简单strcpy实现
#include<stdio.h>
#include<assert.h>
char *my_strcpy(char *dest,const char *src)
{
	assert(dest);
	assert(src);
	char *q = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return q;
}
int main()
{
	char arr[] = "abcd";
	char brr[10] = { 0 };
	printf("%s\n", my_strcpy(brr, arr));
	system("pause");
	return 0;
}
//strlen的三种实现
#include<stdio.h>
#include<assert.h>
int my_strlen1(const char *src)
{
	assert(src);
	int count = 0;
	while (*src++)
	{
		count++;
	}
	return count;
}
int my_strlen2(const char *src)
{
	assert(src);
	if (*src > 0)
		return 1 + my_strlen2(src+1);
	else
		return 0;
}
int my_strlen3(const char *src)
{
	assert(src);
	char *p = src;
	while (*src++)
	{
		;
	}
	return src - p-1;
}
int main()
{
	char arr[] = "abcdef";
	int ret1 = my_strlen1(arr);
	int ret2 = my_strlen2(arr);
	int ret3 = my_strlen3(arr);
	printf("%d %d %d\n", ret1, ret2, ret3);
	system("pause");
	return 0;
}
//简单strcat实现
#include<stdio.h>
#include<assert.h>
char *my_strcat(char *dest,const char *src)
{
	assert(dest);
	assert(src);
	char *p = dest;
	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
		*dest++ = *src++;
	}
	*(dest + 1) ='\0';
	return p;
}
int main()
{
	char arr[10] = "abcd";
	char brr[] = "cdef";
	printf("%s\n", my_strcat(arr, brr));
	system("pause");
	return 0;
}
//简单strcmp实现
#include<stdio.h>
#include<assert.h>
int my_strcmp(const char *buf1,const char *buf2)
{
	assert(buf1);
	assert(buf2);
	while (*buf1 == *buf2)
	{
		buf1++;
		buf2++;
	}
	if (*buf1 == 0)
		return 0;
	else
		return (*buf1 - *buf2);
}
int main()
{
	char arr[] = "abcd";
	char brr[] = "abde";
	int ret = my_strcmp(arr, brr);
	printf("%d\n", ret);
	system("pause");
	return 0;
}
//简单memcpy实现
#include<stdio.h>
#include<assert.h>
void *my_memcpy(void *dest,const void *src, int count)
{
	assert(src);
	char *buf1 = (char *)dest;
	char *buf2 = (char *)src;
	void *ret = buf1;
	while (count--)
	{
		(*buf1++) = (*buf2++);
	}
	return ret;
}
int main()
{
	char arr[] = "abcd";
	char brr[10] = { 0 };
	printf("%s\n", my_memcpy(brr, arr, 5));
	system("pause");
	return 0;
}
//简单memmove实现
#include<stdio.h>
#include<assert.h>
void *my_memmove(const void *dest,const void *src, int count)
{
	assert(dest);
	assert(src);
	char *buf1 = (char *)dest;
	char *buf2 = (char *)src;
	void *ret = buf1;
	if ((buf1<(buf2 + count)) && (buf1>buf2))
	{
		while (count--)
		{
			*(buf1 + count) = *(buf2 + count);
		}
	}
	else
	{
		while (count--)
		{
			*buf1++ = *buf2++;
		}
	}
	return ret;
}
int main()
{
	char arr[] = "123456789";
	my_memmove(arr + 4, arr + 2, 4);
	printf("%s", arr);
	system("pause");
	return 0;
}