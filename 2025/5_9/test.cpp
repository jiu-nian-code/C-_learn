#include<iostream>

using namespace std;

class A
{
	~A() {}
public:
	static void destoryA(A* x)
	{
		delete x;
	}
};

class B : public A
{

};

int main()
{
	A* x = new A;
	A::destoryA(x);
	B y;
}