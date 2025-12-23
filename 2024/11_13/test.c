#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

#include<string.h>

#include<stdlib.h>

#include<assert.h>

#include<errno.h>

//int main()
//{
//    long num = 0;
//    FILE* fp = NULL;
//    if ((fp = fopen("fname.dat", "r")) == NULL)
//    {
//        printf("Can’t open the file!");
//        exit(0);
//    }
//    while (fgetc(fp) != EOF)
//    {
//        num++;
//    }
//    printf("num=%d\n", num);
//    fclose(fp);
//    return 0;
//}

//#define INT_PTR int*
//typedef int* int_ptr;
//INT_PTR a, b;
//int_ptr c, d;

//设有以下宏定义:
//
//#define N 4
//
//#define Y(n) ((N+2)*n) /*这种定义在编程规范中是严格禁止的*/
//
//
//
//则执行语句：z = 2 * (N + Y(5 + 1)); 后，z的值为（   ）
//                    (4 + (4 + 2) * 5 + 1) = 5 + 6 * 5 = 35


//#define A 2+2
//#define B 3+3
//#define C A*B
//int main()
//{
//	printf("%d\n", C);//C -> A*B -> 2 + 2 * 3 + 3 = 11
//	return 0;
//}

//写一个宏，计算结构体中某变量相对于首地址的偏移，并给出说明
//
//考察：offsetof宏的实现

//#define offsetof(a, b) (int)((char*)&(a) - (char*)&(b))//分别取首地址和变量的地址，强制类型转化相减后再转化成int类型
//
//struct A
//{
//	int a;
//	char b;
//	long long c;
//	char d[10];
//	short e;
//	int f;
//};
//
//int main()
//{
//	struct A test = { 0 };
//	printf("%d", offsetof(test.f, test));
//	return 0;
//}

//写一个宏，可以将一个整数的二进制位的奇数位和偶数位交换。

//0000 0101 0011 0001
//1010 1010 1010 1010  &
//0000 0000 0010 0000  >>1
//0000 0000 0001 0000***
//0000 0101 0011 0001  
//0101 0101 0101 0101  &
//0000 0101 0001 0001  <<1
//0000 1010 0010 0010***
//0000 0000 0001 0000***  |
//0000 1010 0011 0010
//0000 0101 0011 0001  交换成功

//#define jiou(a) ((a & 43690) >> 1) | ((a & 21845) << 1)
//
//int main()
//{
//	int a = 1560;
//	printf("%d", jiou(a));
//	return 0;
//}
//
////1560
////0110 0001 1000
////2340
////1001 0010 0100
////交换成功

