#include <stdio.h>
#include <stdlib.h>

int main()
{
    char * source = "duplicate message";
    char * p1, * p2, destination[50];
    p1 = source;

    puts(p1);
    p2 = destination;
    while(*p2++ = *p1++)
        ;
    puts(p2);

    return EXIT_SUCCESS;
}
