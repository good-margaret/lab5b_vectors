//
// Created by 1 on 01.02.2022.
//

#ifndef GIT_PROGECT_VECTOR_H
#define GIT_PROGECT_VECTOR_H

#include <stdio.h>
#include <stdbool.h>

typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
} vector;

//возвращает структуру-дескриптор вектор из n значений.
vector createVector(size_t n);

//выводит элементы вектора v
void outputVector(vector v);

//вводит вектор из элементов size по адресу v
void inputVector(vector *v, size_t size);

//изменяет количество памяти, выделенное под хранение
//элементов вектора с адресом v, на newCapacity
void reserve(vector *v, size_t newCapacity);

//удаляет элементы из контейнера вектора v,
//но не освобождает выделенную память
void shrinkToFit(vector *v);

//удаляет элементы из контейнера вектора v,
//но не освобождает выделенную память
void clear(vector *v);

//освобождает память, выделенную вектору v
void deleteVector(vector *v);

//возвращает true, если вектор v пуст, и false в противном случае
bool isEmpty(vector *v);

//возвращает true, если вектор v подон, и false в противном случае
bool isFull(vector *v);

//возвращает i-ый элемент вектора v
int getVectorValue(vector *v, size_t i);

//добавляет элемент x в конец вектора v
void pushBack(vector *v, int x);

//возвращает , если у векторов совпадают размер массива элементов,
//сами элементы массива и максимальные вместимости
bool isEqualVectors(vector v1, vector v2);



void popBack(vector *v);

#endif //GIT_PROGECT_VECTOR_H
