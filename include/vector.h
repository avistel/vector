#ifndef CVECTOR_H
#define CVECTOR_H

#define VECTOR_INIT_CAPACITY 4

#define VECTOR_INIT(vec) vector_t vec; vector_init(&vec)
#define VECTOR_ADD(vec, item) vector_add(&vec, (void *) item)
#define VECTOR_SET(vec, id, item) vector_set(&vec, id, (void *) item)
#define VECTOR_GET(vec, type, id) (type) vector_get(&vec, id)
#define VECTOR_DELETE(vec, id) vector_delete(&vec, id)
#define VECTOR_TOTAL(vec) vector_total(&vec)
#define VECTOR_FREE(vec) vector_free(&vec)

typedef struct vector_t {
    void **items;
    int capacity;
    int total;
} vector_t;

int vector_init(vector_t *);
int vector_total(vector_t *);
static int vector_resize(vector_t *, int);
int vector_add(vector_t *, void *);
int vector_set(vector_t *, int, void *);
void *vector_get(vector_t *, int);
int vector_delete(vector_t *, int);
void vector_free(vector_t *);

#endif