#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        /*//暴力遍历，时间复杂度为O(n)
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == target)
                return i;
        }
        nums.push_back(target);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == target)
                return i;
        }
        return 0;*/

        //二分查找，时间复杂度为O(logn)
        int left = 0, right = nums.size() - 1, mid = (left + right) / 2;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                return mid;
        }
        //找不到如果目标值不在nums里，那么应该在left位置插入，可以根据示例走一即可发现
        return left;
    }
};