#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <queue>
using namespace std;


class MyStack {
public:
    void push(int x) {
        //����Ϊ�յĶ��з�Ԫ��
        if (!q1.empty())
            q1.push(x);
        else
            q2.push(x);
    }

    int pop() {
        //�ҵ���Ϊ�յĶ��У��Ѳ�Ϊ�յĶ��з���ն�����
        int end = 0;
        if (!q1.empty())
        {
            int size = q1.size() - 1;
            while (size)
            {
                q2.push(q1.front());
                q1.pop();
                --size;
            }
            end = q1.front();
            q1.pop();
        }
        else
        {
            int size = q2.size() - 1;
            while (size)
            {
                q1.push(q2.front());
                q2.pop();
                --size;
            }
            end = q2.front();
            q2.pop();
        }
        return end;
    }

    int top() {
        //���ز�Ϊ�ն��е����һ��Ԫ��
        if (!q1.empty())
            return q1.back();
        else
            return q2.back();
    }

    bool empty() {
        //�������ж���Ϊ�ղ��ǿ�
        return q1.empty() && q2.empty();
    }
private:
    queue<int> q1;
    queue<int> q2;
};