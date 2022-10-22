#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;//典型使用优先级队列
        for (int i = 0; i < nums.size(); ++i)
        {
            pq.push(nums[i]);
        }

        //将第k-1个删除后，第k即为所求值
        for (int i = 0; i < k - 1; ++i)
        {
            pq.pop();
        }
        return pq.top();
    }
};