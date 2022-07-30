#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

//�����ַ��������ַ�������������������ṹ���޷�����������λ�������ݴ�������������
void test1() {
	string s1("hello");
	s1.insert(0, 1, 'x');//���±�Ϊ0λ�ô�ǰ�����һ��x
	s1.insert(s1.begin(), 'y');//ʹ�õ��������±�Ϊ0λ�ô�ǰ�����һ��y
	cout << s1 << endl;

	s1.insert(3, 3, 'x');//���±�Ϊ3��λ�ô�ǰ�����3��x
	s1.insert(s1.begin() + 3, 'y');//ʹ�õ��������±�Ϊ3��λ�ô�ǰ�����һ��y��string�ĵ������ײ���ָ��ʵ�ֵ�
	cout << s1 << endl;

	s1.insert(0, "world ");//��0λ�ô�ǰ�����һ���ַ���
	cout << s1 << endl;
}

//ɾ���ַ������ַ���
void test2() {
	string s1("hello world!");
	s1.erase(1, 3);//���±�Ϊ1��ʼɾ�������ַ�
	cout << s1 << endl;

	s1.erase(s1.begin());
	cout << s1 << endl;//ʹ�õ�����ɾ���±�Ϊ0λ�ô����ַ�

	s1.erase(s1.begin()+2);//ʹ�õ�����ɾ���±�Ϊ2λ�ô����ַ�
	cout << s1 << endl;

	s1.erase(4);//ɾ���±�Ϊ4�����������ַ�
	//static const size_t npos = -1;
	//npos��Ĭ�ϴ�ɾ�����ȣ�Ĭ����-1�����������ֵ��ɾ�����ȴ��ڴ�ɾ���ַ���ʱ��ֻ�Ὣ������ַ�ɾ����ֹͣ
	cout << s1 << endl;
}

//�����ַ���
void test3() {
	string s1("hello world!");
	string s2("hello string!");

	s1.swap(s2);//Ч�ʸߣ���Ա����������ָ���ָ��
	cout << s1 << endl << s2 << endl;

	swap(s1, s2);//Ч�ʵͣ�ȫ�ֱ������������
	cout << s1 << endl << s2 << endl;
}

//stringת����C�����ַ���
void test4() {
	string s("hello wordl!");
	cout << s << endl;
	cout << s.c_str() << endl;//c_str()����C���Ե��ַ�����Ϊ�˸��õ���C������Ӧ
}

//find��rfind��substr��ʹ��
void test5() {

	//����find��rfind��substrȡ���ļ���׺
	string file1("string.cpp");
	string file2("string.c");
	string file3("string.c.tar.zip");//������Զ�����б�ǵĿ���ʹ��rfind�������һ�����

	string& file = file1;//����ʹ�����÷������

	size_t pos = file.find('.');//�����ַ����ҵ����� ���ַ��±꣬���򷵻�npos
	//size_t pos = file.rfind('.');//�����ַ����ҵ����� ���ַ��±꣬���򷵻�npos
	string suffix = file.substr(pos);//���������ַ�������Ĭ����npos
	if (pos != string::npos) {
		cout << suffix << endl;
	}else {
		cout << "�޺�׺" << endl;
	}



	//����substr��findȡ��url�е�Э�飬������uri(��Դ)
	string url1("http://www.cplusplus.com/reference/string/string/find/");
	string url2("https://leetcode.cn/problems/reverse-only-letters/submissions/");

	string& url = url1;//�������

	//�ҳ�Э�顢������uri
	string protocol;//Э��
	size_t pos1 = url.find("://", 0);
	if (pos1 != string::npos) {
		protocol = url.substr(0, pos1);
		cout << protocol << endl;
	}
	else {
		cout << "false" << endl;
	}

	string domain;//����
	size_t pos2 = url.find('/', pos1+3);//��w��ʼ�ң��ҵ�/ͣ��
	if (pos2 != string::npos) {
		domain = url.substr(pos1 + 3, pos2 - (pos1 + 3));//��һ����������ʼλ�ã��ڶ�������������
		cout << domain << endl;
	}
	else {
		cout << "false" << endl;
	}

	string uri;//��Դ
	uri = url.substr(pos2 + 1);
	cout << uri << endl;

}

int main() {
	test1();
	test2();
	test3();
	test4();
	test5();
	return 0;
}