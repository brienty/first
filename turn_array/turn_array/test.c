#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

/*
给你一个数组，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
示例 1:
输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右轮转 1 步: [7,1,2,3,4,5,6]
向右轮转 2 步: [6,7,1,2,3,4,5]
向右轮转 3 步: [5,6,7,1,2,3,4]
示例 2:
输入：nums = [-1,-100,3,99], k = 2
输出：[3,99,-1,-100]
解释:
向右轮转 1 步: [99,-1,-100,3]
向右轮转 2 步: [3,99,-1,-100]
提示：
1<=nums.length<=105
-231<=nums[i]<=231-1
0<=k<=105
进阶：
尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
你可以使用空间复杂度为O(1)的原地 算法解决这个问题吗？
*/



////时间复杂度太差，超出限制，舍弃
//void rotate(int* nums, int numsSize, int k) {
//    int temp = 0;
//    int i = 0;
//    k %= numsSize;
//    for (i = 0; i < k; i++)
//    {
//        temp = nums[numsSize - 1];
//        int j = 0;
//        for (j = 0; j < numsSize - 1; j++)
//        {
//            nums[numsSize - 1 - j] = nums[numsSize - 2 - j];
//        }
//        nums[0] = temp;
//    }
//}

void reverse(int* nums, int left, int right)
{
    while (left < right)
    {
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        ++left;
        --right;
    }
}

//三次逆置最优，以k为分界线，把k（指的是下标为k）后面的元素放到前面
void rotate2(int* nums, int numsSize, int k)
{
    //防越界
    k %= numsSize;
    //前面部分逆置
    reverse(nums, 0, numsSize - k - 1);
    //后面部分逆置
    reverse(nums, numsSize - k, numsSize - 1);
    //全部逆置
    reverse(nums, 0, numsSize - 1);
}

int main()
{
    int nums[7] = { -1,-100,3,99 };
    int k = 2;
    //rotate(nums, sizeof(nums)/sizeof(nums[0]), k);
    rotate2(nums, sizeof(nums) / sizeof(nums[0]), k);

    for (int i = 0; i < 7; i++)
    {
        printf("%d ", nums[i]);
    }
    return 0;
}