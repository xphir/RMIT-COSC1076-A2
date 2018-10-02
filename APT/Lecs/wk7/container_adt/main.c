#include <stdlib.h>
#include <stdio.h>

#include "container.h"

int main (int argc, char **argv)
{
    struct container *container;
    int i;

    int value;
    char *ptr;

    if (argc < 2) {
        fprintf(stderr, "usage: %s <sequence of integers ...>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    container = container_new();

    for (i = 1; i < argc; i++) {
        value = strtol(argv[i], &ptr, 10);

        if (*ptr != '\0') {
            fprintf(stderr, "Error: '%s' is not a valid integer\n", argv[i]);
            continue;
        }

        container_insert(container, value);
    }

    container_print(container);

    container_free(container);

    return EXIT_SUCCESS;
}
