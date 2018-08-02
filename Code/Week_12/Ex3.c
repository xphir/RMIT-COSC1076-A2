#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 40

typedef struct book
{
    char bookTitle[MAX_LENGTH];
    char authorName[MAX_LENGTH];
    char publisher[MAX_LENGTH];
    int isPublished;
    char date[MAX_LENGTH];
    int edition;
    int copiesInStock;
    double prices;
    int isBestSeller;
    struct book * next;
} Book;

typedef struct catalogue
{
    Book * head;
    int totalBooks;
    int bestSellers;
} Catalogue;

void AddBook(Catalogue * cat, Book * book)
{
    Book * prev, * curr;

    book->next = NULL;

    prev = NULL;
    curr = cat->head;
    while(curr != NULL)
    {
        if(strcmp(book->bookTitle, curr->bookTitle) < 0) {
            break;
        }

        prev = curr;
        curr = curr->next;
    }

    if(cat->head == NULL) {
        cat->head = book;
    }
    else if(prev == NULL) {
        book->next = cat->head;
        cat->head = book;
    } else {
        prev->next = book;
        book->next = curr;
    }

    cat->totalBooks++;
    if(book->isBestSeller) {
        cat->bestSellers++;
    }
}

void countBestSellers(Catalogue *cat)
{
    Book * book;
    int bestSellers;

    bestSellers = 0;
    book = cat->head;
    while(book != NULL)
    {
        if(book->isBestSeller) {
            bestSellers++;
            printf("%s %s %s \n", book->bookTitle, book->authorName, book->date);
        }

        book = book->next;
    }

    cat->bestSellers = bestSellers;
}

int main(void)
{
    return 0;
}
