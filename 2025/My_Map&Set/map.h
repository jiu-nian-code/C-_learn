#pragma once

#include"RB_Tree.h"

template<class Key, class Value, class Map_Compare_Ruler = std::less<Key>>
class My_Map
{
public:
	class Map_Fetch_Ruler;

	typedef pair<const Key, Value> Value_Type;

	typedef RB_Tree<Key, Value_Type, Map_Fetch_Ruler, Map_Compare_Ruler> _RB_Tree;

	typedef typename RB_Tree<Key, Value_Type, Map_Fetch_Ruler, Map_Compare_Ruler>::iterator iterator;

	typedef typename RB_Tree<Key, Value_Type, Map_Fetch_Ruler, Map_Compare_Ruler>::const_iterator const_iterator;

	iterator begin()
	{
		return core.begin();
	}

	iterator end()
	{
		return core.end();
	}

	const_iterator begin() const
	{
		return core.begin();
	}

	const_iterator end() const
	{
		return core.end();
	}

	bool find(const Key& x)
	{
		return core.find(x);
	}

	pair<iterator, bool> insert(const Value_Type& x)
	{
		return core.insert(x);
	}

	Value& operator[](const Key& x)
	{
		pair<iterator, bool> ret = core.insert(make_pair(x, Value()));
		return ret.first->second;
	}

private:
	struct Map_Fetch_Ruler
	{
		const Key& operator()(const Value_Type& x)
		{
			return x.first;
		}
	};

	_RB_Tree core;
};