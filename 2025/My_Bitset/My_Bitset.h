#pragma once

#include<iostream>

#include<vector>

using namespace std;


template<size_t N>
class My_Bitset
{
public:
	My_Bitset():
		_Bit((N / 32) + 1),
		_BitCount(N)
	{

	}

	// 将which位设置为1
	void set(size_t which)
	{
		if (which > N) return;
		size_t i = which / 32;
		size_t j = which % 32;
		_Bit[i] |= (1 << j);
	}

	// 将which位设置为0
	void reset(size_t which)
	{
		if (which > N) return;
		size_t i = which / 32;
		size_t j = which % 32;
		_Bit[i] &= (~(1 << j));
	}

	// 检测which位是否为1
	bool test(size_t which)
	{
		if (which > N) return false;
		size_t i = which / 32;
		size_t j = which % 32;
		return _Bit[i] & (1 << j);
	}

	// 获取位图中比特位的总个数
	size_t size()const
	{
		return _BitCount;
	}

	// 位图中比特为1的个数
	size_t count()const
	{
		size_t ret = 0;
		for (auto& e : _Bit)
		{
			int cur = e;
			while (cur)
			{
				if (1 & cur == 1) ++ret;
				cur >> 1;
			}
		}
		return ret;
	}

private:
	vector<int> _Bit;
	size_t _BitCount;
};