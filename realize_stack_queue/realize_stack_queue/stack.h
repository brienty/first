#pragma once
#include <iostream>
#include <stack>
using namespace std;

namespace mystack
{
	template<class T, class Container = deque<T>>
	class stack
	{
	public:
		bool empty()
		{
			return con.empty();
		}

		size_t size()
		{
			return con.size();
		}

		void push(const T& x)
		{
			con.push_back(x);
		}

		void pop()
		{
			con.pop_back();
		}

		T& top()
		{
			return con.back();
		}

		const T& top() const
		{
			return con.back();
		}

	private:
		Container con;
	};
}