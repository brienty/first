#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int mySqrt(int x) {
    /*//遍历，当x等于0返回0，否则当乘方大于x则i-1就是要找的数字
    for(long long i = 1; x > 0; ++i)
    {
        long long mul = i*i;
        if(mul > x)
            return i - 1;
    }
    return 0;*/
    //二分查找法，找到中间值的平方和最右边值的平方作比较
    long long left = 0, right = x;
    while (left <= right)
    {
        long long mid = (left + right) >> 1;
        if (mid * mid > x)
            right = mid - 1;
        else if (mid * mid < x)
            left = mid + 1;
        else
            return mid;
    }
    return right;//跳出循环说明left在right的右边，说明right就是我们要找的值
}



int climbStairs(int n) {
    /*//斐波那契递归超时
    if(n == 0 || n == 1)
        return 1;
    return climbStairs(n - 1) + climbStairs(n - 2);*/
    //斐波那契循环
    //0返回0
    if (n == 0)
        return 0;
    //非0项开始
    int num1 = 0;
    int num2 = 1;
    int num3 = 1;
    for (int i = 0; i < n; ++i)
    {
        num3 = num1 + num2;
        num1 = num2;
        num2 = num3;
    }
    return num3;
}



int maxAscendingSum(vector<int>& nums) {
    //从前开始遍历
    /*//处理只有一个元素的情况
    if(nums.size() == 1)
        return nums[0];

    int maxsum = 0;
    int sum = 0;
    for(int i = 0; i < nums.size() - 1; ++i)
    {
        sum += nums[i];//先直接+=当前元素
        //如果当前元素大于等于后一个元素则进来归0
        if(nums[i] >= nums[i+1])
        {
            if(maxsum < sum)
                maxsum = sum;
            sum = 0;
        }
    }
    //处理最后一个元素
    if(nums[nums.size()-1] > nums[nums.size()-2])
        sum += nums[nums.size()-1];
    else
    {
        if(maxsum < sum)
            maxsum = sum;
        sum = nums[nums.size()-1];
    }
    //可能最后一个元素会比前面加起来的都大
    if(maxsum < sum)
        maxsum = sum;
    return maxsum;*/
    //从前开始遍历
    int maxsum = 0, sum = 0, i = 0;
    while (i < nums.size())
    {
        sum = nums[i++];//把第一个元素赋给sum
        //大于一个以上的元素才会进来判断有是否比前一个元素大
        while (i < nums.size() && nums[i] > nums[i - 1])
        {
            sum += nums[i++];//满足则将当前元素加上
        }
        maxsum = sum > maxsum ? sum : maxsum;//把最大的和存储下来
    }
    return maxsum;
}


ListNode* deleteDuplicates(ListNode* head) {
    //处理为nullptr的情况
    if (head == nullptr)
        return head;

    ListNode* begin = head;
    ListNode* next = begin->next;
    while (next)
    {
        if (begin->val == next->val)
            begin->next = next->next;
        //直接往下走会漏元素，没有删除才往下走
        else
            begin = begin->next;
        //往下走
        next = begin->next;
    }
    return head;
}


int hammingWeight(uint32_t n) {
    int count = 0;
    while (n)
    {
        n = n & n - 1;//消掉最低位的1
        ++count;
    }
    return count;
}