#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    //ʹ��Ĭ�ϵĹ��캯������
    MinStack() {
    }

    void push(int val) {
        st.push(val);//����Ԫ�ش���st
        //ֻ��minstΪ�ջ���valС�ڵ���minst��ջ��Ԫ�زŲ���minst
        if (minst.empty() || val <= minst.top())
            minst.push(val);
    }

    void pop() {
        //������ջ��Ԫ�����ʱ��˵��ջ������СԪ��Ӧ��Ҳ��pop
        if (minst.top() == st.top())
            minst.pop();
        //��β���popst����popst��if���޷��ж���ȷ
        st.pop();
    }

    int top() {
        //����ջ��Ԫ��
        return st.top();
    }

    int getMin() {
        //������Сջ��ջ��Ԫ��
        return minst.top();
    }
private:
    stack<int> st;//������Ԫ�ص�ջ
    stack<int> minst;//����СԪ�ص�ջ
};