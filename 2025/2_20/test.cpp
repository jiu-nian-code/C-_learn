#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

#include<string>

int main()
{
	std::string str("abcdefg");
	for (auto e : str)
	{
		std::cout << e;//´òÓ¡abcdefg
	}
	std::cout << std::endl;
	for (auto& e : str)
	{
		e = 'a';
	}
	std::cout << str;//aaaaaaa
	return 0;
}