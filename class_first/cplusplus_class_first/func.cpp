#define _CRT_SECURE_NO_WARNINGS 1
#include "func.h"

//定义声明分离，push属于类域，需要指定作用域
//void Stack::push(int x)
//{
//	//注意这里不是因为这三个变量是私有才编译不通过
//	//push这个函数是类域里的函数，是类里，不是类外
//	_a = nullptr;
//	_capacity = 0;
//	_size = 0;
//}