#pragma once

//��������������ص�ǰλ�õ���һ��Ԫ��
//���������
template<class Iterator, class Ref, class Ptr>
struct Reverse_iterator
{
	typedef Reverse_iterator<Iterator, Ref, Ptr> self;//����ģ�������������const������
	//���ι��캯��
	Reverse_iterator(Iterator it)
		:_it(it)
	{}

	Ref operator*()
	{
		Iterator tmp(_it);
		return *(--tmp);//���ص���ǰһ��Ԫ��
	}

	Ptr operator->()
	{
		return &(operator*());
	}

	//ǰ��++
	self& operator++()
	{
		--_it;
		return *this;
	}

	//ǰ��--
	self& operator--()
	{
		++_it;
		return *this;
	}

	//!=
	bool operator!=(const self& s)
	{
		return _it != s._it;//˳���ܵ���
	}

	Iterator _it;
};