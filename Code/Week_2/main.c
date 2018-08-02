#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[])
{
    int a, b, c;
    char string[] = "ello world";
    char character;

    a = 2;
    b = 4;
    c = a * b;

    printf("%d * %d = %d\n", a, b, c);

    character = 'H';

    printf("%c%s\n", character, string);

    return EXIT_SUCCESS;
}
