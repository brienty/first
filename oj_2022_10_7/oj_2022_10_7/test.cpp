#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int mySqrt(int x) {
    /*//��������x����0����0�����򵱳˷�����x��i-1����Ҫ�ҵ�����
    for(long long i = 1; x > 0; ++i)
    {
        long long mul = i*i;
        if(mul > x)
            return i - 1;
    }
    return 0;*/
    //���ֲ��ҷ����ҵ��м�ֵ��ƽ�������ұ�ֵ��ƽ�����Ƚ�
    long long left = 0, right = x;
    while (left <= right)
    {
        long long mid = (left + right) >> 1;
        if (mid * mid > x)
            right = mid - 1;
        else if (mid * mid < x)
            left = mid + 1;
        else
            return mid;
    }
    return right;//����ѭ��˵��left��right���ұߣ�˵��right��������Ҫ�ҵ�ֵ
}



int climbStairs(int n) {
    /*//쳲������ݹ鳬ʱ
    if(n == 0 || n == 1)
        return 1;
    return climbStairs(n - 1) + climbStairs(n - 2);*/
    //쳲�����ѭ��
    //0����0
    if (n == 0)
        return 0;
    //��0�ʼ
    int num1 = 0;
    int num2 = 1;
    int num3 = 1;
    for (int i = 0; i < n; ++i)
    {
        num3 = num1 + num2;
        num1 = num2;
        num2 = num3;
    }
    return num3;
}



int maxAscendingSum(vector<int>& nums) {
    //��ǰ��ʼ����
    /*//����ֻ��һ��Ԫ�ص����
    if(nums.size() == 1)
        return nums[0];

    int maxsum = 0;
    int sum = 0;
    for(int i = 0; i < nums.size() - 1; ++i)
    {
        sum += nums[i];//��ֱ��+=��ǰԪ��
        //�����ǰԪ�ش��ڵ��ں�һ��Ԫ���������0
        if(nums[i] >= nums[i+1])
        {
            if(maxsum < sum)
                maxsum = sum;
            sum = 0;
        }
    }
    //�������һ��Ԫ��
    if(nums[nums.size()-1] > nums[nums.size()-2])
        sum += nums[nums.size()-1];
    else
    {
        if(maxsum < sum)
            maxsum = sum;
        sum = nums[nums.size()-1];
    }
    //�������һ��Ԫ�ػ��ǰ��������Ķ���
    if(maxsum < sum)
        maxsum = sum;
    return maxsum;*/
    //��ǰ��ʼ����
    int maxsum = 0, sum = 0, i = 0;
    while (i < nums.size())
    {
        sum = nums[i++];//�ѵ�һ��Ԫ�ظ���sum
        //����һ�����ϵ�Ԫ�زŻ�����ж����Ƿ��ǰһ��Ԫ�ش�
        while (i < nums.size() && nums[i] > nums[i - 1])
        {
            sum += nums[i++];//�����򽫵�ǰԪ�ؼ���
        }
        maxsum = sum > maxsum ? sum : maxsum;//�����ĺʹ洢����
    }
    return maxsum;
}


ListNode* deleteDuplicates(ListNode* head) {
    //����Ϊnullptr�����
    if (head == nullptr)
        return head;

    ListNode* begin = head;
    ListNode* next = begin->next;
    while (next)
    {
        if (begin->val == next->val)
            begin->next = next->next;
        //ֱ�������߻�©Ԫ�أ�û��ɾ����������
        else
            begin = begin->next;
        //������
        next = begin->next;
    }
    return head;
}


int hammingWeight(uint32_t n) {
    int count = 0;
    while (n)
    {
        n = n & n - 1;//�������λ��1
        ++count;
    }
    return count;
}