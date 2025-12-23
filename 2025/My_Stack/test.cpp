#define _CRT_SECURE_NO_WARNINGS 1

#include"My_Stack.h"

int main()
{
	jiunian::stack<int> sk;
	sk.push(1);
	sk.push(2);
	sk.push(3);
	sk.push(4);
	sk.push(5);

	jiunian::stack<int> Sk;
	Sk.push(5);
	Sk.push(4);
	Sk.push(3);
	Sk.push(2);
	Sk.push(1);

	jiunian::stack<int>SK(Sk);

	cout << SK.top();
	return 0;
}