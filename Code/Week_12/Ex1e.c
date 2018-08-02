#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int *xp, x;
    xp = &x;
    *xp = 1/2;
    
    printf("%d\n", x);

    return 0;
}
