#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DISPLEN 3

struct counter
{
    int counter;
    char display[DISPLEN + 1];
};

typedef struct counter COUNTER_TYPE;

static void set_bad(COUNTER_TYPE * counter)
{
    strcpy(counter->display, "***");
}

static void copy_number(char * snum, int num)
{
    int count;
    for(count = DISPLEN - 1; count >= 0; --count)
    {
        snum[count] = '0' + num % 10;
        num /= 10;
    }
    snum[DISPLEN] = 0;
}

static void set_display(COUNTER_TYPE * counter)
{
    if(counter->counter < 0 || counter->counter > 999)
    {
        set_bad(counter);
    }
    else
    {
        copy_number(counter->display, counter->counter);
    }
}

void increment(COUNTER_TYPE * counter)
{
    counter->counter++;
    set_display(counter);
}

void decrement(COUNTER_TYPE * counter)
{
    counter->counter--;
    set_display(counter);
}

void reset(COUNTER_TYPE * counter)
{
    counter->counter = 0;
    set_display(counter);
}

int main()
{
    COUNTER_TYPE counterType;

    reset(&counterType);
    printf("%s\n", counterType.display);

    increment(&counterType);
    printf("%s\n", counterType.display);
    
    increment(&counterType);
    printf("%s\n", counterType.display);

    decrement(&counterType);
    printf("%s\n", counterType.display);

    decrement(&counterType);
    printf("%s\n", counterType.display);

    decrement(&counterType);
    printf("%s\n", counterType.display);

    return EXIT_SUCCESS;
}
