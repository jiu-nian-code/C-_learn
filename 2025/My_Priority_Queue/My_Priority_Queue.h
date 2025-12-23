#pragma once

#include<iostream>

#include<vector>

using namespace std;

namespace jiunian
{
	template<class T, class container = vector<T>, class compare = less<T>>
	class priority_queue
	{
	public:
		typedef priority_queue<T, container> Self;

		priority_queue()
		{
		}

		template<class Iterator>
		priority_queue(Iterator begin, Iterator end)
		{
			Iterator cur = begin;
			while (cur != end) con.push_back(*(cur++));
			int pos = size() / 2 - 1;
			while (pos >= 0) adjustdown(pos--);
		}

		bool empty() const
		{
			return con.empty();
		}

		size_t size() const
		{
			return con.size();
		}

		const T& top() const
		{
			return con.front();
		}

		void push(const T& val)
		{
			con.push_back(val);
			adjustup(con.size() - 1);
		}

		void pop()
		{
			std::swap(con.front(), con.back());
			con.pop_back();
			adjustdown(0);
		}

		void swap(priority_queue& x)
		{
			con.swap(x.con);
		}

		Self operator=(Self x)
		{
			con = x.con;
			comp = x.comp;
			return *this;
		}

	private:
		void adjustdown(int pos)//向下调整
		{
			int parent = pos;
			int child = parent * 2 + 1;
			if (child + 1 < con.size() && comp(con[child] , con[child + 1])) ++child;
			while(child < con.size())
			{
				if (comp(con[parent], con[child]))
				{
					std::swap(con[child], con[parent]);
					parent = child;
					child = parent * 2 + 1;
					if (child + 1 < con.size() && comp(con[child], con[child + 1])) ++child;
				}
				else
				{
					break;
				}
			}
		}

		void adjustup(int pos)//向上调整
		{
			int child = pos;
			int parent = (child + 1) / 2 - 1;
			while (parent >= 0)
			{
				if (comp(con[parent], con[child]))
				{
					std::swap(con[child], con[parent]);
					child = parent;
					parent = (child + 1) / 2 - 1;
				}
				else
				{
					break;
				}
			}
		}

		container con;
		compare comp;
	};

	template<class iterator, class Ref, class Ptr>
	class reverse_iterator
	{
	public:
		typedef reverse_iterator<iterator, Ref, Ptr> Self;

		Self& operator++()
		{
			it--;
			return *this;
		}

		//Self& operator++(int)
		//{
		//	Self* copy = this;
		//	it--;
		//	return *copy;
		//}

		Self& operator--()
		{
			it++;
			return *this;
		}

		//Self& operator--(int)
		//{
		//	reverse_iterator* copy = this;
		//	it++;
		//	return *copy;
		//}

		Ref operator*()
		{
			iterator pos = it;
			return *(--pos);
		}

		Ptr operator->()
		{
			//iterator pos = it;
			//return &(*(--pos));

			return &(operator*());
		}

		bool operator!=(Self& x)
		{
			return it != x.it;
		}

		bool operator==(Self& x)
		{
			return it == x.it;
		}
	private:
		iterator it;
	};
}