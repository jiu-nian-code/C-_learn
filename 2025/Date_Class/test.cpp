#define _CRT_SECURE_NO_WARNINGS 1

#include"Date.h"

void Date_Test_1()
{
	std::cout << Date().GetMonthDay(2025, 1) << std::endl;
}

void Date_Test_2()
{
	Date a(2025, 3, 31);
	Date b(2024, 12, 31);
	a = b;
}

void Date_Test_3()
{
	Date a(2025, 2, 18);
	a += 10000;
}

void Date_Test_4()
{
	Date a(2025, 2, 18);
	Date b = a - 10000;
}

void Date_Test_5()
{
	Date a(2025, 2, 18);
	Date b(2052, 7, 6);
	std::cout << (a - b) << std::endl;
}

void Date_Test_6()
{
	Date a(2025, 2, 19);
	Date b(2025, 2, 18);
	std::cout << (a <= b) << std::endl;
}

int main()
{
	Date_Test_6();
	return 0;
}