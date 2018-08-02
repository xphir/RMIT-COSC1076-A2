#include <stdio.h>
#include <stdlib.h>

/**
 * The issue here is implicit declaration. If a function is not known when
 * it is called, we assume it returns an int which is often not the case
 * - it is not the case here for example.
 * 
 * The solution to this problem is the use of function prototypes.
 **/
int main()
{
    g();
    return EXIT_SUCCESS;
}

double g()
{
    return f();
}

double f()
{
    return g();
}
