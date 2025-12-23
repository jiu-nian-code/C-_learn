#pragma once

#include"RB_Tree.h"

template<class Key, class Set_Compare_Ruler = std::less<Key>>
class My_Set
{
public:
	class Set_Fetch_Ruler;

	typedef Key Value;

	typedef RB_Tree<Key, Value, Set_Fetch_Ruler, Set_Compare_Ruler> _RB_Tree; //写成 const Value 好像也行

	//typedef typename RB_Tree<Key, Value, Set_Fetch_Ruler, Set_Compare_Ruler>::iterator iterator;

	typedef typename RB_Tree<Key, Value, Set_Fetch_Ruler, Set_Compare_Ruler>::const_iterator const_iterator;

	typedef const_iterator iterator;

	iterator begin() const //只提供const版本的，因为权限可以缩小，普通对象也可以调用，这样就让set的迭代器不能修改红黑树的元素
	{
		return core.begin();
	}

	iterator end() const
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
		pair<typename RB_Tree<Key, Value, Set_Fetch_Ruler, Set_Compare_Ruler>::iterator, bool> ret = core.insert(k);//类域指定迭代器，防止调用被typedef的已经是const_iterator的iterator
		return pair<iterator, bool>(ret.first, ret.second);//构造时权限可以缩小，但pair直接的转换是不行的，需要迭代器特殊构造的支持
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