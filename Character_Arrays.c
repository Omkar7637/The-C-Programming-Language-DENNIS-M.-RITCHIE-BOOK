#include<stdio.h>

#define maxline 1000    /*  maximum input line size */

int mygetline(char line[], int lim);
void copy(char to[],char from[]);

/*  print longest input line    */

int main()
{
    int len;    //  current line length
    int max;    //  maximum length seen so far
    char line[maxline]; // currentr inputr line
    char longest[maxline];  //longest line saved here

    max = 0;

    while((len = mygetline(line,maxline)) > 0)
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    if (max > 0)    //there was a line 
    {
        printf("%s",longest);
    }
    return 0;
}

// getline: read a line into s, return length

int mygetline(char line[], int lim)
{
    int c, i;

    for(i = 0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
    {
        line[i] = c;
    }
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

// copy: copy 'from' into 'to' ; assume to i sbig enough

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i])!= '\0')
        ++i;
}
