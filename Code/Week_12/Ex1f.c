#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char a[10], b[10], c[10];
} colors;

void func(colors*);

int main(void)
{
    colors sample = {"blue", "green","red"};
    colors *ptr = &sample;
    printf("%s %c\n", sample.a, ptr->b[2]);
    func(ptr);
    printf("%s %s %c\n", (*ptr).a, ptr->b+1, ptr->c[2]);

    return 0;
}

void func(colors *pt)
{
    strcpy(pt->a, "silver");
    strcpy(pt->b, "purple");
}
