#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int num = 0;
    for (int i = 0; i < 32; ++i)
    {
        int sum = 0;
        for (auto e : nums)
        {
            sum += (e >> i) & 1;
        }
        if (sum % 3)
        {
            num = num | (1 << i);
        }
    }
    return num;
}

int main()
{
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(99);
    cout << singleNumber(v);
	return 0;
}