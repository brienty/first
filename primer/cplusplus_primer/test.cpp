#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;//std�Ƿ�C++��������ռ�
//���Ҳ���Ǳ���Ҫ����Ϊ���������д�����ǰѱ�׼�����ȫ���ų����ˣ���Ȼ���㣬�������ײ�����ͻ

//using std::cout;
//����д����չ�������ռ����ﲿ�ֳ��õģ�����cout������endlû�зų�����ʹ��ʱendl����Ҫ�Լ��ų�����std::endl��
//using namespace test չ��test�����ռ���
//using namespace test2 չ��test2�����ռ���
//����չ��Ƕ����������ռ������߲��ܷ���������������չ��Ҳ�ǰ�һ��������չ��

//std::cout << "hello world" << std::endl;
//�����ǲ��ų������ȫ�ģ�����Ҳ�����鷳�ģ���ʹ�õ�ʱ��ų���

//�������������ռ���������� 
namespace test
{
	//����
	int f = 0;

	//����
	void fun()
	{

	}

	//����
	struct ListNode
	{
		int val;
		struct ListNode* next;
	};
}

//��ͬ���ֵ������ռ��ϲ�
namespace test
{
	int a = 0;
	//�����ռ��ǿ���Ƕ�׵�
	namespace test2
	{
		int a = 111;
	}
}

//int f = 0;ͬһ�����б������������

void fun()
{
	
}

int a = 100;

int f = 1;


void Test(int a = 10, int b = 20, int c = 30)
{
	cout << a << " " << b << " " << c << endl;
}

double Add(double d, double d2)
{
	return d + d2;
}

int Add(int t, int t2)
{
	return t + t2;
}

void test2(double d, int t)
{
	
}

void test1(int t , double d)
{
	
}


int main()
{
	//��ӡhello world
	cout << "hello world" << endl;

	//����ȫ�ֱ����;ֲ�������������������ͬ�ı������ֲ��������ȱ�����
	int a = 0;
	cout << a << endl;

	//����ʹ�������ռ�ķ�ʽ����ȫ�ֱ���
	cout << ::a << endl;//��::���ʲô��û�е�ʱ��Ĭ���Ƿ���ȫ����a����

	//���������ռ�����ı�������ȫ����������Ա�
	cout << f << endl;//�����޶�Ĭ����ȫ������ģ����������ռ����
	cout << test::f << endl;//���������ռ��޶������������ռ����

	//ʹ�������ռ����������
	struct test::ListNode val;
	val.val = 10;
	cout << val.val << endl;

	//���������ռ���ĺ�������ȫ����������Ա�
	cout << test::fun << endl;
	cout << fun << endl;

	//����Ƕ���������ռ���ı���
	cout << test::test2::a << endl;

	//�������
	double d;
	int t;
	char c;
	// >> ����ȡ�����
	//cin >> d >> t >> c;
	//// << �����������
	//cout << d <<" " << t << " " << c << endl;

	//ȱʡ����
	Test();
	Test(1);
	Test(1, 2);
	Test(1,2,3);

	//����������
	cout << Add(1, 2) << endl;
	cout << Add(1.1, 2.2) << endl;

	return 0;
}