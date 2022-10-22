#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

stack<int>s;//中转站station
queue<int>b;//b站台//FIFO原则，用队列 

void fun(int N)
{
	int i, temp;
	for (i = 1; i <= N; i++)//A站台车厢是按顺序递增排的
	{
		s.push(i);//A站台的车厢入栈 
		while (s.size() && s.top() == b.front())
		{
			s.pop();//出栈 
			b.pop();//与B的车厢匹配上 
		}
	}
}

int main()
{
	int N, n, temp;
	while (cin >> N)
	{
		if (N == 0)
		{
			break;
		}
		while (cin >> temp)
		{
			while (!s.empty())s.pop();//千万记得清空！！ 
			while (!b.empty())b.pop();//千万记得清空！！ 
			if (temp == 0)//第一个数据为0的话
			{
				cout << endl;//直接换行 
				break;
			}
			b.push(temp);//入队，B车站的左侧 
			for (n = 2; n <= N; n++)
			{
				cin >> temp;
				b.push(temp);//入队，B车站的左侧
			}
			fun(N);//走函数 
			if (s.size())//栈不为空 
			{
				cout << "No" << endl;//未完全匹配 
			}
			else
			{
				cout << "Yes" << endl;//完全匹配 
			}
		}
	}
}