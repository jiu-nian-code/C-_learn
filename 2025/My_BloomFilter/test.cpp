#define _CRT_SECURE_NO_WARNINGS 1

#include"My_BloomFilter.h"

void test_1()
{
	BloomFilter<23> x; //越大，公因数越少越好，最好是质数
	x.Set("插入");
	x.Set("删除");
	x.Set("查找");
	x.Set("修改");

	cout << x.Test("插入") << endl;
	cout << x.Test("删除") << endl;
	cout << x.Test("查找") << endl;
	cout << x.Test("修改") << endl;
	cout << x.Test("创建") << endl;
	cout << x.Test("销毁") << endl;
}

void test_2()
{
	srand(time(0));
	const size_t N = 100011; //越大，公因数越少越好，最好是质数
	BloomFilter<N * 8> bf; // 测试对象

	std::vector<std::string> v1;
	//std::string url = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";
	std::string url = "猪八戒";

	for (size_t i = 0; i < N; ++i)
	{
		v1.push_back(url + std::to_string(i));
	}

	for (auto& str : v1)
	{
		bf.Set(str);
	}

	// v2跟v1是相似字符串集（前缀一样），但是不一样
	std::vector<std::string> v2;
	for (size_t i = 0; i < N; ++i)
	{
		std::string urlstr = url;
		urlstr += std::to_string(9999999 + i);
		v2.push_back(urlstr);
	}

	size_t n2 = 0;
	for (auto& str : v2)
	{
		if (bf.Test(str)) // 误判
		{
			++n2;
		}
	}
	cout << "相似字符串误判率:" << (double)n2 / (double)N << endl;

	// 不相似字符串集
	std::vector<std::string> v3;
	for (size_t i = 0; i < N; ++i)
	{
		//string url = "zhihu.com";
		string url = "孙悟空";
		url += std::to_string(i + rand());
		v3.push_back(url);
	}

	size_t n3 = 0;
	for (auto& str : v3)
	{
		if (bf.Test(str))
		{
			++n3;
		}
	}
	cout << "不相似字符串误判率:" << (double)n3 / (double)N << endl;
}

int main()
{
	test_2();
	return 0;
}