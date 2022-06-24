#include <iostream>
#include <map>
#include <string>
using namespace std;


#include <time.h>
//struct A { 
//	int a[10000]; 
//};
//void TestFunc1(A a) {}
//
//void TestFunc2(A& a) {}
//
//void TestFunc3(A* a) {}
//
//void TestRefAndValue()
//{
//	A a;
//	// 以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//
//	// 以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	
//	// 以指针作为参数
//	size_t begin3 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc3(&a);
//	size_t end3 = clock();
//
//	// 分别计算两个函数运行结束后的时间
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//	cout << "TestFunc2(A&)-time:" << end3 - begin3 << endl;
//}

struct A { int a[10000]; };
A a;
// 值返回
A TestFunc1() { return a; }
// 引用返回
A& TestFunc2() { return a; }
void TestReturnByRefOrValue()
{
	// 以值作为函数的返回值类型
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc1();
	size_t end1 = clock();
	// 以引用作为函数的返回值类型
	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc2();
	size_t end2 = clock();
	// 计算两个函数运算完成之后的时间
	cout << "TestFunc1 time:" << end1 - begin1 << endl;
	cout << "TestFunc2 time:" << end2 - begin2 << endl;
}



void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}


void TestFor()
{
	//依次自动取array中的数据赋值给e，自动判断结束
	int array[] = { 1, 2, 3, 4, 5 };
	for (auto& e : array)
		e *= 2;

	for (auto e : array)
		cout << e << " ";
}

//引用
int main()
{
	/*int a = 1;
	int b = 2;
	cout << a << " " << b << endl;
	swap(a, b);
	cout << a << " " << b << endl;*/

	//int a = 10;
	//int& ra = a;
	//int& rra = ra;
	//int& rrra = ra;
	////地址一样
	//printf("%p %p %p %p\n", &a, &ra, &rra, &rrra);


	/*TestReturnByRefOrValue();

	double d = 1.1;
	double& c = d;
	cout << sizeof(c) << endl;*/

	int num = 10;

	int* pn = &num;
	*pn = 20;

	int& rn = num;
	rn = 20;


	int x = 10;
	const int y = 20;

	//推断没有带解引用操作符的整形指针
	auto a = &x;
	auto a2 = &y;

	//推断带解引用操作符的整形指针
	auto* b = &x;
	auto* b2 = &y;

	//推断引用类型
	auto& c = x;
	auto& c2 = y;

	//打印类型
	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(a2).name() << endl;
	cout << typeid(b2).name() << endl;
	cout << typeid(c2).name() << endl;

	//迭代器
	std::map<std::string, std::string>dict;
	dict["sort"] = "sort";
	dict["string"] = "string";
	std::map<std::string, std::string>::iterator it = dict.begin();

	TestFor();


	return 0;
}
//int TestAuto()
//{
//	return 10;
//}
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d = TestAuto();
//
//	//打印类型
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//
//	return 0;
//}