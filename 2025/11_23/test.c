#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main()
{
	int a = 3;
	FILE * fp = fopen("test.txt", "wb");
	fwrite("abc", sizeof(char), 3, fp);
	fclose(fp);
	perror("");
	return 0;
}