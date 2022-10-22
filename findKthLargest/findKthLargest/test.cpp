#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;//����ʹ�����ȼ�����
        for (int i = 0; i < nums.size(); ++i)
        {
            pq.push(nums[i]);
        }

        //����k-1��ɾ���󣬵�k��Ϊ����ֵ
        for (int i = 0; i < k - 1; ++i)
        {
            pq.pop();
        }
        return pq.top();
    }
};