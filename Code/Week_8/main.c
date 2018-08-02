#include "intList.h"

int main()
{
    IntList intList;

    intList = createIntList();
    /* OR */
    initialiseIntList(&intList);

    while(true)
    {
        char input[100];
        int value;

        printf("Enter a number: ");

        fgets(input, sizeof(input), stdin);
        if(sscanf(input, "%d", &value) < 1)
        {
            break;
        }
        else if(value == 0)
        {
            printf("0 not supported. \n");
            continue;
        }

        if(value > 0)
        {
            bool success = insertIntList(&intList, value);
            if(success)
            {
                printf("Insert successful. \n");
            }
            else
            {
                printf("Insert failed. \n");
            }
        }
        else if(value < 0)
        {
            bool success = removeIntList(&intList, value * -1);
            if(success)
            {
                printf("Remove successful. \n");
            }
            else
            {
                printf("Remove failed. \n");
            }
        }
    }
    printf("\n");

    displayIntList(&intList);
    displayCsvIntList(&intList);

    return EXIT_SUCCESS;
}
