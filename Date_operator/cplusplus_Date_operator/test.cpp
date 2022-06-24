#define _CRT_SECURE_NO_WARNINGS 1

#include "Date.h"


void Test1()
{
	//���ָ�ֵ�뿽�����캯�������
	Date d1(2022, 5, 19);
	Date d2 = d1;
	//���Բ鿴�������д�����ʵ�ǰ����д���ķ�ʽִ�е�Date d2(d1);

	Date d3;
	Date d4;
	d3 = d4;//���д���ŵ��������ظ�ֵ����������
}

void Test2()
{
	//����==��!=��=��>��>=��<��<=
	Date d1(2022, 5, 19);
	Date d2(2022, 5, 19);
	Date d3(2023, 6, 19);
	Date d4(2022, 6, 29);
	if (d1 == d2)
	{
		cout << "==" << endl;
	}
	if (d2 != d3)
	{
		cout << "!=" << endl;
	}
	if (d3 > d4)
	{
		cout << ">" << endl;
	}
	if (d2 < d4)
	{
		cout << "<" << endl;
	}
	if (d3 >= d4)
	{
		cout << ">=" << endl;
	}
	if (d2 <= d4)
	{
		cout << "<=" << endl;
	}

	//ע��<<��<���ȼ�
	cout << (d1 < d2) << endl;
	cout << (d1 >= d2) << endl;
	cout << (d1 <= d2) << endl;
	cout << (d1 == d2) << endl;
	cout << (d1 != d2) << endl;
	cout << (d1 > d2) << endl;
}

void Test3()
{
	//����+��+=��-��-=
	Date d1(2022, 5, 18);
	Date d2(2022, 5, 19);
	Date d3(2022, 5, 20);
	Date d4(2022, 5, 21);

	d2 = d1 + -10000;
	d1.Print();
	d2.Print();

	d2 = d1 - -10000;
	d1.Print();
	d2.Print();

	d3 += 10000;
	d3.Print();
	
	d4 -= 10000;
	d4.Print();
}

void Test4()
{
	Date d1(2022, 2, 28);
	Date d2(2022, 5, 21);

	d2 = d1--;
	d1.Print();
	d2.Print();

	d2 = d1++;
	d1.Print();
	d2.Print();

	d2 = ++d1;
	d1.Print();
	d2.Print();

	d2 = --d1;
	d1.Print();
	d2.Print();
}

void Test5()
{
	Date d1(2022, 5, 18);
	Date d2(2022, 3, 6);
	
	cout << (d2 - d1) << endl;
}

//��������cin��cout
void Test6()
{
    Date d1;
    cin >> d1;
    cout << d1;
}

int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();
    Test6();
	return 0;
}
