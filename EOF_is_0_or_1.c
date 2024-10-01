#include<stdio.h>

/*  verify that the expersion getchar() != EOF is 0 or 1.   */

main()
{
    int a = (getchar() != EOF);
    printf("%d",a); 
}