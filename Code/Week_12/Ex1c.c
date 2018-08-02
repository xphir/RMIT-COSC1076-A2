#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *a[4];
    char b[2][10];
    char c[10];
    char *p = c;

    strcpy(b[0], "titan");
    strcpy(b[1], "saturn");
    strcpy(c, "jupiter");

    a[0] = b[1];
    a[1] = "gumtree";
    a[2] = p + 3;
    a[3] = c;

    printf("%s", a[1]);
    printf("%s %s", a[3], p);
    printf("%s %d", a[2], strlen(a[2]));
    printf("%c %s %c", a[3][3], *(a+2), *(*a+2));
    printf("%s %s %c", *(b+1), &p[3], *b[1]);

    return 0;
}
