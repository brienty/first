#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;//std是封C++库的命名空间
//这个也不是必须要，因为如果是这样写，就是把标准库里的全部放出来了，虽然方便，但是容易产生冲突

//using std::cout;
//这种写法是展开命名空间域里部分常用的，比如cout，但是endl没有放出来，使用时endl还是要自己放出来（std::endl）
//using namespace test 展开test命名空间域
//using namespace test2 展开test2命名空间域
//这是展开嵌套里的命名空间域，两者不能反过来，而且这种展开也是把一个整个域展开

//std::cout << "hello world" << std::endl;
//这种是不放出来，最安全的，但是也是最麻烦的，在使用的时候放出来

//函数名和命名空间名不能相等 
namespace test
{
	//变量
	int f = 0;

	//函数
	void fun()
	{

	}

	//类型
	struct ListNode
	{
		int val;
		struct ListNode* next;
	};
}

//相同名字的命名空间会合并
namespace test
{
	int a = 0;
	//命名空间是可以嵌套的
	namespace test2
	{
		int a = 111;
	}
}

//int f = 0;同一个域中变量名不能相等

void fun()
{
	
}

int a = 100;

int f = 1;


void Test(int a = 10, int b = 20, int c = 30)
{
	cout << a << " " << b << " " << c << endl;
}

double Add(double d, double d2)
{
	return d + d2;
}

int Add(int t, int t2)
{
	return t + t2;
}

void test2(double d, int t)
{
	
}

void test1(int t , double d)
{
	
}


int main()
{
	//打印hello world
	cout << "hello world" << endl;

	//当在全局变量和局部变量都创建了名字相同的变量，局部变量优先被访问
	int a = 0;
	cout << a << endl;

	//可以使用命名空间的方式访问全局变量
	cout << ::a << endl;//当::左边什么都没有的时候，默认是访问全局里a变量

	//访问命名空间域里的变量并与全局域里的做对比
	cout << f << endl;//不加限定默认是全局域里的，不是命名空间里的
	cout << test::f << endl;//加了命名空间限定，则是命名空间里的

	//使用命名空间域里的类型
	struct test::ListNode val;
	val.val = 10;
	cout << val.val << endl;

	//访问命名空间里的函数并与全局域里的做对比
	cout << test::fun << endl;
	cout << fun << endl;

	//访问嵌套里命名空间域的变量
	cout << test::test2::a << endl;

	//输入输出
	double d;
	int t;
	char c;
	// >> 流提取运算符
	//cin >> d >> t >> c;
	//// << 流插入运算符
	//cout << d <<" " << t << " " << c << endl;

	//缺省参数
	Test();
	Test(1);
	Test(1, 2);
	Test(1,2,3);

	//函数的重载
	cout << Add(1, 2) << endl;
	cout << Add(1.1, 2.2) << endl;

	return 0;
}