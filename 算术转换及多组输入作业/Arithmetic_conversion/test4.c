#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//从键盘任意输入一个整数，编程判断它的奇偶性
//多组输入，每行输入包括一个整数
//针对每行输入，输出该数是奇数（Odd）还是偶数（Even）

int main()
{
    int num = 0;
    //scanf读取失败时会返回EOF，多数输入常用该方法解决
    while (scanf("%d", &num) != EOF)
    {
        if (num % 2 == 1)
        {
            printf("Odd\n");
        }
        else
        {
            printf("Even\n");
        }
    }
    return 0;
}