#include<stdio.h>
FILE * a = fopen("PrintCodeSelf.cpp", "r");
int main()
{
    char c;
    /*
    ºÜ¶à´úÂë¡£¡£¡£
    */

    while (!feof(a))
    {
        c = fgetc(a);
        putchar(c);
    }
    getchar();
}