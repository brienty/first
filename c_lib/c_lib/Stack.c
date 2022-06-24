#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

//这里需要使用到assert函数，因为传过来的结构体指针是否为空决定了栈是否存在


void StackInit(ST* ps)
{
	assert(ps);

	ps->a = NULL;
	//这里初始化为0，则top记录的当前元素的下一个元素
	ps->capacity = ps->top = 0;
}

//因为这里接受的是结构体的地址，所以这里的参数改变会影响到实参
void StackDestroy(ST* ps)
{
	assert(ps);

	free(ps->a);
	//这里置空是有效的
	ps->a = NULL;

	ps->capacity = ps->top = 0;
}

void StackPush(ST* ps, STDataType x)
{
	assert(ps);

	//判断是否需要扩容
	if (ps->top == ps->capacity)
	{
		//这里需要处理capacity为0时的情况
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

	//不需要扩容或者扩容完，将数据放入
	ps->a[ps->top] = x;
	++ps->top;
}

void StackPop(ST* ps)
{
	assert(ps);

	//当栈里没有数据时不能删除
	assert(ps->top > 0);

	//因为数组使用数据覆盖没意义，所以直接将栈顶向下移动
	--ps->top;
}

bool StackEmpty(ST* ps)
{
	assert(ps);

	//当top为0时则为空，否则不为空
	return ps->top == 0;
}

int Stacksize(ST* ps)
{
	assert(ps);

	//因为top是下一个元素的下标，所以它即为元素个数
	return ps->top;
}

STDataType StackTop(ST* ps)
{
	assert(ps);

	//当top为空时不能返回
	assert(ps->top > 0);

	return (ps->a[ps->top - 1]);
}