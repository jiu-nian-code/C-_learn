#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

#include<deque>

using namespace std;

namespace jiunian
{
	template<class T, class container = deque<T>>
	class stack
	{
	public:
		typedef stack<T, container> Self;

		//stack()
		//{
		//}

		//stack(Self& x):
		//	con(x.con)
		//{
		//}

		//~stack()
		//{
		//}

		bool empty()const
		{
			return con.empty();
		}

		size_t size()const
		{
			return con.size();
		}

		T& top()
		{
			return con.back();
		}

		const T& top() const
		{
			return con.back();
		}

		void push(const T& val)
		{
			con.push_back(val);
		}

		void pop()
		{
			con.pop_back();
		}

		void swap(Self& x)
		{
			con.swap(x.con);
		}

		Self operator=(Self x)
		{
			con = x.con;
			return *this;
		}
	private:
		container con;
	};
}