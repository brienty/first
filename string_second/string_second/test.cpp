#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

//插入字符串或者字符，由于是连续的物理结构，无法避免数据移位或者扩容带来的性能消耗
void test1() {
	string s1("hello");
	s1.insert(0, 1, 'x');//在下标为0位置处前面插入一个x
	s1.insert(s1.begin(), 'y');//使用迭代器在下标为0位置处前面插入一个y
	cout << s1 << endl;

	s1.insert(3, 3, 'x');//在下标为3的位置处前面插入3个x
	s1.insert(s1.begin() + 3, 'y');//使用迭代器在下标为3的位置处前面插入一个y，string的迭代器底层是指针实现的
	cout << s1 << endl;

	s1.insert(0, "world ");//在0位置处前面插入一个字符串
	cout << s1 << endl;
}

//删除字符或者字符串
void test2() {
	string s1("hello world!");
	s1.erase(1, 3);//从下标为1开始删除三个字符
	cout << s1 << endl;

	s1.erase(s1.begin());
	cout << s1 << endl;//使用迭代器删除下标为0位置处的字符

	s1.erase(s1.begin()+2);//使用迭代器删除下标为2位置处的字符
	cout << s1 << endl;

	s1.erase(4);//删除下标为4及其后的所有字符
	//static const size_t npos = -1;
	//npos是默认待删除长度，默认是-1即整数的最大值，删除长度大于待删除字符串时，只会将后面的字符删除即停止
	cout << s1 << endl;
}

//交换字符串
void test3() {
	string s1("hello world!");
	string s2("hello string!");

	s1.swap(s2);//效率高，成员函数，交换指向的指针
	cout << s1 << endl << s2 << endl;

	swap(s1, s2);//效率低，全局变量，深拷贝交换
	cout << s1 << endl << s2 << endl;
}

//string转化成C语言字符串
void test4() {
	string s("hello wordl!");
	cout << s << endl;
	cout << s.c_str() << endl;//c_str()返回C语言的字符串，为了更好的与C语言适应
}

//find，rfind，substr的使用
void test5() {

	//利用find、rfind和substr取出文件后缀
	string file1("string.cpp");
	string file2("string.c");
	string file3("string.c.tar.zip");//这里针对多个含有标记的可以使用rfind，找最后一个标记

	string& file = file1;//这里使用引用方便更改

	size_t pos = file.find('.');//查找字符，找到返回 该字符下标，否则返回npos
	//size_t pos = file.rfind('.');//查找字符，找到返回 该字符下标，否则返回npos
	string suffix = file.substr(pos);//不传返回字符串长度默认是npos
	if (pos != string::npos) {
		cout << suffix << endl;
	}else {
		cout << "无后缀" << endl;
	}



	//利用substr和find取出url中的协议，域名，uri(资源)
	string url1("http://www.cplusplus.com/reference/string/string/find/");
	string url2("https://leetcode.cn/problems/reverse-only-letters/submissions/");

	string& url = url1;//方便更改

	//找出协议、域名、uri
	string protocol;//协议
	size_t pos1 = url.find("://", 0);
	if (pos1 != string::npos) {
		protocol = url.substr(0, pos1);
		cout << protocol << endl;
	}
	else {
		cout << "false" << endl;
	}

	string domain;//域名
	size_t pos2 = url.find('/', pos1+3);//从w开始找，找到/停下
	if (pos2 != string::npos) {
		domain = url.substr(pos1 + 3, pos2 - (pos1 + 3));//第一个参数传起始位置，第二个参数传长度
		cout << domain << endl;
	}
	else {
		cout << "false" << endl;
	}

	string uri;//资源
	uri = url.substr(pos2 + 1);
	cout << uri << endl;

}

int main() {
	test1();
	test2();
	test3();
	test4();
	test5();
	return 0;
}