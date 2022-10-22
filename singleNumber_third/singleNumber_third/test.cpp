#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //将异或值存入sum
        int sum = 0;
        for (auto e : nums)
        {
            sum ^= e;
        }

        //获取最低比特位的1，最小整数值时直接返回，不用获取
        int lb = (sum == INT_MIN ? sum : sum & -sum);

        //分类
        int num1 = 0;
        int num2 = 0;

        //将数据分成两类，两个出现一次的数据一定会在两边
        for (auto e : nums)
        {
            if (e & lb)
            {
                num1 ^= e;
            }
            else
            {
                num2 ^= e;
            }
        }

        //将两个只出现一次的数据存入v中
        vector<int> v;
        v.push_back(num1);
        v.push_back(num2);
        return v;
    }
};