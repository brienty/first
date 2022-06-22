#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>



//print_the_number_of_9
/*int main()
{
	int i = 1;
	int j = 0;
	while (i >= 1 && i <= 100)
	{
		//if (i % 10 == 9 || i / 10 == 9)//it's false, because the number of 99 isn't calculated
		//{
		//	j++;
		//}
		if (i % 10 == 9)
		{
			j++;
		}
		if (i / 10 == 9)
		{
			j++;
		}
		i++;
	}
	printf("%d\n", j);

	return 0;
}*/



//Fractional_summation
//dosen't use math function
/*int main()
{
	int i = 1;
	int j = 1;
	double sum = 0.0;
	for (i = 1; i <= 100; i++)
	{
		double z = (1.0 / i) * j;
		j = -j;
		sum += z;
	}
	printf("%lf\n", sum);
	return 0;
}*/
//use_math_function
/*int main()
{
	int i = 1;
	double j = 1.0;
	double sum = 0.0;
	for (i = 1; i <= 100; i++)
	{
		double z = j / i * pow(-1, i + 1);
		sum += z;

	}
	printf("%lf", sum);
	return 0;
}*/



//Find_the_maximum_of_ten_numbers
/*int main()
{
	int arr[10];
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);//array element need & and the format is &array's name[element]
	}
	int j = 0;
	//max must behind, or 0 is given to max
	int max = arr[0];//Assuming that arr[0] is the maximum of number
	//int max = 0;//if all numbers are negative numbers, will appear 0
	for (j = 1; j < 10; j++)
	{
		if (max < arr[j])
		{
			max = arr[j];
		}
	}
		
	printf("最大值是：%d\n", max);
	return 0;
}*/


