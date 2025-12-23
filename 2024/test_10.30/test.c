#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>

typedef void (*pf_t) (int, void (*) (int));

//struct sign
//{
//	int a;
//	float b;
//}p1, p2;
//
//int main()
//{
//	scanf("%d %f", &p1.a, &p2.b);
//
//	return 0;
//}

//int main()
//{
//    char str1[] = "hello bit.";
//    char str2[] = "hello bit.";
//    char* str3 = "hello bit.";
//    char* str4 = "hello bit.";
//    if (str1 == str2)
//        printf("str1 and str2 are same\n");
//    else
//        printf("str1 and str2 are not same\n");
//
//    if (str3 == str4)
//        printf("str3 and str4 are same\n");
//    else
//        printf("str3 and str4 are not same\n");
//
//    return 0;
//    
//}

//int main()
//{
//	int* p = NULL;
//	int arr[10] = { 0 };
//	p = &arr;
//	return 0;
//}

//int main()
//{
//	int input = 0;
//	scanf("%d", &input);
//	int a[4][4] = { 1, 2, 3, 4,
//					2, 3, 4, 5,
//					3, 4, 5, 6,
//					4, 5, 6, 7 };
//	int( *b )[4] = a;
//	int i = 3;//从一行的最高位读起
//	int num = 0;//作为b的计数器
//	while (1)
//	{
//		if (i < 0 && num > 3)//超出范围，以此作为找不到的条件
//		{
//			printf("找不到");
//			break;
//		}
//		else
//		{
//			if (input > (*b)[i])
//			{
//				b++;
//				num++;
//			}
//			else if (input < (*b)[i])
//			{
//				i--;
//			}
//			else
//			{
//				printf("存在");
//				break;
//			}
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	char str[100] = { 0 };
//	scanf("%s", str);
//	scanf("%d", &n);
//	char* size = NULL;
//	int SIZE = 0;
//	for (int i = 0; i < 100; i++)
//	{
//		if (str[i] == '\0')
//		{
//			size = str + i;
//			SIZE = i;
//			break;
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		*(size + i) = *(str + i);
//		*(str + i) = 0;
//	}
//	for (int i = n - 1; i < SIZE + n ; i++)
//	{
//		printf("%c", str[i]);
//	}
//	return 0;
//}

//int judg(char a[], char b[])
//{
//	int size_1 = 0;
//	int size_2 = 0;
//	for (int i = 0; i < 100; i++)
//	{
//		if (a[i] == '\0')
//		{
//			size_1 = i;
//			break;
//		}
//	}
//
//	for (int i = 0; i < 100; i++)
//	{
//		if (a[i] == '\0')
//		{
//			size_2 = i;
//			break;
//		}
//	}
//
//	if (size_1 != size_2)
//	{
//		return 0;
//	}
//	else
//	{
//
//	}
//
//}

//int main()
//{
//	int a[5] = { 5, 4, 3, 2, 1 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));
//	return 0;
//}

//int main()
//{
//	int aa[2][5] = { 10,9,8,7,6,5,4,3,2,1 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//	return 0;
//}

//int main()
//{
//	char a[10] = "aj\0bjgfhd";
//	char* b = "ahd";
//	strcat(a, b);
//	return 0;
//}

//int main()
//{
//	printf("%c", tolower(''));
//	return 0;
//}

int main()
{
	int a = 'a';
	printf("%c", a);
	return 0;
}
