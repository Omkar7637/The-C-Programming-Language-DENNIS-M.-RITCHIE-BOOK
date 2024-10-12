#include<stdio.h>

#define column_width 80
#define max_line 1000

int main()
{
    char currentword[max_line];
    int i;
    for ( i = 0; i < max_line; ++i)
        currentword[i] = '\0';

    int c, length = 0, pos = 0;

    while((c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\t' || c == '\n')
        {
            currentword[pos] = '\0';

            if (length + pos > column_width)
            {
                printf("\n");
                length = 0;
            }

            printf("%s",currentword);
            putchar(c);

            if(c == '\n')
            {
                length = 0;
            }
            else
            {
                length += (c == '\t') ? 4 : 1;
            }
            pos = 0;
        }
        else
        {
            if (pos < max_line -1)
            {
                currentword[pos] = c;
                pos++;
            }
            length++;
        }
    }

    if(pos > 0)
    {
        currentword[pos] = '\0';
        printf("%s",currentword);
    }
    return 0;

}