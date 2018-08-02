#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void genericSumArray(void * base, unsigned numElts, unsigned sizeElt,
    void * out, void sum(const void * element, void * out))
{
    char * pointer = base;
    int i;

    for(i = 0; i < numElts; i++)
    {
        sum(pointer, out);
        pointer += sizeElt;
    }
}

void sumInt(const void * element, void * out)
{
    const int * intElement = element;
    int * intOut = out;

    *intOut += *intElement;
}

void sumDouble(const void * element, void * out)
{
    const double * doubleElement = element;
    double * doubleOut = out;

    *doubleOut += *doubleElement;
}

#define SIZE 5

int main()
{
    int intArray[SIZE] = { 2, 4, 5, 7, 9 };
    double doubleArray[SIZE] = { 2.1, 4.5, 5.7, 7.9, 9.2 };
    int intSum = 0;
    double doubleSum = 0;

    genericSumArray(intArray, SIZE, sizeof(*intArray), &intSum, sumInt);
    printf("Int sum: %d \n", intSum);

    genericSumArray(doubleArray, SIZE, sizeof(*doubleArray), &doubleSum, sumDouble);
    printf("Double sum: %f \n", doubleSum);

    return EXIT_SUCCESS;
}
