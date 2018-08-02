#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int i = 0;
    while (i < 3) {
        switch(i++) {
            case 0 : printf("Merry");
            case 1 : printf("Merr");
            case 2 : printf("Mer");
            default: printf("Oh no!");
        }
        putchar('\n');
    }

    return 0;
}
