#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#define N 10

/*
    题目：
    输入一个整数数组，实现一个函数，
    来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
    所有偶数位于数组的后半部分。
*/

//把奇数按顺序交换，从第一个元素开始往后放
void Adjust1(int arr1[])
{
    int i = 0;
    int j = 0;
    for (i = 0; i < N; i++)
    {
        if (arr1[i] % 2 == 1)
        {
            int temp = arr1[i];
            arr1[i] = arr1[j];
            arr1[j] = temp;
            ++j;
        }
    }
    
}

//使用指针，从两头开始遍历
void Adjust2(int* L)
{
    int* R = L + N - 1;
    while (L < R)
    {
        //左边找偶数
        while (*L % 2 == 1  && L < R)
        {
            L++;
        }

        //右边找奇数
        while (*R % 2 == 0 && L < R)
        {
            R--;
        }

        //判断当L大于R时，防止把正确的顺序换了
        if (L < R)
        {
            int temp = *R;
            *R = *L;
            *L = temp;
        }

    }
}


int main()
{
    int arr1[N] = { 1,2,3,4,5,6,7,8,9,10 };
    int arr2[N] = { 1,2,3,4,5,6,7,8,9,10 };
    
    Adjust1(arr1);//第一种方法

    Adjust2(arr2);//第二种方法
    
    int i = 0;
    
    //打印arr1数组
    for (i = 0; i < N; ++i)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    
    //打印arr2数组
    for (i = 0; i < N; ++i)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");
}