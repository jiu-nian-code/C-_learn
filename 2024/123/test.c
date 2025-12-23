#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

#include<stdlib.h>

#include<time.h>

#include<math.h>

//int main()
//{
//	char* a[] = {'a', 'b', 'c'};
//	for (int i = 0; i < 3; i++)
//	{
//		printf("%c\n", a[i]);
//	}
//	return 0;
//}
//int num = 10;
//
//void print()
//{
//    printf("%d", num);
//}
//
//
//int main()
//{
//    int num = 1;
//    printf("num = %d\n", num);
//    print();
//    return 0;
//}

//int main()
//{
//	int input = 0;
//	while (scanf("%d", &input) != EOF)
//	{
//		if (input < 0)
//		{
//			printf("%d\n", 1);
//		}
//		else if (input == 0)
//		{
//			printf("%d\n", 0);
//		}
//		else if (input > 0)
//		{
//			printf("%d\n", -1);
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	printf("%d %d", a / b, a % b);
//	return 0;
//}

//void input(float*  group[5])
//{
//	for (int i = 0; i < 5; i++)
//	{
//		scanf("%f %f %f %f %f", group[i], group[i] + 1, group[i] + 2, group[i] + 3, group[i] + 4);
//	}
//}
//
//void print(float* group[])
//{
//	int num = 0;
//	float sum = 0;
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			printf("%.1f ", *(group[i] + j));
//			num++;
//			sum += *(group[i] + j);
//		}
//		if (num == 5)
//		{
//			printf("%.1f\n", sum);
//			sum = 0;
//			num = 0;
//		}
//	}
//}
//
//
//int main()
//{
//	float student_1[5] = { 0 };
//	float student_2[5] = { 0 };
//	float student_3[5] = { 0 };
//	float student_4[5] = { 0 };
//	float student_5[5] = { 0 };
//	float* group[5] = { student_1, student_2, student_3, student_4, student_5 };
//	input(group);
//	print(group);
//	return 0;
//}

//int main()
//{
//	int input = 0;
//	while (scanf("%d", &input) != EOF)
//	{
//		for (int i = 0; i < input; i++)
//		{
//			printf("%c", '*');
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int input = 0;
//	scanf("%d", &input);
//	printf("%d %d %d", input / 3600, (input % 3600) / 60, (input % 3600) % 60);
//	return 0;
//}

//int main()
//{
//	int t = 0;
//	while (scanf("%d", &t) != EOF)
//	{
//		if (t > 0)
//		{
//			printf("%d\n", 1);
//		}
//		else if (t == 0)
//		{
//			printf("%.1f\n", 0.5);
//		}
//		else
//		{
//			printf("%d\n", 0);
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	if (a > b)
//	{
//		printf("%d", a);
//
//	}
//	else if(a < b)
//	{
//		printf("%d", b);
//	}
//	else
//	{
//		printf("error");
//	}
//	return 0;
//}

//int main()
//{
//	int input = 0;
//	while(scanf("%d", &input) != EOF)
//	{
//		if (input % 2 == 0)
//		{
//			printf("Even\n");
//		}
//		else
//		{
//			printf("Odd\n");
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int input = 0;
//	while (scanf("%d", &input) != EOF)
//	{
//		if (input >= 60)
//		{
//			printf("Pass\n");
//		}
//		else
//		{
//			printf("Fail\n");
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int input = 0;
//	while (scanf("%d", &input) != EOF)
//	{
//		if (input >= 90 && input <= 100)
//		{
//			printf("Perfect");
//		}
//	}
//	return 0;
//}

//int main()
//{
//	for (int i = 1; i < 100; i ++)
//	{
//		if (i % 3 == 0)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int a, b, c = 0;
//	while (scanf("%d %d %d", &a, &b, &c) != EOF)
//	{
//		if (a > b)
//		{
//			if (b > c)
//			{
//				printf("%d %d %d\n", a, b, c);
//			}
//			else
//			{
//				if (a > c)
//				{
//					printf("%d %d %d\n", a, c, b);
//				}
//				else
//				{
//					printf("%d %d %d\n", c, a, b);
//				}
//			}
//		}
//		else
//		{
//			if (a > c)
//			{
//				printf("%d %d %d\n", b, a, c);
//			}
//			else
//			{
//				if (b > c)
//				{
//					printf("%d %d %d\n", b, c, a);
//				}
//				else
//				{
//					printf("%d %d %d\n", c, b, a);
//				}
//			}
//		}
//	}
//	return 0;
//}

//int main()
//{
//	for (int i = 101; i < 200; i += 2)
//	{
//		for (int j = 2; j < i; j++)
//		{
//			if (i % j == 0)
//			{
//				printf("%d ", i);
//				break;
//			}
//		}
//	}
//	return 0;
//}

//int main()
//{
//	for (int i = 1000; i < 2001; i += 4)
//	{
//		if (i % 100 != 0)
//		{
//			printf("%d ", i);
//		}
//		else if(i % 400 == 0)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//int compare(int x, int y)//x小y大
//{
//	int result = 0;
//	for (int i = x; i > 0; i--)
//	{
//		if (x % i == 0 && y % i == 0)
//		{
//			result = i;
//			break;
//		}
//	}
//	return result;
//}
//
//
//int main()
//{
//	int a, b = 0;
//	int back = 0;
//	scanf("%d %d", &a, &b);
//	if (a > b)
//	{
//		back = compare(b, a);
//	}
//	else if(b < a)
//	{
//		back = compare(a, b);
//	}
//	else
//	{
//		back = a;//ab都行
//	}
//	printf("%d", back);
//	return 0;
//}

//int main()
//{
//	for (int i = 1; i < 10; i++)
//	{
//		for (int j = 1; j < i + 1; j++)
//		{
//			printf("%d * %d = %d\t", i, j, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int a[10] = { 0 };
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	int max = a[0];
//	for (int i = 1; i < 10; i++)
//	{
//		if (max < a[i])
//		{
//			max = a[i];
//		}
//	}
//	printf("%d", max);
//	return 0;
//}

//int main()
//{
//	int k = -1;
//	float sum = 0;
//	for (float i = 1; i < 101; i++)
//	{
//		k *= -1;
//		sum = sum + k * (1 / i);
//	}
//	printf("%.6f", sum);
//	return 0;
//}

//int main()
//{
//	for (int i = 9; i < 100; i++)
//	{
//		if ((i % 10) == 9 || (i % 100) / 10 == 9)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int input = 0;
//	while (scanf("%d", &input) != EOF)
//	{
//		int left = 0;
//		int right = 9;
//		while(1)
//		{
//			if (left > right)
//			{
//				printf("找不到\n");
//				break;
//			}
//			if (input > a[(left + right) / 2])
//			{
//				left = ((left + right) / 2) + 1;
//			}
//			else if (input < a[(left + right) / 2])
//			{
//				right = ((left + right) / 2) - 1;
//			}
//			else if(input == a[(left + right) / 2])
//			{
//				printf("%d\n", (left + right) / 2);
//				break;
//			}
//		}
//	}
//	return 0;
//}

//int main()
//{
//	srand(time(NULL));
//	int guess = 0;
//	int num = rand() % 100 + 1;
//	while (1)
//	{
//		scanf("%d", &guess);
//		if (num == guess)
//		{
//			printf("猜对了\n");
//			break;
//		}
//		else if (num > guess)
//		{
//			printf("猜小了\n");
//		}
//		else
//		{
//			printf("猜大了\n");
//		}
//	}
//	return 0;
//}

//int main()
//{
//	long long input = 0;
//	long long num = 0;
//	scanf("%lld", &input);
//	for (long long i = 1; i < input + 1; i++)
//		{
//			num += i;
//		}
//		printf("%lld\n", num);
//		num = 0;
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d", (n / 12) * 4 + 2);
//	return 0;
//}


//void power(int a)
//{
//	for (int i = 0; i < a + 1; i++)
//	{
//		for (int j = 0; j < i + 1; j++)
//		{
//			printf("%d * %d = %d\t", i, j, i * j);
//		}
//		printf("\n");
//	}
//}
//
//
//int main()
//{
//	int size = 0;
//	scanf("%d", &size);
//	power(size);
//	return 0;
//}


//void exchange(int* p1, int* p2)
//{
//	int ex = *p1;
//	*p1 = *p2;
//	*p2 = ex;
//}
//
//int main()
//{
//	int a, b = 0;
//	scanf("%d %d", &a, &b);
//	exchange(&a, &b);
//	printf("%d %d", a, b);
//	return 0;
//}

//void run(int a)
//{
//	if (a % 4 == 0 && a % 100 != 0)
//	{
//		printf("是闰年");
//	}
//	else if (a % 400 == 0)
//	{
//		printf("是闰年");
//	}
//	else
//	{
//		printf("不是闰年");
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int year = 0;
//	while (scanf("%d", &year) != EOF)
//	{
//		run(year);
//	}
//	return 0;
//}

//int is_prime(int a)
//{
//	int result = 0;
//	for (int i = 2; i < a; i++)
//	{
//		if (a % i == 0)
//		{
//			result = 1;
//			break;
//		}
//	}
//	return result;
//}
//
//int main()
//{
//	int input = 0;
//	scanf("%d", &input);
//	int back = is_prime(input);
//	if (back == 0)
//	{
//		printf("是素数\n");
//	}
//	else if (back == 1)
//	{
//		printf("不是素数\n");
//	}
//	for (int i = 101; i < 200; i += 2)
//	{
//		int Back = is_prime(i);
//		if (Back == 0)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//int power(int a, int b)
//{
//	if (b == 1)
//	{
//		return a;
//	}
//	else
//	{
//		return a * power(a, b - 1);
//	}
//}
//
//int main()
//{
//	int n, k = 0;
//	scanf("%d %d", &n, &k);
//	int result = power(n, k);
//	printf("%d", result);
//	return 0;
//}

//int summing(int a)
//{
//	if (a / 10 == 0)
//	{
//		return a;
//	}
//	else
//	{
//		return a % 10 + summing(a / 10);
//	}
//}
//
//
//int main()
//{
//	int b = 0;
//	scanf("%d", &b);
//	int result = summing(b);
//	printf("%d", result);
//	return 0;
//}

//int strlen_1(char *a)
//{
//	if (*a == '\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return 1 + strlen_1(a + 1);
//	}
//}
//
//int strlen_2(char* a)
//{
//	int size = 0;
//	while (*a != '\0')
//	{
//		a++;
//		size++;
//	}
//	return size;
//}
//
//int main()
//{
//	int result_1 = strlen_1("abcdef");
//	int result_2 = strlen_2("cghbdg");
//	printf("%d %d", result_1, result_2);
//	return 0;
//}

//void print(int a)
//{
//	if (a / 10 != 0)
//	{
//		print(a / 10);
//	}
//	printf("%d ", a % 10);
//}
//
//int main()
//{
//	int input = 0;
//	scanf("%d", &input);
//	print(input);
//	return 0;
//}

//int feibo_1(int num)
//{
//	if (num == 1 || num == 2)
//	{
//		return 1;
//	}
//	else
//	{
//		return feibo_1(num - 1) + feibo_1(num - 2);
//	}
//}
//
//int feibo_2(int num)
//{
//	int a = 1;
//	int b = 1;
//	for (int i = 2; i < num; i++)
//	{
//		int c = a + b;
//		a = b;
//		b = c;
//	}
//	return b;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int result = feibo_1(n);
//	int Result = feibo_2(n);
//	printf("%d\n", result);
//	printf("%d\n", Result);
//	return 0;
//}

//int my_strlen(char* s)
//{
//	int count = 0;
//	while (*s != '\0')
//	{
//		count++;
//		s++;
//	}
//	return count;
//}
//void reverse_string(char* str)
//{
//	int len = my_strlen(str);
//	char tmp = *str;
//	*str = *(str + len - 1);
//	*(str + len - 1) = '\0';
//	if (my_strlen(str + 1) > 1)
//	{
//		reverse_string(str + 1);
//	}
//	*(str + len - 1) = tmp;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	reverse_string(arr);
//	printf("%s\n", arr);
//	return 0;
//}

//int power(int n)
//{
//	if (n == 1)
//	{
//		return n;
//	}
//	else
//	{
//		return n * power(n - 1);
//	}
//}
//
//int main()
//{
//	int input = 0;
//	scanf("%d", &input);
//	int result = power(input);
//	printf("%d", result);
//	return 0;
//}

//void exchange(int x[], int y[], int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		int c = x[i];
//		x[i] = y[i];
//		y[i] = c;
//	}
//}
//
//void print(int x[], int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", x[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int b[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
//	exchange(a, b, sizeof(a) / sizeof(a[0]));
//	print(a, sizeof(a) / sizeof(a[0]));
//	print(b, sizeof(b) / sizeof(a[0]));
//	return 0;
//}

//void init(int x[], int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		x[i] = 0;
//	}
//}
//
//void print(int x[], int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", x[i]);
//	}
//	printf("\n");
//}
//
//void reverse(int x[], int size)
//{
//	int num = 0;
//	while (num != size / 2 + 1)
//	{
//		int c = x[num];
//		x[num] = x[size - num - 1];
//		x[size - num - 1] = c;
//		num++;
//	}
//}
//
//int main()
//{
//	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	reverse(a, sizeof(a) / sizeof(a[0]));
//	print(a, sizeof(a) / sizeof(a[0]));
//	init(a, sizeof(a) / sizeof(a[0]));
//	print(a, sizeof(a) / sizeof(a[0]));
//	return 0;
//}

//int main()
//{
//	printf("     **     \n");
//	printf("     **    \n");
//	printf("************\n");
//	printf("************\n");
//	printf("    *  *    \n");
//	printf("    *  *    \n");
//	return 0;
//}

//int main()
//{
//	printf("I lost my cellphone!");
//	return 0;
//}

//(-8 + 22)×a - 10 + c÷2计算之后的结果，为一个整数。

//int main()
//{
//	int a = 40;
//	int c = 212;
//	printf("%d", ((-8 + 22) * a) - 10 + (c / 2));
//	return 0;
//}

//void mao(int x[], int size)
//{
//	for (int i = 0; i < size - 1; i++)
//	{
//		for (int j = 0; j < size - 1 - i; j++)
//		{
//			if (x[j] > x[j + 1])
//			{
//				int a = x[j];
//				x[j] = x[j + 1];
//				x[j + 1] = a;
//			}
//		}
//	}
//}
//
//void xuan(int x[], int size)
//{
//	for (int i = 0; i < size - 1; i++)
//	{
//		for (int j = i + 1; j < size; j++)
//		{
//			if (x[i] > x[j])
//			{
//				int c = x[i];
//				x[i] = x[j];
//				x[j] = c;
//			}
//		}
//	}
//}
//
//void print(int x[], int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", x[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int a[10] = { 5, 9, 12, 6, 8, 23, 4, 2, 1, 15 };
//	mao(a, sizeof(a) / sizeof(a[0]));
//	xuan(a, sizeof(a) / sizeof(a[0]));
//	print(a, sizeof(a) / sizeof(a[0]));
//	return 0;
//}

//int main()
//{
//	int a = 1;
//	int b = 5;
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("%d %d", a, b);
//	return 0;
//}

//int main()
//{
//	int input = 0;
//	scanf("%d", &input);
//	int num = 0;
//	int i = 0;
//	while (i != 32)
//	{
//		int origin = input;
//		if ((input | ( 1 << i )) == input)
//		{
//			num++;
//		}
//		i++;
//		input = origin;
//	}
//	return 0;
//}

//void print(int a, int b, int c)
//{
//	if (c != 32)
//	{
//		if ((a | b << c) == a)
//		{
//			print(a, b, c + 2);
//			printf("%d", 1);
//		}
//		else
//		{
//			print(a, b, c + 2);
//			printf("%d", 0);
//		}
//	}
//}
//
//int main()
//{
//	int input = 0;
//	scanf("%d", &input);
//	print(input, 1, 0);
//	printf("\n");//奇数位
//	print(input, 2, 0);//偶数位
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int c = a ^ b;
//	int num = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		int origin = c;
//		if ((c | (1 << i)) == c)
//		{
//			num++;
//		}
//		c = origin;
//	}
//	printf("%d", num);
//	return 0;
//}

//int demo(int n)
//{
//	if (n <= 2)
//	{
//		return n;
//	}
//	else
//	{
//		return demo(n - 1) + demo(n - 2);
//	}
//}
//
//int main()
//{
//	int input = 0;
//	scanf("%d", &input);
//	int result = demo(input);
//	printf("%d", result);
//	return 0;
//}

//int runnian(int a)
//{
//	if (a % 4 == 0 && a % 100 != 0)
//	{
//		return 1;
//	}
//	else if (a % 400 == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int yue(int a, int b)
//{
//	if ((a > 0 && a <= 7 && a % 2 == 1) || (a > 7 && a <= 12 && a % 2 == 0))
//	{
//		return 31;
//	}
//	else if (a == 2)
//	{
//		if (b == 0)
//		{
//			return 28;
//		}
//		else
//		{
//			return 29;
//		}
//	}
//	else
//	{
//		return 30;
//	}
//}
//
//int main()
//{
//	int year = 0;
//	int month = 0;
//	while (scanf("%d %d", &year, &month) != EOF)
//	{
//		int result = runnian(year);
//		int back = yue(month, result);
//		printf("%d\n", back);
//	}
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int * a = arr;
//	int (*b) [10] = &arr;
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", *(a + i));
//	}
//	printf("\n");
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", (*b)[i]);
//	}
//	return 0;
//}

//int main()
//{
//	char a[10000] = { 0 };
//	int i = 0;
//	int num = 0;
//	while (1)
//	{
// 		scanf("%c", &a[i]);
//		if (a[i] == '\n')
//		{
//			num = i;
//			break;
//		}
//		i++;
//	}
//	for (int j = num - 1; j >= 0; j--)
//	{
//		printf("%c", a[j]);
//	}
//	return 0;
//}

int main()
{
	int n = 0;
	int a[10][10] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	int num = 1;
	int (*b) [10] = &a;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n - i; j++)
		{
			if ((*(b + j))[i] != 0)
			{
				printf("NO");
				num = 0;
				goto end;
			}
		}
		b++;
	}
	end:
	if (num == 1)
	{
		printf("YES");
	}
	return 0;
}

//void print(int a[10][10], int x, int y)
//{
//    for (int i = 0; i < x; i++)
//    {
//        for (int j = 0; j < y; j++)
//        {
//            scanf("%d", &a[i][j]);
//        }
//    }
//}
//
//int judgment(int a[10][10], int b[10][10], int x, int y)
//{
//    int out = 1;
//    for (int i = 0; i < x; i++)
//    {
//        for (int j = 0; j < y; j++)
//        {
//            if (a[i][j] != b[i][j])
//            {
//                out = 0;
//                goto end;
//            }
//        }
//    }
//end:
//    return out;
//}
//
//#include <stdio.h>
//
//int main() 
//{
//    int a, b;
//    while (scanf("%d %d", &a, &b) != EOF)
//    { 
//        int A[10][10] = { 0 };
//        int B[10][10] = { 0 };
//        print(A, a, b);
//        print(B, a, b);
//        int result = judgment(A, B, a, b);
//        if (result == 1)
//        {
//            printf("YES");
//        }
//        else
//        {
//            printf("NO");
//        }
//    }
//    return 0;
//}

//int summing(int x)
//{
//	if (x == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return x + summing(x / 2);
//	}
//}
//
//int main()
//{
//	int a = 20;
//	int sum = summing(a);
//	printf("%d", sum);
//	return 0;
//}


//int main()
//{
//	for (int i = 0; i < 100000; i++)
//	{
//		if (i >= 0 && i <= 9 && pow(i, 1) == i)
//		{
//			printf("%d ", i);
//		}
//		else if (i >= 10 && i <= 99 && pow((i / 10), 2) + pow((i % 10), 2) == i)
//		{
//			printf("%d ", i);
//		}
//		else if (i >= 100 && i <= 999 && pow(i / 100, 3) + pow((i % 100) / 10, 3) + pow(i % 10, 3) == i)
//		{
//			printf("%d ", i);
//		}
//		else if (i >= 1000 && i <= 9999 && pow(i / 1000, 4) + pow((i % 1000) / 100, 4) + pow((i % 100) / 10, 4) + pow(i % 10, 4) == i)
//		{
//			printf("%d ", i);
//		}
//		else if (i >= 10000 && i <= 99999 && pow(i / 10000, 5) + pow((i % 10000) / 1000, 5) + pow((i % 1000) / 100, 5) + pow((i % 100) / 10, 5) + pow(i % 10, 5) == i)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//int summing(int x, int y)
//{
//	if (x / 10000 > 1)
//	{
//		return x;
//	}
//	else
//	{
//		return x + summing(x * 10 + y, y);
//	}
//}
//
//int main()
//{
//	int input = 0;
//	scanf("%d", &input);
//	int result = summing(input, input);
//	printf("%d", result);
//	return 0;
//}