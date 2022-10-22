#define _CRT_SECURE_NO_WARNINGS 1
/*
        第n层的跳法等于第n-1层加第n-2层一直加到第一层只有一种跳法
        同理n-1层跳法也是如此，得到以下公式
        f(n) = f(n-1)+f(n-2)+...+1
        f(n-1) = f(n-2)+...+1
        相减后得到f(n)跳法的计算公式：
        f(n)=2*f(n-1)
    */
int jumpFloorII(int number) {
    //递归解决
    /*if(number == 1)
        return 1;
    return 2 * jumpFloorII(number-1);*/


    //迭代做法
    if (number == 1)
        return 1;
    //从第二项开始，没有第一项只能循环number-1次数
    int num1 = 1, num2 = 2;
    for (int i = 1; i < number; ++i) {
        num2 = 2 * num1;//计算当前项数的方法数
        num1 = num2;//计算完后给num1，进行下一次的计算
    }
    return num2;
}