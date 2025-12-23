#include<iostream>
#include<fstream>
#include<print>

int main()
{
	int a = 0;
	int&& b = std::move(a);
	std::cout << "hello world" << std::endl;
	return 0;
}