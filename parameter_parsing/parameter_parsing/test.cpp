#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	//����
	string s, tmp;
	getline(cin, s);

	vector<string> v;//�洢�ָ������ָ��
	for (int i = 0; i < s.size(); ++i)
	{
		//�����ո���ָ�����v
		if (s[i] == ' ')
		{
			v.push_back(tmp);
			tmp.clear();
		}
		//����"ָ��
		else if (s[i] == '"')
		{
			//"��һ��λ�ÿ�ʼ����������"ֹͣ
			for (++i; s[i] != '"'; ++i)
			{
				tmp += s[i];
			}
			v.push_back(tmp);
			tmp.clear();
			++i;//"��һ��λ���ǿո���Ҫ����
		}
		else
		{
			tmp += s[i];//�������ַ�����tmp
		}
	}
	//���tmp��Ϊ��˵������ָ��δ���뵽v�У���֮���Ѿ�ͳ�����
	if (!tmp.empty())
		v.push_back(tmp);
	//���
	cout << v.size() << endl;
	for (auto e : v)
	{
		cout << e << endl;
	}
	return 0;
}