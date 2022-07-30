#define _CRT_SECURE_NO_WARNINGS 1

//#include <iostream>
//#include <string>
//using namespace std;
//
//bool isnum(int num, int square)
//{
//    while (num)
//    {
//        int remainder1 = num % 10;
//        int remainder2 = square % 10;
//        if (remainder1 != remainder2)
//            return false;
//        num /= 10;
//        square /= 10;
//    }
//
//    return true;
//}
//
//int main()
//{
//    int input = 0;
//    cin >> input;
//    int count = 0;
//    for (int i = 0; i <= input; ++i)
//    {
//        int square = i * i;
//        if (isnum(i, square))
//        {
//            ++count;
//        }
//    }
//
//    cout << count << endl;
//}

#include <iostream>
#include <math.h>
using namespace std;

bool isprime(int num)
{
    for (int i = 2; i <= sqrt(num); ++i)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

int main()
{
    int input = 0;
    cin >> input;
    int count = 0;
    for (int i = 2; i < input; ++i)
    {
        if (isprime(i))
            ++count;
    }

    cout << count << endl;
    return 0;
}