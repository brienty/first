#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

const int N = 1000010;
int q[N];

int n;

void quick_sort(int q[], int l, int r)
{
	if (l == r) return;//边界情况
	int x = q[l], i = l - 1, j = r + 1;//两边各退一步
	while (i < j)
	{
		do i++; while (q[i] < x);
		do j--; while (q[j] > x);
		if (i < j) swap(q[i], q[j]);
	}

	quick_sort(q, l, j);
	quick_sort(q, j + 1, r);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &q[i]);
	quick_sort(q, 0, n - 1);
	for (int i = 0; i < n; ++i) printf("%d ", q[i]);
	return 0;
}