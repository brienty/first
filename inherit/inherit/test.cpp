#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	void Print()
	{
		cout << _name << endl;
		cout << _age << endl;
	}
protected:
	string _name ;
	string _gender;
	int _age;
};

class student : public Person
{
public:
	int _stuid;
};

int main()
{
	student s;
	Person p = s;//����ֵ
	Person* pp = &s;//ָ�븳ֵ
	Person& rp = s;//���ø�ֵ

	//s = p;���಻�ܸ�ֵ��������

	//�����ָ��ͨ��ǿ������ת����ֵ��������ָ��
	pp = &s;
	student* ps1 = (student*)pp;
	ps1->_stuid = 10;

	pp = &p;
	student* ps2 = (student*)pp;//Ϊʲô�����Խ����ʣ����������ȴ����
	ps2->_stuid = 10;;

	return 0;
}