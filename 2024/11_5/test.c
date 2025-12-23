#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

#include<assert.h>

#include<string.h>

//模拟实现memcpy

//void* memcpy(void* destination, const void* source, size_t num);

//void* my_memcpy(void* destination, const void* source, size_t num)
//{
//	void* ret = destination;
//	assert(destination && source);
//	while (num--)
//	{
//		*(char*)destination = *(char*)source;
//		destination = (char*)destination + 1;
//		source = (char*)source + 1;
//	}
//	return ret;
//}
//
//
//int main()
//{
//	char a[] = "efg";
//	char b[20] = "abcd";
//	my_memcpy(b + 4, a, sizeof(a));
//	printf("%s", b);
//	return 0;
//}

//模拟实现memmove

//void* memmove(void* destination, const void* source, size_t num);

//void* my_memmove(void* destination, const void* source, size_t num)
//{
//	assert(destination && source);
//	void* ret = destination;
//	char* dest = (char*)destination + num -1;
//	char* sour = (char*)source + num - 1;
//	if (destination > source)
//	{
//		while(num--)
//		{
//			*dest = *sour;
//			dest--;
//			sour--;
//		}
//	}
//	else
//	{
//		while (num--)
//		{
//			*(char*)destination = *(char*)source;
//			destination = (char*)destination + 1;
//			source = (char*)source + 1;
//		}
//	}
//	return ret;
//}
//
//int main()
//{
//	char b[20] = "abcdefg";
//	my_memmove(b + 2, b, 3);
//	printf("%s\n", b);
//	return 0;
//}


//******************************************************************************************
//struct A
//{
//	int a;//7
//	short b;//9
//	int c;//15
//	char d;//16
//};
//
//struct B
//{
//	int a;//7
//	short b;//9
//	char c;//10
//	int d;//16
//};
//
//
//int main()
//{
//	printf("%d", sizeof(struct A));
//	printf("%d", sizeof(struct B));
//	return 0;
//}


//#pragma pack(4)/*编译选项，表示4字节对齐 平台：VS2013。语言：C语言*/
////假设long 是4个字节
//int main(int argc, char* argv[])
//{
//    struct tagTest1
//    {
//        short a;//0 1
//        char d;//2
//        long b;//4 5 6 7
//        long c;//8 9 10 11
//    };//12
//    struct tagTest2
//    {
//        long b;//0 1 2 3
//        short c;//4 5
//        char d;//6
//        long a;//8 9 10 11
//    };//12
//    struct tagTest3
//    {
//        short c;//0 1
//        long b;//4 5 6 7
//        char d;//8
//        long a;//12 13 14 15
//    };//16
//    struct tagTest1 stT1;
//    struct tagTest2 stT2;
//    struct tagTest3 stT3;
//
//    printf("%d %d %d", sizeof(stT1), sizeof(stT2), sizeof(stT3));
//    return 0;
//}
//#pragma pack()

//描述
//输入NxM矩阵，矩阵元素均为整数，计算其中大于零的元素之和。
//
//输入描述：
//第一行为N M(N: 矩阵行数；M: 矩阵列数, 且M, N <= 10)，接下来的N行为矩阵各行。
//输出描述：
//一行，其中大于零的元素之和。

//int main() 
//{
//    int a, b;
//    while (scanf("%d %d", &a, &b) != EOF) 
//    {
//        int input = 0;
//        int num = 0;
//        for (int i = 0; i < a; i++)
//        {
//            for (int j = 0; j < b; j++)
//            {
//                scanf("%d", &input);
//                if (input > 0)
//                {
//                    num = num + input;
//                }
//            }
//        }
//        printf("%d\n", num);
//    }
//    return 0;
//}

//小乐乐在课上学习了二进制八进制与十六进制后，对进制转换产生了浓厚的兴趣。因为他的幸运数字是6，所以他想知道一个数表示为六进制后的结果。请你帮助他解决这个问题。
//
//输入描述：
//输入一个正整数n(1 ≤ n ≤ 109)
//
//输出描述：
//输出一行，为正整数n表示为六进制的结果

//int main()
//{
//	long long input = 0;
//	long long num = 1;
//	scanf("%lld", &input);
//	long long result = 0;
//	do
//	{
//		result = result + num * (input % 6);
//		num = num * 10;
//		input = input / 6;
//	} while (input >= 1);
//	printf("%lld", result);
//	return 0;
//}

//描述
//KiKi有一个矩阵，他想知道转置后的矩阵（将矩阵的行列互换得到的新矩阵称为转置矩阵），请编程帮他解答。
//
//输入描述：
//第一行包含两个整数n和m，表示一个矩阵包含n行m列，用空格分隔。(1≤n≤10, 1≤m≤10)
//
//从2到n + 1行，每行输入m个整数（范围 - 231~231 - 1），用空格分隔，共输入n * m个数，表示第一个矩阵中的元素。
//
//输出描述：
//输出m行n列，为矩阵转置后的结果。每个数后面有一个空格。

//int main()
//{
//	int a[10][10] = { 0 };
//	int n = 0;
//	int m = 0;
//	scanf("%d %d", &n, &m);
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			scanf("%d", &a[i][j]);
//		}
//	}
//	for (int j = 0; j < m; j++)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			printf("%d ", a[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//有一个整数序列（可能有重复的整数），现删除指定的某一个整数，输出删除指定数字之后的序列，序列中未被删除数字的前后位置没有发生改变。

int main()
{
	int a[50] = { 0 };
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	int m = 0;
	scanf("%d", &m);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == m)
		{
			;
		}
		else
		{
			printf("%d ", a[i]);
		}
	}
	return 0;
}