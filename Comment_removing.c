#include <stdio.h>

int main() {
    int in_single_quote = 0; 
    int in_double_quote = 0; 
    int in_comment = 0;      
    int c, prev = 0;         
    while ((c = getchar()) != EOF) 
    {       
        if (c == '\'' && !in_double_quote && !in_comment) 
        {
            in_single_quote = !in_single_quote; 
            putchar(c); 
        }        
        else if (c == '\"' && !in_single_quote && !in_comment) 
        {
            in_double_quote = !in_double_quote; 
            putchar(c); 
        }
        else if (c == '/' && prev == '*') 
        {
            in_comment = 0; 
        }
        else if (c == '*' && prev == '/') 
        {
            in_comment = 1; 
        }
        else if (c == '/' && prev == '/') 
        {
            while (c != '\n' ) {
                c = getchar();
            }
            prev = c;
            putchar(c);
        }
        else if (!in_comment) {
            putchar(c); 
        }
        prev = c;
    }
    
    return 0;
}
