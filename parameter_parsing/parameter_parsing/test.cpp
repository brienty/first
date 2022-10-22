#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	//输入
	string s, tmp;
	getline(cin, s);

	vector<string> v;//存储分割出来的指令
	for (int i = 0; i < s.size(); ++i)
	{
		//遇到空格则将指令插入v
		if (s[i] == ' ')
		{
			v.push_back(tmp);
			tmp.clear();
		}
		//处理"指令
		else if (s[i] == '"')
		{
			//"下一个位置开始遍历，遇到"停止
			for (++i; s[i] != '"'; ++i)
			{
				tmp += s[i];
			}
			v.push_back(tmp);
			tmp.clear();
			++i;//"下一个位置是空格，需要跳过
		}
		else
		{
			tmp += s[i];//正常将字符插入tmp
		}
	}
	//如果tmp不为空说明还有指令未插入到v中，反之则已经统计完毕
	if (!tmp.empty())
		v.push_back(tmp);
	//输出
	cout << v.size() << endl;
	for (auto e : v)
	{
		cout << e << endl;
	}
	return 0;
}