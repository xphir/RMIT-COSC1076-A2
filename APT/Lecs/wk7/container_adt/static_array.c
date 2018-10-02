#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "container.h"

#define DEFAULT_SIZE 10

struct container {
    int data[DEFAULT_SIZE];
    size_t count;
    size_t size;
};

struct container *container_new ()
{
    struct container *new_container;

    new_container = malloc(sizeof(struct container));
    if (new_container == NULL) {
        perror("container_new: new_container malloc");
        exit(EXIT_FAILURE);
    }

    new_container->count = 0;

    new_container->size = DEFAULT_SIZE;

    return new_container;
}

int container_insert (struct container *container, int data)
{
    size_t i;

    assert(container != NULL);

    if (container->count == container->size) {
        fprintf(stderr, "Failed to insert '%d' -- container is full\n", data);
        return 1;
    }

    i = container->count;

    while (i > 0 && data < container->data[i - 1]) {
        container->data[i] = container->data[i - 1];
        i--;
    }

    container->data[i] = data;

    container->count++;

    return 0;
}

void container_print (struct container *container)
{
    size_t i;

    assert(container != NULL);

    for (i = 0; i < container->count; i++)
        printf("%d ", container->data[i]);

    printf("\n");
}

void container_free (struct container *container)
{
    assert(container != NULL);

    free(container);
}

size_t container_size (struct container *container)
{
    assert(container != NULL);

    return container->count;
}
