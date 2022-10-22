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
	Person p = s;//对象赋值
	Person* pp = &s;//指针赋值
	Person& rp = s;//引用赋值

	//s = p;基类不能赋值给派生类

	//基类的指针通过强制类型转换赋值给派生类指针
	pp = &s;
	student* ps1 = (student*)pp;
	ps1->_stuid = 10;

	pp = &p;
	student* ps2 = (student*)pp;//为什么会存在越界访问，但是上面的却不会
	ps2->_stuid = 10;;

	return 0;
}