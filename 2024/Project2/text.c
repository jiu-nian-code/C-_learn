#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<Windows.h>
#include<time.h>

//int main()
//{
//	int price = 1;
//	int money = 0;
//	while (scanf("%d", &money) != EOF)
//	{
//		int result = money / price;//喝的瓶数
//		int num = result;//剩的瓶子数
//		while (num != 1)
//		{
//			result = result + num / 2;
//			num = num / 2 + num % 2;
//		}
//		printf("能喝%d瓶\n", result);
//	}
//	return 0;
//}

//int main()
//{
//	char a[13][13] = { 0 };
//	for (int i = 0; i <= 6; i++)
//	{
//		for (int j = 0; j < i * 2 + 1; j++)
//		{
//			a[i][6 - i + j] = '*';
//		}
//	}
//	for (int i = 12; i > 6; i--)
//	{
//		for (int j = 0; j < (12 - i) * 2 + 1; j++)
//		{
//			a[i][-6 + i + j] = '*';
//		}
//	}
//	for (int i = 0; i < 13; i++)
//	{
//		for (int j = 0; j < 13; j++)
//		{
//			if (a[i][j] == '\0')
//				printf(" ");
//			else
//				printf("%c", a[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//int main()
//{
//	int result = 0;//各项n次方和
//	int num = 0;//运算时替换i
//	int dig = 0;//存放位数
//	int sum = 1;//各项的n次方
//	for (int i = 1; i < 100000; i++)
//	{
//		num = i;//先替换i
//		while (num != 0)//计算位数
//		{
//			num = num / 10;
//			dig++;
//
//		}
//		num = i;//再次重置num，下面循环也会用到
//		while (num != 0)//计算各项n次方和
//		{
//			for (int j = 0; j < dig; j++)
//			{
//				sum = sum * (num % 10);
//			}//利用for循环计算各项n次方
//			result = result + sum;
//			num = num / 10;//算完减一位
//			sum = 1;//循环内sum的值发生了改变且需要再次利用，所以重置
//		}
//		dig = 0;//重置位数
//		if(i == result)//水仙花数的判断依据
//			printf("%d ", result);//打印
//		result = 0;//重置结果
//	}
//	return 0;
//}
//int main()
//{
//	int a = 0;//输入值
//	int num = 0;//单个数
//	int power = 0;//次方数
//	int sum = 0;//总合
//	scanf("%d", &a);
//	int term = a;
//	for (int i = 0; i < 5; i++)//算总合
//	{
//		for (int j = 0; j <= i; j++)//算单个数
//		{
//			for (int k = 0; k <= j; k++)//算位数
//			{
//				term = term * 10;
//			}
//			term = term / 10;
//			num = num + term;
//			term = a;//重置，不然指数爆炸
//		}
//		sum = sum + num;
//		num = 0;//重置
//	}
//	printf("%d", sum);
//	return 0;
//}
//int main()
//{
//	int a = 1;
//	int b = 1;
//	int c = 0;
//	int n = 0;
//	while (scanf("%d", &n) != EOF)
//	{
//		if (n <= 2)
//		{
//			printf("%d\n", 1);
//		}
//		else {
//			for (int i = 2; i < n; i++)
//			{
//				c = a + b;
//				a = b;
//				b = c;
//			}
//			printf("%d\n", b);
//		}
//		a = 1;
//		b = 1;
//		c = a + b;
//	}
//	return 0;
//}
//int fei(int n)
//{
//	if (n <= 2) {
//		return 1;
//	}
//	else
//	{
//		return (fei(n - 1) + fei(n - 2));
//	}
//}
//
//int main()
//{
//	int num = 0;
//	while (scanf("%d", &num) != EOF)
//	{
//		int result = fei(num);
//		printf("%d\n", result);
//		result = 0;
//	}
//	return 0;
//}



//int fei(int n)
//{
//	if (n <= 2) {
//		return 1;
//	}
//	else
//	{
//		return (fei(n - 1) + fei(n - 2));
//	}
//}
//
//int main()
//{
//again :
//	printf("**********************************************\n");
//	printf("****请选择：1.用递归函数求斐波那契数**********\n");
//	printf("************2.用非递归方法求斐波那契数********\n");
//	printf("************3.结束****************************\n");
//	printf("**********************************************\n");
//	int choose = 0;
//	scanf("%d", &choose);
//	system("cls");
//	switch (choose)
//	{
//	case 1 :
//		int num = 0;
//		scanf("%d", &num);
//		int result = fei(num);
//		printf("%d\n", result);
//		result = 0;
//		goto again;
//		break;
//	case 2 :
//		int a = 1;
//		int b = 1;
//		int c = 0;
//		int n = 0;
//		scanf("%d", &n);
//		if (n <= 2)
//		{
//			printf("%d\n", 1);
//		}
//		else {
//			for (int i = 2; i < n; i++)
//			{
//				c = a + b;
//				a = b;
//				b = c;
//			}
//			printf("%d\n", b);
//		}
//		goto again;
//		break;
//	case 3 :
//		printf("感谢使用\n");
//		break;
//	}
//	return 0;
//}
//int power(int n, int k)
//{
//	if (k == 1) 
//	{
//		return n;
//	}
//	else
//	{
//		return (n * power(n, k - 1));
//	}
//}
//
//int main()
//{
//	int N = 0;
//	int K = 0;
//	while (scanf("%d %d", &N, &K) != EOF)
//	{
//		int result = power(N, K);
//		printf("结果是%d\n", result);
//	}
//	return 0;
//}

//int sum(int n)
//{
//	int replace = n;//替换n
//	int dig = 0;//位数
//	int ret = 0;
//	while (replace != 0)
//	{
//		ret = ret + replace % 10;
//		replace = replace / 10;
//	}
//	return ret;
//}
//
//int main()
//{
//	int number = 0;
//	while (scanf("%d", &number) != EOF)
//	{
//		int result = sum(number);
//		printf("%d\n", result);
//	}
//	return 0;
//}

//int power(int n)
//{
//	if (n == 1)
//		return n;
//	else
//		return n * power(n - 1);
//}
//
//int main()
//{
//again:
//	printf("**********************************************\n");
//	printf("****请选择：1.用递归函数求阶乘****************\n");
//	printf("************2.用非递归方法求阶乘**************\n");
//	printf("************3.结束****************************\n");
//	printf("**********************************************\n");
//	int choose = 0;
//	scanf("%d", &choose);
//	system("cls");
//	switch (choose)
//	{
//	case 1:
//	{
//		int a = 0;
//		scanf("%d", &a);
//		int result = power(a);
//		printf("%d\n", result);
//		goto again;
//	}
//	case 2:
//	{
//		int a = 0;
//		int result = 1;
//		scanf("%d", &a);
//		for (int i = a; i > 0; i--)
//		{
//			result = result * i;
//		}
//		printf("%d\n", result);
//		goto again;
//	}
//	case 3:
//	{
//		printf("谢谢使用");
//		break;
//	}
//	}
//	return 0;
//}

//int print(int n)
//{
//	if (n % 10 == 0)
//	{
//		return n;
//	}
//	else
//	{
//		print(n / 10);
//		printf("%d ", n % 10);
//	}
//
//}
//
//int main()
//{
//	int a = 0;
//	while (scanf("%d", &a) != EOF)
//	{
//		print(a);
//	}
//	return 0;
//}

//int main()
//{
//	int a[9] = { 1, 2, 3, 4, 5, 1, 2, 3, 4 };
//	int n = 0;
//	for (int i = 0; i< 9; i++)
//	{
//		for (int j = 0; j < 9; j++)
//		{
//			if ((a[i] ^ a[j]) == 0)
//			{
//				n++;
//			}
//		}
//		if (n == 1)
//			printf("%d", a[i]);
//		n = 0;
//	}
//	return 0;
//}

//int main()
//{
//	int a = 1;
//	int b = 3;
//	printf("交换前a=%d b=%d\n\n", a, b);
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("交换前a=%d b=%d\n", a, b);
//	return 0;
//}

//int sum(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		n = n & (n - 1);
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	int num = 0;
//	while (scanf("%d", &num) != EOF)
//	{
//		printf("%d\n", sum(num));
//	}
//}

//int main()
//{
//	int ji[16] = { 0 };
//	int ou[16] = { 0 };
//	int input = 0;
//	while (scanf("%d", &input) != EOF)
//	{
//		for (int i = 0; i < 16; i++)
//		{
//				ji[i] = input & 1;
//				input = input >> 1;
//				ou[i] = input & 1;
//				input = input >> 1;
//		}
//		printf("奇数位； ");
//		for (int i = 0; i < 16; i++)
//		{
//			printf("%d ", ji[i]);
//		}
//		printf("\n");
//		printf("偶数位； ");
//		for (int i = 0; i < 16; i++)
//		{
//			printf("%d ", ou[i]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	while (scanf("%d %d", &a, &b) != EOF)
//	{
//		int diff = a ^ b;
//		int count = 0;
//		while (diff)
//		{
//			diff = diff & (diff - 1);
//			count++;
//		}
//		printf("%d\n", count);
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int i = 1;
//    int ret = (++i) + (++i) + (++i);
//    printf("ret = %d\n", ret);
//    return 0;
//}

//#include <stdio.h>
//int i;
//int main()
//{
//
//    i--;
//    int a = sizeof(i);
//    if (i > sizeof(i))
//    {
//        printf(">\n");
//    }
//    else
//    {
//        printf("<\n");
//    }
//    return 0; 
//}

//int main() 
//{
//	int a = 1;
//	char* pa = (char*)&a;
//	if (*pa == 1)
//	{
//		printf("小端");
//	}
//	else
//	{
//		printf("大端");
//	}
//	return 0;
//}

//int main()
//{
//	int a = -1;
//	unsigned int b= (unsigned int)a;
//	printf("%u", b);
//	return 0;
//}
////-1
////1000000000000000001
////1111111111111111110
////1111111111111111111

int main()
{

	return 0;
}

//-1-1
//-1
//100000000000001
//111111111111110
//111111111111111
//1111111111111111

