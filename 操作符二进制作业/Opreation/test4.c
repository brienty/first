#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//��ȡһ���������������������е�ż��λ������λ���ֱ��ӡ������������

/*
* ˼·���ƶ�λ������ӡ
*	    �ƶ�λ�������ر������䱾���δ�ı�
*	   ����Ҫע���ƶ��˶���λ�������ƶ�λ������һλ
*/
void Print(int n)
{
	int i = 0;
	//��ӡ����λ
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (n >> i) & 1);
	}
	printf("\n");
	//��ӡż��λ
	for (i = 31; i >= 1; i -= 2)
	{
		printf("%d ", (n >> i) & 1);
	}
}
int main()
{
	int num = 0;
	scanf("%d", &num);
	Print(num);
	return 0;
}