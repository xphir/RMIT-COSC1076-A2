#include <stdio.h>
#include <stdlib.h>

int main()
{
    char words[5][8] = { "the", "cat", "in", "the", "hat" };
    char * wp[5];
    int i;

    for(i = 0; i < 5; i++)
    {
        wp[i] = words[i];
    }

    puts(*wp);
    puts(*(wp + 2));
    puts(*(wp + 3) + 1);
    putchar(**(wp + 1));

    /* output:
     * the
     * in
     * he
     * c
     *
     * Again, take them through the reasoning about this. I like to 
     * emphasize that everything is a number and you are just adding on
     * to memory addresses.
     **/
    return EXIT_SUCCESS;
}
