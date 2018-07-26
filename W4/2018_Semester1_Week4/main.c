#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "windowsCompatibility.h"

void questions1to6();
void question7();
void question8();

int main()
{
    enableWindowsCompatibility();

    questions1to6();
    /* question7(); */
    /* question8(); */

    printf("Terminating. \n\n");

    return EXIT_SUCCESS;
}

void readRestOfLine()
{
    int ch;

    while(ch = getc(stdin), ch != '\n' && ch != EOF)
    { }

    clearerr(stdin);
}

typedef enum
{
    false = 0, true = 1
} bool;

#define INPUT_MAX_LENGTH 5
#define NEW_LINE_SPACE 1
#define NULL_SPACE 1
#define EXTRA_SPACES (NEW_LINE_SPACE + NULL_SPACE)

void questions1to6()
{
    /* char input[80 + 2]; */
    char input[INPUT_MAX_LENGTH + EXTRA_SPACES];

    while(true)
    {
        printf("Enter input up to %d characters: ", INPUT_MAX_LENGTH);

        fgets(input, sizeof(input), stdin);
        if(input[strlen(input) - 1] != '\n')
        {
            printf("Input was too long, try again. \n\n");
            readRestOfLine();
            continue;
        }
        /**
         * You can strip off the new line at the end of the string here if you want.
         * Typically you do because most of the time you don't want the \n to be processed.
         */
        input[strlen(input) - 1] = '\0';

        break;
    }
    printf("Your input was '%s' \n", input);
    printf("\n");
}

void question7()
{
    char string[] = "Hello World Bye World";
    char token1[100], token2[100], token3[100], token4[100];
    char * currentToken;
    int i;

    if(sscanf(string, "%s %s %s %s", token1, token2, token3, token4) != 4)
    {
        printf("sscanf failed. \n\n");
        exit(EXIT_FAILURE);
    }

    printf(
        "Token 1: %s \n"
        "Token 2: %s \n"
        "Token 3: %s \n"
        "Token 4: %s \n\n", token1, token2, token3, token4);

    i = 0;
    currentToken = strtok(string, " ");
    while(currentToken != NULL)
    {
        i++;
        printf("Token %d: %s \n", i, currentToken);
        currentToken = strtok(NULL, " ");
    }
    printf("\n");
}

void question8()
{
    char string[] = "105";
    char * stringEndPtr;
    int i;

    i = atoi(string);
    printf("i = %d \n", i);

    i = strtol(string, NULL, 10);
    printf("i = %d \n", i);

    i = strtol(string, &stringEndPtr, 10);
    if(string == stringEndPtr || *stringEndPtr != '\0')
    {
        printf("strtol failed. \n\n");
        exit(EXIT_FAILURE);
    }
    printf("i = %d \n\n", i);
}
