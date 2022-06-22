#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

/*
输入两个升序排列的序列，将两个序列合并为一个有序序列并输出。
数据范围： 1 \le n, m \le 1000 \1≤n,m≤1000  ， 序列中的值满足 0 \le val \le 30000 \0≤val≤30000 
输入描述：
输入包含三行，
第一行包含两个正整数n, m，用空格分隔。n表示第二行第一个升序序列中数字的个数，m表示第三行第二个升序序列中数字的个数。
第二行包含n个整数，用空格分隔。
第三行包含m个整数，用空格分隔。

输出描述：
输出为一行，输出长度为n+m的升序序列，即长度为n的升序序列和长度为m的升序序列中的元素重新进行升序序列排列合并。

示例
输入：
5 6
1 3 7 9 22
2 8 10 17 33 44
输出：
1 2 3 7 8 9 10 17 22 33 44
*/


int main()
{
    //创建数组
    int arr1[1000] = { 0 };
    int arr2[1000] = { 0 };
    int n = 0;
    int m = 0;
    scanf("%d %d", &n, &m);
    
    //初始化数组
    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d ", &arr1[i]);
    }
    for (i = 0; i < m; i++)
    {
        scanf("%d ", &arr2[i]);
    }

    //输出
    i = 0;
    int j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            printf("%d ", arr1[i]);
            i++;
        }
        else
        {
            printf("%d ", arr2[j]);
            j++;
        }
    }

    //数组剩余元素的输出
    if (i == n)
    {
        for (; j < m; j++)
        {
            printf("%d ", arr2[j]);
        }
    }
    else
    {
        for (; i < n; i++)
        {
            printf("%d ", arr1[i]);
        }
    }

    return 0;
}