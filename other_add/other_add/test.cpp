#define _CRT_SECURE_NO_WARNINGS 1

//利用^其实无进位加法，&<<1则可以得到进位
class UnusualAdd {
public:
    int addAB(int A, int B) {
        //当B等于0时说明无需进位直接加
        while (B)
        {
            //无进位加法
            int tmp = A ^ B;
            //进位
            B = (A & B) << 1;
            //将无进位加法赋值给A继续下轮循环
            A = tmp;
        }
        //A即是加完后的值
        return A;
    }
};