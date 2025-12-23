#pragma once

#include"hash.h"

#include<string>

template<class Key, class Transform_Ruler = Uint_Transform_Ruler<Key>>
class My_Unordered_Set
{
	struct Set_Fetch_Ruler
	{
		const Key& operator()(const Key& a)
		{
			return a;
		}
	};
public:
	typedef Key Data;

	typedef typename Hash_bucket::Hash<Key, Data, Set_Fetch_Ruler, Transform_Ruler> _hash;

	//typedef Hash_bucket::Hash<Key, Data, Map_Fetch_Ruler, Transform_Ruler>::iterator iterator;

	typedef typename Hash_bucket::Hash<Key, Data, Set_Fetch_Ruler, Transform_Ruler>::const_iterator const_iterator;

	typedef const_iterator iterator;

	iterator begin() const
	{
		return _core.begin();
	}

	iterator end() const
	{
		return _core.end();
	}

	bool insert(const Data& d)
	{
		return _core.insert(d);
	}

	bool erase(const Key& k)
	{
		return _core.erase(k);
	}

	bool find(const Key& k)
	{
		return _core.find(k);
	}

private:
	_hash _core;
};