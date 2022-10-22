#pragma once
#include <iostream>
#include <queue>
#include <functional>
#include <assert.h>
using namespace std;


// ���ȼ����� -- ��� <  С�� >
namespace mypriority_queue
{
	template<class T>
	struct less
	{
		bool operator()(const T& x, const T& y) const
		{
			return x < y;
		}
	};

	template<class T>
	struct greater
	{
		bool operator()(const T& x, const T& y) const
		{
			return x > y;
		}
	};

	template<class T, class Container = vector<T>, class compare = less<T>>
	class priority_queue
	{
	public:

		priority_queue(const compare& comfun = compare())
			:com(comfun)
		{}

		template <class InputIterator>
		priority_queue(InputIterator first, InputIterator last, const compare& comp = compare())
			:com(comp)
		{
			//��������
			while (first != last)
			{
				con.push_back(*first);
				++first;
			}

			//�������µ����������һ����Ҷ�ӽ�㴦��ʼ����
			for (int i = (con.size() - 1 - 1) / 2; i >= 0; --i)
			{
				Adjustdown(i);
			}
		}

		bool empty()
		{
			return con.empty();
		}

		size_t size()
		{
			return con.size();
		}

		const T& top()
		{
			return con[0];
		}

		//Ĭ�Ͻ����
		void Adjustup(int child)
		{
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				if(com(con[parent] ,con[child]))
				{
					swap(con[child], con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		void push(const T& val)
		{
			con.push_back(val);
			Adjustup(con.size() - 1);
		}

		//Ĭ�Ͻ����
		void Adjustdown(int parent)
		{
			size_t child = parent * 2 + 1;
			while (child < con.size())
			{
				if (child + 1 < con.size() && com(con[child], con[child + 1]))
				{
					++child;
				}

				if (com(con[parent], con[child]))
				{
					swap(con[child], con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

		void pop()
		{
			assert(!con.empty());
			swap(con[0], con[con.size() - 1]);
			con.pop_back();

			Adjustdown(0);
		}

	private:
		compare com;
		Container con;
	};
}