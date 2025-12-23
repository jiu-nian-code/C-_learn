#pragma once

#include"RB_Tree.h"

template<class Key, class Set_Compare_Ruler = std::less<Key>>
class My_Set
{
public:
	class Set_Fetch_Ruler;

	typedef Key Value;

	typedef RB_Tree<Key, const Value, Set_Fetch_Ruler, Set_Compare_Ruler> _RB_Tree;

	typedef typename RB_Tree<Key, const Value, Set_Fetch_Ruler, Set_Compare_Ruler>::iterator iterator;

	typedef typename RB_Tree<Key, const Value, Set_Fetch_Ruler, Set_Compare_Ruler>::const_iterator const_iterator;

	const_iterator begin() const
	{
		return core.begin();
	}

	const_iterator end() const
	{
		return core.end();
	}

	iterator begin()
	{
		return core.begin();
	}

	iterator end()
	{
		return core.end();
	}

	bool find(const Key& k)
	{
		return core.find(k);
	}

	int Height()
	{
		return core.Height();
	}

	pair<iterator, bool> insert(const Value& k)
	{
		return core.insert(k);
	}

private:
	struct Set_Fetch_Ruler
	{
		const Key& operator()(const Key& a)
		{
			return a;
		}
	};

	_RB_Tree core;
};