#define _CRT_SECURE_NO_WARNINGS 1

#include"My_String.h"

const size_t jiunian::string::npos = -1;

using namespace jiunian;

void test_1()
{
	string a("123456789");
	std::cin >> a;
	std::cout << a << std::endl;
}

void test_2()
{
	string a("123456789");
	string b("456");
	a = "45646487";
	std::cout << a << std::endl;
}

void test_3()
{
	string a;
	string b("4567895645456");
	const char* c = b.c_str();
	std::cout << a.empty() << std::endl << b.empty();
}

void test_4()
{
	string a("5645645674");
	a.resize(100);
	a.reserve(10);
	a.reserve(200);
	std::cout << a[0] << a[10] << std::endl;
}

void test_5()
{
	string a("5645635674");
	string b("5645635674");
	std::cout << (a <= b) << std::endl;
}

void test_6()
{
	string a("463456356714");
	string b("5645635674");
	std::cout << a.find('1');
}

void test_7()
{
	string a("463456356714");
	a.insert(0, "123456");
	a.erase(0, 15);
}

int main()
{
	//test_7();
	std::cout << int() << std::endl;
	return 0;
}