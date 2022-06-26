#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
编写一个函数找出这两个只出现一次的数字。
*/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumbers(int* nums, int numsSize, int* returnSize) {
    int ret = 0;
    int i = 0;
    int temp = 0;
    int m = 0;
    int n = 0;
    //开辟一块连续空间存储只出现一次的数字
    int* arr = (int*)malloc(sizeof(int) * 2);
    if (arr == NULL)
    {
        return;
    }
    //将只出现一次的数字异或到一起
    for (i = 0; i < numsSize; i++)
    {
        ret ^= nums[i];
    }
    //用异或到一起的数字从右到左开始找二进制位为1的位
    for (i = 0; i < 32; i++)
    {
        if (((ret >> i) & 1) == 1)
        {
            //存储到temp中
            temp = i;
            break;
        }
    }
    //根据该二进制位为1的位分类，找到第一个只出现一次的数字
    for (i = 0; i < numsSize; i++)
    {
        if (((nums[i] >> temp) & 1) == 1)
        {
            n ^= nums[i];
        }
    }
    //第二个只出现一次 的数字
    m = ret ^ n;
    //放到开辟的空间中
    arr[0] = m;
    arr[1] = n;
    //开辟的空间里所存数字的个数
    *returnSize = 2;
    //返回开辟的空间
    return arr;
}

int main()
{
    int arr[] = { 1,2,3,4,5,1,2,3,4,6 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    int* returnSize = NULL;
    //动态内存版本
    int* p = singleNumbers(arr, sz, returnSize);
    free(p);
    p = NULL;

    return 0;
}