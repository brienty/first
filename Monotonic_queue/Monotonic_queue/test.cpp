#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdio>
using namespace std;

//����������һ����1000000��
const int N = 1000010;

//a[N]�洢�����Ԫ��
//q[N]�������У������Ǵ洢�±�
int a[N], q[N];

//nԪ�ظ���
//k�������ڴ�С
//hh��ͷԪ��
//tt��βԪ��
int n, k, hh, tt = -1;

int main()
{
	//ʹ��scanf()��printf()��������
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);

	//ɸѡ������������С��Ԫ��
	for (int i = 0; i < n; ++i)
	{
		//�ж϶�ͷ�Ƿ񻬳����ڣ���Ϊֻ�ƶ�һ�Σ�����if������while
		if (hh <= tt && i - k + 1 > q[hh]) hh++;
		//����βԪ�ر�����Ԫ��Ҫ��ʱ��ȥ����βԪ��
		while (hh <= tt && a[q[tt]] >= a[i]) tt--;
		//���ǰ���룬�п�����������������С��ֵ
		q[++tt] = i;
		//ֻ�е����������е�Ԫ�����˲ſ�ʼ�����СԪ��
		if (i >= k - 1) printf("%d ", a[q[hh]]);
	}
	puts("");

	hh = 0, tt = -1;//��ն���
	//ɸѡ��������������Ԫ��
	for (int i = 0; i < n; ++i)
	{
		//�ж��Ƿ񻬶����ڣ���Ϊֻ�ƶ�һ�Σ�����if������while
		if (hh <= tt && i - k + 1 > q[hh]) hh++;
		//����βԪ�ر�����Ԫ��ҪСʱ��ȥ����βԪ��
		while (hh <= tt && a[q[tt]] <= a[i]) tt--;
		//���ǰ���룬�п�����������������С��ֵ
		q[++tt] = i;
		//ֻ�е����������е�Ԫ�����˲ſ�ʼ�����СԪ��
		if (i >= k - 1) printf("%d ", a[q[hh]]);
	}
	puts("");
	return 0;
}