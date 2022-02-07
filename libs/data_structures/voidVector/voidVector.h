//
// Created by 1 on 06.02.2022.
//

#ifndef GIT_PROGECT_VOIDVECTOR_H
#define GIT_PROGECT_VOIDVECTOR_H

#include <stdio.h>
#include <stdbool.h>

typedef struct vectorVoid {
    void *data;          //указатель на нулевой элемент вектора
    size_t size;         //размер вектора
    size_t capacity;     //вместимость вектора
    size_t baseTypeSize; //размер базового типа
} vectorVoid;

vectorVoid createVectorV(size_t n, size_t baseTypeSize);

void reserveV(vectorVoid *v, size_t newCapacity);

bool isEqualVectorsV(vectorVoid v1, vectorVoid v2);

void shrinkToFitV(vectorVoid *v);

void clearV(vectorVoid *v);

void deleteVectorV(vectorVoid *v);


#endif //GIT_PROGECT_VOIDVECTOR_H
