#include<stdio.h>

#define tab 4

int main()
{
    int space_count = 0;
    int current_pos = 0;
    int c;

    while((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            ++space_count;
            ++current_pos;

            if(current_pos % tab == 0 && space_count % 4 == 0)
            {
                putchar('\t');
                space_count = 0;
            }
        }
        else if (c == '\n')
        {
            putchar('\n');
            current_pos = 0;
            space_count = 0;
        }
        else if (c == '\t')
        {
            putchar('\t');
            current_pos = current_pos + tab - (current_pos & tab);
            space_count = 0;
        }
        else
        {
            while(space_count > 0)
            {
                putchar(' ');
                --space_count;
                ++current_pos;
            }
            putchar(c);
            ++current_pos;
        }
    }
    return 0;
}