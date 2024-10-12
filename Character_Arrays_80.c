#include<stdio.h>

#define maxline 1000    /*  maximum input line size */

int mygetline(char line[], int lim);
void copy(char to[],char from[]);

/*  print longest input line    */

int max=0;    //  maximum length seen so far

int main()
{
    int len;    //  current line length
    char line[maxline]; // currentr inputr line
   

    while((len = mygetline(line,maxline)) > 0)
        if (len > max)
        {
            printf("%s",line);
        }
    return 0;
}

// getline: read a line into s, return length

int mygetline(char line[], int lim)
{
    int c, i;

    for(i = 0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
    {
        if(c == ' ')
        {
            --i;
        }
        else{
        line[i] = c;
        }
    }
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}
