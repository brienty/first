#define _CRT_SECURE_NO_WARNINGS 1
#include "vector.h"


void test1()
{
	myvector::vector<int> v;
	v.reserve(10);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	
	v.pop_back();
	v.resize(8);
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

void test2()
{
	myvector::vector<int> v;
	v.insert(v.begin(), 0);
	v.insert(v.begin(), 1);
	v.insert(v.begin(), 2);
	v.insert(v.begin(), 3);
	v.insert(v.begin(), 4);


	auto pos = find(v.begin(), v.end(), 4);
	cout << "size:capacity = " << v.size() << ":" << v.capacity() << endl;
	cout << *pos << endl;
	*pos = 10;
	cout << *pos << endl;

	//it指向更改，重复插入-1，迭代器失效，使用返回值解决，引用在会出现常性的问题
	myvector::vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		//虽然即使在内部实现时针对迭代器失效做了处理，但是外部仍然会有迭代器失效的问题
		//由于使用的是值传递，一旦发生了扩容，由于pos(it)没有改变仍然指向旧空间，仍然会出现越界的野指针迭代器失效的问题
		//即使空间足够仍然会出现由于it指向位置意义改变导致重复插入-1，出现迭代器失效
		//通过使用使用返回值解决，既解决了位置的最新的问题，又能防止意义改变导致迭代器失效的问题，引用在会出现数据常性的问题
		if (*it % 2 == 0)
		{
			it = v.insert(it, -1);
			++it;
		}
		++it;
	}
	cout << "size:capacity = " << v.size() << ":" << v.capacity() << endl;
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test3()
{
	//myvector::vector<int> v;
	vector<int> v;//使用stl库里的程序直接崩溃
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	//cout << "size:capacity = " << v.size() << ":" << v.capacity() << endl;
	//auto pos = find(v.begin(), v.end(), 2);
	//if (pos != v.end())
	//{
	//	v.erase(pos);
	//}
	//cout << *pos << endl;
	//*pos = 10;
	//cout << *pos << endl << endl;
	//cout << "size:capacity = " << v.size() << ":" << v.capacity() << endl;
	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;


	auto it = v.begin();
	while (it != v.end())
	{
		//erase一般是不会出现野指针导致的迭代器失效的问题
		//erase的失效都是意义变了，或者不在有效访问数据有效范围（因为一般不会使用缩容方案）
		//通过使用使用返回值解决，既解决了位置的最新的问题，又能防止意义改变导致迭代器失效的问题，引用在会出现数据常性的问题
		if (*it % 2 == 0)
		{
			v.erase(it);
			++it;
		}
		/*if (*it % 2 == 0)
		{
			it = v.erase(it);
		}
		else
		{
			++it;
		}*/
	}
	cout << "size:capacity = " << v.size() << ":" << v.capacity() << endl;
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test4()
{
	myvector::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	string s("hello");
	myvector::vector<int> v2(s.begin(), s.end());
	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;
	myvector::vector<int> v3(v);
	for (auto e : v3)
	{
		cout << e << " ";
	}
	cout << endl;
	myvector::vector<int> v4(v2);
	for (auto e : v4)
	{
		cout << e << " ";
	}
	cout << endl;
	v = v3;
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	//10和1都是整形，会涉及到函数参数类型最适配问题，如果不重载一个int类型的构造函数则出现匹配函数出错
	myvector::vector<int> v5(10, 1);
	//myvector::vector<char> v5(10, 'a');//通过这里发现参数匹配出问题
	for (auto e : v5)
	{
		cout << e << " ";
	}
	cout << endl;
}

myvector::vector<vector<int>> generate(int numRows) {
	myvector::vector<vector<int>> vv;
	//初始化vv前numRows
	vv.resize(numRows);
	//
	for (int i = 0; i < numRows; ++i)
	{
		vv[i].resize(i + 1, 0);
		vv[i][0] = vv[i][vv[i].size() - 1] = 1;
	}
	for (size_t i = 0; i < vv.size(); ++i)
	{
		for (size_t j = 0; j < vv[i].size(); ++j)
		{
			if (vv[i][j] == 0)
			{
				vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
			}
		}
	}

	for (size_t i = 0; i < vv.size(); ++i)
	{
		for (size_t j = 0; j < vv[i].size(); ++j)
		{
			cout << vv[i][j];
		}
		cout << endl;
	}
	cout << endl;
	return vv;
}

void test5()
{
	myvector::vector<vector<int>> vv = generate(5);
	for (size_t i = 0; i < vv.size(); ++i)
	{
		for (size_t j = 0; j < vv[i].size(); ++j)
		{
			cout << vv[i][j];
		}
		cout << endl;
	}
}

void test6()
{
	myvector::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	myvector::vector<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend())
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
	test5();*/
	test6();
	return 0;
}