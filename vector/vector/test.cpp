#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void test1()
{
	//�޲ι��첢β������
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	
	vector<double> v2;
	v2.push_back(1.1);
	v2.push_back(2.1);
	v2.push_back(3.1);
	v2.push_back(4.1);

	vector<string> s;
	s.push_back("aaa");
	s.push_back("bbb");
	s.push_back("ccc");
	s.push_back("ddd");

	//�õ�������ʼ��
	string s1("hello world!");
	vector<char> v3(++s1.begin(), --s1.end());

	//�вι��죬��ָ�������ݸ�������
	vector<int> v4(3, 2);

}

void test2()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);

	//����
	//�±�+[]
	for (size_t i = 0; i < v1.size(); ++i)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	//������
	vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		*it -= 1;
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//��Χfor
	for (auto& n : v1)
	{
		n += 1;
		cout << n << " ";
	}
	cout << endl;
}

void test3()
{
	size_t sz;
	vector<int> v;
	//֪�����ݵĴ�С��resize����reserve
	//v.resize(100);��Ҫ��ʼ������resize����Ϊ��ı�size
	v.reserve(100);//ֻ��Ҫ������reserve��ֻ�ı�����
	sz = v.capacity();
	cout << "making v grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}

	//ֻ�ı�size
	v.resize(10);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	//���ݣ��ı�capacity
	v.shrink_to_fit();
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}

void test4()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	v.insert(v.begin() + 6, -1);//�������������ĺ�һ��λ�ò��룬���ǲ���Խ��
	for (auto n : v)
	{
		cout << n << " ";
	}
	cout << endl;

	v.erase(v.begin(), v.end() - 7);//ע�ⲻ��Խ��
	for (auto n : v)
	{
		cout << n << " ";
	}
	cout << endl;
}

void test5()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	vector<int>::iterator it = find(v.begin(), v.end(), 3);
	if (it != v.end())
	{
		v.erase(it);
	}
	v.push_back(6);
	v.push_back(9);
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);

	sort(v.begin(), v.end());//Ĭ�Ͻ���Ĭ�ϴ����ǽ���ķº���
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	sort(v.begin(), v.end(), greater<int>());//���򣬴�����ķº���
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	return 0;
}