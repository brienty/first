#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//判断闰年
bool isleapyear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    return false;
}

//获取每月天数
int getmonthday(int year, int month) {
    static int arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (isleapyear(year) && month == 2)
        return 29;
    return arr[month];
}

void Date(int date1, int date2) {
    int day1 = date1 % 100;
    int month1 = (date1 / 100) % 100;
    int year1 = date1 / 10000;
    int day2 = date2 % 100;
    int month2 = (date2 / 100) % 100;
    int year2 = date2 / 10000;
    int num = 0;
    if (year1 > year2) {
        while (year1 != year2 || month1 != month2 || day1 != day2) {
            if (day2 == getmonthday(year2, month2)) {
                ++month2;
                if (month2 > 12) {
                    ++year2;
                    month2 = 1;
                }
                day2 = 0;
            }
            ++day2;
            ++num;
        }
    }
    else if (year1 < year2) {
        while (year1 != year2 || month1 != month2 || day1 != day2) {
            if (day1 == getmonthday(year1, month1)) {
                ++month1;
                if (month1 > 12) {
                    ++year1;
                    month1 = 1;
                }
                day1 = 0;
            }
            ++day1;
            ++num;
        }
    }
    else {
        if (month1 > month2) {
            while (month1 != month2 || day1 != day2) {
                if (day2 == getmonthday(year2, month2)) {
                    ++month2;
                    day2 = 0;
                }
                ++day2;
                ++num;
            }
        }
        else if (month1 < month2) {
            while (month1 != month2 || day1 != day2) {
                if (day1 == getmonthday(year1, month1)) {
                    ++month1;
                    day1 = 0;
                }
                ++day1;
                ++num;
            }
        }
        else {
            if (day1 > day2) {
                while (day1 != day2) {
                    ++day2;
                    ++num;
                }
            }
            else if (day1 < day2) {
                while (day1 != day2) {
                    ++day1;
                    ++num;
                }
            }
            else {
                num = 0;
            }
        }
    }
    cout << num + 1;
}

int main() {
    int date1 = 0;
    int date2 = 0;
    scanf("%d %d", &date1, &date2);
    Date(date1, date2);
    return 0;
}