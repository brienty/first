#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <assert.h>
using namespace std;

namespace mystring {
	class string 
	{
	public:	
		//构造函数
		string(const char* str)
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str);
		}

		//不写该拷贝构造函数则发生拷贝时会是浅拷贝
		string(string& s)
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}

		char& operator[](size_t pos) 
		{
			assert(pos < strlen(_str));
			
			//本质字符数组方式访问
			return _str[pos];
		}

		~string()
		{
			if(_str)
				delete[]_str;
		}

		//让const对象和非const对象都可以调用该函数
		const char* c_str() const {
			return _str;
		}
	private:
		char* _str;
	};
}