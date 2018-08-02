#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum { clubs, diamonds, hearts, spades } Suit;

typedef struct card {
    int pips;
    Suit suit;
} Card;

void question3();
void question4();
void funct(int * p, int num);
void question5();
void assignCard(Card * c, int p, Suit s);

int main()
{
    question3();
    /* question4(); */
    /* question5(); */

    return EXIT_SUCCESS;
}

void question3()
{
    int x[8] = {10, 20, 30, 40, 50, 60, 70, 80};

    printf("%d \n", x);
    printf("%p \n", x);
    printf("%p \n", x + 2);
    printf("%d \n", *x);
    printf("%d \n", *x + 2);
    printf("%d \n", *(x + 2));
}

void question4()
{
    int a[5] = {10, 20, 30, 40, 50};

    funct(a + 3, 2);
}

void funct(int * p, int num)
{
    int i, sum = 0;

    for(i = 1; i < num; ++i)
        sum += *(p + i);

    printf("sum=%d\n", sum);
}

void question5()
{
    Card myCard;

    assignCard(&myCard, 2, clubs);
    printf("pips: %d suit: %d \n", myCard.pips, myCard.suit);
}

void assignCard(Card * c, int p, Suit s)
{
    c->pips = p;
    c->suit = s;
}
