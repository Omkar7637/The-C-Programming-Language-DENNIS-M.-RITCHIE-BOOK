#include<stdio.h>

#define maxline 1000 // maximum input line size

int max ;   // maximum length seen so far

char line[maxline]; //current input line
char longest[maxline];  // longest line saved here

int mygetline(void);
void copy(void);

// print longest input line : spcialized version 

int main()
{
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while((len = mygetline()) > 0)
    {
        if (len > max)
        {
            max = len;
            copy();
        }
    }

    if(max > 0)
    {
        printf("%s", longest);
    }
    return 0;
}

// mygetline spacialized version 

int mygetline()
{
    int c, i;

    extern char line[];
    for(i = 0; i < maxline-1 && (c = getchar()) != EOF && c != '\n'; ++i)

    {
        line[i] = c;
        ++i; 
    }

    line[i] = '\0';

    return i;
}


// copy: specialized version

void copy(void)
{
    int i;
    extern char line[], longest[];

    i = 0;

    while((longest[i] = line[i]) != '\0')
    {
        ++i;
    }
}
