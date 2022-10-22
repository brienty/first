#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int main()
{
	double sum = 0.0;
	for (int i = 0; i < 12; ++i)
	{
		double d = 0.0;
		cin >> d;
		sum += d;
	}
	printf("$%.2lf", (sum / 12));
	return 0;
}