//
// Created by 1 on 01.02.2022.
//

#ifndef GIT_PROGECT_VECTOR_H
#define GIT_PROGECT_VECTOR_H

#include <stdio.h>

typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
} vector;

vector createVector(size_t n);
void outputVector(vector v);
void inputVector(vector *v, size_t size);
void reserve(vector *v, size_t newCapacity);
void shrinkToFit(vector *v);
void clear(vector *v);
void deleteVector(vector *v);

#endif //GIT_PROGECT_VECTOR_H
