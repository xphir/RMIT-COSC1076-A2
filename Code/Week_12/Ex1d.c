#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *message[]={ "I'm", "all", "out", "of", "bubble", "gum" };
    
    puts(*message);
    puts(*(message+3));
    putchar(*(*(message+2)+2));
    putchar('\n');
    putchar(*(*(message+4)+4)+5);
    putchar('\n');

    return 0;
}
