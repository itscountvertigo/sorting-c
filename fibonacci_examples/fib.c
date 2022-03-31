/*
    Basic script that generates Fibonacci numbers as an example of C syntax
*/

#include<stdio.h>

void fibonacci(int max)
{
    int a = 0, b = 1, c;

    printf("0\n");
    printf("1\n");

    for (int i = 2; i < max; i++)
    {
        c = a + b;
        a = b;
        b = c;

        printf("%ld\n", c);
    }
}

void main()
{
    fibonacci(10);
}
