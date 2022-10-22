#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <stack>
using namespace std;

//ת������
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
		//��������ֹͣ����
		if (s == "0")
			break;

		stack<double> st1;
		int i = 0;
		while (i < s.size())
		{
			int num = 0;
			//��һ��һ��������
			if (i == 0)
			{
				num = toint(s, i);
				st1.push((double)num);
			}
			//��������ջ
			if (s[i] == '+')
			{
				i += 2;
				num = toint(s, i);
				st1.push((double)num);
			}
			//������ջ
			if (s[i] == '-')
			{
				i += 2;
				num = toint(s, i);
				st1.push(-(double)num);
			}
			//�˳�ջ�������ջ
			if (s[i] == '*')
			{
				i += 2;
				num = toint(s, i);
				double left = st1.top();
				st1.pop();
				st1.push(left * num);
			}
			//����ջ�������ջ
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
		//��ջ���������
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