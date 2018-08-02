#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void question3();
void question4();
void question5();

int main()
{
    question3();
    /* question4(); */
    /* question5(); */

    return EXIT_SUCCESS;
}

void question3()
{
    char * result;
    char line[12];

    printf("Enter your input: ");
    result = fgets(line, sizeof(line), stdin);
    printf("'%s' \n", result);

    /* abcdefghij */
    /* abcdefghijkl */
}

void question4()
{
    const char * day[] =
    {
        "Sunday", "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday"
    };
    int dayNum;

    printf("Please enter a day number (0-6): ");
    scanf("%d", &dayNum);
    printf("That day is %s\n", day[dayNum]);
}

void question5()
{
    char name[10];
    char colour[10];

    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Please enter your favourite colour: ");
    scanf("%s", colour);

    printf("Thank you, %s. ", name);

    if(!strcmp(colour, "Red"))
        printf("Red is a good colour.\n");
    else
        printf("%s is an okay colour.\n", colour);
}
