#include<stdio.h>

#define tab 4

int main()
{
    int c,count = 0, space = 0;

    while((c = getchar()) != EOF)
    {
        if(c == '\t')
        {
            space = tab - ( count % tab);

            while(space > 0)
            {
                putchar('-');
                count++;
                space--;
            }
        }
        else
        {
            putchar(c);
            count++;
        }

        if(c == '\n')
        {
            count = 0;
        }
    }
    return 0;
}