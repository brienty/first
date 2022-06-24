#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

struct ListNode
{
	ListNode* _next;
	ListNode* _prev;
	int _data;
	void* operator new(size_t n)
	{
		void* p = nullptr;
		p = allocator<ListNode>().allocate(1);
		cout << "memory pool allocate" << endl;
		return p;
	}
	void operator delete(void* p)
	{
		allocator<ListNode>().deallocate((ListNode*)p, 1);
		cout << "memory pool deallocate" << endl;
	}
};
class List
{
public:
	List()
	{
		_head = new ListNode;
		_head->_next = _head;
		_head->_prev = _head;
	}
	~List()
	{
		ListNode* cur = _head->_next;
		while (cur != _head)
		{
			ListNode* next = cur->_next;
			delete cur;
			cur = next;
		}
		delete _head;
		_head = nullptr;
	}
private:
	ListNode* _head;
};

int main()
{
	List l;
	return 0;
}


//class Test
//{
//public:
//	Test(int date = 0)
//		:_date(date)
//	{
//		cout << "Test()" << endl;
//	}
//
//	~Test()
//	{
//		cout << "~Test()" << endl;
//	}
//
//private:
//	int _date;
//};
//int main()
//{
//	/*int* ptr = new int;
//	int* ptr2 = new int[2];
//	int* ptr3 = new int(2);
//	delete ptr;
//	delete[] ptr2;
//	delete ptr3;*/
//
//	Test* p = (Test*)malloc(sizeof(Test*));
//	free(p);
//
//	Test* p2 = (Test*)malloc(sizeof(Test*) * 10);
//	free(p2);
//
//	Test* p3 = new Test;
//	delete p3;
//
//	Test* p4 = new Test[10];
//	delete[] p4;
//
//	return 0;
//}