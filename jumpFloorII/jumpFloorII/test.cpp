#define _CRT_SECURE_NO_WARNINGS 1
/*
        ��n����������ڵ�n-1��ӵ�n-2��һֱ�ӵ���һ��ֻ��һ������
        ͬ��n-1������Ҳ����ˣ��õ����¹�ʽ
        f(n) = f(n-1)+f(n-2)+...+1
        f(n-1) = f(n-2)+...+1
        �����õ�f(n)�����ļ��㹫ʽ��
        f(n)=2*f(n-1)
    */
int jumpFloorII(int number) {
    //�ݹ���
    /*if(number == 1)
        return 1;
    return 2 * jumpFloorII(number-1);*/


    //��������
    if (number == 1)
        return 1;
    //�ӵڶ��ʼ��û�е�һ��ֻ��ѭ��number-1����
    int num1 = 1, num2 = 2;
    for (int i = 1; i < number; ++i) {
        num2 = 2 * num1;//���㵱ǰ�����ķ�����
        num1 = num2;//��������num1��������һ�εļ���
    }
    return num2;
}