#pragma once
#include <iostream>
#include <queue>
using namespace std;

//FIFO
namespace myqueue
{
	template <class T, class Container = deque<T>>
	class queue
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

		void pop()
		{
			con.pop_front();
		}
	private:
		Container con;
	};
}