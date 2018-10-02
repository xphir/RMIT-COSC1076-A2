/*
 * This program has deliberate errors.
 * Use gdb to assist you locating them.
 * Please note that you are unwise to
 * simply copy and paste from a pdf into a
 * text editor as some hidden characters that
 * impact on the compiler may be inserted.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i;
    int * intArray;
    char string[50];
    for(i = 0; i <= 10; i++)
    {
        intArray[i] = rand() % 10;
    }
    printf("''string'' is %i characters long\n", (int) strlen(string));
    strcpy(string, "This is a medium sized string");
    printf("''string'' is %i characters long\n", (int) strlen(string));
    return EXIT_SUCCESS;
}
