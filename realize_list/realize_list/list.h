#pragma once
#include <iostream>
#include <assert.h>
#include <list>
#include <algorithm>
#include "Reverse_iterator.h"
using namespace std;

namespace mylist
{
	//ģ���㣬���е�ʹ��struct
	template<class T>
	struct _list_node
	{
		_list_node<T>* next;//ָ����һ�����
		_list_node<T>* prev;//ָ����һ�����
		T _data;//�洢����

		//Ĭ�Ϲ��캯��������һ����������������ȱʡֵ
		_list_node(const T& val = T())
			:next(nullptr)
			, prev(nullptr)
			, _data(val)
		{}
	};

	//������(��������ģ��ָ�����Ϊ)�����е�ʹ��struct
	//ʹ������ģ�������һ�������ݵ����ͣ��������������const����������ͨ���������õ�
	template<class T, class Ref, class Ptr>
	struct _list_iterator
	{
		//�������
		typedef _list_node<T> Node;
		//�������Լ�����������
		typedef _list_iterator<T, Ref, Ptr> self;
		Node* _node;
		
		//���캯��
		_list_iterator(Node* node)
			:_node(node)
		{}
		//����ʹ��Ĭ�ϵģ���Ϊ��㲻�ǵ���������ģ����ɵ������ͷ�
		//�������첻��д��������Ҫ�ľ���ǳ��������Ϊ����������Ҫ�ͽ��ָ��һ��ռ�

		//����*
		Ref operator*()
		{
			//ȡ����
			return _node->_data;
		}

		//����->
		Ptr operator->()
		{
			return &_node->_data;
		}

		//����ǰ��++��������
		self& operator++()
		{
			_node = _node->next;
			//*this�ǵ���������
			return *this;
		}

		//���غ���++�������ڣ���Ҫ����������һ��Ĭ�ϲ�����ǰ��++�����֣����ɺ�������
		self operator++(int)
		{
			//����һ�ݶ�����++
			self temp(*this);
			_node = _node->next;
			//���ؿ����Ķ���
			return temp;
		}

		//����ǰ��--
		self& operator--()
		{
			_node = _node->prev;
			return *this;
		}

		//���غ���--������һ��Ĭ�ϲ�����ǰ��--�����֣����ɺ�������
		self operator--(int)
		{
			self temp(*this);
			_node = _node->prev;
			return temp;
		}

		//����!=
		bool operator!=(const self& it)
		{
			//�Ƚ��������������_node�Ƿ���һ��
			return _node != it._node;
		}

		//���ص���
		bool operator==(const self& it)
		{
			return _node == it._node;
		}
	};

	//����
	template<class T>
	class list
	{
	public:
		//���̽������
		typedef _list_node<T> node;
		//������������
		typedef _list_iterator<T, T&, T*> iterator;//��ͨ������
		typedef _list_iterator<T, const T&, const T*> const_iterator;//const������
		typedef Reverse_iterator<iterator, T&, T*> reverse_iterator;//���������
		typedef Reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;//const���������
		//�޲ι��캯��
		list()
		{
			_head = new node();
			_head->next = _head;
			_head->prev = _head;
		}

		//���εĵ��������乹�캯��
		template <class InputIterator>  
		list(InputIterator first, InputIterator last)
		{
			empty_init();//�ȳ�ʼ������ͷ��㣬��Ȼû������
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		//��������������clear������æ����
		~list()
		{
			clear();
			delete _head;//�ͷ��ڱ�λ��ͷ���
			_head = nullptr;
		}

		//�ճ�ʼ������
		void empty_init()
		{
			_head = new node();
			_head->next = _head;
			_head->prev = _head;
		}

		//����������ֻ��Ҫ�����ڱ�λ��ͷ��㼴��
		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
		}

		//��������
		//��ͳд��
		//list(const list<T>& lt)
		//{
		//	//�ȳ�ʼ��������������
		//	_head = new node();
		//	_head->next = _head;
		//	_head->prev = _head;

		//	//�����������󽫿�������Ľ����������������
		//	for (auto e : lt)
		//	{
		//		push_back(e);
		//	}
		//}
		//�ִ�����
		list(const list<T>& lt)
		{
			empty_init();//�Ƚ��Լ���ʼ��
			list<T> tmp(lt.begin(), lt.end());//��lt����tmp
			swap(tmp);//��tmp��ĺͱ�����Ľ�������tmp�ͷų�ʼ����ͷ���
		}

		//�ִ���������=
		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}

		//������
		iterator begin()
		{
			//iterator�������󴴽���һ�����ĵ�����
			return iterator(_head->next);
		}
		iterator end()
		{
			//iterator�������󴴽����һ��������һ���ĵ�����
			return iterator(_head);
		}

		//const������
		const_iterator begin() const
		{
			//conts_iterator�������󴴽���һ�����ĵ�����
			return const_iterator(_head->next);
		}
		const_iterator end() const
		{
			//const_iterator�������󴴽����һ��������һ���ĵ�����
			return const_iterator(_head);
		}


		//���������
		reverse_iterator rbegin()
		{
			//reverse_iterator�������󴴽���һ�����ĵ�����
			return reverse_iterator(end());
		}
		reverse_iterator rend()
		{
			//reverse_iterator�������󴴽����һ��������һ���ĵ�����
			return reverse_iterator(begin());
		}

		//const���������
		const_reverse_iterator rbegin() const
		{
			//const_reverse_iterator�������󴴽���һ�����ĵ�����
			return const_reverse_iterator(end());
		}
		const_reverse_iterator rend() const
		{
			//const_reverse_iterator�������󴴽����һ��������һ���ĵ�����
			return const_reverse_iterator(begin());
		}

		//���룬�����ڵ�����ʧЧ������Ȼ���÷���ֵ
		iterator insert(iterator pos, const T& x)
		{
			//�������
			node* newnode = new node(x);
			node* cur = pos._node;//�洢��ǰλ��
			node* prev = cur->prev;//�洢ǰһ��λ��

			//��newnode��nextָ��pos��prevָ��pos��ǰһ�����ٰ�posǰһ��ָ��newnode��pos��prevָ��newnode
			newnode->next = cur;
			newnode->prev = prev;
			prev->next = newnode;
			cur->prev = newnode;

			return iterator(newnode);//����һ������������������
		}

		//β��
		void push_back(const T& val)
		{
			////βָ��
			//node* tail = _head->prev;
			//node* newnode = new node(val);
			////���һ������nextָ��newnode��newnode��prevָ�����һ�����
			////newnode��nextָ���ڱ�λ��ͷ��㣬�ڱ�λͷ����orevָ��newnode
			//tail->next = newnode;
			//newnode->prev = tail;
			//newnode->next = _head;
			//_head->prev = newnode;
			insert(end(), val);
		}

		//ͷ��
		void push_front(const T& val)
		{
			insert(begin(), val);
		}

		//ɾ������Ҫע������Ұָ����ʵĵ�����ʧЧ���⣬��Ϊ�ͷ���cur���÷�����һ��λ��������
		iterator erase(iterator pos)
		{
			//����ɾ���ڱ�λ��ͷ���
			assert(pos != end());

			node* cur = pos._node;//�洢��ǰλ��
			node* next = cur->next;//�洢ǰһ��λ��
			node* prev = cur->prev;//�洢��һ��λ��

			//��prev��nextָ��next��next��prevָ��prev���ͷ�cur
			prev->next = next;
			next->prev = prev;
			delete cur;

			return iterator(next);//�õ��������󴴽�һ���������󷵻���һ��λ�ã����������ʧЧ
		}

		//βɾ
		void pop_back()
		{
			erase(--end());
		}

		//ͷɾ
		void pop_front()
		{
			erase(begin());
		}

		//��ս��
		void clear()
		{
			iterator it = begin();
			//�ڱ�λ��ͷ�����Ҫ����
			while (it != end())
			{
				it = erase(it);//��Ҫ��ֵ����ֹ������ʧЧ
			}
		}

	private:
		node* _head;
	};
}