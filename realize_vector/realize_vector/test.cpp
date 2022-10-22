#define _CRT_SECURE_NO_WARNINGS 1
#include "vector.h"


void test1()
{
	myvector::vector<int> v;
	v.reserve(10);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	
	v.pop_back();
	v.resize(8);
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

void test2()
{
	myvector::vector<int> v;
	v.insert(v.begin(), 0);
	v.insert(v.begin(), 1);
	v.insert(v.begin(), 2);
	v.insert(v.begin(), 3);
	v.insert(v.begin(), 4);


	auto pos = find(v.begin(), v.end(), 4);
	cout << "size:capacity = " << v.size() << ":" << v.capacity() << endl;
	cout << *pos << endl;
	*pos = 10;
	cout << *pos << endl;

	//itָ����ģ��ظ�����-1��������ʧЧ��ʹ�÷���ֵ����������ڻ���ֳ��Ե�����
	myvector::vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		//��Ȼ��ʹ���ڲ�ʵ��ʱ��Ե�����ʧЧ���˴��������ⲿ��Ȼ���е�����ʧЧ������
		//����ʹ�õ���ֵ���ݣ�һ�����������ݣ�����pos(it)û�иı���Ȼָ��ɿռ䣬��Ȼ�����Խ���Ұָ�������ʧЧ������
		//��ʹ�ռ��㹻��Ȼ���������itָ��λ������ı䵼���ظ�����-1�����ֵ�����ʧЧ
		//ͨ��ʹ��ʹ�÷���ֵ������Ƚ����λ�õ����µ����⣬���ܷ�ֹ����ı䵼�µ�����ʧЧ�����⣬�����ڻ�������ݳ��Ե�����
		if (*it % 2 == 0)
		{
			it = v.insert(it, -1);
			++it;
		}
		++it;
	}
	cout << "size:capacity = " << v.size() << ":" << v.capacity() << endl;
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test3()
{
	//myvector::vector<int> v;
	vector<int> v;//ʹ��stl����ĳ���ֱ�ӱ���
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	//cout << "size:capacity = " << v.size() << ":" << v.capacity() << endl;
	//auto pos = find(v.begin(), v.end(), 2);
	//if (pos != v.end())
	//{
	//	v.erase(pos);
	//}
	//cout << *pos << endl;
	//*pos = 10;
	//cout << *pos << endl << endl;
	//cout << "size:capacity = " << v.size() << ":" << v.capacity() << endl;
	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;


	auto it = v.begin();
	while (it != v.end())
	{
		//eraseһ���ǲ������Ұָ�뵼�µĵ�����ʧЧ������
		//erase��ʧЧ����������ˣ����߲�����Ч����������Ч��Χ����Ϊһ�㲻��ʹ�����ݷ�����
		//ͨ��ʹ��ʹ�÷���ֵ������Ƚ����λ�õ����µ����⣬���ܷ�ֹ����ı䵼�µ�����ʧЧ�����⣬�����ڻ�������ݳ��Ե�����
		if (*it % 2 == 0)
		{
			v.erase(it);
			++it;
		}
		/*if (*it % 2 == 0)
		{
			it = v.erase(it);
		}
		else
		{
			++it;
		}*/
	}
	cout << "size:capacity = " << v.size() << ":" << v.capacity() << endl;
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test4()
{
	myvector::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	string s("hello");
	myvector::vector<int> v2(s.begin(), s.end());
	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;
	myvector::vector<int> v3(v);
	for (auto e : v3)
	{
		cout << e << " ";
	}
	cout << endl;
	myvector::vector<int> v4(v2);
	for (auto e : v4)
	{
		cout << e << " ";
	}
	cout << endl;
	v = v3;
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	//10��1�������Σ����漰�����������������������⣬���������һ��int���͵Ĺ��캯�������ƥ�亯������
	myvector::vector<int> v5(10, 1);
	//myvector::vector<char> v5(10, 'a');//ͨ�����﷢�ֲ���ƥ�������
	for (auto e : v5)
	{
		cout << e << " ";
	}
	cout << endl;
}

myvector::vector<vector<int>> generate(int numRows) {
	myvector::vector<vector<int>> vv;
	//��ʼ��vvǰnumRows
	vv.resize(numRows);
	//
	for (int i = 0; i < numRows; ++i)
	{
		vv[i].resize(i + 1, 0);
		vv[i][0] = vv[i][vv[i].size() - 1] = 1;
	}
	for (size_t i = 0; i < vv.size(); ++i)
	{
		for (size_t j = 0; j < vv[i].size(); ++j)
		{
			if (vv[i][j] == 0)
			{
				vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
			}
		}
	}

	for (size_t i = 0; i < vv.size(); ++i)
	{
		for (size_t j = 0; j < vv[i].size(); ++j)
		{
			cout << vv[i][j];
		}
		cout << endl;
	}
	cout << endl;
	return vv;
}

void test5()
{
	myvector::vector<vector<int>> vv = generate(5);
	for (size_t i = 0; i < vv.size(); ++i)
	{
		for (size_t j = 0; j < vv[i].size(); ++j)
		{
			cout << vv[i][j];
		}
		cout << endl;
	}
}

void test6()
{
	myvector::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	myvector::vector<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}

int main()
{
	/*test1();
	test2();
	test3();
	test4();
	test5();*/
	test6();
	return 0;
}