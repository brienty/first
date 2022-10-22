#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int sum = 0;
        int ret = 0;
        //遍历数组
        for (auto e : array)
        {
            //当ret+e小于0说明不是该位置开始
            if (ret + e < 0)
            {
                ret = 0;
            }
            //直到ret+e不小于0才是开始的位置
            else
            {
                ret += e;
            }
            //找到较大的那个
            sum = max(ret, sum);
        }
        //sum等于0说明全部都是负数
        if (sum == 0)
        {
            //找到最大的负数
            sort(array.begin(), array.end());
            return array[array.size() - 1];
        }
        else
        {
            return sum;
        }
    }
};