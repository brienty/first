#define _CRT_SECURE_NO_WARNINGS 1

#include "Date.h"


void Test1()
{
	//区分赋值与拷贝构造函数的情况
	Date d1(2022, 5, 19);
	Date d2 = d1;
	//调试查看发现这行代码其实是按这行代码的方式执行的Date d2(d1);

	Date d3;
	Date d4;
	d3 = d4;//这行代码才调用了重载赋值操作符函数
}

void Test2()
{
	//测试==，!=，=，>，>=，<，<=
	Date d1(2022, 5, 19);
	Date d2(2022, 5, 19);
	Date d3(2023, 6, 19);
	Date d4(2022, 6, 29);
	if (d1 == d2)
	{
		cout << "==" << endl;
	}
	if (d2 != d3)
	{
		cout << "!=" << endl;
	}
	if (d3 > d4)
	{
		cout << ">" << endl;
	}
	if (d2 < d4)
	{
		cout << "<" << endl;
	}
	if (d3 >= d4)
	{
		cout << ">=" << endl;
	}
	if (d2 <= d4)
	{
		cout << "<=" << endl;
	}

	//注意<<和<优先级
	cout << (d1 < d2) << endl;
	cout << (d1 >= d2) << endl;
	cout << (d1 <= d2) << endl;
	cout << (d1 == d2) << endl;
	cout << (d1 != d2) << endl;
	cout << (d1 > d2) << endl;
}

void Test3()
{
	//测试+、+=、-、-=
	Date d1(2022, 5, 18);
	Date d2(2022, 5, 19);
	Date d3(2022, 5, 20);
	Date d4(2022, 5, 21);

	d2 = d1 + -10000;
	d1.Print();
	d2.Print();

	d2 = d1 - -10000;
	d1.Print();
	d2.Print();

	d3 += 10000;
	d3.Print();
	
	d4 -= 10000;
	d4.Print();
}

void Test4()
{
	Date d1(2022, 2, 28);
	Date d2(2022, 5, 21);

	d2 = d1--;
	d1.Print();
	d2.Print();

	d2 = d1++;
	d1.Print();
	d2.Print();

	d2 = ++d1;
	d1.Print();
	d2.Print();

	d2 = --d1;
	d1.Print();
	d2.Print();
}

void Test5()
{
	Date d1(2022, 5, 18);
	Date d2(2022, 3, 6);
	
	cout << (d2 - d1) << endl;
}

//测试重载cin和cout
void Test6()
{
    Date d1;
    cin >> d1;
    cout << d1;
}

int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();
    Test6();
	return 0;
}
