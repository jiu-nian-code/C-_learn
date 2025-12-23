#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

enum Color
{
	red,
	black
};

template<class Key, class Value>
struct RB_Node
{
	typedef RB_Node<Key, Value> Node;

	RB_Node(Key k, Value v, Color c) :
		_key(k),
		_value(v),
		_color(c)
	{
	}

	Node* _parent = nullptr;
	Node* _left = nullptr;
	Node* _right = nullptr;

	Key _key = 0;
	Value _value = 0;

	Color _color = red;
};

template<class Key, class Value>
class RB_Tree
{
public:
	int rotation_num = 0;

	typedef RB_Node<Key, Value> Node;

	bool insert(Key k, Value v)
	{
		if (!_root)
		{
			_root = new Node(k, v, black);
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;

		while (cur)
		{
			if (cur->_key == k) return false;

			parent = cur;
			if (cur->_key > k) cur = cur->_left;
			else cur = cur->_right;
		}

		cur = new Node(k, v, red);
		if (parent->_key > cur->_key)
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
			if (pparent->_key > parent->_key) uncle = pparent->_right;
			else uncle = pparent->_left;

			if (!uncle || uncle->_color == black)
			{
				if (pparent->_key > parent->_key)
				{
					if (parent->_key > cur->_key)
					{
						Rrotation(parent);
						parent->_color = black;
						pparent->_color = red;
					}
					else
					{
						LRrotation(parent);
						cur->_color = black;
						pparent->_color = red;
					}
				}
				else
				{
					if (parent->_key < cur->_key)
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
		return true;
	}

	//void inorder()//中序打印
	//{
	//	_inorder(root);
	//}

	//int high()//树的高度
	//{
	//	return _high(root);
	//}

	//void check()//检查结点平衡
	//{
	//	_check(root);
	//}

	bool CheckColour(Node* root, int blacknum, int benchmark)
	{
		if (root == nullptr)
		{
			if (blacknum != benchmark)
				return false;

			return true;
		}

		if (root->_color == black)
		{
			++blacknum;
		}

		if (root->_color == red && root->_parent && root->_parent->_color == red)
		{
			cout << root->_key << "出现连续红色节点" << endl;
			return false;
		}

		return CheckColour(root->_left, blacknum, benchmark)
			&& CheckColour(root->_right, blacknum, benchmark);
	}

	bool IsBalance()
	{
		return IsBalance(_root);
	}

	bool IsBalance(Node* root)
	{
		if (root == nullptr)
			return true;

		if (root->_color != black)
		{
			return false;
		}

		// 基准值
		int benchmark = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_color == black)
				++benchmark;

			cur = cur->_left;
		}

		return CheckColour(root, 0, benchmark);
	}

	int Height()
	{
		return Height(_root);
	}

	int Height(Node* root)
	{
		if (root == nullptr)
			return 0;

		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);

		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

private:
	//int _check(Node* cur)
	//{
	//	if (!cur) return 0;
	//	int lret = _check(cur->_left);
	//	int rret = _check(cur->_right);
	//	if (lret != rret) cout << cur->_key << " : 错误" << endl;
	//	if (cur->_color == black) return lret + 1;
	//	return lret;
	//}

	//int _high(Node* cur)
	//{
	//	if (!cur) return 0;
	//	int releft = _high(cur->_left);
	//	int reright = _high(cur->_right);
	//	return releft > reright ? releft + 1 : reright + 1;
	//}

	//void _inorder(Node* cur)
	//{
	//	if (!cur) return;
	//	_inorder(cur->_left);
	//	cout << cur->_key << endl;
	//	_inorder(cur->_right);
	//}

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
			if (pparent->_key > cur->_key) pparent->_left = cur; //父节点的父节点更新
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
			if (pparent->_key > cur->_key) pparent->_left = cur; //父节点的父节点更新
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

	Node* _root = nullptr;
};