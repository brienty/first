#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using std::cout;
using std::cin;
using std::endl;


//������
class Date
{
public:

	//���캯������Ҫ�Լ�д������ʹ��Ĭ�ϵ�
	Date(int year = 1, int month = 1, int day = 1)
	{
		//��ֹ�Ƿ�����
		if (year > 0 && month > 0 && month < 13 && day > 0 && day <= Getmonthday(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "����Ƿ���" << endl;
		}
	}

	//�������������Բ����Լ�д������ʹ��Ĭ�ϵģ������Լ�д��Ϊ�˷���鿴Date d1 = d2 �� Date d1(d2) �Ƿ�һ��ֻ�ǵ����˿������캯��
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	//������������ʹ��Ĭ�ϵģ�����û����Դ��Ҫ����
	~Date()
	{
		_year = 1;
		_month = 1;
		_day = 1;
	}

	bool Isleapyear(const int& year)
	{
		//����һ�󣬰��겻���İ���һ��
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int Getmonthday(const int& year, const int& month)
	{
		//ע����ƽ�꣬ʹ��static������߳��������Ч��
		static int date[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30,30 };
		//���·���Ҫ���⴦��
		if (month == 2 && Isleapyear(year))
		{
			return 29;
		}
		else
		{
			return date[month];
		}
	}

	// ��ӡ����
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	//�е����������
	bool operator==(const Date& d2)
	{
		return ((this->_year == d2._year) && (this->_month == d2._month) && (this->_day == d2._day));
	}

	//�������������
	bool operator!=(const Date& d2)
	{
		//��ַЧ�ʸ���
		//return !(*this == d2);Ч�ʵ��£���Ҫ�������ص�==����������Ҫ����
		return !(this == &d2);
	}

	//��ֵ���������أ���ʵ��ֵ���������������з���ֵ�ģ���Ϊ��Ҫ֧��������ֵ
	Date& operator=(const Date& d2)
	{
		//����ֵ���Լ�
		if(this != &d2)
		{
			_year = d2._year;
			_month = d2._month;
			_day = d2._day;
		}
		
		//this�����٣�d1û�У���������û������
		return *this;
	}

	//С�ڲ���������
	bool operator<(const Date& d2)
	{
		if ((_year < d2._year) || 
			(_year == d2._year && _month < d2._month) ||
			(_year == d2._year && _month == d2._month && _day < d2._day))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//���ڲ���������
	bool operator>(const Date& d2)
	{
		if ((_year > d2._year) ||
			(_year == d2._year && _month > d2._month) ||
			(_year == d2._year && _month == d2._month && _day > d2._day))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//С�ڵ��ڲ���������
	bool operator<=(const Date& d2)
	{
		return !(*this > d2);
	}

	//���ڵ��ڲ���������
	bool operator>=(const Date& d2)
	{
		return !(*this < d2);
	}

	// ����+=����
	Date& operator+=(int day)
	{
		_day = _day + day;

	}

	// ����+����
	Date operator+(int day);

	// ����-����
	Date operator-(int day);

	// ����-=����
	Date& operator-=(int day);

	// ǰ��++
	Date& operator++();

	// ����++
	Date operator++(int);

	// ����--
	Date operator--(int);

	// ǰ��--
	Date& operator--();

private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1(2022, 3, 19);
	Date d2(2022, 2, 29);
	d1.Print();
	d2.Print();

	Date d3;
	//����ĸ�ֵ��������û�������ã�����ʹ�õĿ������캯��������
	Date d4 = d3;
	//���´��뿽����ʹ�������ظ�ֵ������
	Date d5(2022, 1, 1);
	Date d6;
	d6 = d5;
	d6.Print();
	d5.Print();
	if (d1 == d2)
	{
		cout << "==" << endl;
	}
	if (d1 != d2)
	{
		cout << "!=" << endl;
	}
	if (d1 <= d2)
	{
		cout << "<=" << endl;
	}
	if (d1 >= d2)
	{
		cout << ">=" << endl;
	}
	if (d1 < d2)
	{
		cout << "<" << endl;
	}
	if (d1 > d2)
	{
		cout << ">" << endl;
	}
	return 0;
}