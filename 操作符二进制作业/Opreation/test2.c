#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//дһ���������ز������ڴ��ﲹ��������� 1 �ĸ���,���磺15 00001111  4 �� 1



/*
* ˼·���������еĶ�����λһ��һ�� & 1������ʮ����������λһ��һ���ж�
* ��ʹ�� >> ���Ѿ��ж��˵Ķ�����λ��ȥ����
*/
int Count_num1(int n)
{
	int count = 0;
	int i = 0;
	//������Ȼ��λ��1������ֻ�ƶ���32�Σ�
	for (i = 0; i < 32; i++)
	{
		//==�����ȼ�����&
		if ((n & 1) == 1)
		{
			count++;
			//num2 >> 1 δ�ı�num2����Ҫ���¸�ֵ
			n = n >> 1;
		}
		else
		{
			n = n >> 1;
		}
	}
	return count;
}

/*
* ˼·��������ʮ������ n % 10 ȡ���һλ�� n / 10 ��ȥ���һλ
*		n % 2 == 1 �õ����һ��������λ��n / 2 ����ȥ���һ��������λ
*/
//ע��Ҫ��unsigned����ֹ -1 ���ָ���
//����unsigned�ڴ��е� -1 ��Ȼ��32��1
int Count_num2(unsigned int n)
{
	int count = 0;
	while (n)
	{
		if (n % 2 == 1)
		{
			count++;
		}
		n /= 2;
	}
	return count;
}

/*
* ˼·���� n & (n - 1) ʱ��n�Ķ�����λ�����ұ�һλ 1 ��ȥ��
*	   ���������㷨���м��� 1 ѭ������
* PS�� Ҳ���������ж�2��k�η�
*/
int Count_num3(int n)
{
	int count = 0;
	//n�������0
	while (n)
	{
		n = n & (n - 1);
		count++;
	}
}

int main()
{
	int num1 = 0;
	scanf("%d", &num1);
	int num2 = Count_num1(num1);
	int num3 = Count_num2(num1);
	int num4 = Count_num3(num1);
	printf("%d %d %d\n", num2, num3, num4);
	return 0;
}