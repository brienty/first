#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

/*
	ջ����Ҫע�⣺
	ջ�Ǳ����ջ�����벢��һ���Ǻ���ȳ�
	����ʹ�ö�̬����ķ�ʽ��ʹ��������ã����ǿ���ʹ������
	��Ϊջ���ﲻ���м����Ԫ�أ�������β��Ч�ʸ�
	�������ƣ�
	ʹ�õ�ָ���˫��������
	���ٻ���������ʱ������ 
*/

void Test()
{
	ST st;
	//Ҫ�ı�ṹ�壬��Ҫ����ַ
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	StackPush(&st, 6);
	printf("%d\n", Stacksize(&st));

	//��ӡջ��Ҫ�������ۣ���Ϊջ��ֻ�ܴ�ջ����ջ�ͳ�ջ�����Դ�ӡ���ɾ����
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	printf("\n");

	StackDestroy(&st);
}


int main()
{
	Test();
	return 0;
}