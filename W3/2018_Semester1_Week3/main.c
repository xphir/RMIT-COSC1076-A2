#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int power(int base, int power)
{
    int total, i;

    total = 1;
    for(i = 0; i < power; i++)
    {
        total *= base;
    }

    return total;
}

int main()
{
    int i;
    for(i = 0; i <= 13; i++)
    {
        printf("2^%d = %d \n", i, power(2, i));
        /* OR - note you must include the compile flag "-lm" to use the math.h library. */
        /* printf("2^%d = %d \n", i, (int) pow(2, i)); */
        /* OR - note you must include the compile flag "-lm" to use the math.h library. */
        /* printf("2^%d = %.0f \n", i, pow(2, i)); */
    }

    return EXIT_SUCCESS;
}
