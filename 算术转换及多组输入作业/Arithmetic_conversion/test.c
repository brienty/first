#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/*
* ���ʽ(++i)+(++i)+(++i)��ֻ�в����������ȼ��ͽ���ԣ�û��ȷ��Ψһ����·��
* ����������ʽ������Ϊ����˳��Ĳ��쵼�½���ǲ�һ�µģ����Ա��ʽ�Ǵ���ı��ʽ
* ������VS��Linux gcc���ԣ���������в���
*/
int main()
{
	int i = 1;
	int ret = (++i) + (++i) + (++i);
	printf("ret = %d\n", ret);//VS�д���12
	return 0;
}