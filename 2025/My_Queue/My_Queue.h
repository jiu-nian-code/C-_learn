#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

#include<deque>

using namespace std;

namespace jiunian
{
	template<class T, class container = deque<T>>
	class queue
	{
	public:
		typedef queue<T, container> Self;

		//queue()
		//{
		//}

		//queue(Self& x):
		//	con(x.con)
		//{
		//}

		//~queue()
		//{
		//}

		bool empty() const
		{
			return con.empty();
		}

		size_t size() const
		{
			return con.size();
		}

		T& front()
		{
			return con.front();
		}

		const T& front() const
		{
			return con.front();
		}

		T& back()
		{
			return con.back();
		}

		const T& back() const
		{
			return con.back();
		}

		void push(const T& val)
		{
			con.push_back(val);
		}

		void pop()
		{
			con.pop_front();
		}

		void swap(Self& x)
		{
			con.swap(x.con);
		}

		Self operator=(Self& x)
		{
			con = x.con;
			return *this;
		}
	private:
		container con;
	};
}