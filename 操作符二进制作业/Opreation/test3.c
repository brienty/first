#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//���ʵ�֣�����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ�� 
//��������:1999 2299
//������� : 7
//PS����test2����Ŀ�йأ��Ƚ��test2����Ŀ����

/*
* ˼·�����հ�λ��1�Ժ�ֵ���Ƿ����
*/
int Count_diff_num1(int n, int m)
{
	int count = 0;
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		//ע�����ȼ�
		if ((n & 1) != (m & 1))
		{
			count++;
		}
		n >>= 1;
		m >>= 1;
	}
	return count;
}

/*
* ˼·�����ú�������������ͬΪ0������Ϊ1
*		������ֵ����ֵ������
*		�ټ������ж� 1 ��⼴��
*/
int Count_diff_num2(int n, int m)
{
	int count = 0;
	int temp = n ^ m;
	while (temp)
	{
		//ע�����ȼ�
		temp = temp & (temp - 1);
		count++;
	}
	return count;
}
int main()
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);
	int num3 = Count_diff_num1(num1, num2);
	int num4 = Count_diff_num2(num1, num2);
	printf("%d %d\n", num3, num4);
	return 0;
}