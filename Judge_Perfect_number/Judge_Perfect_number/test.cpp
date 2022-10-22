#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

bool JudgePerfect(int num)
{
    vector<int> v;//存储约数
    int i = 0, sum = 0;
    //判断约数
    for (int i = 1; i < num; ++i)
        if (num % i == 0)
            v.push_back(i);
    //将约数相加
    for (int i = 0; i < v.size(); ++i)
        sum += v[i];
    //如果和等于num，那么这个数是完全数
    if (sum == num)
        return true;
    return false;
}

int main()
{
    int n = 0, count = 0;
    cin >> n;
    for (int i = 4; i <= n; ++i)
        if (JudgePerfect(i))
            ++count;
    cout << count << endl;
    return 0;
}