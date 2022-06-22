#include<stdio.h>
int main()
{
	float _it, _iy, _iu;
	_iu = 3.0;//注意加小数点，单精度浮点型需小数点
	_iy = 2.0;
	_it = _iy / _iu;

	printf("%f\n", _it);

	return 0;
}