#include "card.h"

int main()
{
    Card c;
    Hand hand;
    int i;
    
    c.pips = 2;
    c.suit = clubs;
    display(c);

    setHand(hand);
    for(i = 0; i < 4; i++)
    {
        display(hand[i]);
    }

    return EXIT_SUCCESS;
}

void display(Card c)
{
    char * suit;
    switch(c.suit)
    {
        case clubs:
            suit = "Clubs";
            break;
        case diamonds:
            suit = "Diamonds";
            break;
        case hearts:
            suit = "Hearts";
            break;
        case spades:
            suit = "Spades";
            break;
        default:
            assert(0);
    }
    printf("pips: %d suit: %s \n", c.pips, suit);
}

void setHand(Hand hand)
{
    int i = 0;
    hand[i].pips = 2;
    hand[i++].suit = clubs;
    hand[i].pips = 4;
    hand[i++].suit = diamonds;
    hand[i].pips = 6;
    hand[i++].suit = hearts;
    hand[i].pips = 8;
    hand[i++].suit = spades;
}
