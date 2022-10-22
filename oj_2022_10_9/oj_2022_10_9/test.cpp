#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <string>
using namespace std;

char findTheDifference(string s, string t) {
    //映射到数组上
    int arrays[26] = { 0 };
    int arrayt[26] = { 0 };
    for (int i = 0; i < s.size(); ++i)
        ++arrays[s[i] - 'a'];
    for (int i = 0; i < t.size(); ++i)
        ++arrayt[t[i] - 'a'];
    char c = 0;
    //两个数组映射的值不一样则该字母就是被插入的值
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
            k = (k & (k - 1));//去除最低位
            ++count;
        }
        v.push_back(count);
    }
    return v;
}


int guessNumber(int n) {
    //二分查找
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
    //使用stl里的栈
    /*int n = temperatures.size();
    stack<int> st;//创建单调栈，存储元素下标
    vector<int> v(n);//存储答案
    for(int i = temperatures.size() - 1; i >= 0; --i)
    {
        //当栈顶的数据小于等于数组数据时，出栈
        while(!st.empty() && temperatures[st.top()] <= temperatures[i])
            st.pop();
        //存储两个元素下标的差值
        v[i] = st.empty() ? 0 : st.top() - i;
        st.push(i);
    }
    return v;
    */
    //数组模拟栈
    const int N = 100010;
    int stk[N] = { 0 };////创建单调栈，存储元素下标
    int tt = 0;//栈顶元素
    int n = temperatures.size();
    vector<int> v(n);//存储答案
    for (int i = temperatures.size() - 1; i >= 0; --i)
    {
        //当栈顶的数据小于等于数组数据时，出栈
        while (tt > 0 && temperatures[stk[tt]] <= temperatures[i])
            --tt;
        //存储两个元素下标的差值
        v[i] = (tt > 0) ? stk[tt] - i : 0;
        //将元素插入栈顶
        stk[++tt] = i;
    }
    return v;
}