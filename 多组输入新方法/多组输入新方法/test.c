#define _CRT_SECURE_NO_WARNINGS 1


/*
公务员面试现场打分。
有7位考官，从键盘输入若干组成绩，每组7个分数（百分制），
去掉一个最高分和一个最低分，输出每组的平均成绩。（注：本题有多组输入）

输入描述：
每一行，输入7个整数（0~100），代表7个成绩，用空格分隔。

输出描述：
每一行，输出去掉最高分和最低分的平均成绩，小数点后保留2位，每行输出后换行。

示例1
输入：
99 45 78 67 72 88 60
输出：
73.00
*/

#include <stdio.h>
int main()
{
    int n = 0;
    int max = 0;
    int min = 100;//满分制置于最大
    int count = 0;//满分制置于最小
    int sum = 0;
    while (scanf("%d", &n) != EOF)
    {
        if (n < min)
        {
            min = n;
        }
        if (n > max)
        {
            max = n;
        }
        sum += n;

        //每七个一组
        count++;
        if (count == 7)
        {
            printf("%.2f \n", (sum - max - min) / 5.0f);
            
            count = 0;//重置
            max = 0;//重置
            min = 100;//重置
            sum = 0;//重置
        }
    }
    return 0;
}