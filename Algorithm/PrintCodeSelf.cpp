#include<stdio.h>
FILE * a = fopen("PrintCodeSelf.cpp", "r");
int main()
{
    char c;
    /*
    �ܶ���롣����
    */

    while (!feof(a))
    {
        c = fgetc(a);
        putchar(c);
    }
    getchar();
}