#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;

//string
void test1() {
	cout << sizeof(char16_t) << endl;
	cout << sizeof(char32_t) << endl;
	cout << sizeof(wchar_t) << endl;
	string path = "C:\\";
	path += "a\\";
	path += "b\\";
	path += "c++";
	cout << path << endl;
}

//构造，拷贝构造
void test2() {
	string s1;
	string s2("hello");
	string s3(s2);
	string s4 = s3;
	string s5("abcdefghijklmnopqrstuvwxyz");
	string s6(s5, 5, 10);//从s5中的下标为5处开始复制10个字符
	string s7(s5, 5);//从s5中的下标为5处开始复制，直到全部复制到s7中，最长复制一个整形的最大值长度

	string s8("213241", 5);//从下标为0开始复制字符串里的5个字符到s8中
	string s9(2, 'x');//用2个x初始化

	//string s10(s5, 30, 100);//越界抛出异常
	string s11(s5, 4, 200);//长度不够全部只能将全部字符串复制即截止

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;
	cout << s7 << endl;
	cout << s8 << endl;
	cout << s9 << endl;
	cout << s11 << endl;
}

//string类型会被其他的字符串或者字符覆盖
void test3() {
	string s1("hello");
	string s2("xxx");
	s1 = s2;//用s2将s1覆盖
	s1 = "yyy";//用字符串将s1覆盖
	s1 = 'y';//用字符将s1覆盖

	cout << s1 << endl;
}

//字符串的遍历
void test4() {
	
	//第一种方式，下标+[]
	string s1("hello world!");
	//size是字符串容量函数，获取字符串的长度，不包含\0
	for (size_t i = 0; i < s1.size(); ++i) {
		//这里的[]是被string重载过的，注意越界会抛出异常
		//s1.operator[].(i);
		cout << s1[i] << " ";
	}
	cout << endl;

	//第二种方式，迭代器 -------像指针一样的东西或者就是指针
	string s2("hello");
	string::iterator it = s2.begin();//begin获取第一个字符的迭代器
	//end获取最后一个字符即（\0处）下一个位置的迭代器，begin和end的区间范围是左闭右开
	while (it != s2.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//第三种方式，范围for ------原理：替换成迭代器
	string s3("world!");
	for (auto ch : s3) {
		cout << ch << " ";
	}
	cout << endl;
}

//使用迭代器遍历vector
void test5() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	vector<int>::iterator vit = v.begin();
	while (vit != v.end()) {
		cout << *vit << " ";
		++vit;
	}
	cout << endl;
}



//管理以\0结尾的动态增长字符数组，关于operator[]重载问题
namespace a {
	class string {
	public:
		//可读可写重载，值修改返回对象
		char& operator[](size_t pos) {
			
			assert(pos <= _size);
			
			return _str[pos];
		}

		//只读重载
		const char& operator[](size_t pos) const {
			
			assert(pos <= _size);
			
			return _str[pos];
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}

//operator[]和at的两种重载
void test6() {
	string s1("hello");
	const string s2("hello");
	//s1[6];//越界使用断言判错
	//s2[6];同理

	//s1.at(6);//越界抛出异常
	//s2.at(6);//同理

	s1[0] = 'x';
	//s2[0] = 'x';//const修饰不能修改
	s1.at(0) = 'y';//s2同理
}

//四种迭代器：可读可写正向迭代器，可读可写反向迭代器，只读正向迭代器，只读反向迭代器
//begin和end迭代器的比较一般使用!=，除了一些特殊情况使用<，标准化
//begin获取第一个字符的迭代器，end获取最后一个字符即（\0处）下一个位置的迭代器，begin和end的区间范围是左闭右开，rbegin和rend同理
void test7() {
	string s1("hello world!");
	//可读可写正向迭代器
	string::iterator sit = s1.begin();
	while (sit != s1.end()) {
		(*sit) += 1;
		cout << *sit << " ";
		++sit;
	}
	cout << endl;
	cout << s1 << endl;

	//可读可写反向迭代器
	string::reverse_iterator rsit = s1.rbegin();
	while (rsit != s1.rend()) {
		(*rsit) -= 1;
		cout << *rsit << " ";
		++rsit;
	}
	cout << endl;
	cout << s1 << endl;



	const string s2("hello world");
	//只读正向迭代器
	string::const_iterator sit2 = s2.begin();
	while (sit2 != s2.end()) {
		//(*sit2) += 1;//报错
		cout << *sit2 << " ";
		++sit2;
	}
	cout << endl;

	//只读反向迭代器
	string::const_reverse_iterator rsit2 = s2.rbegin();
	while (rsit2 != s2.rend()) {
		//(*rsit2) -= 1;//报错
		cout << *rsit2 << " ";
		++rsit2;
	}
	cout << endl;
}

//容量函数
void test8() {
	string s("hello world!");
	cout << s.length() << endl;//返回字符串长度
	cout << s.size() << endl;//返回字符串长度
	cout << s.max_size() << endl;//可放入字符串最大的长度
	cout << s.capacity() << endl;//字符串的容量



	//无初始化扩容
	string s1;
	s1.reserve(100);//扩容不初始化
	s1.resize(100, 'x');//扩容初始化
	cout << s1 << endl;

	//查看在vs下的扩容情况
	size_t sz = s.capacity();
	cout << "capacity:" << " " << sz << endl;
	for (size_t i = 0; i < 1000; ++i) {
		s.push_back('x');
		//不等于说明扩容了
		if (sz != s.capacity()) {
			sz = s.capacity();
			cout << "capacity:" << " " << sz << endl;
		}
	}

	//有初始化扩容
	string s2("hello");
	s2.reserve(100);//只扩容
	s2.resize(100, 'x');//扩容完后面补x
	cout << s2 << endl;

	//在vs下这两个函数不会缩容
	s2.reserve(10);//容量不变
	s2.resize(10);//size变小，容量不变，只在s2后打印五个x
	cout << s2 << endl;



	//连接字符串并扩容
	string s3;
	s3.push_back('x');//只能用来连接字符
	s3.append("hello");//连接字符串
	string s4("world");
	s3.append(s4);//连接字符串
	cout << s3 << endl;

	//常用为以下方法，使用重载后的+=
	string s5;
	s5 += 'x';
	s5 += "hello";
	string s6("world");
	s5 += s6;
	cout << s5 << endl;
}

int main() {
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	return 0;
}