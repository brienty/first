#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

const int N = 100010;

//son[N][26]存的是每个结点的儿子，即当前结点的下一个结点，下标为0的点既是根节点也是空节点
//cnt[N]存的是每个字符串结尾字符出现的次数
//idx下标
int son[N][26], cnt[N], idx;
char str[1000000];

void insert(char str[])
{
	int p = 0;//下一个字符位置
	//遍历字符串
	for (int i = 0; str[i]; ++i)
	{
		int u = str[i] - 'a';//将字符映射到0~25的数字上
		if (!son[p][u]) son[p][u] = ++idx;//如果该结点的子节点不存在则开一个位置
		p = son[p][u];//得到下一个字符的位置
	}
	cnt[p]++;//统计以该字符结尾的次数
}

//统计该字符串出现几次，返回次数
int query(char str[])
{
	int p = 0;//下一个字符的位置
	//遍历字符串
	for (int i = 0; str[i]; ++i)
	{
		int u = str[i] - 'a';//得到字符映射在0~25数字的字符
		if (!son[p][u]) return 0;//如果没该子节点，说明不存在该字符串，返回0
		p = son[p][u];//得到下一个字符
	}

	return cnt[p];//返回以该字符结尾的字符串出现的次数
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