#define _CRT_SECURE_NO_WARNINGS 1
#include <stack>
#include <iostream>
#include <vector>
using namespace std;

bool IsPopOrder(vector<int> pushV, vector<int> popV) {
    stack<int> st;//�洢pushV��Ԫ��
    int popi = 0;
    for (auto e : pushV) {
        st.push(e);//��pushV��Ԫ��push��st��
        //���st���ղ��Һ�popV��ջ��Ԫ����ͬ��˵����Ҫ��ջ
        while (!st.empty() && st.top() == popV[popi]) {
            st.pop();
            ++popi;//popV����
        }
    }
    //���st��Ϊ��˵�����ǳ�ջ����
    if (!st.empty())
        return false;
    return true;
}

int main()
{
    vector<int> pushV;
    pushV.push_back(1);
    pushV.push_back(2);
    pushV.push_back(3);
    pushV.push_back(4);
    pushV.push_back(5);
    vector<int> popV;
    popV.push_back(4);
    popV.push_back(5);
    popV.push_back(3);
    popV.push_back(2);
    popV.push_back(1);
    cout << IsPopOrder(pushV, popV);
	return 0;
}