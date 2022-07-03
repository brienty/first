#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;

//string
void test1() {
	cout << sizeof(char16_t) << endl;
	cout << sizeof(char32_t) << endl;
	cout << sizeof(wchar_t) << endl;
	string path = "C:\\";
	path += "a\\";
	path += "b\\";
	path += "c++";
	cout << path << endl;
}

//���죬��������
void test2() {
	string s1;
	string s2("hello");
	string s3(s2);
	string s4 = s3;
	string s5("abcdefghijklmnopqrstuvwxyz");
	string s6(s5, 5, 10);//��s5�е��±�Ϊ5����ʼ����10���ַ�
	string s7(s5, 5);//��s5�е��±�Ϊ5����ʼ���ƣ�ֱ��ȫ�����Ƶ�s7�У������һ�����ε����ֵ����

	string s8("213241", 5);//���±�Ϊ0��ʼ�����ַ������5���ַ���s8��
	string s9(2, 'x');//��2��x��ʼ��

	//string s10(s5, 30, 100);//Խ���׳��쳣
	string s11(s5, 4, 200);//���Ȳ���ȫ��ֻ�ܽ�ȫ���ַ������Ƽ���ֹ

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;
	cout << s7 << endl;
	cout << s8 << endl;
	cout << s9 << endl;
	cout << s11 << endl;
}

//string���ͻᱻ�������ַ��������ַ�����
void test3() {
	string s1("hello");
	string s2("xxx");
	s1 = s2;//��s2��s1����
	s1 = "yyy";//���ַ�����s1����
	s1 = 'y';//���ַ���s1����

	cout << s1 << endl;
}

//�ַ����ı���
void test4() {
	
	//��һ�ַ�ʽ���±�+[]
	string s1("hello world!");
	//size���ַ���������������ȡ�ַ����ĳ��ȣ�������\0
	for (size_t i = 0; i < s1.size(); ++i) {
		//�����[]�Ǳ�string���ع��ģ�ע��Խ����׳��쳣
		//s1.operator[].(i);
		cout << s1[i] << " ";
	}
	cout << endl;

	//�ڶ��ַ�ʽ�������� -------��ָ��һ���Ķ������߾���ָ��
	string s2("hello");
	string::iterator it = s2.begin();//begin��ȡ��һ���ַ��ĵ�����
	//end��ȡ���һ���ַ�����\0������һ��λ�õĵ�������begin��end�����䷶Χ������ҿ�
	while (it != s2.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//�����ַ�ʽ����Χfor ------ԭ���滻�ɵ�����
	string s3("world!");
	for (auto ch : s3) {
		cout << ch << " ";
	}
	cout << endl;
}

//ʹ�õ���������vector
void test5() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	vector<int>::iterator vit = v.begin();
	while (vit != v.end()) {
		cout << *vit << " ";
		++vit;
	}
	cout << endl;
}



//������\0��β�Ķ�̬�����ַ����飬����operator[]��������
namespace a {
	class string {
	public:
		//�ɶ���д���أ�ֵ�޸ķ��ض���
		char& operator[](size_t pos) {
			
			assert(pos <= _size);
			
			return _str[pos];
		}

		//ֻ������
		const char& operator[](size_t pos) const {
			
			assert(pos <= _size);
			
			return _str[pos];
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}

//operator[]��at����������
void test6() {
	string s1("hello");
	const string s2("hello");
	//s1[6];//Խ��ʹ�ö����д�
	//s2[6];ͬ��

	//s1.at(6);//Խ���׳��쳣
	//s2.at(6);//ͬ��

	s1[0] = 'x';
	//s2[0] = 'x';//const���β����޸�
	s1.at(0) = 'y';//s2ͬ��
}

//���ֵ��������ɶ���д������������ɶ���д�����������ֻ�������������ֻ�����������
//begin��end�������ıȽ�һ��ʹ��!=������һЩ�������ʹ��<����׼��
//begin��ȡ��һ���ַ��ĵ�������end��ȡ���һ���ַ�����\0������һ��λ�õĵ�������begin��end�����䷶Χ������ҿ���rbegin��rendͬ��
void test7() {
	string s1("hello world!");
	//�ɶ���д���������
	string::iterator sit = s1.begin();
	while (sit != s1.end()) {
		(*sit) += 1;
		cout << *sit << " ";
		++sit;
	}
	cout << endl;
	cout << s1 << endl;

	//�ɶ���д���������
	string::reverse_iterator rsit = s1.rbegin();
	while (rsit != s1.rend()) {
		(*rsit) -= 1;
		cout << *rsit << " ";
		++rsit;
	}
	cout << endl;
	cout << s1 << endl;



	const string s2("hello world");
	//ֻ�����������
	string::const_iterator sit2 = s2.begin();
	while (sit2 != s2.end()) {
		//(*sit2) += 1;//����
		cout << *sit2 << " ";
		++sit2;
	}
	cout << endl;

	//ֻ�����������
	string::const_reverse_iterator rsit2 = s2.rbegin();
	while (rsit2 != s2.rend()) {
		//(*rsit2) -= 1;//����
		cout << *rsit2 << " ";
		++rsit2;
	}
	cout << endl;
}

//��������
void test8() {
	string s("hello world!");
	cout << s.length() << endl;//�����ַ�������
	cout << s.size() << endl;//�����ַ�������
	cout << s.max_size() << endl;//�ɷ����ַ������ĳ���
	cout << s.capacity() << endl;//�ַ���������



	//�޳�ʼ������
	string s1;
	s1.reserve(100);//���ݲ���ʼ��
	s1.resize(100, 'x');//���ݳ�ʼ��
	cout << s1 << endl;

	//�鿴��vs�µ��������
	size_t sz = s.capacity();
	cout << "capacity:" << " " << sz << endl;
	for (size_t i = 0; i < 1000; ++i) {
		s.push_back('x');
		//������˵��������
		if (sz != s.capacity()) {
			sz = s.capacity();
			cout << "capacity:" << " " << sz << endl;
		}
	}

	//�г�ʼ������
	string s2("hello");
	s2.reserve(100);//ֻ����
	s2.resize(100, 'x');//��������油x
	cout << s2 << endl;

	//��vs��������������������
	s2.reserve(10);//��������
	s2.resize(10);//size��С���������䣬ֻ��s2���ӡ���x
	cout << s2 << endl;



	//�����ַ���������
	string s3;
	s3.push_back('x');//ֻ�����������ַ�
	s3.append("hello");//�����ַ���
	string s4("world");
	s3.append(s4);//�����ַ���
	cout << s3 << endl;

	//����Ϊ���·�����ʹ�����غ��+=
	string s5;
	s5 += 'x';
	s5 += "hello";
	string s6("world");
	s5 += s6;
	cout << s5 << endl;
}

int main() {
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	return 0;
}