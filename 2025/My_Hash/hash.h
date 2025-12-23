#pragma once

#include<iostream>

#include<vector>

using namespace std;

template<class T>
struct Uint_Transform_Ruler
{
	size_t operator()(const T& a)
	{
		return (size_t)a;
	}
};

template<>
struct Uint_Transform_Ruler<string>
{
	size_t operator()(const string& s)
	{
		const char* str = s.c_str();
		unsigned int seed = 131; // 31 131 1313 13131 131313
		unsigned int hash = 0;
		while (*str)
		{
			hash = hash * seed + (*str++);
		}
		return (hash & 0x7FFFFFFF); // 防溢出
	}
};

size_t My_GetNextPrime(size_t prime)
{
	const int PRIMECOUNT = 28;
	static const size_t primeList[PRIMECOUNT] =
	{
		53ul, 97ul, 193ul, 389ul, 769ul,
		1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
		49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
		1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
		50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
		1610612741ul, 3221225473ul, 4294967291ul
	};

	size_t i = 0;

	for (; i < PRIMECOUNT; ++i)
	{
		if (primeList[i] > prime)
			return primeList[i];
	}
	return primeList[i];
}

namespace Open_Addressing
{
	enum State
	{
		Exist,
		Empty,
		Delete
	};

	template<class Key, class Value>
	struct Hash_Node
	{
		Hash_Node(Key k, Value v, State s) :
			_key(k),
			_value(v),
			_state(s)
		{

		}

		Key _key;
		Value _value;
		State _state;
	};

	template<class Key, class Value>
	class Hash
	{
	public:
		typedef Hash_Node<Key, Value> Node;

		Hash() :
			_table(10, Node(Key(), Value(), Empty)),
			N(0)
		{

		}

		bool insert(Key k, Value v)
		{
			if ((double)N / _table.size() >= 0.7) // 扩容
			{
				int new_size = _table.size() * 2;
				vector<Node> new_table(new_size, Node(Key(), Value(), Empty));
				swap(new_table, _table);
				N = 0;
				for (auto& e : new_table) //相对位置重新排，Delete就可以不用管不了
					if (e._state == Exist)
						insert(e._key, e._value);
			}

			int cur = k % _table.size(); // 取余数
			while (_table[cur]._state == Exist)
			{
				if (_table[cur]._key == k) return false;
				++cur;
				cur %= _table.size();
			}

			++N;

			_table[cur]._key = k;
			_table[cur]._value = v;
			_table[cur]._state = Exist;

			return true;
		}

		bool erase(Key k)
		{
			int cur = k % _table.size(); // 取余数

			while (_table[cur]._state != Empty) // 忽视Delete的原因是可能会出现先往后找插入之后把之前的删掉了，所以即使遇到Delete也要往后跑
			{
				if (_table[cur]._state == Exist && _table[cur]._key == k)
				{
					--N;
					_table[cur]._state = Delete;
					return true;
				}

				++cur;
				cur %= _table.size();

				if (cur == k % _table.size()) return false; //找一圈没找到
			}

			return false;
		}

		bool find(Key k)
		{
			int cur = k % _table.size(); // 取余数
			while (_table[cur]._state == Exist)
			{
				if (_table[cur]._key == k) return true;
				++cur;
				cur %= _table.size();
			}
			return false;
		}

		size_t size()
		{
			return N;
		}

	private:
		vector<Node> _table;
		size_t N;
	};
}

namespace Hash_bucket
{
	template<class Data>
	struct Hash_List_Node
	{
		typedef Hash_List_Node<Data> Self;

		Hash_List_Node(const Data& d, Self* n) :
			_data(d),
			_next(n)
		{

		}

		Data _data;
		Self* _next;
	};

	template<class Key, class Data, class Fetch_Ruler, class Transform_Ruler>
	class Hash;

	template<class Key, class Data, class Ptr, class Ref, class Fetch_Ruler, class Transform_Ruler>
	struct _Hash_Iterator
	{
		typedef _Hash_Iterator<Key, Data, Ptr, Ref, Fetch_Ruler, Transform_Ruler> Self;

		typedef _Hash_Iterator<Key, Data, Data*, Data&, Fetch_Ruler, Transform_Ruler> Normal_RB_Iterator;

		typedef Hash_List_Node<Data> Node;

		//typedef Hash<Key, Data, Fetch_Ruler, Transform_Ruler>* PHash; //重要！！！巨坑，typedef指针后被当成普通类型，const修饰只能表示指针不能被修改，无法转换const的this指针

		_Hash_Iterator(const Hash<Key, Data, Fetch_Ruler, Transform_Ruler>* ph, Node* pn):
			_pHash(ph),
			_pNode(pn)
		{

		}

		_Hash_Iterator(const Normal_RB_Iterator& x):
			_pHash(x._pHash),
			_pNode(x._pNode)
		{
		
		}

		Self& operator++()
		{
			if (_pNode->_next)
			{
				_pNode = _pNode->_next;
			}
			else
			{
				Fetch_Ruler fr;
				Transform_Ruler tr;
				size_t cur = tr(fr(_pNode->_data)) % _pHash->_table.size();
				++cur;
				while (cur < _pHash->_table.size())
				{
					if (_pHash->_table[cur])
					{
						_pNode = _pHash->_table[cur];
						return *this;
					}
					else
					{
						++cur;
					}
				}
				_pNode = nullptr;
			}

			return *this;
		}

		Self& operator++(int)
		{
			Self* tmp = this;
			if (_pNode->_next)
			{
				_pNode = _pNode->_next;
			}
			else
			{
				Fetch_Ruler fr;
				Transform_Ruler tr;
				size_t cur = tr(fr(_pNode->_data)) % _pHash->_table.size();
				++cur;
				while (cur < _pHash->_table.size())
				{
					if (_pHash->_table[cur])
					{
						_pNode = _pHash->_table[cur];
						return *tmp;
					}
					else
					{
						++cur;
					}
				}
				_pNode = nullptr;
			}

			return *tmp;
		}

		Ptr operator->()
		{
			return &(_pNode->_data);
		}

		Ref operator*()
		{
			return _pNode->_data;
		}

		bool operator!=(const Self& x) const
		{
			return _pNode != x._pNode;
		}
		
		bool operator==(const Self& x) const
		{
			return _pNode == x._pNode;
		}

		const Hash<Key, Data, Fetch_Ruler, Transform_Ruler>* _pHash;

		Node* _pNode;
	};

	template<class Key, class Data, class Fetch_Ruler, class Transform_Ruler>
	class Hash
	{
	public:
		template<class Key, class Data, class Ptr, class Ref, class Fetch_Ruler, class Transform_Ruler>
		friend struct _Hash_Iterator;

		typedef Hash_List_Node<Data> Node;

		typedef _Hash_Iterator<Key, Data, Data*, Data&, Fetch_Ruler, Transform_Ruler> iterator;

		typedef _Hash_Iterator<Key, Data, const Data*, const Data&, Fetch_Ruler, Transform_Ruler> const_iterator;

		typedef Hash<Key, Data, Fetch_Ruler, Transform_Ruler> Self;

		iterator begin()
		{
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				if (cur)
				{
					return iterator(this, cur);
				}
			}

			return iterator(this, nullptr);
		}

		const_iterator begin() const
		{
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				if (cur)
				{
					return const_iterator(this, cur);
				}
			}

			return const_iterator(this, nullptr);
		}

		iterator end()
		{
			return iterator(this, nullptr);
		}
		
		const_iterator end() const
		{
			return const_iterator(this, nullptr);
		}

		Hash() :
			_table(11, nullptr),
			N(0)
		{

		}

		pair<iterator, bool> insert(const Data& d)
		{
			Fetch_Ruler fr;
			Transform_Ruler tr;
			if ((double)N / _table.size() >= 1) //扩容
			{
				size_t new_size = My_GetNextPrime(_table.size());
				vector<Node*> new_table(new_size, nullptr);
				std::swap(new_table, _table);
				N = 0;
				for (auto& e : new_table)
				{
					Node* ptr = e;
					while (ptr)
					{
						Node* next = ptr->_next;
						size_t cur = tr(fr(ptr->_data)) % _table.size();
						ptr->_next = _table[cur];
						_table[cur] = ptr;
						++N;
						ptr = next;
					}
				}
			}

			size_t cur = tr(fr(d)) % _table.size();
			Node* tmp = _table[cur];
			while (tmp)
			{
				if (tr(fr(tmp->_data)) == tr(fr(d))) return make_pair(iterator(this, tmp), false);
				tmp = tmp->_next;
			}

			Node* new_node = new Node(d, nullptr);
			new_node->_next = _table[cur];
			_table[cur] = new_node;
			++N;
			return make_pair(iterator(this, _table[cur]), true);
		}

		bool erase(Key k)
		{
			Fetch_Ruler fr;
			Transform_Ruler tr;
			size_t cur = tr(k) % _table.size();
			Node* ptr = _table[cur];
			Node* prev = nullptr;
			while (ptr)
			{
				if (tr(fr(ptr->_data)) == tr(k))
				{
					if (!prev)
					{
						_table[cur] = ptr->_next;
						delete ptr;
					}
					else
					{
						prev->_next = ptr->_next;
						delete ptr;
					}
					return true;
				}

				prev = ptr;
				ptr = ptr->_next;
			}

			return false;
		}

		bool find(Key k)
		{
			Fetch_Ruler fr;
			Transform_Ruler tr;
			size_t cur = tr(k) % _table.size();
			Node* ptr = _table[cur];
			while (ptr)
			{
				if (tr(fr(ptr->_data)) == tr(k)) return true;
				ptr = ptr->_next;
			}
			return false;
		}

	private:
		vector<Node*> _table;
		size_t N;
	};
};