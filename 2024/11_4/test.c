#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

#include<assert.h>
//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//
//
//
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//
//给定s1 = abcd和s2 = ACBD，返回0.
//
//
//
//AABCD左旋一个字符得到ABCDA
//
//AABCD左旋两个字符得到BCDAA
//
//AABCD右旋一个字符得到DAABC

//void revolve(char * a, char* b, int size)
//{
//	char ex = *a;
//	*a = *b;
//	*b = ex;
//}
//
//int judg(char * a, char * b)
//{
//	int len1 = strlen(a);
//	int len2 = strlen(b);
//	if (len1 != len2)
//	{
//		return 0;
//	}
//	else
//	{
//		for (int i = 0; i < strlen(a) - 1; i++)
//		{
//			revolve(a, b, strlen(a));
//			while (*a == *b)
//			{
//				if (a == '\0')
//				{
//					return 1;
//				}
//			}
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	char s1[] = "AABCF";
//	char s2[] = "BCDAA";
//	int result = judg(s1, s2);
//	if (result == 0)
//	{
//		printf("NO");
//	}
//	else
//	{
//		printf("YES");
//	}
//	return 0;
//}


//模拟实现strlen

//int my_strlen(char* a)
//{
//	int num = 0;
//	while (*a != '\0')
//	{
//		a++;
//		num++;
//	}
//	return num;
//}
//
//int main()
//{
//	char str[] = "abcdef";
//	int len = my_strlen(str);
//	printf("%d", len);
//	return 0;
//}

//模拟实现strcpy

//char* strcpy(char* destination, const char* source);

//void my_strcpy(char* destination, const char* source)
//{
//	while (*destination = *source)
//	{
//		destination++;
//		source++;
//	}
//}
//
//int main()
//{
//	char a[10] = { 0 };
//	char b[] = "abcdefg";
//	my_strcpy(a, b);
//	printf("%s", a);
//	return 0;
//}

//模拟实现strcmp

//int strcmp(const char* str1, const char* str2);

//int my_strcmp(const char* str1, const char* str2)
//{
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0' || *str2 == '\0')
//		{
//			return 0;
//		}
//		str1++;
//		str2++;
//	}
//	if (*str1 > *str2)
//	{
//		return 1;
//	}
//	else
//	{
//		return -1;
//	}
//}
//
//int main()
//{
//	char str1[] = "abcdef";
//	char str2[] = "abcdef";
//	int result = my_strcmp(str1, str2);
//	if (result == 0)
//	{
//		printf("相同");
//	}
//	else if (result > 0)
//	{
//		printf("大于");
//	}
//	else
//	{
//		printf("小于");
//	}
//	return 0;
//}

//模拟实现strcat

//char* strcat(char* destination, const char* source);

//char* my_strcat(char* destination, const char* source)
//{
//	int len1 = strlen(destination);
//	char* origin = destination;
//	while (*(destination + len1) = *source)
//	{
//		destination++;
//		source++;
//	}
//	return origin;
//}
//
//int main()
//{
//	char a[20] = "abcdef";
//	char b[] = "ghijk";
//	printf("%s", my_strcat(a, b));
//	return 0;
//}

//模拟实现strstr

//const char* strstr(const char* str1, const char* str2);
//char* strstr(char* str1, const char* str2);


int check(const char* str1, const char* str2)
{
	while (*str1 == *str2 && *str1 != '\0' && *str2 !='\0')
	{
		str1++;
		str2++;
	}
	if (*str2 == '\0')
	{
		return 1;
	}
	return 0;
}

const char* strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for (int i = 0; i < len1 - len2 + 1; i++)
	{
		if (*str1 == *str2)
		{
			int result = check(str1, str2);
			if (result == 1)
			{
				return str1;
			}
		}
		str1++;
	}
	return NULL;
}

int main()
{
	char a[] = "abccdef";
	char b[] = "cde";
	char * result = strstr(a, b);
	printf("%s", result);
	return 0;
}