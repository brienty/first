#define _CRT_SECURE_NO_WARNINGS 1
#include "queue.h"
#include "stack.h"

void test_queue()
{
	myqueue::queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	for (int i = 0; i < 5; ++i)
	{
		cout << q.front() << " ";
		cout << q.back() << " ";
		cout << q.empty() << " ";
		cout << q.size() << " ";
		q.pop();
	}
	cout << endl;
}

void test_stack()
{
	mystack::stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	for (int i = 0; i < 4; ++i)
	{
		cout << st.top() << " ";
		st.pop();
		cout << st.empty() << " ";
		cout << st.size() << " ";
	}
	cout << endl;
}

int main()
{
	test_queue();
	test_stack();
	return 0;
}