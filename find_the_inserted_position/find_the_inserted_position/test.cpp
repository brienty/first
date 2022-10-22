#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        /*//����������ʱ�临�Ӷ�ΪO(n)
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

        //���ֲ��ң�ʱ�临�Ӷ�ΪO(logn)
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
        //�Ҳ������Ŀ��ֵ����nums���ôӦ����leftλ�ò��룬���Ը���ʾ����һ���ɷ���
        return left;
    }
};