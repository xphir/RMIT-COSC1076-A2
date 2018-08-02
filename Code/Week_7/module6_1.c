#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void rainfall_calc(int rainfall[SIZE], int cursize, int * sum, double * ave)
{
    int count;
    int lsum = 0;
    double lave;
    for(count = 0; count < cursize; ++count)
    {
        lsum += rainfall[count];
    }
    lave = lsum / (double) cursize;
    *sum = lsum;
    *ave = lave;
}

int main()
{
    int rainfall[SIZE] = { 3, 5, 10, 15 };
    int sum;
    double ave;

    rainfall_calc(rainfall, 4, &sum, &ave);

    printf("The total rainfall was %d and the average was %f\n", sum, ave);

    return EXIT_SUCCESS;
}
