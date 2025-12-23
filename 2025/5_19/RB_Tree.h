#pragma once

#include<iostream>

using namespace std;

enum Color
{
	red,
	black
};

template<class Value>
struct RB_Node
{
	typedef RB_Node<Value> Node;

	RB_Node(const Value& v, Color c = red) :
		_value(v),
		_color(c)
	{
	}

	Node* _parent = nullptr;
	Node* _left = nullptr;
	Node* _right = nullptr;

	Value _value;

	Color _color;
};

template<class Value, class Ptr, class Ref>
struct RB_Iterator
{
	typedef RB_Iterator<Value, Ptr, Ref> Self;

	typedef RB_Iterator<Value, Value*, Value&> Normal_RB_Iterator;

	typedef RB_Node<Value>* PNode;

	RB_Iterator(PNode p):
		_pNode(p)
	{

	}

	//重要！！！
	RB_Iterator(const Normal_RB_Iterator& x): //是普通的迭代器就是拷贝构造，const迭代器就是特殊的构造，这时const迭代器的拷贝构造编译器会单独生成
		_pNode(x._pNode)
	{

	}

	Ref operator*()
	{
		return _pNode->_value;
	}

	Ptr operator->()
	{
		return &(_pNode->_value);
	}

	Self& operator++()
	{
		if (_pNode->_right)
		{
			PNode cur = _pNode->_right;
			while (cur->_left)
			{
				cur = cur->_left;
			}
			_pNode = cur;
		}
		else
		{
			PNode cur = _pNode->_parent;
			while (cur && cur->_left != _pNode)
			{
				_pNode = cur;
				cur = cur->_parent;
			}
			_pNode = cur;
		}
		return *this;
	}

	Self& operator++(int)
	{
		Self* tmp = this;
		if (_pNode->_right)
		{
			PNode cur = _pNode->_right;
			while (cur->_left)
			{
				cur = cur->_left;
			}
			_pNode = cur;
		}
		else
		{
			PNode cur = _pNode->_parent;
			while (cur && cur->_left != _pNode)
			{
				_pNode = cur;
				cur = cur->_parent;
			}
			_pNode = cur;
		}
		return *tmp;
	}

	Self& operator--()
	{
		if (_pNode->_left)
		{
			PNode cur = _pNode->_left;
			while (cur->_right)
			{
				cur = cur->_right;
			}
			_pNode = cur;
		}
		else
		{
			PNode cur = _pNode->_parent;
			while (cur && cur->_right != _pNode)
			{
				_pNode = cur;
				cur = cur->_parent;
			}
			_pNode = cur;
		}
		return *this;
	}

	Self& operator--(int)
	{
		Self* tmp = this;
		if (_pNode->_left)
		{
			PNode cur = _pNode->_left;
			while (cur->_right)
			{
				cur = cur->_right;
			}
			_pNode = cur;
		}
		else
		{
			PNode cur = _pNode->_parent;
			while (cur && cur->_right != _pNode)
			{
				_pNode = cur;
				cur = cur->_parent;
			}
			_pNode = cur;
		}
		return *tmp;
	}

	bool operator==(const Self& a)
	{
		return _pNode == a._pNode;
	}

	bool operator!=(const Self& a)
	{
		return _pNode != a._pNode;
	}

//private:
	PNode _pNode;
};

template<class Key, class Value, class Fetch_Ruler, class Compare_Ruler>
class RB_Tree
{
public:
	int rotation_num = 0;

	typedef RB_Tree<Key, Value, Fetch_Ruler, Compare_Ruler> Self;
	typedef RB_Node<Value> Node;

	typedef RB_Iterator<Value, Value*, Value&> iterator;
	typedef RB_Iterator<Value, const Value*, const Value&> const_iterator;

	iterator begin()
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}
		return iterator(cur);
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	const_iterator begin() const
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}
		return const_iterator(cur);
	}

	const_iterator end() const
	{
		return const_iterator(nullptr);
	}

	bool find(const Key& k)
	{
		return _find(k, _root);
	}

	pair<iterator, bool> insert(const Value& v)
	{
		if (!_root)
		{
			_root = new Node(v, black);
			return make_pair(iterator(_root), true);
		}

		Node* cur = _root;
		Node* parent = nullptr;

		while (cur)
		{
			if (fr(cur->_value) == fr(v)) return make_pair(iterator(cur), false);

			parent = cur;
			if (cr(fr(v), fr(cur->_value))) cur = cur->_left;
			else cur = cur->_right;
		}

		Node* ret = new Node(v, red);
		cur = ret;
		if (cr(fr(cur->_value), fr(parent->_value)))
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}

		while (parent)
		{
			if (parent->_color == black) break;

			Node* pparent = parent->_parent;
			Node* uncle = nullptr;
			if (cr(fr(parent->_value), fr(pparent->_value))) uncle = pparent->_right;
			else uncle = pparent->_left;

			if (!uncle || uncle->_color == black)
			{
				if (cr(fr(parent->_value), fr(pparent->_value)))
				{
					if (cr(fr(cur->_value), fr(parent->_value)))//右旋
					{
						Rrotation(parent);
						parent->_color = black; //parent替代了pparent的位置，给成黑色
						pparent->_color = red; //pparent变成了parent的位置，给成红色
						//cur本身是红，转完的位置也是红，不需要变色
					}
					else
					{
						LRrotation(parent); //先左旋再右旋，左旋时cur替代了parent的位置，右旋时替代了pparent的位置
						cur->_color = black; //cur相当于单旋中的parent
						pparent->_color = red; //pparent还是一样
					}
				}
				else
				{
					if (cr(fr(parent->_value), fr(cur->_value)))
					{
						Lrotation(parent);
						parent->_color = black;
						pparent->_color = red;
					}
					else
					{
						RLrotation(parent);
						cur->_color = black;
						pparent->_color = red;
					}
				}
				if (parent == _root) parent->_color = black;
				break;
			}
			else if (uncle->_color == red)
			{
				uncle->_color = parent->_color = black;
				pparent->_color = red;

				if (pparent == _root)
				{
					pparent->_color = black;
					break;
				}
				cur = pparent;
				parent = pparent->_parent;
			}
		}
		return  make_pair(iterator(ret), true);
	}

	int Height()
	{
		return _Height(_root);
	}

private:
	int _Height(Node* cur)
	{
		if (!cur) return 0;
		int lret = _Height(cur->_left);
		int rret = _Height(cur->_right);
		return lret > rret ? lret + 1 : rret + 1;
	}

	bool _find(const Key& k, Node* cur)
	{
		if (!cur) return false;
		
		if (fr(cur->_value) == k) return true;

		if (fr(cur->_value) > k) return _find(k, cur->_left);

		return _find(k, cur->_right);
	}

	void LRrotation(Node* cur)
	{
		Lrotation(cur->_right);
		cur = cur->_parent;
		Rrotation(cur);
	}

	void RLrotation(Node* cur)
	{
		Rrotation(cur->_left);
		cur = cur->_parent;
		Lrotation(cur);
	}

	void Lrotation(Node* cur)
	{
		rotation_num++;
		Node* parent = cur->_parent;
		Node* pparent = parent->_parent;
		Node* cur_left = cur->_left;

		parent->_right = cur_left; //左右节点更新
		cur->_left = parent;

		if (cur_left) cur_left->_parent = parent; //父节点的更新
		parent->_parent = cur;
		cur->_parent = pparent;

		if (pparent) //判断是不是空
		{
			if (pparent->_value > cur->_value) pparent->_left = cur; //父节点的父节点更新
			else pparent->_right = cur;
		}
		else
		{
			_root = cur;
			cur->_parent = nullptr; //解耦
		}

		//cur->_color = black; //颜色更新
		//parent->_color = red;
	}

	void Rrotation(Node* cur)
	{
		rotation_num++;
		Node* parent = cur->_parent;
		Node* pparent = parent->_parent;
		//Node* son = cur->_left;
		Node* cur_right = cur->_right;

		parent->_left = cur_right; //左右节点更新
		cur->_right = parent;

		if (cur_right) cur_right->_parent = parent; //父节点的更新
		parent->_parent = cur;
		cur->_parent = pparent;

		if (pparent) //判断是不是空
		{
			if (pparent->_value > cur->_value) pparent->_left = cur; //父节点的父节点更新
			else pparent->_right = cur;
		}
		else
		{
			_root = cur;
			cur->_parent = nullptr; //解耦
		}

		//cur->_color = black; //颜色更新
		//parent->_color = red;
	}

	Fetch_Ruler fr;

	Compare_Ruler cr;

	Node* _root = nullptr;
};