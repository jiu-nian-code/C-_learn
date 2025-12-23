#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

//class jiunian
//{
//public:
//	jiunian()
//	{
//		_a = 1;
//		_b = 1;
//	}
//	static void print(jiunian& x)
//	{
//		x._a = 3;
//		x._b = 3;
//		std::cout << "print" << std::endl;
//	}
//	int add()
//	{
//		++_a;
//		++_b;
//	}
//private:
//	int _a;
//	int _b;
//	static int _c;
//};
//
//int jiunian::_c = 0;
//
//int main()
//{
//	jiunian x;
//	//x.print();
//	jiunian::print(x);
//	return 0;
//}

//class jiunian
//{
//public:
//	static jiunian* GetHeapObj()
//	{
//		return new jiunian;
//	}
//	static jiunian GetStackObj()
//	{
//		jiunian x;
//		return x;
//	}
//	static jiunian& GetStaticObj()
//	{
//		static jiunian x;
//		return x;
//	}
//	jiunian(const jiunian& x)
//	{
//		std::cout << "jiunian" << std::endl;
//		_a = x._a;
//		_b = x._b;
//	}
//private:
//	jiunian():
//		_a(2),
//		_b(2)
//	{
//
//	}
//	int _a;
//	int _b;
//};
//
//int main()
//{
//	jiunian y = jiunian::GetStackObj();
//	return 0;
//}

//using namespace std;
//
//class Date
//{
//    friend ostream& operator<<(ostream& _cout, const Date& d);
//    friend istream& operator>>(istream& _cin, Date& d);
//public:
//    Date(int year = 1900, int month = 1, int day = 1)
//        : _year(year)
//        , _month(month)
//        , _day(day)
//    {}
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//ostream& operator<<(ostream& _cout, const Date& d)
//{
//    _cout << d._year << "-" << d._month << "-" << d._day;
//    return _cout;
//}
//istream& operator>>(istream& _cin, Date& d)
//{
//    _cin >> d._year;
//    _cin >> d._month;
//    _cin >> d._day;
//    return _cin;
//}
//int main()
//{
//    Date d;
//    cin >> d;
//    cout << d << endl;
//    return 0;
//}

//class jiunian
//{
//public:
//	class thx
//	{
//	public:
//		thx():
//		_x(1)
//		{
//			b = 1;//不用作用域解析符也不用类类型对象，直接访问
//		}
//	private:
//		int _x;
//	};
//private:
//	int _a;
//	static int b;
//};
//
//int jiunian::b = 0;
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	return 0;
//}

void func() {
    int x;
    std::cout << "func x: " << &x << std::endl;
}

int main() {
    int a;
    int b;
    std::cout << "main a: " << &a << std::endl;
    std::cout << "main b: " << &b << std::endl;
    func();
    return 0;
}