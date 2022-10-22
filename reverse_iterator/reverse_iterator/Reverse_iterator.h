#pragma once

//反向迭代器，返回当前位置的上一个元素
//反向迭代器
template<class Iterator, class Ref, class Ptr>
struct Reverse_iterator
{
	typedef Reverse_iterator<Iterator, Ref, Ptr> self;//三个模板参数用来处理const的问题
	//带参构造函数
	Reverse_iterator(Iterator it)
		:_it(it)
	{}

	Ref operator*()
	{
		Iterator tmp(_it);
		return *(--tmp);//返回的是前一个元素
	}

	Ptr operator->()
	{
		return &(operator*());
	}

	//前置++
	self& operator++()
	{
		--_it;
		return *this;
	}

	//前置--
	self& operator--()
	{
		++_it;
		return *this;
	}

	//!=
	bool operator!=(const self& s)
	{
		return _it != s._it;//顺序不能调换
	}

	Iterator _it;
};