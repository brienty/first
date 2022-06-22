#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/*
* C语言中，0为假，非0即为真。
* 全局变量，没有给初始值时，编译其会默认将其初始化为0。
* i的初始值为0，i的结果-1，i为整形，sizeof(i)求i类型大小是4
* 按照此分析来看，结果应该打印 < ，但是sizeof的返回值类型实际为无符号整形
* 因此编译器会自动将左侧的i自动进行算术转换为无符号整形的数据
* -1对应的无符号整形是一个非常大的数字（2的32次方），超过4或者8
* 故打印 >
* 这道题其实很隐蔽，真是虾仁猪心！！！
*/
int i;
int main()
{
    i--;
    if (i > sizeof(i))
    {
        printf(">\n");
    }
    else
    {
        printf("<\n");
    }
    return 0;
}