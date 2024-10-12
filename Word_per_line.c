#include<stdio.h>

/*  write a program that prints its input one word per line */

int main()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            putchar('\n');
        }
        else{
            putchar(c);
        }
    }
}