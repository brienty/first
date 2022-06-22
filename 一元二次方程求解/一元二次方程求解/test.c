#define _CRT_SECURE_NO_WARNINGS 1
/*
从键盘输入a, b, c的值，编程计算并输出一元二次方程ax2 + bx + c = 0的根，
当a = 0时，输出“Not quadratic equation”，
当a ≠ 0时，根据△ = b2 - 4*a*c的三种情况计算并输出方程的根。

输入描述：
多组输入，一行，包含三个浮点数a, b, c，以一个空格分隔，表示一元二次方程ax2 + bx + c = 0的系数。

输出描述：
针对每组输入，输出一行，输出一元二次方程ax2 + bx +c = 0的根的情况。

如果a = 0，输出“Not quadratic equation”；

如果a ≠  0，分三种情况：
△ = 0，则两个实根相等，输出形式为：x1=x2=...。
△  > 0，则两个实根不等，输出形式为：x1=...;x2=...，其中x1  <=  x2。
△  < 0，则有两个虚根，则输出：x1=实部-虚部i;x2=实部+虚部i，即x1的虚部系数小于等于x2的虚部系数，实部为0时不可省略。
实部= -b / (2*a),虚部= sqrt(-△ ) / (2*a)所有实数部分要求精确到小数点后2位，数字、符号之间没有空格。

示例1
输入：
2.0 7.0 1.0
输出：
x1=-3.35;x2=-0.15
示例2
输入：
0.0 3.0 3.0
输出：
Not quadratic equation
示例3
输入：
1 2 1
输出：
x1=x2=-1.00
示例4
输入：
2 2 5
输出：
x1=-0.50-1.50i;x2=-0.50+1.50i
示例5
输入：
1 0 1
输出：
x1=0.00-1.00i;x2=0.00+1.00i
*/

#include<stdio.h>
#include<math.h>
int main()
{
    float a, b, c;
    while (scanf("%f %f %f", &a, &b, &c) != EOF)
    {
        double t = b * b - 4.0 * a * c;// 求解的△ 
        double x1 = (-b - sqrt(t)) / (2 * a);
        double x2 = (-b + sqrt(t)) / (2 * a);
        double s = -b / (2 * a);
        double x = sqrt(-t) / (2 * a);//实部与虚部
        if (a == 0.0)
            printf("Not quadratic equation\n");
        else if (t == 0)
        {
            //实数中有-0.0
            if (x1 == -0.00)
            {
                x1 = 0.00;
            }
            printf("x1=x2=%.2lf\n", x1);
        }

        else if (t > 0)
            printf("x1=%.2lf;x2=%.2lf\n", x1, x2);
        else if (t < 0)
            printf("x1=%.2lf-%.2lfi;x2=%.2lf+%.2lfi\n", s, x, s, x);
    }
    return 0;
}