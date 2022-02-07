//
// Created by 1 on 06.02.2022.
//

#include "voidVector.h"
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

vectorVoid createVectorV (size_t n, size_t baseTypeSize) {
    void *data = NULL;
    if (n != 0)
        if ((data = malloc(sizeof(baseTypeSize) * n)) == NULL) {
            fprintf(stderr, "bad alloc, vector creation failed");
            exit(1);
        }

    return (vectorVoid) {data, 0, n, baseTypeSize};
}

static size_t min2(size_t a, size_t b) {
    return a < b ? a : b;
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity == 0)
        *v = (vectorVoid) {NULL, 0, 0, v->baseTypeSize};
    else {
        void *data;
        if ((data = (void *) realloc(v->data, v->baseTypeSize * newCapacity)) == NULL) {
            fprintf(stderr, "bad alloc, everything failed");
            exit(1);
        }

        *v = (vectorVoid) {data, min2(v->size, newCapacity), newCapacity, v->baseTypeSize};
    }
}

bool isEqualVectorsV(vectorVoid v1, vectorVoid v2) {
    if (v1.size != v2.size || v1.capacity != v2.capacity || v1.baseTypeSize != v2.baseTypeSize)
        return false;

    return memcmp(v1.data, v2.data, v1.baseTypeSize * v1.size) == 0;
}

void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
}


