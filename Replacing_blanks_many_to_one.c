#include <stdio.h>

/* Program to copy input to output, replacing multiple blanks with a single blank */

main() {
    int c;
    int flag = 0;  

while((c = getchar()) != EOF)
{
    if(c == ' ')
    {
        if(flag == 0)
        {
            putchar(c);
            flag = 1;
        }
    }
    else
    {
        putchar(c);
        flag = 0;
    }

}
}