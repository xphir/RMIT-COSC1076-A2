#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef enum { clubs, diamonds, hearts, spades } Suit;

typedef struct card
{
    int pips;
    Suit suit;
} Card;

typedef Card Hand[4];

void display(Card c);
void setHand(Hand hand);
