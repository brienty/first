#include<stdio.h>
int main()
{
	char _y, _x, _t;
	_x = 'a';
	_y = 'A';
	_t = _y + 32;//在算出ASC码值的基础上加上整型数字

	printf("%d\n%d\n", 'a', 'A');
	printf("字母A转换为%c\n", _t);

	return 0;
}