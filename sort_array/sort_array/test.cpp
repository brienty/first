#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v;
	int number = 0;
	int num = 0;
	while (cin >> number >> num)
	{
		if (number == 0 && num == 0)
			break;
		v.resize(number, 0);
		for (int i = 0; i < number; ++i)
		{
			int ret = 0;
			cin >> ret;
			v[i] = ret;
		}
		
		v.push_back(num);
		sort(v.begin(), v.end());
		for (auto e : v)
			cout << e << " ";
	}
	return 0;
}