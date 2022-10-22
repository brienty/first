#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    //输入n个整数
    vector<int> v;
    int n = 0;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < v.size(); ++i)
    {
        int in = 0;
        cin >> in;
        v[i] = in;
    }
    //使用ret来找到起始位置，sum来存储连续子数组的和
    int sum = 0;
    int ret = 0;
    //遍历数组查找
    for (auto e : v)
    {
        //如果ret加上数组的元素等于负数，说明该位置不是起始位置
        if (ret + e < 0)
            ret = 0;
        else
            //找到起始位置以后，尽管往ret上加上去
            ret += e;
        //求得sum和ret中最大的一个即为和最大的连续子数组
        sum = max(ret, sum);
    }
    //sum不等于0说明存在和最大的子数组
    if (sum != 0)
        cout << sum;
    else
    {
        //如果sum等于0，说明该数组全部为负数，则返回最大的那个负数
        sort(v.begin(), v.end());
        cout << v[v.size() - 1];
    }
    return 0;
}