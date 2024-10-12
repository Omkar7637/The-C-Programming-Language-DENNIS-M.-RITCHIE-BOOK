#include<stdio.h>

    /* print Fahrenheit-Celsius table for fahr = 0 ,20, ...., 300; floating-point version using function */

float converter(float a);

int main()
{
    float fahr, celsius;
    int lower, upper, step ;
    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while(fahr <= upper)
    {
        celsius = converter(fahr);
        printf("%3.0f %6.1f \n",fahr,celsius);
        fahr = fahr + step;
    }
}

float converter(float a)
{
    float fahr = a, celsius, b;
    b = (5.0/9.0) * (fahr-32.0);

    return b;

}