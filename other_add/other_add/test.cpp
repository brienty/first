#define _CRT_SECURE_NO_WARNINGS 1

//����^��ʵ�޽�λ�ӷ���&<<1����Եõ���λ
class UnusualAdd {
public:
    int addAB(int A, int B) {
        //��B����0ʱ˵�������λֱ�Ӽ�
        while (B)
        {
            //�޽�λ�ӷ�
            int tmp = A ^ B;
            //��λ
            B = (A & B) << 1;
            //���޽�λ�ӷ���ֵ��A��������ѭ��
            A = tmp;
        }
        //A���Ǽ�����ֵ
        return A;
    }
};