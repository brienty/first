#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//��дһ������ʵ��n��k�η���ʹ�õݹ�ʵ�֣����磺3��3�η���4��-2�η�
/*
* ˼·��num * num �� n-1 �η�
*/

double Mul(int num, int n)
{
	if (n > 0)
	{
		//ע���д��num*num����Ȼÿ�εݹ�num���ڱ仯
		return Mul(num, n - 1) * num;
	}
	else if (n < 0)
	{
		//��-n����nת������1.0�������弴����
		//����1.0/num��ԭ����Mul�Ĳ�����Ϊint��
		return 1.0 / (Mul(num, -n) * num);
	}
	else
	{
		//��n=0ʱ��Ҫ����1�����磺1*3*3*3
		return 1;
	}
}
int main()
{
	int n = 0;
	int num = 0;
	scanf("%d %d", &n, &num);
	double sum = Mul(num, n);
	printf("%lf\n", sum);
	return 0;
}