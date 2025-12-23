#pragma once

#include<iostream>

#include<algorithm>


using namespace std;

template<class Key, class Value>
struct AVL_Node
{
	typedef AVL_Node<Key, Value> Node;

	AVL_Node(Key k, Value v):
		_key(k),
		_value(v)
	{

	}

	Node* _parent = nullptr;
	Node* _left = nullptr;
	Node* _right = nullptr;
	
	Key _key = 0;
	Value _value = 0;

	int BFactor = 0;//平衡因子
};

template<class Key, class Value>
class AVL_Tree
{
public:
	int rotation_num = 0;

	typedef AVL_Node<Key, Value> Node;

	bool find(Key a)
	{
		return _find(root, a);
	}

	bool insert(Key a, Value b)
	{
		if (!root)//树判空
		{
			root = new Node(a, b);
			return true;
		}

		Node* cur = root;
		Node* parent = nullptr;
		while (cur)//找位置
		{
			if (cur->_key == a) return false;

			parent = cur;
			if (cur->_key > a) cur = cur->_left;
			else cur = cur->_right;
		}

		if (parent->_key > a)//插入
		{
			parent->_left = new Node(a, b);
			cur = parent->_left;
			cur->_parent = parent;
			//parent->BFactor++;
		}
		else
		{
			parent->_right = new Node(a, b);
			cur = parent->_right;
			cur->_parent = parent;
			//parent->BFactor--;
		}

		Node* son = nullptr;
		while (parent)
		{
			if (parent->_key > cur->_key)
			{
				parent->BFactor++;
			}
			else
			{
				parent->BFactor--;
			}

			if (parent->BFactor == 0) break;

			if (parent->BFactor == 2 || parent->BFactor == -2)
			{
				if (parent->_key > cur->_key)
				{
					if (son && (cur->_key > son->_key)) Rrotation(cur);
					else LRrotation(cur);
				}
				else
				{
					if (son && (cur->_key < son->_key)) Lrotation(cur);
					else RLrotation(cur);
				}
				break;
			}

			son = cur;
			cur = parent;
			parent = parent->_parent;
		}


		return true;
	}

	void inorder()//中序打印
	{
		_inorder(root);
	}

	int high()//树的高度
	{
		return _high(root);
	}

	void check()//检查结点平衡
	{
		_check(root);
	}

private:
	void _check(Node* cur)
	{
		if (!cur) return;
		if (high(cur->_left) - high(cur->_right) != cur->BFactor)
		{
			cout << cur->_key << " : " << cur->BFactor << ", " << high(cur->_left) - high(cur->_right) << endl;
		}
		check(cur->_left);
		check(cur->_right);
	}

	int _high(Node* cur)
	{
		if (!cur) return 0;
		int releft = _high(cur->_left);
		int reright = _high(cur->_right);
		return releft > reright ? releft + 1 : reright + 1;
	}

	void _inorder(Node* cur)
	{
		if (!cur) return;
		_inorder(cur->_left);
		cout << cur->_key << endl;
		_inorder(cur->_right);
	}

	void LRrotation(Node* cur)
	{
		if (cur->_right->BFactor == 1)
		{
			Lrotation(cur->_right);
			cur = cur->_parent;
			Rrotation(cur);
			cur->BFactor = 0;
			cur->_left->BFactor = 0;
			cur->_right->BFactor = -1;
		}
		else if (cur->_right->BFactor == -1)
		{
			Lrotation(cur->_right);
			cur = cur->_parent;
			Rrotation(cur);
			cur->BFactor = 0;
			cur->_left->BFactor = 1;
			cur->_right->BFactor = 0;
		}
		else //cur的子结点是刚插入的情况
		{
			Lrotation(cur->_right);
			cur = cur->_parent;
			Rrotation(cur);
			cur->BFactor = 0;
			cur->_left->BFactor = 0;
			cur->_right->BFactor = 0;
		}
	}

	void RLrotation(Node* cur)
	{
		if (cur->_left->BFactor == 1)
		{
			Rrotation(cur->_left);
			cur = cur->_parent;
			Lrotation(cur);
			cur->BFactor = 0;
			cur->_left->BFactor = 0;
			cur->_right->BFactor = -1;
		}
		else if (cur->_left->BFactor == -1)
		{
			Rrotation(cur->_left);
			cur = cur->_parent;
			Lrotation(cur);
			cur->BFactor = 0;
			cur->_left->BFactor = 1;
			cur->_right->BFactor = 0;
		}
		else //cur的子结点是刚插入的情况
		{
			Rrotation(cur->_left);
			cur = cur->_parent;
			Lrotation(cur);
			cur->BFactor = 0;
			cur->_left->BFactor = 0;
			cur->_right->BFactor = 0;
		}
	}

	void Lrotation(Node* cur)
	{
		rotation_num++;
		Node* parent = cur->_parent;
		Node* pparent = parent->_parent;
		Node* cur_left = cur->_left;

		parent->_right = cur_left; //左右节点更新
		cur->_left = parent;

		if(cur_left) cur_left->_parent = parent; //父节点的更新
		parent->_parent = cur;
		cur->_parent = pparent;

		if (pparent) //判断是不是空
		{
			if (pparent->_key > cur->_key) pparent->_left = cur; //父节点的父节点更新
			else pparent->_right = cur;
		}
		else
		{
			root = cur;
			cur->_parent = nullptr; //解耦
		}

		cur->BFactor = 0; //平衡因子的更新
		parent->BFactor = 0;
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
			if (pparent->_key > cur->_key) pparent->_left = cur; //父节点的父节点更新
			else pparent->_right = cur;
		}
		else
		{
			root = cur;
			cur->_parent = nullptr; //解耦
		}

		cur->BFactor = 0; //平衡因子的更新
		parent->BFactor = 0;
	}

	bool _find(Node* root, Key a)
	{
		if (!root) return false;
		if (root->_key == a) return true;

		if (root->_key > a) return _find(root->_left, a);
		return _find(root->_right, a);
	}

	Node* root = nullptr;
};