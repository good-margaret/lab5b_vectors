//
// Created by 1 on 06.02.2022.
//

#ifndef GIT_PROGECT_VOIDVECTOR_H
#define GIT_PROGECT_VOIDVECTOR_H

typedef struct vectorVoid {
    void *data;          //указатель на нулевой элемент вектора
    size_t size;         //размер вектора
    size_t capacity;     //вместимость вектора
    size_t baseTypeSize; //размер базового типа
} vectorVoid;

#endif //GIT_PROGECT_VOIDVECTOR_H
