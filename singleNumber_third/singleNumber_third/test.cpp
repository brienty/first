#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //�����ֵ����sum
        int sum = 0;
        for (auto e : nums)
        {
            sum ^= e;
        }

        //��ȡ��ͱ���λ��1����С����ֵʱֱ�ӷ��أ����û�ȡ
        int lb = (sum == INT_MIN ? sum : sum & -sum);

        //����
        int num1 = 0;
        int num2 = 0;

        //�����ݷֳ����࣬��������һ�ε�����һ����������
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

        //������ֻ����һ�ε����ݴ���v��
        vector<int> v;
        v.push_back(num1);
        v.push_back(num2);
        return v;
    }
};