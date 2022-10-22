#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <list>
#include <array>
#include <vector>
#include "Date.h"
using namespace std;

////typename的独特功能
//template<class T>
//void print(const list<T>& lt)
//{
//	typename list<T>::const_iterator cit = lt.begin();
//	while (cit != lt.end())
//	{
//		cout << *cit << " ";
//		++cit;
//	}
//	cout << endl;
//}
//void test1()
//{
//	list<int> lt1;
//	lt1.push_back(1);
//	lt1.push_back(2);
//	lt1.push_back(3);
//	lt1.push_back(4);
//	print(lt1);
//	list<string> lt2;
//	lt2.push_back("abc");
//	lt2.push_back("def");
//	lt2.push_back("ghi");
//	lt2.push_back("jkl");
//	print(lt2);
//}
//
//
////静态栈
////非类型模板参数，传一个常量的参数
//template<class T, size_t N>
//class stack 
//{
//public:
//	void f()
//	{
//		N = 20;
//	}
//private:
//	T _a[N];
//	int _top;
//};
//
//template<class T, char N>
//class A
//{};
//
//void test2()
//{
//	stack<int, 100> st1;
//	stack<int, 500> st2;
//	//封装过的原生数组
//	int a2[100] = { 0 };
//	array<int, 100> a;//确定大小的情况下和vector一样，无法扩容，将数据直接存储到array上
//	vector<int> v(100);//不确定大小和确定大小都可以使用，可以扩容，存的是指针
//	A<int, 'a'> st3;
//}
//
//
// //函数模板 -- 参数匹配
//template<class T>
//bool Less(T left, T right)
//{
//	return left < right;
//}
// //对Less函数模板进行特化
//template<>
//bool Less<Date*>(Date* left, Date* right)
//{
//	return *left < *right;
//}
//void test3()
//{
//	cout << Less(1, 2) << endl; // 可以比较，结果正确
//	Date d1(2022, 7, 7);
//	Date d2(2022, 7, 8);
//	cout << Less(d1, d2) << endl; // 可以比较，结果正确
//	Date* p1 = &d1;
//	Date* p2 = &d2;
//	cout << Less(p1, p2) << endl; // 可以比较，结果错误
//}
//
//
//
////特化
//template<class T1, class T2>
//class Date
//{
//public:
//	Date()
//	{
//		cout << "Date<T1, T2>" << endl;
//	}
//private:
//	T1 _d1;
//	T2 _d2;
//};
////全特化
//template<>
//class Date<int, double>
//{
//public:
//	Date()
//	{
//		cout << "Date<int, double>" << endl;
//	}
//private:
//	int _d1;
//	double _d2;
//};
//
////半特化/偏特化
////特化部分参数
//template<class T>
//class Date<T, char>
//{
//public:
//	Date()
//	{
//		cout << "Date<T, char>" << endl;
//	}
//private:
//	T _d1;
//	char _d2;
//};
////限制模板参数
//template<class T1, class T2>
//class Date<T1*, T2*>
//{
//public:
//	Date()
//	{
//		cout << "Date<T1*, T2*>" << endl;
//	}
//};
//template<class T1, class T2>
//class Date<T1&, T2&>
//{
//public:
//	Date()
//	{
//		cout << "Date<T1&, T2&>" << endl;
//	}
//};
//void test4()
//{
//	Date<int, int> d1;
//	Date<int, double> d2;
//	Date<int, char> d3;
//	Date<char, char> d4;
//	Date<string*, string*> d5;
//	Date<string*, int> d6;
//}

#include<vector>
#include <algorithm>
template<class T>
struct Less
{
	bool operator()(const T& x, const T& y) const
	{
		return x < y;
	}
};
// 对Less类模板按照指针方式特化
template<>
struct Less<Date*>
{
	bool operator()(Date* x, Date* y) const
	{
		return *x < *y;
	}
};
void test5()
{
	Date d1(2022, 7, 7);
	Date d2(2022, 7, 6);
	Date d3(2022, 7, 8);
	vector<Date> v1;
	v1.push_back(d1);
	v1.push_back(d2);
	v1.push_back(d3);
	// 可以直接排序，结果是日期升序
	sort(v1.begin(), v1.end(), Less<Date>());
	vector<Date*> v2;
	v2.push_back(&d1);
	v2.push_back(&d2);
	v2.push_back(&d3);

	// 可以直接排序，结果错误日期还不是升序，而v2中放的地址是升序
	// 此处需要在排序过程中，让sort比较v2中存放地址指向的日期对象
	// 但是走Less模板，sort在排序时实际比较的是v2中指针的地址，因此无法达到预期
	sort(v2.begin(), v2.end(), Less<Date*>());
}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	return 0;
}