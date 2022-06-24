#pragma once
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Date
{
    friend std::ostream& operator<<(std::ostream& _out, const Date& d);
    friend std::istream& operator>>(std::istream& _in, Date& d);
public:
	//����Ĭ�Ϲ��캯��
	Date(int year = 1, int month = 1, int day = 1)
	{
		//�Ƿ����봦��
		if (year > 0 && month > 0 && month < 13 && day > 0 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "�����������������룡" << endl;
		}
	}
	//�����������Բ��ô������������캯��Ҳ���Բ��ô���
	//Ϊ�˷���鿴���ԣ��������ɿ������캯��
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	//ȡÿ������
	int GetMonthDay(const int& year, const int& month)const;

	//�����Ƿ�������
	bool Isleapyear(const int& year)const;



	//==����
	bool operator==(const Date& d)const;

	//=����
	Date& operator=(const Date& d);

	//<����
	bool operator<(const Date& d)const;

	// ����+=����
	Date& operator+=(int day);

	// ����-=����
	Date& operator-=(int day);

	// ����-���� ��������
	int operator-(const Date& d)const;



	//���¸����˺����ĺ������������ĺ���
	//!=����
	bool operator!=(const Date& d)const
	{
		//���õ���
		return (!(*this == d));
	}

	//<=����
	bool operator<=(const Date& d)const
	{
		//����<��==
		return ((*this) < d || (*this) == d);
	}

	//>����
	bool operator>(const Date& d)const
	{
		//����С�ڵ���
		return (!(*this <= d));
	}

	//>=����
	bool operator>=(const Date& d)const
	{
		//����С��
		return (!(*this < d));
	}




	// ����+����
	Date operator+(int day)const
	{
		//����ʹ��+����+=������+=����+��ԭ����+Ҫ�������ο�������+=���ÿ���
		//ͬʱ������������ʱ��ֻ�ÿ������ζ������ĴΣ�Ч�ʸ���

		//�����ܸ�
		Date ret = *this;

		ret += day;//����+=

		return ret;//ret�����٣�ֻ�ܴ�ֵ
	}

	// ����-����
	Date operator-(int day)const
	{
		Date ret = *this;

		ret -= day;//����-=

		return ret;
	}
	


	// ǰ��++
	Date& operator++()
	{
		*this += 1;//����+=

		return *this;
	}

	// ����++
	Date operator++(int)
	{
		Date ret = *this;

		*this += 1;//����+=

		return ret;
	}

	// ǰ��--
	Date& operator--()
	{
		*this -= 1;//����-=

		return *this;
	}

	// ����--
	Date operator--(int)
	{
		Date ret = *this;

		*this -= 1;//����-=

		return ret;
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	
private:
	int _year;
	int _month;
	int _day;
};
