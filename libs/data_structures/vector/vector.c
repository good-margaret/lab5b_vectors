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

void outputVector(vector v) {
    if (v.size == 0)
        printf("{}\n");
    else {
        printf("{");
        for (size_t i = 0; i < v.size; i++)
            printf("%d, ", v.data[i]);
        printf("\b\b}\n");
    }
}

void inputVector(vector *v, size_t size) {
    if (size > v->capacity)
        reserve(v, size);

    for (size_t i = 0; i < size; i++)
        scanf("%d", &v->data[i]);

    v->size = size;
}

static size_t min2(size_t a, size_t b) {
    return a < b ? a : b;
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0)
        *v = (vector) {NULL, 0, 0};
    else {
        int *data;
        if ((data = (int *) realloc(v->data, sizeof(int) * newCapacity)) == NULL) {
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

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    assert(i <= v->size);
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (v->capacity == 0) {
        v->data = (int*) malloc(sizeof(int));
        v->capacity = 1;
    } else if (isFull(v))
        reserve(v, v->capacity * 2);

    v->data[v->size++] = x;
}

bool isEqualVector(vector v1, vector v2) {
    if (v1.size != v2.size || v1.capacity != v2.capacity)
        return false;
    for (size_t i = 0; i < v1.size; i++)
        if (v1.data[i] != v2.data[i])
            return false;

    return true;
}

void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "No element to be deleted");
        exit(1);
    }

    v->size--;
}

int* atVector(vector *v, size_t index) {
    if (v->size <= index) {
        fprintf(stderr, "IndexError: a[index] does not exist");
        exit(1);
    }

    return v->data + index;
}

int* back(vector *v) {
    if (v->size == 0) {
        fprintf(stderr, "No elements in vector");
        exit(1);
    }

    return v->data + v->size - 1;
}

int* front(vector *v) {
    if (v->size == 0) {
        fprintf(stderr, "No elements in vector");
        exit(1);
    }

    return v->data;
}

