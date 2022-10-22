#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;


int removeDuplicates(vector<int>& nums) {
    int fast = 1;
    int slow = 0;
    while (fast < nums.size())
    {
        if (nums[fast] == nums[slow])
        {
            nums.erase(nums.begin() + fast);
        }
        else
        {
            slow = fast;
            ++fast;
        }
    }
    return nums.size();
}

int main()
{
    vector<int> v;
    v.push_back(0);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    v.push_back(4);
    removeDuplicates(v);
	return 0;
}