#include<stdio.h>

#define Max_word_length 20 

int main()
{
    int c, word_len = 0;

    int count[Max_word_length+1]={0};

    while((c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\n' || c == '\t')
        {
            if(word_len > 0 && word_len <= Max_word_length)
            {
                ++count[word_len];
            }
            word_len = 0;
        }
        else
        {
            ++word_len;
        }

    }

    printf("\n Horizontal histogram\n");

    for(int i= 1; i<=Max_word_length;++i)
    {
        if(count[i]>0)
        {
            printf("%d: ",i);
            for(int j = 0; j<count[i];++j)
            {
                putchar('*');
            }
            printf("\n");
        }

    }

}