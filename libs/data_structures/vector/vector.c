//
// Created by 1 on 01.02.2022.
//

#include "vector.h"
#include <stdlib.h>
#include <assert.h>

vector createVector(size_t n) {
    int *data = NULL;
    if (n != 0)
        if ((data = (int *) malloc(sizeof(int) * n)) == NULL) {
            fprintf(stderr, "bad alloc, vector creation failed");
            exit(1);
        }

    return (vector) {data, 0, n};
}

void outputVector (vector v) {
    if (v.size == 0)
        printf("{}\n");
    else {
        printf("{");
        for (size_t i = 0; i < v.size; i++)
            printf("%d, ", v.data[i]);
        printf("\b\b}\n");
    }
}

void inputVector (vector *v, size_t size) {
    if (size > v->capacity)
        reserve(v, size);

    for (size_t i = 0; i < size; i++)
        scanf("%d", &v->data[i]);

    v->size = size;
}

static size_t min2 (size_t a, size_t b) {
    return a < b ? a : b;
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0)
        *v = (vector) {NULL, 0, 0};
    else {
        int *data;
        if ((data = (int*) realloc(v->data, sizeof(int) * newCapacity)) == NULL) {
            fprintf(stderr, "bad alloc, everything failed");
            exit(1);
        }

        *v = (vector) {data, min2(v->size, newCapacity), newCapacity};
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    free(v->data);
}