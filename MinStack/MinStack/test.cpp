#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    //使用默认的构造函数即可
    MinStack() {
    }

    void push(int val) {
        st.push(val);//所有元素存入st
        //只有minst为空或者val小于等于minst的栈顶元素才插入minst
        if (minst.empty() || val <= minst.top())
            minst.push(val);
    }

    void pop() {
        //当两个栈顶元素相等时，说明栈顶的最小元素应该也被pop
        if (minst.top() == st.top())
            minst.pop();
        //其次才是popst，先popst，if则无法判断正确
        st.pop();
    }

    int top() {
        //返回栈顶元素
        return st.top();
    }

    int getMin() {
        //返回最小栈的栈顶元素
        return minst.top();
    }
private:
    stack<int> st;//存所有元素的栈
    stack<int> minst;//存最小元素的栈
};