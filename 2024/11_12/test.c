#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

#include<string.h>

#include<stdlib.h>

#include<assert.h>

#include<errno.h>

//#define MAX_SIZE A+B
//struct _Record_Struct
//{
//	unsigned char Env_Alarm_ID : 4;
//	unsigned char Para1 : 2;
//	unsigned char state;
//	unsigned char avail : 1;
//}*Env_Alarm_Record;
//struct _Record_Struct* pointer = (struct _Record_Struct*)malloc(sizeof(struct _Record_Struct) * MAX_SIZE);
//当A = 2， B = 3时，pointer分配（ ）个字节的空间。

//int main()
//{
//    unsigned char puc[4];//16
//    struct tagPIM
//    {
//        unsigned char ucPim1;//8
//        unsigned char ucData0 : 1;
//        unsigned char ucData1 : 2;
//        unsigned char ucData2 : 3;//8
//    }*pstPimData;//12
//    pstPimData = (struct tagPIM*)puc;
//    memset(puc, 0, 4);
//    pstPimData->ucPim1 = 2;//010
//    pstPimData->ucData0 = 3;//011
//    pstPimData->ucData1 = 4;//100
//    pstPimData->ucData2 = 5;//101
//    printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);//%x十六进制
//    return 0;
//}
//00000010  00101001  00000000  00000000
//  2  29  0  0

//下面代码的结果是：（ ）
//
//enum ENUM_A
//{
//    X1,//253
//    Y1,//254
//    Z1 = 255,
//    A1,//256
//    B1,//257
//};
//
//int main()
//{
//    enum ENUM_A enumA = Y1;
//    enum ENUM_A enumB = B1;
//    printf("%d %d\n", enumA, enumB);
//    /*printf("%d %d %d %d %d ", X1, Y1, Z1, A1, B1);*/
//    return 0;
//}

//#include <stdio.h>
//union Un
//{
//	short s[7];
//	int n;
//};
//int main()
//{
//	printf("%d\n", sizeof(union Un));
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//    union//2
//    {
//        short k;//2
//        char i[2];//2
//    }*s, a;
//    s = &a;
//    s->i[0] = 0x39;
//    s->i[1] = 0x38;
//    printf("%x\n", a.k);
//    return 0;
//}

//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//
//编写一个函数找出这两个只出现一次的数字。
//
//
//
//例如：
//
//有数组的元素是：1，2，3，4，5，1，2，3，4，6
//
//只有5和6只出现1次，要找出5和6.

//int main()
//{
//	int a[10] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 6 };
//	int num = 0;
//	int size = sizeof(a) / sizeof(a[0]);
//	for (int i = 1; i < size; i++)
//	{
//		if (size == 2)
//		{
//			break;
//		}
//		if (a[0] == a[i])
//		{
//			memmove(a , a + 1, sizeof(a[0]) * (size - 1));
//			memmove(a + i - 1, a + i, sizeof(a[0]) * (size - 1));
//			size -= 2;
//			i = 1;
//		}
//	}
//	for (int i = 0; i < 2; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}


//模拟实现strncpy

//char* my_strncpy(char* destination, const char* source, size_t num)
//{
//	assert(destination && source);
//	char* ret = destination;
//	int sum = 0;
//	while (num != sum)
//	{
//		if (*source == '\0')
//		{
//			*destination = *source;
//			destination++;
//		}
//		else
//		{
			//*destination = *source;
			//destination++;
			//source++;
//		}
//		sum++;
//	}
//	return ret;
//}
//
//int main()
//{
//	char a[] = "ABCDEFGHIJKLMNOPQ";
//	char b[] = "abcdefghi";
//	char* str = my_strncpy(a, b, 12);
//	printf("%s", str);
//	return 0;
//}

//char* my_strncat(char* destination, const char* source, size_t num)
//{
//	assert(destination && source);
//	char* ret = destination;
//	int size = sizeof(destination);
//	int sum = 0;
//	destination = destination + size;
//	while (sum != num && *source != '\0')
//	{
//		*destination = *source;
//		destination++;
//		source++;
//		sum++;
//	}
//	*destination = '\0';
//	return ret;
//}
//
//int main()
//{
//	char a[20] = "ABCDEFGHIJK";
//	char b[] = "abcdefg";
//	char* str = my_strncat(a, b, 9);
//	printf("%s", str);
//	return 0;
//}

//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//}

//char* GetMemory(void)
//{
//	char p[] = "hello world";
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}

///* atoi example */
//#include <stdio.h>      /* printf, fgets */
//#include <stdlib.h>     /* atoi */
//
//int main()
//{
//	int i;
//	char buffer[256];
//	printf("Enter a number: ");
//	fgets(buffer, 256, stdin);
//	i = atoi(buffer);
//	printf("The value entered is %d. Its double is %d.\n", i, i * 2);
//	return 0;
//}

//模拟实现atoi

int my_atoi(const char* str)
{
	assert(str);
	while (*str == ' ')//或者32(空格的ascii值是32)
	{
		str++;
	}
	int symb = 1;
	if (*str == '+')
	{
		symb *= 1;
		str++;
	}
	else if (*str == '-')
	{
		symb *= -1;
		str++;
	}
	int size = strlen(str) - 1;
	int ret = 0;
	if (size == 10 && strcmp(str, "2147483647") >= 0 || size > 10)
	{
		return 2147483647;
	}
	for (int i = 0; i < size; i++)
	{
		if (*(str + i) < 48 || *(str + i) > 57)
		{
			return ret * symb;
		}
		else
		{
			ret = ret * 10+ (*(str + i) - 48);
		}
	}
	return ret * symb;
}

int main()
{
	int i;
	char buffer[256];
	printf("Enter a number: ");
	//char * a = NULL;
	fgets(buffer, 256, stdin);
	i = my_atoi(buffer);
	printf("The value entered is %d. Its double is %d.\n", i, i * 2);
	return 0;
}