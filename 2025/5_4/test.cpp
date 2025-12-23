#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

class jiunian
{
public:
	jiunian():
		a(new int[10])
	{

	}
private:
	int* a;
};

int main()
{
	jiunian x;
	return 0;
}