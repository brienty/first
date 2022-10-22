#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <string>
using namespace std;

char findTheDifference(string s, string t) {
    //ӳ�䵽������
    int arrays[26] = { 0 };
    int arrayt[26] = { 0 };
    for (int i = 0; i < s.size(); ++i)
        ++arrays[s[i] - 'a'];
    for (int i = 0; i < t.size(); ++i)
        ++arrayt[t[i] - 'a'];
    char c = 0;
    //��������ӳ���ֵ��һ�������ĸ���Ǳ������ֵ
    for (int i = 0; i < 26; ++i)
    {
        if (arrays[i] != arrayt[i])
            c = i + 'a';
    }
    return c;
}

vector<int> countBits(int n) {
    vector<int> v;
    for (int i = 0; i <= n; ++i)
    {
        int count = 0, k = i;
        while (k)
        {
            k = (k & (k - 1));//ȥ�����λ
            ++count;
        }
        v.push_back(count);
    }
    return v;
}


int guessNumber(int n) {
    //���ֲ���
    long long left = 1, right = n;
    while (left <= right)
    {
        long long mid = (left + right) >> 1;
        if (guess(mid) == -1)
            right = mid - 1;
        else if (guess(mid) == 1)
            left = mid + 1;
        else
            return mid;
    }
    return 0;
}


vector<int> dailyTemperatures(vector<int>& temperatures) {
    //ʹ��stl���ջ
    /*int n = temperatures.size();
    stack<int> st;//��������ջ���洢Ԫ���±�
    vector<int> v(n);//�洢��
    for(int i = temperatures.size() - 1; i >= 0; --i)
    {
        //��ջ��������С�ڵ�����������ʱ����ջ
        while(!st.empty() && temperatures[st.top()] <= temperatures[i])
            st.pop();
        //�洢����Ԫ���±�Ĳ�ֵ
        v[i] = st.empty() ? 0 : st.top() - i;
        st.push(i);
    }
    return v;
    */
    //����ģ��ջ
    const int N = 100010;
    int stk[N] = { 0 };////��������ջ���洢Ԫ���±�
    int tt = 0;//ջ��Ԫ��
    int n = temperatures.size();
    vector<int> v(n);//�洢��
    for (int i = temperatures.size() - 1; i >= 0; --i)
    {
        //��ջ��������С�ڵ�����������ʱ����ջ
        while (tt > 0 && temperatures[stk[tt]] <= temperatures[i])
            --tt;
        //�洢����Ԫ���±�Ĳ�ֵ
        v[i] = (tt > 0) ? stk[tt] - i : 0;
        //��Ԫ�ز���ջ��
        stk[++tt] = i;
    }
    return v;
}