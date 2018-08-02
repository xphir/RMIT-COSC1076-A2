#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int find_pattern(char * pattern, char * given_string)
{
    int i;

    for(i = 0; i < strlen(given_string); i++)
    {
        int j, matched;

        matched = 0;
        for(j = 0; i + j < strlen(given_string) && j < strlen(pattern); j++)
        {
            if(tolower(pattern[j]) != tolower(given_string[i + j])) {
                break;
            }
            matched++;
        }

        if(strlen(pattern) == matched) {
            return 1;
        }
    }

    return 0;
}

int main(int argc, char ** argv)
{
    char input[100];
    char * pattern;

    if(argc != 2) {
        printf("Need to pass pattern! \n");
        return 0;
    }
    pattern = argv[1];

    while(1)
    {
        if(fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }
        if(find_pattern(pattern, input) == 1) {
            printf("Pattern found. :) \n");
        } else {
            printf("No pattern found. :( \n");
        }
    }

    return 0;
}
