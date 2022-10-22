#pragma once
#include <iostream>
#include <assert.h>
#include <list>
#include <algorithm>
#include "Reverse_iterator.h"
using namespace std;

namespace mylist
{
	//模板结点，公有的使用struct
	template<class T>
	struct _list_node
	{
		_list_node<T>* next;//指向下一个结点
		_list_node<T>* prev;//指向上一个结点
		T _data;//存储数据

		//默认构造函数，创建一个匿名对象用来给缺省值
		_list_node(const T& val = T())
			:next(nullptr)
			, prev(nullptr)
			, _data(val)
		{}
	};

	//迭代器(本质上是模拟指针的行为)，公有的使用struct
	//使用三个模板参数，一个是数据的类型，另外两个是针对const迭代器和普通迭代器设置的
	template<class T, class Ref, class Ptr>
	struct _list_iterator
	{
		//声明结点
		typedef _list_node<T> Node;
		//重命名自己后续更方便
		typedef _list_iterator<T, Ref, Ptr> self;
		Node* _node;
		
		//构造函数
		_list_iterator(Node* node)
			:_node(node)
		{}
		//析构使用默认的，因为结点不是迭代器申请的，不由迭代器释放
		//拷贝构造不用写，我们需要的就是浅拷贝，因为迭代器就是要和结点指向一块空间

		//重载*
		Ref operator*()
		{
			//取数据
			return _node->_data;
		}

		//重载->
		Ptr operator->()
		{
			return &_node->_data;
		}

		//重载前置++，对象还在
		self& operator++()
		{
			_node = _node->next;
			//*this是迭代器对象
			return *this;
		}

		//重载后置++，对象不在，需要拷贝，设置一个默认参数和前置++做区分，构成函数重载
		self operator++(int)
		{
			//拷贝一份对象再++
			self temp(*this);
			_node = _node->next;
			//返回拷贝的对象
			return temp;
		}

		//重载前置--
		self& operator--()
		{
			_node = _node->prev;
			return *this;
		}

		//重载后置--，设置一个默认参数和前置--做区分，构成函数重载
		self operator--(int)
		{
			self temp(*this);
			_node = _node->prev;
			return temp;
		}

		//重载!=
		bool operator!=(const self& it)
		{
			//比较两个迭代器里的_node是否是一个
			return _node != it._node;
		}

		//重载等于
		bool operator==(const self& it)
		{
			return _node == it._node;
		}
	};

	//链表
	template<class T>
	class list
	{
	public:
		//缩短结点名字
		typedef _list_node<T> node;
		//重命名迭代器
		typedef _list_iterator<T, T&, T*> iterator;//普通迭代器
		typedef _list_iterator<T, const T&, const T*> const_iterator;//const迭代器
		typedef Reverse_iterator<iterator, T&, T*> reverse_iterator;//反向迭代器
		typedef Reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;//const反向迭代器
		//无参构造函数
		list()
		{
			_head = new node();
			_head->next = _head;
			_head->prev = _head;
		}

		//带参的迭代器区间构造函数
		template <class InputIterator>  
		list(InputIterator first, InputIterator last)
		{
			empty_init();//先初始化，给头结点，不然没法继续
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		//析构函数，调用clear函数帮忙清理
		~list()
		{
			clear();
			delete _head;//释放哨兵位的头结点
			_head = nullptr;
		}

		//空初始化函数
		void empty_init()
		{
			_head = new node();
			_head->next = _head;
			_head->prev = _head;
		}

		//交换函数，只需要交换哨兵位的头结点即可
		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
		}

		//拷贝构造
		//传统写法
		//list(const list<T>& lt)
		//{
		//	//先初始化待被拷贝对象
		//	_head = new node();
		//	_head->next = _head;
		//	_head->prev = _head;

		//	//遍历拷贝对象将拷贝对象的结点插入待被拷贝对象
		//	for (auto e : lt)
		//	{
		//		push_back(e);
		//	}
		//}
		//现代方法
		list(const list<T>& lt)
		{
			empty_init();//先将自己初始化
			list<T> tmp(lt.begin(), lt.end());//用lt构造tmp
			swap(tmp);//把tmp里的和本对象的交换，让tmp释放初始化的头结点
		}

		//现代方法重载=
		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}

		//迭代器
		iterator begin()
		{
			//iterator匿名对象创建第一个结点的迭代器
			return iterator(_head->next);
		}
		iterator end()
		{
			//iterator匿名对象创建最后一个结点的下一个的迭代器
			return iterator(_head);
		}

		//const迭代器
		const_iterator begin() const
		{
			//conts_iterator匿名对象创建第一个结点的迭代器
			return const_iterator(_head->next);
		}
		const_iterator end() const
		{
			//const_iterator匿名对象创建最后一个结点的下一个的迭代器
			return const_iterator(_head);
		}


		//反向迭代器
		reverse_iterator rbegin()
		{
			//reverse_iterator匿名对象创建第一个结点的迭代器
			return reverse_iterator(end());
		}
		reverse_iterator rend()
		{
			//reverse_iterator匿名对象创建最后一个结点的下一个的迭代器
			return reverse_iterator(begin());
		}

		//const反向迭代器
		const_reverse_iterator rbegin() const
		{
			//const_reverse_iterator匿名对象创建第一个结点的迭代器
			return const_reverse_iterator(end());
		}
		const_reverse_iterator rend() const
		{
			//const_reverse_iterator匿名对象创建最后一个结点的下一个的迭代器
			return const_reverse_iterator(begin());
		}

		//插入，不存在迭代器失效但是仍然设置返回值
		iterator insert(iterator pos, const T& x)
		{
			//创建结点
			node* newnode = new node(x);
			node* cur = pos._node;//存储当前位置
			node* prev = cur->prev;//存储前一个位置

			//将newnode的next指向pos，prev指向pos的前一个，再把pos前一个指向newnode，pos的prev指向newnode
			newnode->next = cur;
			newnode->prev = prev;
			prev->next = newnode;
			cur->prev = newnode;

			return iterator(newnode);//返回一个迭代器的匿名对象
		}

		//尾插
		void push_back(const T& val)
		{
			////尾指针
			//node* tail = _head->prev;
			//node* newnode = new node(val);
			////最后一个结点的next指向newnode，newnode的prev指向最后一个结点
			////newnode的next指向哨兵位的头结点，哨兵位头结点的orev指向newnode
			//tail->next = newnode;
			//newnode->prev = tail;
			//newnode->next = _head;
			//_head->prev = newnode;
			insert(end(), val);
		}

		//头插
		void push_front(const T& val)
		{
			insert(begin(), val);
		}

		//删除，需要注意会出现野指针访问的迭代器失效问题，因为释放了cur，用返回下一个位置来避免
		iterator erase(iterator pos)
		{
			//不能删除哨兵位的头结点
			assert(pos != end());

			node* cur = pos._node;//存储当前位置
			node* next = cur->next;//存储前一个位置
			node* prev = cur->prev;//存储后一个位置

			//将prev的next指向next，next的prev指向prev，释放cur
			prev->next = next;
			next->prev = prev;
			delete cur;

			return iterator(next);//用迭代器对象创建一个匿名对象返回下一个位置，避免迭代器失效
		}

		//尾删
		void pop_back()
		{
			erase(--end());
		}

		//头删
		void pop_front()
		{
			erase(begin());
		}

		//清空结点
		void clear()
		{
			iterator it = begin();
			//哨兵位的头结点需要留着
			while (it != end())
			{
				it = erase(it);//需要赋值，防止迭代器失效
			}
		}

	private:
		node* _head;
	};
}