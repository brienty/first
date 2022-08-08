#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <assert.h>
using namespace std;

//stringʵ��
namespace mystring
{
	class string
	{
	public:
		//���������ṩconst��ֹ���ݱ��۸�
		typedef char* iterator;
		typedef const char* const_iterator;

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		//���캯����ʹ��ȱʡֵ����ΪĬ�Ϲ��캯�������޲ι��캯�����ã�ʹ�����γ�ʼ���ķ�ʽ����Ƶ������strlen
		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		//����������������������
		void swap(string& temp)
		{
			//std���swap��ǳ����
			std::swap(_str, temp._str);
			std::swap(_size, temp._size);
			std::swap(_capacity, temp._capacity);
		}

		//�ִ������Ŀ������죬��s��ʼ������ֹ��=������������ĵĵ�ַ�����ֵ��Ȼ���ͷ����ֵ
		string(const string& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			//����temp���������ٸ�s
			string temp(s._str);
			swap(temp);
		}

		//��������
		~string()
		{
			if (_str)
			{
				delete[]_str;
				_str = nullptr;
				_size = _capacity = 0;
			}
		}

		//����C�����ַ�������const����ͷ�const���󶼿��Ե��øú���
		const char* c_str() const
		{
			return _str;
		}

		//����[]
		char& operator[](size_t pos)
		{
			//��ֹԽ�磬С��_size
			assert(pos < _size);

			return _str[pos];
		}

		//����[]��const�汾����Ҫע�ⷵ��ֵҲ��Ҫ��const����
		const char& operator[](size_t pos) const
		{
			assert(pos < _size);

			return _str[pos];
		}

		//�����ַ������ȣ�const����ͨ�����ܵ���
		size_t size() const
		{
			return _size;
		}

		//�����ַ����ռ�������const����ͨ�����ܵ���
		size_t capacity() const
		{
			return _capacity;
		}

		//�ִ���������=��s��ʹ�ô����ú�const��ʹ�ô�ֵ
		string& operator=(string s)
		{
			//����ֵ�ұ߶��󿽱����쵽s��ٽ�s��ĺ͸�ֵ��ߵĶ��󽻻�����s���͸�ֵ��߶��󽻻��������ͷţ����ͷ���ߵĶ���
			swap(s);
			return *this;
		}

		//���ݺ���
		void reserve(size_t n)
		{
			//��n����������ʱ������
			if (n > _capacity)
			{
				char* temp = new char[n + 1];
				strcpy(temp, _str);
				delete[]_str;
				_str = temp;

				_capacity = n;
			}
		}

		//ʵ��push_back�����뵥���ַ�����
		void push_back(char ch)
		{
			//����insert
			insert(_size, ch);
		}

		//+=�ַ�����
		string& operator+=(char ch)
		{
			push_back(ch);

			return *this;
		}

		//+=�ַ�������
		string& operator+=(const char* str)
		{
			append(str);

			return *this;
		}

		//ʵ��append��β�������ַ���
		void append(const char* str)
		{
			//����insert
			insert(_size, str);
		}

		//���ռ�+��ʼ��
		//ɾ���������ݣ�����ǰn��
		void resize(size_t n, char ch = '\0')
		{
			//��nС����Ч���ݸ���ʱ��������Ч���ݸ���
			if (n < _size)
			{
				_str[n] = ch;
				_size = n;
			}
			//��n��������ʱ��Ҫ���ݲ���ch��ʼ��
			else
			{
				reserve(n);
				for (size_t i = _size; i < n; ++i)
				{
					_str[i] = ch;
				}
				_size = n;
				_str[_size] = '\0';
			}
		}

		//insert�����ַ�
		string& insert(size_t pos, char ch)
		{
			//Խ�紦��
			assert(pos <= _size);

			if (_size + 1 > _capacity)
			{
				reserve(_size + 1);
			}

			//����д�����޷���������ԭ�򣬻���ѭ��
			/*size_t end = _size;
			while (end >= pos)
			{
				_str[end + 1] = _str[end];
				--end;
			}*/

			//ע������_size��\0������������ʵ\0Ҳ��һ�������ƶ�������Ҫ�Լ����
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			_str[pos] = ch;
			++_size;

			return *this;
		}

		//insert�����ַ���
		string& insert(size_t pos, const char* str)
		{
			//�жϺϷ���
			assert(pos <= _size);

			size_t length = strlen(str);
			size_t end = _size + length;

			//�ж�����
			if (end > _capacity)
			{
				reserve(end);
			}

			//��end��pos+lengthλ��ʱ����Ҫ��
			while (end > pos + length - 1)
			{
				_str[end] = _str[end - length];
				--end;
			}

			strncpy(_str, str, length);
			_size += length;

			return *this;
		}

		//ɾ��posλ�õ��ַ��������ַ���
		string& erase(size_t pos, size_t len = npos)
		{
			//�ж�Խ�����
			assert(pos < _size);

			//�����ȴ����ַ������ȼ�ȫ��ɾ��
			if (len == npos || len + pos >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			//����С���ַ���
			else
			{
				size_t begin = pos + len;
				while (begin <= _size)
				{
					_str[begin - len] = _str[begin];
					++begin;
				}
				_size = pos;
			}

			return *this;
		}

		//�����ַ���posΪ��ʼ�ҵ�λ�ã����û���ṩ����Ĭ�ϴ�0λ�ô���ʼѰ��
		size_t find(char ch, size_t pos = 0)
		{
			for (; pos < _size; ++pos)
			{
				if (_str[pos] == ch)
					return pos;
			}

			//�Ҳ�����Ҫ����npos
			return npos;
		}

		//�����ַ�����posΪ��ʼ�ҵ�λ�ã����û���ṩ����Ĭ�ϴ�0λ�ô���ʼѰ�ң��ҵ��򷵻ص�һ���ַ����±�
		size_t find(const char* str, size_t pos = 0)
		{
			char* p = strstr(_str + pos, str);
			if (p == nullptr)
			{
				return npos;
			}

			return p - _str;
		}

	private:
		char* _str;//ָ���ַ���
		size_t _size;//��Ч�ַ�����
		size_t _capacity;//�����Ĵ�С

		//����npos
		const static size_t npos;
	};

	//����<<
	ostream& operator<<(ostream& out, const string& s)
	{
		//��ʹ���������ַ�����Ҫ����ΪĳЩ��������»�����⣬����Ҫ��ӡ\0
		/*out << s.c_str();
		return out;*/

		for (auto ch : s)
		{
			out << ch;
		}

		return out;
	}

	//����>>
	istream& operator>>(istream& in, string& s)
	{
		//ʹ��istream��get����һ��һ���Ļ�ȡ�ַ�
		char ch = in.get();

		//�ȴ洢���ַ�������
		char buff[128] = { '\0' };

		//���ַ������ﱻ������δ��������ʱ���ͷŵ�s�ﲢ�������
		size_t i = 0;
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			//Ԥ��\0���ַ�����β��־
			if (i == 127)
			{
				//���˷���s��
				s += buff;
				//��ղ���\0��ʼ��
				memset(buff, '\0', 127);
				//��������
				i = 0;
			}

			ch = in.get();
		}

		//��������ַ�����s��
		s += buff;

		return in;
	}

	//����npos
	const size_t string::npos = -1;

	//���������أ�ʹ��c_str()��������Ҫ����˽�г�Ա�����Բ�ʹ����Ԫ

	bool operator<(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) < 0;
	}

	bool operator==(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) == 0;
	}

	bool operator<=(const string& s1, const string& s2)
	{
		return s1 < s2 || s1 == s2;
	}

	bool operator!=(const string& s1, const string& s2)
	{
		return !(s1 == s2);
	}

	bool operator>(const string& s1, const string& s2)
	{
		return !(s1 <= s2);
	}

	bool operator>=(const string& s1, const string& s2)
	{
		return !(s1 < s2);
	}
}