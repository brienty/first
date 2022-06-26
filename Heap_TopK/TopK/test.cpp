#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>

using namespace std;

//����
void swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}

//���µ�����
void AdjustDown(int*a, int& n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (a[child] > a[child + 1] && child + 1 < n)
		{
			child++;
		}
		
		if (a[child] < a[parent])
		{
			swap(a[child], a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}


void PrintTopK(int* a, int& n, int k)
{
	// 1. ����--��a��ǰk��Ԫ�ؽ���
	int* heapmink = (int*)malloc(sizeof(int) * k);
	assert(heapmink);

	for (int i = 0; i < k; i++)
	{
		heapmink[i] = a[i];
	}

	for (int i = (k-1-1)/2; i >= 0; i--)
	{
		AdjustDown(heapmink, k, i);
	}


	// 2. ��ʣ��n-k��Ԫ��������Ѷ�Ԫ�ؽ��������������滻
	for (int j = k; j < n; j++)
	{
		if (heapmink[0] < a[j])
		{
			swap(heapmink[0], a[j]);
			//���������Ҫ�����������ݴ���µ�
			AdjustDown(heapmink, k, 0);
		}
	}

	//��ӡ����k������
	for (int i = 0; i < k; ++i)
	{
		cout << heapmink[i] << " ";
	}
	cout << endl;

	//�ͷſ��ٵĿռ�
	free(heapmink);
}

void TestTopk()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	assert(a);
	srand(time(0));
	for (size_t i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;
	}
	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 3;
	a[5121] = 1000000 + 4;
	a[115] = 1000000 + 5;
	a[2335] = 1000000 + 6;
	a[9999] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10;
	PrintTopK(a, n, 10);
}

int main()
{
	TestTopk();
	return 0;
}