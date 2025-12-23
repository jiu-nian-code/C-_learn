#pragma once

#include"hash.h"

template<class Key, class Value, class Transform_Ruler = Uint_Transform_Ruler<Key>>
class My_Unordered_Map
{
	struct Map_Fetch_Ruler
	{
		const Key& operator()(const pair<Key, Value>& a)
		{
			return a.first;
		}
	};
public:
	typedef pair<const Key, Value> Data;

	typedef typename Hash_bucket::Hash<Key, Data, Map_Fetch_Ruler, Transform_Ruler> _hash;

	typedef typename Hash_bucket::Hash<Key, Data, Map_Fetch_Ruler, Transform_Ruler>::iterator iterator;

	typedef typename Hash_bucket::Hash<Key, Data, Map_Fetch_Ruler, Transform_Ruler>::const_iterator const_iterator;

	iterator begin()
	{
		return _core.begin();
	}

	const_iterator begin() const
	{
		return _core.begin();
	}

	iterator end()
	{
		return _core.end();
	}

	const_iterator end() const
	{
		return _core.end();
	}

	pair<iterator, bool> insert(const Data& d)
	{
		return _core.insert(d);
	}

	Value& operator[](const Key& k)
	{
		pair<iterator, bool> ret = _core.insert(make_pair(k, Value()));
		return ret.first->second;
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