#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include"test.h"

//int a = 1;

//namespace bit3
//{
//	int a = 2;
//}
//
//namespace bit
//{
//	//int a = 5;
//	namespace bit2
//	{
//		using namespace bit3;
//	}
//}

namespace bit
{
	int a = 0;
}

//using namespace bit;


//void test(int a)
//{
//	std::cout << a << std::endl;
//}
//
//void test(int a = 5);

//using namespace bit;

//int a = 6;

//using std::cout;

//int main()
//{
//	test();
//	//printf("%d", bit::bit2::a);
//	//int a = 5;
//	//std::cout << ::a << std::endl;
//	return 0;
//}

//typedef char* pstring;
//int main()
//{
//	char a = 'a';
//	const pstring p1 = &a;
//	const pstring* p2;
//	return 0;
//}

//int hunt(int, int)
//{
//
//}
//
//double hunt(int, int)
//{
//
//}

//int main()
//{
//	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (auto& e : a)
//	{
//		e++;
//		//std::cout << e << std::endl;
//	}
//	for (auto e : a)
//	{
//		std::cout << e << std::endl;
//	}
//	//int* b = nullptr;
//	//std::cout << b << std::endl;
//	std::cout << sizeof(nullptr) << std::endl;
//	std::cout << sizeof((void*)0) << std::endl;
//	std::cout << sizeof(NULL) << std::endl;
//	return 0;
//}

//using namespace std;
//
//void f(int)
//{
//	cout << "f(int)" << endl;
//}
//void f(int*)
//{
//	cout << "f(int*)" << endl;
//}
//int main()
//{
//	f(0);
//	f(nullptr);
//	f((int*)NULL);
//	return 0;
//}

//inline void test()
//{
//	std::cout << 6 << std::endl;
//}
//
////inline void test();
//
//void test_1()
//{
//	test();
//	test();
//	test();
//	test();
//	test();
//	test();
//}

//void test_1();

//int main()
//{
//	//test_1();
//	//test_2();
//	//std::cout << sizeof(short) << std::endl;
//	int a = 1545;
//	return 0;
//}

//class shinku
//{
//public:
//	shinku()
//	{
//		_a = 0;
//		_b = 0;
//		_c = 0;
//	}
//private:
//	int _a;
//	int _b;
//	int _c;
//};
//
//class thx
//{
//public:
//	thx(int a = 1, int b = 2, int c = 3)
//	{
//		_a = a;
//		_b = b;
//		_c = c;
//	}
//
//private:
//	int _a;
//	int _b;
//	int _c;
//	shinku love;
//};
//
//int main()
//{
//	thx s(2, 3, 4);
//	shinku love;
//	return 0;
//}

//class Date
//{
//public:
//	//Date()
//	//{
//	//	_year = 1900;
//	//	_month = 1;
//	//	_day = 1;
//	//}
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//// 以下测试函数能通过编译吗？
//int main()
//{
//	Date d1;
//	return 0;
//}

//class Time
//{
//public:
//	Time()
//	{
//		_hour = 1;
//		_minute = 1;
//		_second = 1;
//	}
//	Time& operator=(const Time& t)
//	{
//		std::cout << "Time" << std::endl;
//		if (this != &t)
//		{
//			_hour = t._hour;
//			_minute = t._minute;
//			_second = t._second;
//		}
//		return *this;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//private:
//	// 基本类型(内置类型)
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//	// 自定义类型
//	Time _t;
//};
//int main()
//{
//	Date d1;
//	Date d2;
//	d1 = d2;
//	return 0;
//}

//using std::cout;
//using std::endl;
//
//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << "Print()" << endl;
//		cout << "year:" << _year << endl;
//		cout << "month:" << _month << endl;
//		cout << "day:" << _day << endl << endl;
//	}
//	void Print() const
//	{
//		cout << "Print()const" << endl;
//		cout << "year:" << _year << endl;
//		cout << "month:" << _month << endl;
//		cout << "day:" << _day << endl << endl;
//	}
//private:
//	int _year; // 年
//	int _month; // 月
//	int _day; // 日
//};
//void Test()
//{
//	Date d1(2022, 1, 13);
//	d1.Print();
//	const Date d2(2022, 1, 13);
//	d2.Print();
//}
//
//
//
//int main()
//{
//	Test();
//	return 0;
//}

//#include <iostream>
//
//class MyClass {
//public:
//    void nonConstFunction() {
//        std::cout << "Non-const function called." << std::endl;
//    }
//
//    void constFunction() const {
//        // nonConstFunction(); // 编译错误，const 成员函数内不能调用非 const 成员函数
//        std::cout << "Const function called." << std::endl;
//    }
//};
//
//int main() {
//    MyClass obj;
//    obj.constFunction();
//    return 0;
//}

//class A
//{
//public:
//    A(int a)
//        :_a1(a)
//        , _a2(_a1)
//    {}
//
//    void Print() {
//        std::cout << _a1 << " " << _a2 << std::endl;
//    }
//private:
//    int _a2;
//    int _a1;
//};
//
//int main() {
//    A aa(1);
//    aa.Print();
//}

//class shinku
//{
//public:
//	shinku(int a)
//	{
//		_a = a;
//		_b = a;
//		std::cout << "shinku" << std::endl;
//	}
//	shinku& operator= (shinku& b)
//	{
//		_a = b._a;
//		_b = b._b;
//		return *this;
//	}
//private:
//	int _a;
//	int _b;
//};
//
//int main()
//{
//	//shinku a(1);
//	//shinku b(2);
//	shinku a = 1;
//	return 0;
//}

//class _jiunian
//{
//public:
//	//……
//protected:
//	//……
//private:
//	//……
//};



//void shinku()
//{
//	std::cout << "love" << std::endl;
//}
//
////void shinku();
//
//namespace thx
//{
//	void shinku();
//}
//
//using namespace thx;
//
//int main()
//{
//	shinku();
//	return 0;
//}


class _jiunian
{
public:
	_jiunian(int a, int b, int c)
	{
		_a = a;
		_b = b;
		_c = c;
	}
	void reset(int a, int b, int c)
	{
		_a = a;
		_b = b;
		_c = c;
	}
private:
	int _a;
	int _b;
	int _c;
};

int main()
{
	_jiunian x(1, 1, 1), y(2, 2, 2);
	x.reset(1, 2, 3);
	y.reset(1, 2, 3);
	return 0;
}