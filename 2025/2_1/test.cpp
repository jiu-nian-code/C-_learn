#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

class shinku
{
public:
	shinku()
	{
		std::cout << "shinku" << std::endl;
	}
private:
	int _a;
};

class jiunian
{
public:
	jiunian(int a, int b):
		_a(a),
		_b(b)
	{
		//int* ptr = (int*)calloc(4, sizeof(int));
		//if (ptr == nullptr)
		//{
		//	perror("jiunian_i_i:calloc");
		//	return;
		//}
		//_c = ptr;
	}
	jiunian(jiunian& x)
	{
		std::cout << "jiunian" << std::endl;
		_a = x._a;
		_b = x._b;
		//int* ptr = (int*)calloc(4, sizeof(int));
		//if (ptr == nullptr)
		//{
		//	perror("jiunian_j:calloc");
		//	return;
		//}
		//_c = ptr;
		//memcpy(_c, x._c, sizeof(_c));
	}
	bool operator<(jiunian y)const
	{
		if (_a < y._a && _b < y._b)
		{
			return true;
		}
		return false;
	}
	jiunian& operator++()
	{
		++_a;
		++_b;
		return *this;
	}
	jiunian& operator++(int)
	{
		jiunian* const ret = this;
		++_a;
		++_b;
		return *ret;
	}
	jiunian& operator=(jiunian& y)
	{
		std::cout << "=" << std::endl;
		_a = y._a;
		_b = y._b;
		return *this;
	}
	~jiunian()
	{
		_a = 0;
		_b = 0;
		//free(_c);
		//_c = nullptr;
	}
//private:
	int _a;
	int _b;
	//int* _c;
};

jiunian& operator=(jiunian& x, jiunian& y)
{
	std::cout << "=" << std::endl;
	x._a = y._a;
	x._b = y._b;
	return x;
}

int main()
{
	jiunian x(1, 1);
	jiunian y(x);//拷贝构造
	jiunian z = x;//拷贝构造
	jiunian a(1,1);
	jiunian b(2, 2);
	x = y;//赋值运算符重载
	return 0;
}