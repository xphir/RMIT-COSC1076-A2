#include "intList.h"

IntList createIntList()
{
    IntList intList;

    intList.size = 0;
    /* OR */
    /* memset(&intList, 0, sizeof(intList)); */

    return intList;
}

void initialiseIntList(IntList * intList)
{
    intList->size = 0;
    /* OR */
    /* memset(intList, 0, sizeof(*intList)); */
}

bool insertIntList(IntList * intList, int value)
{
    int i, insertPosition;

    if(intList->size == INTLIST_SIZE)
    {
        return false;
    }

    /* Find position to insert into. */
    for(i = 0; i < intList->size; i++)
    {
        if(value < intList->list[i])
        {
            break;
        }
    }
    insertPosition = i;

    /* Shuffle values along. */
    intList->size++;
    for(i = intList->size - 1; i > insertPosition; i--)
    {
        intList->list[i] = intList->list[i - 1];
    }
    /* OR */
    /*
    memmove(&intList->list[insertPosition + 1], &intList->list[insertPosition],
           (intList->size - 1 - insertPosition) * sizeof(*intList->list));
    */

    intList->list[insertPosition] = value;

    return true;
}

bool removeIntList(IntList * intList, int value)
{
    int i, removePosition;

    if(intList->size == 0)
    {
        return false;
    }

    /* Find position to remove from. */
    for(i = 0; i < intList->size; i++)
    {
        if(value == intList->list[i])
        {
            break;
        }
    }
    if(i == intList->size)
    {
        return false;
    }

    removePosition = i;

    /* Shuffle values back. */
    for(i = removePosition; i < intList->size - 1; i++)
    {
        intList->list[i] = intList->list[i + 1];
    }
    /* OR */
    /*
    memmove(&intList->list[removePosition], &intList->list[removePosition + 1],
           (intList->size - 1 - removePosition) * sizeof(*intList->list));
    */

    intList->size--;

    return true;
}

void displayIntList(IntList * intList)
{
    int i;

    printf("IntList (size=%u): ", intList->size);
    for(i = 0; i < intList->size; i++)
    {
        printf("%d ", intList->list[i]);
    }
    printf("\n");
}

void displayCsvIntList(IntList * intList)
{
    int i;

    printf("IntList (size=%u): ", intList->size);
    for(i = 0; i < intList->size; i++)
    {
        printf("%d", intList->list[i]);
        if(i < intList->size - 1)
        {
            printf(", ");
        }
    }
    printf("\n");
}
