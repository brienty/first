#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

stack<int>s;//��תվstation
queue<int>b;//bվ̨//FIFOԭ���ö��� 

void fun(int N)
{
	int i, temp;
	for (i = 1; i <= N; i++)//Aվ̨�����ǰ�˳������ŵ�
	{
		s.push(i);//Aվ̨�ĳ�����ջ 
		while (s.size() && s.top() == b.front())
		{
			s.pop();//��ջ 
			b.pop();//��B�ĳ���ƥ���� 
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
			while (!s.empty())s.pop();//ǧ��ǵ���գ��� 
			while (!b.empty())b.pop();//ǧ��ǵ���գ��� 
			if (temp == 0)//��һ������Ϊ0�Ļ�
			{
				cout << endl;//ֱ�ӻ��� 
				break;
			}
			b.push(temp);//��ӣ�B��վ����� 
			for (n = 2; n <= N; n++)
			{
				cin >> temp;
				b.push(temp);//��ӣ�B��վ�����
			}
			fun(N);//�ߺ��� 
			if (s.size())//ջ��Ϊ�� 
			{
				cout << "No" << endl;//δ��ȫƥ�� 
			}
			else
			{
				cout << "Yes" << endl;//��ȫƥ�� 
			}
		}
	}
}