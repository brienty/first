#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <queue>
using namespace std;


class MyStack {
public:
    void push(int x) {
        //往不为空的队列放元素
        if (!q1.empty())
            q1.push(x);
        else
            q2.push(x);
    }

    int pop() {
        //找到不为空的队列，把不为空的队列放入空队列中
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
        //返回不为空队列的最后一个元素
        if (!q1.empty())
            return q1.back();
        else
            return q2.back();
    }

    bool empty() {
        //两个队列都不为空才是空
        return q1.empty() && q2.empty();
    }
private:
    queue<int> q1;
    queue<int> q2;
};