#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

#include<string>

using namespace std;

//class jiunian
//{
//    friend ostream& operator<<(ostream& _cout, const jiunian& x);
//    friend istream& operator>>(istream& _cin, jiunian& x);
//public:
//    jiunian()
//    {
//    }
//
//private:
//    int _a;
//    int _b;
//    int _c;
//} ;
//
//typedef jiunian Date;
//
//ostream& operator<<(ostream& _cout, const Date& x)
//{
//    _cout << x._a << "-" << x._b << "-" << x._c;
//    return _cout;
//}
//istream& operator>>(istream& _cin, Date& d)
//{
//    _cin >> d._a;
//    _cin >> d._b;
//    _cin >> d._c;
//    return _cin;
//}
//int main()
//{
//    jiunian a;
//    cin >> a;
//    cout << a << endl;
//    return 0;
//}

//class jiunian
//{
//public:
//
////private:
//	class Jiunian
//	{
//	private:
//		int a = 1;
//	};
//};
//
//int main()
//{
//	jiunian::Jiunian a;
//	return 0;
//}

//class jiunian
//{
//public:
//	class thx
//	{
//	public:
//		thx() :
//			_x(1)
//		{
//			_b = 1;
//		}
//	private:
//		int _x;
//	};
//private:
//	int _a;
//	static int _b;
//};
//
//int jiunian::_b = 0;
//
//int main()
//{
//	jiunian m;
//	jiunian::thx n;//作用域解析符,thx被包在jiunian的类域中了
//	return 0;
//}

int main()
{
	string jiunian("123456789");
	char* a = (char*)malloc(10);
	((string*)nullptr)->c_str();
	string* str = nullptr;
	str->c_str();
	string b = jiunian.substr(0, 5);
	//string Jiunian("abcdefghijklmnopqrstuvwxyz");
	//jiunian.swap(Jiunian);
	//swap(jiunian, Jiunian);
	cout << jiunian.empty() << endl;
	return 0;
}