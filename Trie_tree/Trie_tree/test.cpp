#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

const int N = 100010;

//son[N][26]�����ÿ�����Ķ��ӣ�����ǰ������һ����㣬�±�Ϊ0�ĵ���Ǹ��ڵ�Ҳ�ǿսڵ�
//cnt[N]�����ÿ���ַ�����β�ַ����ֵĴ���
//idx�±�
int son[N][26], cnt[N], idx;
char str[1000000];

void insert(char str[])
{
	int p = 0;//��һ���ַ�λ��
	//�����ַ���
	for (int i = 0; str[i]; ++i)
	{
		int u = str[i] - 'a';//���ַ�ӳ�䵽0~25��������
		if (!son[p][u]) son[p][u] = ++idx;//����ý����ӽڵ㲻������һ��λ��
		p = son[p][u];//�õ���һ���ַ���λ��
	}
	cnt[p]++;//ͳ���Ը��ַ���β�Ĵ���
}

//ͳ�Ƹ��ַ������ּ��Σ����ش���
int query(char str[])
{
	int p = 0;//��һ���ַ���λ��
	//�����ַ���
	for (int i = 0; str[i]; ++i)
	{
		int u = str[i] - 'a';//�õ��ַ�ӳ����0~25���ֵ��ַ�
		if (!son[p][u]) return 0;//���û���ӽڵ㣬˵�������ڸ��ַ���������0
		p = son[p][u];//�õ���һ���ַ�
	}

	return cnt[p];//�����Ը��ַ���β���ַ������ֵĴ���
}

int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		char op[2];
		scanf("%s%s", op, str);
		if (op[0] == 'I') insert(str);
		else printf("%d\n", query(str));
	}
	return 0;
}s