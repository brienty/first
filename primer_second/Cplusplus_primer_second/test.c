
#include "../../cpp_lib/cpp_lib/Stack.h"


bool isValid(char* s) {
    //�����ṹ��
    ST st;

    //��ջ��ʼ��
    StackInit(&st);

    while (*s)
    {
        //����������ʱ����ջ
        if (*s == '(' || *s == '[' || *s == '{')
        {
            StackPush(&st, *s);
            ++s;
        }
        //���������ջ���Ա�ƥ��
        else
        {
            //��ջ��û�����ݵ��ǻ��������ŵ�ʱ��Ҳ��û��ȫ��ƥ��
            if (Stacksize(&st) == 0)
            {
                //��ƥ��������ջ������
                StackDestroy(&st);
                return false;
            }
            //ջ�ﻹ������
            STDataType ret = StackTop(&st);
            //���Ա�ƥ������
            if ((ret == '(' && *s == ')') || (ret == '[' && *s == ']') || (ret == '{' && *s == '}'))
            {
                //�Աȼ��󣬳�ջ������ݱ���ɾ��
                StackPop(&st);
                ++s;
            }
            //��һ�����Ų����������
            else
            {
                //���ٲ�����false
                StackDestroy(&st);
                return false;
            }
        }
    }

    //�ж�ջ���Ƿ������ݣ���ջ�ﻹ�����ݵ���û��������ƥ��ʱ��Ҳ�����㣬��Ҫ����false���򷵻�true
    STDataType ret = StackEmpty(&st);

    //����ǰ��ջ����
    StackDestroy(&st);

    //����true����false
    return ret;
}

int main()
{
    printf("%d\n", isValid("[]"));
    return 0;
}