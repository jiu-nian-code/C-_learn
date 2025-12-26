#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<unordered_map>
#include"my_vector.hpp"

using namespace std;

//class Date
//{
//	int _year;
//	int _month;
//	int _day;
//public:
//	Date(int y, int m, int d) : _year(y), _month(m), _day(d) {}
//
//	void PRINT() { std::cout << "year: " << _year << " " << "month: " << _month << " " << "day: " << _day << std::endl; }
//};
//
//struct Point
//{
//	Point(int a, int b) : _a(a), _b(b)
//	{
//		std::cout << "Point(int a, int b)" << std::endl;
//	}
//
//	Point(const Point& pt) : _a(pt._a), _b(pt._b)
//	{
//		std::cout << "Point(const Point& pt)" << std::endl;
//	}
//
//	int _a;
//	int _b;
//};
//
//template<class T>
//void PRINTING(std::initializer_list<T> il)
//{
//	for (auto& e : il)
//		std::cout << e << " ";
//	std::cout << std::endl;
//}
//
//void func(auto x)
//{
//	std::cout << x << std::endl;
//}

//int main()
//{
	//int a { 1 };
	//std::cout << a << std::endl;
	//Date d = { 1, 1, 1 };
	//d.PRINT();
	//Date{ 2025, 12, 24 }.PRINT();
	//Date *date_ptr = new Date{ 2025, 1, 1 };
	//date_ptr->PRINT();
	//int arr[]{ 1, 2, 3, 4 };
	//for (int i = 0; i < 4; ++i)
	//	std::cout << arr[i] << std::endl;
	//printf("|%*d|\n", 1, 8);
	//auto init = { 1, 2, 3 };
	//std::cout << typeid(init).name() << std::endl;
	// const int* ptr = { 1, 2, 3 };
	//
	// int arr1[4] = { 1, 2, 3, 4 };
	// int arr2[] = { 1, 2, 3, 4 }; // 等价上一行
	// Point pt = { 1, 2 };
	// std::cout << sizeof(arr2) << std::endl;
	// std::cout << pt._a << " " << pt._b << std::endl;
	//for (int i = 0; i < 4; ++i)
	//	std::cout << arr3[i] << std::endl;
	//
	//int a = { 1 };
	//int b { 1 };
	//Point pt = { 1, 2 }; 
	// 这里就能看出C++对C语言的兼容了，如果没有写构造，汇编代码就只是对结构体成员变量直接进行赋值，
	// 但是如果有构造函数，则是进行构造函数的调用，而且如果构造函数的参数不符合，还会报错
	//
	//std::vector<int> arr1 { 1, 2, 3 };
	//std::vector<int> arr2 = { 1, 2, 3 };
	//Point pt1 { 1, 2 };
	//Point pt2 = { 1, 2 };
	//
	//auto init1 = { 1, 2, 3 };
	//auto init2 = { 1, 2, 3, 4, 5, 6 };
	//std::cout << sizeof(init1) << std::endl;
	//std::cout << sizeof(init2) << std::endl;
	//// 输出结果: 16 16
	//std::cout << init1.size() << std::endl;
	//std::cout << init2.size() << std::endl;
	// PRINTING({1, 2, 3, 4});
	//jiunian::vector<int> arr = { 1, 2, 3 };
	//for (auto& e : arr)
	//	std::cout << e << " ";
	//std::cout << std::endl;
	//
	//std::unordered_map<int, int> mp{ {1, 1}, {2, 2}, {3, 30} };
	//std::vector<std::pair<int, int>> arr1{ {1, 2}, {1, 2}, {1, 2} };
	//jiunian::vector<int> arr2 = {1, 2, 3};
	//arr.push_back(1);
	//arr.push_back(2);
	//arr.push_back(3);
	//arr.push_back(1);
	//
	//std::vector<int>arr{1, 2, 3};
	//for (auto& e : arr)
	//	std::cout << e << std::endl;
	//std::unordered_map<int, int>mp{ {1, 1}, {2, 2}, {3, 3} };
	//for (auto& [k, v] : mp) // 结构化绑定，C++17支持
	//	std::cout << k << " " << v << std::endl;
	//auto it = arr.begin();
	//std::cout << typeid(it).name() << std::endl;
	//std::cout << typeid(it).raw_name() << std::endl;
	//decltype(it) tmp;
	//std::cout << typeid(tmp).name() << std::endl;
	//
	//auto x = 5, * y = &x;   // 正确：x是int，y是int*
	//// auto a = 1, b = 2.0; // 错误：a和b的类型不一致
	// 
	//std::vector<int>arr{ 1, 2, 3 };
	//auto it = arr.begin();
	//typeid(it).name() tmp; // 报错
	//decltype(it) tmp = it; // 直接推导变量
	//std::vector<decltype(1 * 1.2)> num; // 也能当模板参数，里面也能传表达式
	//std::cout << typeid(it).name() << std::endl;
	//return 0;
//}

template<class Container, class Index>
decltype(auto) func(Container& c, Index i)
{
	char& a = c[i];
	return a;
}

int main()
{
	std::vector<char> arr{'a', 'b', 'c'};
	int a = 1;
	int& b = a;
	decltype(auto) c = b;
	c++;
	//for (auto& e : arr)
	//	std::cout << e << std::endl;
	std::cout << c << std::endl;

	//std::cout << typeid(tmp).name() << std::endl;
	//int& n = i;
	//decltype(auto) m = n;
	//std::cout << typeid(i).name() << std::endl;
	return 0;
}