
#include "../../cpp_lib/cpp_lib/Stack.h"


bool isValid(char* s) {
    //创建结构体
    ST st;

    //将栈初始化
    StackInit(&st);

    while (*s)
    {
        //当是左括号时，入栈
        if (*s == '(' || *s == '[' || *s == '{')
        {
            StackPush(&st, *s);
            ++s;
        }
        //右括号则出栈检查对比匹配
        else
        {
            //当栈里没有数据但是还有右括号的时候，也是没有全部匹配
            if (Stacksize(&st) == 0)
            {
                //不匹配则销毁栈并返回
                StackDestroy(&st);
                return false;
            }
            //栈里还有数据
            STDataType ret = StackTop(&st);
            //检查对比匹配括号
            if ((ret == '(' && *s == ')') || (ret == '[' && *s == ']') || (ret == '{' && *s == '}'))
            {
                //对比检查后，出栈后的数据必须删除
                StackPop(&st);
                ++s;
            }
            //有一对括号不满足则结束
            else
            {
                //销毁并返回false
                StackDestroy(&st);
                return false;
            }
        }
    }

    //判断栈里是否还有数据，当栈里还有数据但是没有右括号匹配时，也不满足，需要返回false否则返回true
    STDataType ret = StackEmpty(&st);

    //返回前将栈销毁
    StackDestroy(&st);

    //返回true或者false
    return ret;
}

int main()
{
    printf("%d\n", isValid("[]"));
    return 0;
}