#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

/*
	���ʸó��������Ƕ��٣�
	A 2
	B ��ѭ��
	C 173
	D 172
*/
// 7, 4, 1, 254...2, 255... 6, 3, 0
// 1  2  3   1    85  1     84 85
//3+85+85=173
void test1()
{
	unsigned char i = 7;
	int j = 0;
	for (; i > 0; i -= 3)
	{
		++j;
	}
	printf("%d\n", j);
}



/*
��Fibonacci���С�Fibonacci��������������ģ�
F[0] = 0
F[1] = 1
for each i �� 2: F[i] = F[i-1] + F[i-2]
��ˣ�Fibonacci���о����磺0, 1, 1, 2, 3, 5, 8, 13, ...��
��Fibonacci�����е������ǳ�ΪFibonacci��������һ��N�����������Ϊһ��Fibonacci����ÿһ�����
�԰ѵ�ǰ����X��ΪX-1����X+1�����ڸ���1һ����N��������Ҫ���ٲ����Ա�ΪFibonacci����
����������
����Ϊһ��������N(1 �� N �� 1,000,000)
���������
���һ����С�Ĳ�����ΪFibonacci��
ʾ��1��
����
15
���
2
*/
void test2()
{
	int n = 0;
	int a = 0;
	int b = 1;
	int c = a + b;
	int r = scanf("%d", &n);
	while (1)//ʹ��b��ʹ��a������
	{
		//n����b������0��
		if (n == b)
		{
			printf("%d\n", 0);
			break;
		}
		//nС��b�����ж���a��������b��
		else if(n < b)
		{
			//ʹ��n���������쳲���������ľ���ֵ����Ϊ���貽��
			if (abs(a - n) < abs(b - n))
			{
				printf("%d\n", abs(a - n));
				break;
			}
			else
			{
				printf("%d\n", abs(b - n));;
				break;
			}

		}
		//n����bʱ������������쳲�������
		a = b;
		b = c;
		c = a + b;
	}
}



/*
	��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20����
	���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy
*/
void test3(char* str, int length)
{
	//ͳ�ƿո��ַ�
	int count = 0;
	char* temp = str;
	while (*temp != '\0')
	{
		if (*temp == ' ')
		{
			count++;
		}
		temp++;
	}

	//ʹ��ָ��ѭ���������ÿ���
	int newlen = length + count * 2;
	int end1 = length - 1;
	int end2 = newlen - 1;

	//��%20�滻�ո�����end2׷����end1
	while (end1 != end2)
	{
		//�����ո�ʹ��%20�滻
		if (str[end1] == ' ')
		{
			str[end2--] = '0';
			str[end2--] = '2';
			str[end2--] = '%';
			end1--;
		}
		//�������������
		else
		{
			str[end2--] = str[end1--];
		}
	}
}




int main()
{
	test1();
	test2();
	
	char str[20] = "We Are Happy";                       
	test3(str, 13);
	printf("%s\n", str);
	return 0;
}
