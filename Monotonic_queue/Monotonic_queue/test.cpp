#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdio>
using namespace std;

//比赛的数据一般是1000000个
const int N = 1000010;

//a[N]存储输入的元素
//q[N]单调队列，这里是存储下标
int a[N], q[N];

//n元素个数
//k滑动窗口大小
//hh队头元素
//tt队尾元素
int n, k, hh, tt = -1;

int main()
{
	//使用scanf()和printf()函数更快
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);

	//筛选滑动窗口中最小的元素
	for (int i = 0; i < n; ++i)
	{
		//判断队头是否滑出窗口，因为只移动一次，所以if，否则while
		if (hh <= tt && i - k + 1 > q[hh]) hh++;
		//当队尾元素比数组元素要大时，去除队尾元素
		while (hh <= tt && a[q[tt]] >= a[i]) tt--;
		//输出前插入，有可能输入的这个数是最小的值
		q[++tt] = i;
		//只有当滑动窗口中的元素满了才开始输出最小元素
		if (i >= k - 1) printf("%d ", a[q[hh]]);
	}
	puts("");

	hh = 0, tt = -1;//清空队列
	//筛选滑动窗口中最大的元素
	for (int i = 0; i < n; ++i)
	{
		//判断是否滑动窗口，因为只移动一次，所以if，否则while
		if (hh <= tt && i - k + 1 > q[hh]) hh++;
		//当队尾元素比数组元素要小时，去除队尾元素
		while (hh <= tt && a[q[tt]] <= a[i]) tt--;
		//输出前插入，有可能输入的这个数是最小的值
		q[++tt] = i;
		//只有当滑动窗口中的元素满了才开始输出最小元素
		if (i >= k - 1) printf("%d ", a[q[hh]]);
	}
	puts("");
	return 0;
}