#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

//������Ҫʹ�õ�assert��������Ϊ�������Ľṹ��ָ���Ƿ�Ϊ�վ�����ջ�Ƿ����


void StackInit(ST* ps)
{
	assert(ps);

	ps->a = NULL;
	//�����ʼ��Ϊ0����top��¼�ĵ�ǰԪ�ص���һ��Ԫ��
	ps->capacity = ps->top = 0;
}

//��Ϊ������ܵ��ǽṹ��ĵ�ַ����������Ĳ����ı��Ӱ�쵽ʵ��
void StackDestroy(ST* ps)
{
	assert(ps);

	free(ps->a);
	//�����ÿ�����Ч��
	ps->a = NULL;

	ps->capacity = ps->top = 0;
}

void StackPush(ST* ps, STDataType x)
{
	assert(ps);

	//�ж��Ƿ���Ҫ����
	if (ps->top == ps->capacity)
	{
		//������Ҫ����capacityΪ0ʱ�����
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* temp = (STDataType*)realloc(ps->a, sizeof(STDataType) * newcapacity);
		if (temp == NULL)
		{
			printf("realloc fail!\n");
			exit(-1);
		}
		ps->a = temp;
		ps->capacity = newcapacity;
	}

	//����Ҫ���ݻ��������꣬�����ݷ���
	ps->a[ps->top] = x;
	++ps->top;
}

void StackPop(ST* ps)
{
	assert(ps);

	//��ջ��û������ʱ����ɾ��
	assert(ps->top > 0);

	//��Ϊ����ʹ�����ݸ���û���壬����ֱ�ӽ�ջ�������ƶ�
	--ps->top;
}

bool StackEmpty(ST* ps)
{
	assert(ps);

	//��topΪ0ʱ��Ϊ�գ�����Ϊ��
	return ps->top == 0;
}

int Stacksize(ST* ps)
{
	assert(ps);

	//��Ϊtop����һ��Ԫ�ص��±꣬��������ΪԪ�ظ���
	return ps->top;
}

STDataType StackTop(ST* ps)
{
	assert(ps);

	//��topΪ��ʱ���ܷ���
	assert(ps->top > 0);

	return (ps->a[ps->top - 1]);
}