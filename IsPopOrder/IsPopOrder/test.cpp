#define _CRT_SECURE_NO_WARNINGS 1
#include <stack>
#include <iostream>
#include <vector>
using namespace std;

bool IsPopOrder(vector<int> pushV, vector<int> popV) {
    stack<int> st;//存储pushV的元素
    int popi = 0;
    for (auto e : pushV) {
        st.push(e);//将pushV的元素push进st里
        //如果st不空并且和popV的栈顶元素相同则说明需要出栈
        while (!st.empty() && st.top() == popV[popi]) {
            st.pop();
            ++popi;//popV后移
        }
    }
    //如果st不为空说明不是出栈序列
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