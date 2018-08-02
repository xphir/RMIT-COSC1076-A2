#include <stdio.h>
#include <stdlib.h>

static int i = 0;

/**
 * Explain storage classes - auto, register, extern and static.
 * Note the different meanings of static here.
 * 
 * Read more here:
 *     https://www.tutorialspoint.com/cprogramming/c_storage_classes.htm
 **/
static int times_called()
{
    static int times = 0;
    return ++times;
}

int main()
{
    printf("%d \n", times_called());
    printf("%d \n", times_called());
    printf("%d \n", times_called());
    printf("%d \n", times_called());

    return EXIT_SUCCESS;
}
