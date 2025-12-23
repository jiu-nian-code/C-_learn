#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

#include<string>

using namespace std;

template<class K, class V>
struct BSTreeNode
{
	K _key;
	V _value;
	BSTreeNode* _left;
	BSTreeNode* _right;

	BSTreeNode(K key = K(), V value = V()) :
		_key(key),
		_value(value),
		_left(nullptr),
		_right(nullptr)
	{
	}
};


template<class K, class V>
class BSTree
{
	typedef BSTreeNode<K, V> Node;
public:
	BSTree():
		_root(nullptr)
	{
	}

	BSTree(const BSTree<K, V>& t)
	{
		copy(_root, t._root);
	}

	~BSTree()
	{
		Destroy(_root);
	}

	BSTree<K, V>& operator=(BSTree<K, V> t)
	{
		swap(_root, t._root);
		return *this;
	}

	bool Insert(const K& key, const V& value)
	{
		if (_root == nullptr)
		{
			_root = new Node(key, value);
			return true;
		}
		Node* cur = _root;
		Node* prev = nullptr;
		while (cur)
		{
			if (key < cur->_key)
			{
				prev = cur;
				cur = cur->_left;
			}
			else if (key > cur->_key)
			{
				prev = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}
		Node* newnode = new Node(key, value);
		if (key > prev->_key)
			prev->_right = newnode;
		else
			prev->_left = newnode;
		return true;
	}

	bool Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (key < cur->_key)
			{
				cur = cur->_left;
			}
			else if (key > cur->_key)
			{
				cur = cur->_right;
			}
			else
			{
				return true;
			}
		}
		return false;
	}

	bool Erase(const K& key)
	{
		Node* cur = _root;
		Node* prev = nullptr;
		while (cur)
		{
			if (key > cur->_key)
			{
				prev = cur;
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				prev = cur;
				cur = cur->_left;
			}
			else//找到了
			{
				if (cur->_left == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else
					{
						if (prev->_left == cur)
							prev->_left = cur->_right;
						else
							prev->_right = cur->_right;
					}
				}
				else if (cur->_right == nullptr)
				{
					if(cur == _root)
					{
						_root = cur->_right;
					}
					else
					{
						if (prev->_left == cur)
							prev->_left = cur->_left;
						else
							prev->_right = cur->_left;
					}
				}
				else
				{
					Node* leftmax = cur->_left;
					Node* leftmax_prev = cur;
					while (leftmax->_right)
					{
						leftmax_prev = leftmax;
						leftmax = leftmax->_right;
					}
					swap(leftmax->_key, cur->_key);
					swap(leftmax->_value, cur->_value);
					if (leftmax_prev->_left == leftmax)
						leftmax_prev->_left = leftmax->_left; 
					else
						leftmax_prev->_right = leftmax->_left;
					cur = leftmax;
				}
				delete cur;
				return true;
			}
		}
		return false;
	}

	void InOrder()//中序遍历，结果是顺序
	{
		_InOrder(_root);
	}

	bool InsertR(const K& key, const V& value)
	{
		return _InsertR(_root, key, value);
	}

	bool EraseR(const K& key)
	{
		return _Erase(_root, key);
	}

	bool FindR(const K& key)
	{
		return _Find(_root, key);
	}
private:
	void copy(Node*& root, Node* const& t)
	{
		if (t == nullptr) return;
		root = new Node(t->_key, t->_value);
		copy(root->_left, t->_left);
		copy(root->_right, t->_right);
	}

	void Destroy(Node*& root)
	{
		if (root == nullptr) return;
		Destroy(root->_left);
		Destroy(root->_right);
		delete root;
		root = nullptr;
	}

	bool _Find(Node*& root, const K& key)
	{
		if (root == nullptr) return false;
		if (root->_key == key) return true;
		if (key > root->_key) return _Find(root->_right, key);
		if (key < root->_key) return _Find(root->_left, key);
	}

	bool _Erase(Node*& root, const K& key)
	{
		if (root == nullptr) return false;
		if (key > root->_key)
		{
			_Erase(root->_right, key);
		}
		else if (key < root->_key)
		{
			_Erase(root->_left, key);
		}
		else
		{
			Node* prev = root;
			if (root->_left == nullptr) 
			{
				root = root->_right;
			}
			else if (root->_right == nullptr) 
			{
				root = root->_left;
			}
			else
			{
				Node* leftmax = root->_left;
				while (leftmax->_right)
				{
					leftmax = leftmax->_right;
				}
				swap(leftmax->_key, root->_key);
				swap(leftmax->_value, root->_value);
				return _Erase(root->_left, key);//leftmax不能传,交换完成之后二叉的位置被破坏，必须传root->_left，不然就往右边找了
			}
			delete prev;
			return true;
		}
	}

	bool _InsertR(Node*& root, const K& key, const V& value)
	{
		if (root == nullptr) 
		{
			root = new Node(key, value);
			return true;
		}
		if (key > root->_key)
		{
			return _InsertR(root->_right, key, value);
		}
		else if (key < root->_key)
		{
			return _InsertR(root->_left, key, value);
		}
		else
		{
			return false;
		}
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_key << " " << root->_value << endl;
		_InOrder(root->_right);
	}

	Node* _root;
};

void TestBSTree()
{
	BSTree<string, string> dict;
	dict.InsertR("insert", "插入");
	dict.InsertR("erase", "删除");
	dict.InsertR("left", "左边");
	dict.InsertR("string", "字符串");
	BSTree<string, string> a(dict);
	//dict.EraseR("insert");
	a = dict;
	a.InOrder();
	//BSTreeNode<string, string>* tmp = dict.FindR("erase");
}

int main()
{
	TestBSTree();
	return 0;
}