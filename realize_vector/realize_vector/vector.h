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
		//�޲ι���
		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr)
		{}

		//�������乹��
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

		//n��val��ʼ�����죬����һ��int�����Ƿ�ֹ����ƥ�䵽���乹�캯��
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

		//��������
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}

		//��������
		//ע��vector(const vector& v)���ڵĺ�����������д�����ǲ��Ƽ�
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			vector<T> tmp(v.begin(), v.end());
			swap(tmp);
		}

		//����=
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}
		

		//��Դ����
		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstorage = nullptr;
			}
		}

		//������
		iterator begin() 
		{ 
			return _start; 
		}
		iterator end() 
		{ 
			return _finish; 
		}

		//const������
		const_iterator begin() const 
		{ 
			return _start;
		}
		const_iterator end() const 
		{ 
			return _finish; 
		}

		//���������
		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}
		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		//const���������
		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		}
		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}

		//������Ч���ݸ���
		size_t size() const 
		{
			return _finish - _start; 
		}

		//����������С
		size_t capacity() const 
		{ 
			return _endofstorage - _start; 
		}

		//����
		void reserve(size_t n)
		{
			//�Ƚ������������Ϊ_start�ᱻ����
			size_t oldsize = size();

			if (n > capacity())
			{
				T* temp = new T[n];
				//_startΪ��ָ��ʱ��Ӧ���ͷ�
				if (_start)
				{
					//�����ݷ�ʽ��ǳ����������Ϊvector/string���׳�����ǳ��������
					/*memcpy(temp, _start, sizeof(T) * oldsize);*/
					//��_start�����ݻ��߶���һ��һ����ֵ��temp
					for (size_t i = 0; i < size(); ++i)
					{
						//��ֵ�����
						temp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = temp;
				_finish = _start + oldsize;
				_endofstorage = _start + n;
			}
		}

		//�ı���������Ҫ���ʼ��������һ����ʱ����
		//void resize(size_t n, const T& val = T())ʹ�����ã���ͬ�����¿��ܻ�������
		void resize(size_t n, T val = T())
		{
			//����
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

		//β��
		void push_back(const T& x)
		{
			/*//�ռ䲻������
			if (_finish == _endofstorage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}

			*_finish = x;
			++_finish;*/
			insert(end(), x);
		}

		//βɾ
		void pop_back()
		{
			/*assert(_start < _finish);
			--_finish;*/
			erase(end() - 1);
		}

		//�±����
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

		//����
		iterator insert(iterator pos, const T& x)
		{
			//λ�úϷ���
			assert(pos <= _finish && pos >= _start);
			//����
			if (_finish == _endofstorage)
			{
				//ע�������ʧЧ����Ҫ����pos
				size_t oldsize = pos - _start;

				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);

				pos = _start + oldsize;
			}
			//ĩβ
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

		//�������
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