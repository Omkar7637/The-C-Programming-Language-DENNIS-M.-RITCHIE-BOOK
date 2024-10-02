#include<stdio.h>

/* Write a program to count blanks, tabs, and newlines  */

    
main()
{
    int c,nl=0,bl=0,tb=0;

    while((c = getchar()) != EOF)
    {
        if(c == ' ')
            ++bl;
        if(c == '\t')
            ++tb;
        if(c == '\n')
            ++nl;
    }    

    printf("Blanks = %d\n Tabs = %d\n Newlines = %d\n",bl,tb,nl);
}