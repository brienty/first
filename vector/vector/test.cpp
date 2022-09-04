#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void test1()
{
	//无参构造并尾插数据
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	
	vector<double> v2;
	v2.push_back(1.1);
	v2.push_back(2.1);
	v2.push_back(3.1);
	v2.push_back(4.1);

	vector<string> s;
	s.push_back("aaa");
	s.push_back("bbb");
	s.push_back("ccc");
	s.push_back("ddd");

	//用迭代器初始化
	string s1("hello world!");
	vector<char> v3(++s1.begin(), --s1.end());

	//有参构造，用指定的数据个数构造
	vector<int> v4(3, 2);

}

void test2()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);

	//遍历
	//下标+[]
	for (size_t i = 0; i < v1.size(); ++i)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	//迭代器
	vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		*it -= 1;
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//范围for
	for (auto& n : v1)
	{
		n += 1;
		cout << n << " ";
	}
	cout << endl;
}

void test3()
{
	size_t sz;
	vector<int> v;
	//知道扩容的大小用resize或者reserve
	//v.resize(100);需要初始化再用resize，因为会改变size
	v.reserve(100);//只需要扩容用reserve，只改变容量
	sz = v.capacity();
	cout << "making v grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}

	//只改变size
	v.resize(10);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	//缩容，改变capacity
	v.shrink_to_fit();
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}

void test4()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	v.insert(v.begin() + 6, -1);//可以在数据最后的后一个位置插入，但是不能越界
	for (auto n : v)
	{
		cout << n << " ";
	}
	cout << endl;

	v.erase(v.begin(), v.end() - 7);//注意不能越界
	for (auto n : v)
	{
		cout << n << " ";
	}
	cout << endl;
}

void test5()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	vector<int>::iterator it = find(v.begin(), v.end(), 3);
	if (it != v.end())
	{
		v.erase(it);
	}
	v.push_back(6);
	v.push_back(9);
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);

	sort(v.begin(), v.end());//默认降序，默认传的是降序的仿函数
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	sort(v.begin(), v.end(), greater<int>());//升序，传升序的仿函数
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
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