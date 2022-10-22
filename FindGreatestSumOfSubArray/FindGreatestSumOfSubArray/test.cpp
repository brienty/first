#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int sum = 0;
        int ret = 0;
        //��������
        for (auto e : array)
        {
            //��ret+eС��0˵�����Ǹ�λ�ÿ�ʼ
            if (ret + e < 0)
            {
                ret = 0;
            }
            //ֱ��ret+e��С��0���ǿ�ʼ��λ��
            else
            {
                ret += e;
            }
            //�ҵ��ϴ���Ǹ�
            sum = max(ret, sum);
        }
        //sum����0˵��ȫ�����Ǹ���
        if (sum == 0)
        {
            //�ҵ����ĸ���
            sort(array.begin(), array.end());
            return array[array.size() - 1];
        }
        else
        {
            return sum;
        }
    }
};