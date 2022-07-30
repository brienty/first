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
		//���캯��
		string(const char* str)
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str);
		}

		//��д�ÿ������캯����������ʱ����ǳ����
		string(string& s)
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}

		char& operator[](size_t pos) 
		{
			assert(pos < strlen(_str));
			
			//�����ַ����鷽ʽ����
			return _str[pos];
		}

		~string()
		{
			if(_str)
				delete[]_str;
		}

		//��const����ͷ�const���󶼿��Ե��øú���
		const char* c_str() const {
			return _str;
		}
	private:
		char* _str;
	};
}