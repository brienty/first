#pragma once
#include <iostream>
#include <vector>
#include <string.h>
#include <assert.h>
#include <algorithm>
#include "Reverse_iterator.h"
using namespace std;
namespace myvector
{
	template <class T>
	class vector 
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		typedef Reverse_iterator<iterator, T&, T*> reverse_iterator;
		typedef Reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;
		//无参构造
		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr)
		{}

		//带参区间构造
		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		//n个val初始化构造，重载一个int类型是防止参数匹配到区间构造函数
		vector(size_t n, const T& val = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(n);
			while (n)
			{
				push_back(val);
				--n;
			}
		}
		vector(int n, const T& val = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(n);
			while (n)
			{
				push_back(val);
				--n;
			}
		}

		//交换函数
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}

		//拷贝构造
		//注：vector(const vector& v)类内的函数可以这样写，但是不推荐
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			vector<T> tmp(v.begin(), v.end());
			swap(tmp);
		}

		//重载=
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}
		

		//资源管理
		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstorage = nullptr;
			}
		}

		//迭代器
		iterator begin() 
		{ 
			return _start; 
		}
		iterator end() 
		{ 
			return _finish; 
		}

		//const迭代器
		const_iterator begin() const 
		{ 
			return _start;
		}
		const_iterator end() const 
		{ 
			return _finish; 
		}

		//反向迭代器
		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}
		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		//const反向迭代器
		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		}
		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}

		//返回有效数据个数
		size_t size() const 
		{
			return _finish - _start; 
		}

		//返回容量大小
		size_t capacity() const 
		{ 
			return _endofstorage - _start; 
		}

		//扩容
		void reserve(size_t n)
		{
			//先将结果保留，因为_start会被更改
			size_t oldsize = size();

			if (n > capacity())
			{
				T* temp = new T[n];
				//_start为空指针时不应该释放
				if (_start)
				{
					//该扩容方式是浅拷贝，参数为vector/string容易出现深浅拷贝问题
					/*memcpy(temp, _start, sizeof(T) * oldsize);*/
					//将_start的数据或者对象一个一个赋值给temp
					for (size_t i = 0; i < size(); ++i)
					{
						//赋值是深拷贝
						temp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = temp;
				_finish = _start + oldsize;
				_endofstorage = _start + n;
			}
		}

		//改变容量，需要则初始化，创建一个临时对象
		//void resize(size_t n, const T& val = T())使用引用，不同环境下可能会有问题
		void resize(size_t n, T val = T())
		{
			//扩容
			if (n > capacity())
			{
				reserve(n);
			}

			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}

		//尾插
		void push_back(const T& x)
		{
			/*//空间不够扩容
			if (_finish == _endofstorage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}

			*_finish = x;
			++_finish;*/
			insert(end(), x);
		}

		//尾删
		void pop_back()
		{
			/*assert(_start < _finish);
			--_finish;*/
			erase(end() - 1);
		}

		//下标访问
		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}
		const T& operator[](size_t pos) const
		{
			assert(pos < size());
			return _start[pos];
		}

		//插入
		iterator insert(iterator pos, const T& x)
		{
			//位置合法化
			assert(pos <= _finish && pos >= _start);
			//扩容
			if (_finish == _endofstorage)
			{
				//注意迭代器失效，需要更新pos
				size_t oldsize = pos - _start;

				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);

				pos = _start + oldsize;
			}
			//末尾
			iterator end = _finish - 1;
			while (pos <= end)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;

			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);

			iterator it = pos + 1;
			while (it < _finish)
			{
				*(it - 1) = *it;
				++it;
			}
			--_finish;

			return pos;
		}

		//清空数据
		void clear()
		{
			_start = _finish = _endofstorage;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
}