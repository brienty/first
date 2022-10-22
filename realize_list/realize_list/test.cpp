#define _CRT_SECURE_NO_WARNINGS 1
#include "list.h"
#include "Reverse_iterator.h"

void test1()
{
	mylist::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	
	mylist::list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test2()
{
	//普通迭代器
	mylist::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	mylist::list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		*it += 1;
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//const迭代器
	const mylist::list<int> Lt = lt;
	mylist::list<int>::const_iterator It = Lt.begin();
	while (It != Lt.end())
	{
		//*It -= 1;//报错
		cout << *It << " ";
		++It;
	}
	cout << endl;
}

void test3()
{
	mylist::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_front(1);
	lt.push_front(2);
	lt.push_front(3);
	lt.push_front(4);
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.pop_back();
	lt.pop_back();
	lt.pop_front();
	lt.pop_front();
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test4()
{
	mylist::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(6);

	//偶数前插入，不存在迭代器失效问题
	auto it = lt.begin();
	while (it != lt.end())
	{
		if (*it % 2 == 0)
		{
			lt.insert(it, *it * 2);
		}
		++it;
	}
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	//删除偶数
	auto it2 = lt.begin();
	while (it2 != lt.end())
	{
		if (*it2 % 2 == 0)
		{
			it2 = lt.erase(it2);//需要注意迭代器失效问题
		}
		else
		{
			++it2;
		}
	}
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test5()
{
	mylist::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(6);
	lt.clear();
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
	lt.push_back(1);
	lt.push_front(2);
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
	mylist::list<int> lt2(lt.begin(), lt.end());
	for (auto e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;
	lt2.push_back(3);
	lt2.push_back(4);
	lt2.push_back(5);
	lt2.push_back(6);
	mylist::list<int> lt3(lt2);
	for (auto e : lt3)
	{
		cout << e << " ";
	}
	cout << endl;
	mylist::list<int> lt4;
	lt4.push_back(1);
	lt4.push_back(2);
	lt4.push_back(2);
	for (auto e : lt4)
	{
		cout << e << " ";
	}
	cout << endl;
	lt4 = lt;
	for (auto e : lt4)
	{
		cout << e << " ";
	}
	cout << endl;
}

struct A
{
	int _a;
	int _b;
	A(int a = 100, int b = 200)
		:_a(a)
		, _b(b)
	{}
};

void test6()
{
	mylist::list<A> a;
	a.push_back(A(100, 200));
	a.push_back(A(300, 400));
	a.push_back(A(500, 600));
	a.push_back(A(700, 800));
	mylist::list<A>::iterator it = a.begin();
	while (it != a.end())
	{
		cout << it->_a << " " << it->_b << " ";
		++it;
	}
	cout << endl;
}

void test7()
{
	mylist::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(6);
	mylist::list<int>::reverse_iterator rit = lt.rbegin();
	while (rit != lt.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}

int main()
{
	/*test1();
	test2();
	test3();
	test4();
	test5();
	test6();*/
	test7();
	return 0;
}