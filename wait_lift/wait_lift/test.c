#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(int argc, char** argv) {
    int n = 0;
    int t = 0;
    scanf("%d", &n);
    if (n < 12)
    {
        printf("%d\n", 2);
    }
    else
    {
        n /= 12;
        t = 2 + n * 4;
        printf("%d\n", t);
    }
    return 0;
}