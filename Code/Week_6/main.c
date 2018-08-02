#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBERS 10
#define MAX_LINE_LENGTH 1000

#define NULL_SPACE 1

int main(int argc, char ** argv)
{
    FILE * fp;
    char line[MAX_LINE_LENGTH + NULL_SPACE];
    int numbers[MAX_NUMBERS];
    int numbersLength;
    char * token;
    int sum, i;

    if(argc != 2)
    {
        printf("Must pass a file name as a command line parameter. \n\n");
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    if(fp == NULL)
    {
        printf("File '%s' could not be opened for reading. \n\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if(fgets(line, sizeof(line), fp) == NULL)
    {
        printf("Unable to read from file. \n\n");
        exit(EXIT_FAILURE);
    }
    fclose(fp);

    numbersLength = 0;
    token = strtok(line, ",");
    while(token != NULL)
    {
        char * tokenEndPtr;

        numbersLength++;
        if(numbersLength > MAX_NUMBERS)
        {
            printf("Too many tokens in file. \n\n");
            exit(EXIT_FAILURE);
        }

        numbers[numbersLength - 1] = strtol(token, &tokenEndPtr, 10);
        if(token == tokenEndPtr || *tokenEndPtr != '\0')
        {
            printf("Encountered corrupt data. \n\n");
            exit(EXIT_FAILURE);
        }

        token = strtok(NULL, ",");
    }

    sum = 0;
    for(i = 0; i < numbersLength; i++)
    {
        sum += numbers[i];
    }

    fp = fopen(argv[1], "w");
    if(fp == NULL)
    {
        printf("File '%s' could not be opened for writing. \n\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < numbersLength; i++)
    {
        fprintf(fp, "%d,", numbers[i]);
    }
    fprintf(fp, "%d", sum);
    fclose(fp);

    printf("Finished. \n\n");

    return EXIT_SUCCESS;
}
