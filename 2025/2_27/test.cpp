#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

#include<list>

#include<vector>


class A
{
public:
	//A()
	//{
	//}
private:
	int a;
	int b;
};
template <class T>
class B
{
public:
	B()
	{

	}
private:
	int a;
	int b;
};



int main()
{
	B<A> tmp;
	return 0;
}