/* This code is largely based off Edd Mann's blogpost
 * https://eddmann.com/posts/implementing-a-dynamic-vector-array-in-c/
 */

#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

int vector_init(vector_t *v)
{
    v->capacity = VECTOR_INIT_CAPACITY;
    v->total = 0;

    if (NULL == (v->items = malloc(sizeof(void *) * v->capacity)))
    {
        return -1;
    }

    return 0;
}

int vector_total(vector_t *v)
{
    return v->total;
}

static int vector_resize(vector_t *v, int capacity)
{
    void **items = realloc(v->items, sizeof(void *) * capacity);

    if (items) {
        v->items = items;
        v->capacity = capacity;
        return 0;
    }
    else
    {
        return -1;
    }
}

int vector_add(vector_t *v, void *item)
{
    int ret = 0;
    if (v->capacity == v->total)
        ret = vector_resize(v, v->capacity * 2);
    v->items[v->total++] = item;
    return ret;
}

int vector_set(vector_t *v, int index, void *item) {
    if (index >= 0 && index < v->total) {
        v->items[index] = item;
        return 0;
    }
    else
    {
        return -1;
    }
}

void *vector_get(vector_t *v, int index)
{
    if (index >= 0 && index < v->total)
        return v->items[index];
    return NULL;
}

int vector_delete(vector_t *v, int index)
{
    if (index < 0 || index >= v->total)
        return -1;

    v->items[index] = NULL;
    /* DANGER: memory leak possible here if the deleted item is not
     * deallocated afterwards.*/
    for (int i = index; i < v->total - 1; i++) {
        v->items[i] = v->items[i + 1];
        v->items[i + 1] = NULL;
    }

    v->total--;

    if (v->total > 0 && v->total == v->capacity / 4)
        vector_resize(v, v->capacity / 2);
}

void vector_free(vector_t *v)
{
    free(v->items);
}