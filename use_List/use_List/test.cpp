#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <List>
#include <vector>
using namespace std;

int main()
{
	list<int>  lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_front(4);
	lt.push_front(10);
	lt.push_front(20);
	lt.push_front(30);
	lt.push_front(40);
	lt.push_back(4);
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
	/*lt.pop_back();
	lt.pop_back();
	lt.pop_front();
	lt.pop_front();
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;*/
	//去重必须先排序
	lt.sort();
	lt.unique();
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}