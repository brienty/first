#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <stack>
using namespace std;

//转出数字
int toint(const string& s, int& i)
{
	string tmp;
	while (i < s.size() && s[i] != ' ')
	{
		tmp += s[i];
		++i;
	}
	return stoi(tmp);
}

int main()
{
	string s;
	while (getline(cin, s))
	{
		//多组输入停止条件
		if (s == "0")
			break;

		stack<double> st1;
		int i = 0;
		while (i < s.size())
		{
			int num = 0;
			//第一个一定是数字
			if (i == 0)
			{
				num = toint(s, i);
				st1.push((double)num);
			}
			//是正数入栈
			if (s[i] == '+')
			{
				i += 2;
				num = toint(s, i);
				st1.push((double)num);
			}
			//负数入栈
			if (s[i] == '-')
			{
				i += 2;
				num = toint(s, i);
				st1.push(-(double)num);
			}
			//乘出栈计算后入栈
			if (s[i] == '*')
			{
				i += 2;
				num = toint(s, i);
				double left = st1.top();
				st1.pop();
				st1.push(left * num);
			}
			//除出栈计算后入栈
			if (s[i] == '/')
			{
				i += 2;
				num = toint(s, i);
				double left = st1.top();
				st1.pop();
				st1.push(left / num);
			}
			++i;
		}
		//将栈中数据相加
		double sum = 0.0;
		while (!st1.empty())
		{
			sum += st1.top();
			st1.pop();
		}
		printf("%.2lf\n", sum);
	}
	return 0;
}