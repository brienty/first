#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

/*
	����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Ժȶ�����ˮ
*/

int main()
{
	int money = 0;
	int empty = 0;
	int total = 0;
	scanf("%d", &money);
	
	//�ȵ���ˮ����
	total += money;

	//ʣ�µĿ�ƿ����
	empty += money;

	//��ƿ�û�
	while (empty > 1)
	{
		//ÿ������ƿ��һ����ˮ
		total += empty / 2;

		//ͳ��ʣ�µĿ�ƿ����
		empty = empty / 2 + empty % 2;
	}

	printf("%d\n", total);
	return 0;
}
/*
	���ﻹ��һ�ַ���
	���ݼ������������20��Ǯ=40����ƿ
	Ȼ��ʵ��ת����20��Ǯ=39ƿ��ˮ+1����ƿ
	���Ժȵ���ˮ��=money*2-1
	Ҳ���ǿ���д��
	total = money*2-1��
	����
*/