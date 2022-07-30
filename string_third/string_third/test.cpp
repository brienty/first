#define _CRT_SECURE_NO_WARNINGS 1
#include "string.h"

//深浅拷贝问题和[]重载
void test1() {
	mystring::string s1("hello world!");
	mystring::string s2(s1);
	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;

	s1[0] = 'x';
	cout << s1.c_str() << endl;
}

int main() {
	test1();
	return 0;
}