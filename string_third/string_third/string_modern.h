#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <assert.h>
using namespace std;

//string实现
namespace mystring
{
	class string
	{
	public:
		//迭代器，提供const防止数据被篡改
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

		//构造函数，使用缺省值，成为默认构造函数，让无参构造函数调用，使用依次初始化的方式不用频繁调用strlen
		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		//交换函数，交换两个对象
		void swap(string& temp)
		{
			//std里的swap是浅拷贝
			std::swap(_str, temp._str);
			std::swap(_size, temp._size);
			std::swap(_capacity, temp._capacity);
		}

		//现代方法的拷贝构造，将s初始化，防止当=里拷贝构造过来的的地址是随机值，然后释放随机值
		string(const string& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			//借用temp构造完了再给s
			string temp(s._str);
			swap(temp);
		}

		//析构函数
		~string()
		{
			if (_str)
			{
				delete[]_str;
				_str = nullptr;
				_size = _capacity = 0;
			}
		}

		//返回C语言字符串，让const对象和非const对象都可以调用该函数
		const char* c_str() const
		{
			return _str;
		}

		//重载[]
		char& operator[](size_t pos)
		{
			//防止越界，小于_size
			assert(pos < _size);

			return _str[pos];
		}

		//重载[]的const版本，需要注意返回值也需要被const修饰
		const char& operator[](size_t pos) const
		{
			assert(pos < _size);

			return _str[pos];
		}

		//返回字符串长度，const和普通对象都能调用
		size_t size() const
		{
			return _size;
		}

		//返回字符串空间容量，const和普通对象都能调用
		size_t capacity() const
		{
			return _capacity;
		}

		//现代方法重载=，s不使用传引用和const，使用传值
		string& operator=(string s)
		{
			//将赋值右边对象拷贝构造到s里，再将s里的和赋值左边的对象交换，由s将和赋值左边对象交换过来的释放（即释放左边的对象）
			swap(s);
			return *this;
		}

		//扩容函数
		void reserve(size_t n)
		{
			//当n大于容量的时候扩容
			if (n > _capacity)
			{
				char* temp = new char[n + 1];
				strcpy(temp, _str);
				delete[]_str;
				_str = temp;

				_capacity = n;
			}
		}

		//实现push_back，插入单个字符函数
		void push_back(char ch)
		{
			//复用insert
			insert(_size, ch);
		}

		//+=字符重载
		string& operator+=(char ch)
		{
			push_back(ch);

			return *this;
		}

		//+=字符串重载
		string& operator+=(const char* str)
		{
			append(str);

			return *this;
		}

		//实现append，尾部插入字符串
		void append(const char* str)
		{
			//复用insert
			insert(_size, str);
		}

		//扩空间+初始化
		//删除部分数据，保留前n个
		void resize(size_t n, char ch = '\0')
		{
			//当n小于有效数据个数时，减少有效数据个数
			if (n < _size)
			{
				_str[n] = ch;
				_size = n;
			}
			//当n大于容量时需要扩容并用ch初始化
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

		//insert插入字符
		string& insert(size_t pos, char ch)
		{
			//越界处理
			assert(pos <= _size);

			if (_size + 1 > _capacity)
			{
				reserve(_size + 1);
			}

			//这样写由于无符号整数的原因，会死循环
			/*size_t end = _size;
			while (end >= pos)
			{
				_str[end + 1] = _str[end];
				--end;
			}*/

			//注意由于_size是\0，所以这里其实\0也会一起往后移动，不需要自己添加
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

		//insert插入字符串
		string& insert(size_t pos, const char* str)
		{
			//判断合法性
			assert(pos <= _size);

			size_t length = strlen(str);
			size_t end = _size + length;

			//判断扩容
			if (end > _capacity)
			{
				reserve(end);
			}

			//当end在pos+length位置时还需要移
			while (end > pos + length - 1)
			{
				_str[end] = _str[end - length];
				--end;
			}

			strncpy(_str, str, length);
			_size += length;

			return *this;
		}

		//删除pos位置的字符或者是字符串
		string& erase(size_t pos, size_t len = npos)
		{
			//判断越界情况
			assert(pos < _size);

			//当长度大于字符串长度即全部删除
			if (len == npos || len + pos >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			//长度小于字符串
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

		//查找字符，pos为开始找的位置，如果没有提供，则默认从0位置处开始寻找
		size_t find(char ch, size_t pos = 0)
		{
			for (; pos < _size; ++pos)
			{
				if (_str[pos] == ch)
					return pos;
			}

			//找不到需要返回npos
			return npos;
		}

		//查找字符串，pos为开始找的位置，如果没有提供，则默认从0位置处开始寻找，找到则返回第一个字符的下标
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
		char* _str;//指向字符串
		size_t _size;//有效字符个数
		size_t _capacity;//容量的大小

		//声明npos
		const static size_t npos;
	};

	//重载<<
	ostream& operator<<(ostream& out, const string& s)
	{
		//不使用下面这种方法主要是因为某些特殊情况下会出问题，如需要打印\0
		/*out << s.c_str();
		return out;*/

		for (auto ch : s)
		{
			out << ch;
		}

		return out;
	}

	//重载>>
	istream& operator>>(istream& in, string& s)
	{
		//使用istream的get函数一个一个的获取字符
		char ch = in.get();

		//先存储到字符数组里
		char buff[128] = { '\0' };

		//当字符数组里被存满且未满足条件时，就放到s里并清空数组
		size_t i = 0;
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			//预留\0，字符串结尾标志
			if (i == 127)
			{
				//满了放入s里
				s += buff;
				//清空并用\0初始化
				memset(buff, '\0', 127);
				//清零重来
				i = 0;
			}

			ch = in.get();
		}

		//将输入的字符放入s里
		s += buff;

		return in;
	}

	//定义npos
	const size_t string::npos = -1;

	//操作符重载，使用c_str()函数不需要访问私有成员，可以不使用友元

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