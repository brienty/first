#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ����磺1729
/*
*  ˼·��172+9	�����9+172��ÿһλ
*		17+2+9	�����9+2+17��ÿһλ
*		1+7+2+9	�����9+2+7+1
*/

int DigitSum(int n)
{
	//��nС��10���ݹ�
	if (n <= 9)
	{
		return n;
	}
	else
	{
		return DigitSum(n / 10) + n % 10;
	}
}
int main()
{
	unsigned num = 0;
	scanf("%u", &num);
	int sum = DigitSum(num);
	printf("%u\n", sum);
	return 0;
}