#pragma once

#include<iostream>

#include<vector>

#include<string>

#include<bitset>

using namespace std;

struct BKDRHash
{
	size_t operator()(const string& s)
	{
		// BKDR
		size_t value = 0;
		for (auto ch : s)
		{
			value *= 31;
			value += ch;
		}
		return value;
	}
};
struct APHash
{
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (long i = 0; i < s.size(); i++)
		{
			if ((i & 1) == 0)
			{
				hash ^= ((hash << 7) ^ s[i] ^ (hash >> 3));
			}
			else
			{
				hash ^= (~((hash << 11) ^ s[i] ^ (hash >> 5)));
			}
		}
		return hash;
	}
};

struct DJBHash
{
	size_t operator()(const string& s)
	{
		size_t hash = 5381;
		for (auto ch : s)
		{
			hash += (hash << 5) + ch;
		}
		return hash;
	}
};

template<size_t N,
	class K = string,
	class HashFunc1 = BKDRHash,
	class HashFunc2 = APHash,
	class HashFunc3 = DJBHash>
class BloomFilter
{
public:
	void Set(const K& a)
	{
		_bs.set(HashFunc1()(a) % N);
		_bs.set(HashFunc2()(a) % N);
		_bs.set(HashFunc3()(a) % N);
	}

	bool Test(const K& a)
	{
		HashFunc1 hf1;
		if (!_bs.test(HashFunc1()(a) % N)) return false;

		HashFunc2 hf2;
		if (!_bs.test(HashFunc2()(a) % N)) return false;

		HashFunc3 hf3;
		if (!_bs.test(HashFunc3()(a) % N)) return false;

		return true;
	}

private:
	bitset<N> _bs;
};