#include<stdio.h>

void reverse(char rev[1000]);
char array[1000];

int main()
{
    int c, i;

    for(i = 0; i<999 && (c = getchar()) != EOF && c != '\n';++i)
    {
        array[i] = c;
    }
    if(c == '\n')
    {
        array[i] = c;
        ++i;
    }
    array[i] = '\0';

    printf("%s",array);

    reverse(array);

    printf("%s",array);


    return 0;
}

void reverse(char rev[1000])
{
    int len = 0;

    while(rev[len]!= '\0')
        ++len;
    
    if(rev[len - 1] == '\n')
        --len;

    int start = 0;
    int end = len - 1;

    while(start < end)
    {
        char temp = rev[start];
        rev[start] = rev[end];
        rev[end] = temp;
        start++;
        end--; 
    }
}