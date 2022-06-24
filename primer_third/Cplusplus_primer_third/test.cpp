#include <iostream>
#include <map>
#include <string>
using namespace std;


#include <time.h>
//struct A { 
//	int a[10000]; 
//};
//void TestFunc1(A a) {}
//
//void TestFunc2(A& a) {}
//
//void TestFunc3(A* a) {}
//
//void TestRefAndValue()
//{
//	A a;
//	// ��ֵ��Ϊ��������
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//
//	// ��������Ϊ��������
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	
//	// ��ָ����Ϊ����
//	size_t begin3 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc3(&a);
//	size_t end3 = clock();
//
//	// �ֱ���������������н������ʱ��
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//	cout << "TestFunc2(A&)-time:" << end3 - begin3 << endl;
//}

struct A { int a[10000]; };
A a;
// ֵ����
A TestFunc1() { return a; }
// ���÷���
A& TestFunc2() { return a; }
void TestReturnByRefOrValue()
{
	// ��ֵ��Ϊ�����ķ���ֵ����
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc1();
	size_t end1 = clock();
	// ��������Ϊ�����ķ���ֵ����
	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc2();
	size_t end2 = clock();
	// �������������������֮���ʱ��
	cout << "TestFunc1 time:" << end1 - begin1 << endl;
	cout << "TestFunc2 time:" << end2 - begin2 << endl;
}



void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}


void TestFor()
{
	//�����Զ�ȡarray�е����ݸ�ֵ��e���Զ��жϽ���
	int array[] = { 1, 2, 3, 4, 5 };
	for (auto& e : array)
		e *= 2;

	for (auto e : array)
		cout << e << " ";
}

//����
int main()
{
	/*int a = 1;
	int b = 2;
	cout << a << " " << b << endl;
	swap(a, b);
	cout << a << " " << b << endl;*/

	//int a = 10;
	//int& ra = a;
	//int& rra = ra;
	//int& rrra = ra;
	////��ַһ��
	//printf("%p %p %p %p\n", &a, &ra, &rra, &rrra);


	/*TestReturnByRefOrValue();

	double d = 1.1;
	double& c = d;
	cout << sizeof(c) << endl;*/

	int num = 10;

	int* pn = &num;
	*pn = 20;

	int& rn = num;
	rn = 20;


	int x = 10;
	const int y = 20;

	//�ƶ�û�д������ò�����������ָ��
	auto a = &x;
	auto a2 = &y;

	//�ƶϴ������ò�����������ָ��
	auto* b = &x;
	auto* b2 = &y;

	//�ƶ���������
	auto& c = x;
	auto& c2 = y;

	//��ӡ����
	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(a2).name() << endl;
	cout << typeid(b2).name() << endl;
	cout << typeid(c2).name() << endl;

	//������
	std::map<std::string, std::string>dict;
	dict["sort"] = "sort";
	dict["string"] = "string";
	std::map<std::string, std::string>::iterator it = dict.begin();

	TestFor();


	return 0;
}
//int TestAuto()
//{
//	return 10;
//}
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d = TestAuto();
//
//	//��ӡ����
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//
//	return 0;
//}