#define _CRT_SECURE_NO_WARNINGS 1
#include "priority_queue.h"


void test_priority_queue()
{
	mypriority_queue::priority_queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	for (int i = 0; i < 5; ++i)
	{
		cout << q.top() << " ";
		q.pop();
	}
	cout << endl;
}

bool lessintcom(const int x, const int y)
{
	return x < y;
}

void test_compare()
{
	mypriority_queue::priority_queue<int, vector<int>, greater<int>> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(5);
	for (int i = 0; i < 6; ++i)
	{
		cout << q.top() << " ";
		q.pop();
	}
	cout << endl;
	//兼容函数指针
	mypriority_queue::priority_queue<int, vector<int>, bool (*)(int, int)> pq(lessintcom);
	pq.push(1);
	pq.push(2);
	pq.push(3);
	pq.push(4);
	pq.push(5);
	pq.push(5);
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
	//区间构造
	int a[] = { 1,5,5,2,7,1,9,2,4,6,3 };
	mypriority_queue::priority_queue<int, vector<int>, greater<int>> Pq(a, a+10);
	while (!Pq.empty())
	{
		cout << Pq.top() << " ";
		Pq.pop();
	}
	cout << endl;
}

int main()
{
	//test_priority_queue();
	test_compare();
	return 0;
}