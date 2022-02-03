#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "libs/data_structures/vector/vector.h"

void test_pushBack_emptyVector_1() {
    vector vector1 = createVector(5);

    pushBack(&vector1, 8);

    int data[] = {8};
    vector expectedVector = (vector) {data, 1, 5};

    assert(isEqualVectors(vector1, expectedVector));
}

void test_pushBack_emptyVector_2() {
    vector vector1 = createVector(0);

    pushBack(&vector1, 8);

    int data[] = {8};
    vector expectedVector = (vector) {data, 1, 1};

    assert(isEqualVectors(vector1, expectedVector));
}

void test_pushBack_emptyVector() {
    test_pushBack_emptyVector_1();
    test_pushBack_emptyVector_2();
}

void test_pushBack_fullVector_1() {
    int *data1 = (int *) malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++)
        data1[i] = i + 1;

    vector vector1 = (vector) {data1, 5, 5};

    pushBack(&vector1, 8);

    int data[] = {1, 2, 3, 4, 5, 8};
    vector expectedVector = (vector) {data, 6, 10};

    assert(isEqualVectors(vector1, expectedVector));

    free(data1);
}

void test_pushBack_fullVector_2() {
    int *data1 = (int *) malloc(sizeof(int));
    data1[0] = 1;

    vector vector1 = (vector) {data1, 1,  1};
    pushBack(&vector1, 8);

    int data[] = {1, 8};
    vector expectedVector = (vector) {data, 2, 2};

    assert(isEqualVectors(vector1, expectedVector));

    clear(&vector1);
}

void test_pushBack_fullVector() {
    test_pushBack_fullVector_1();
    test_pushBack_fullVector_2();
}

void test_popBack_notEmptyVector_1() {
    vector v = createVector(0);
    pushBack(&v, 10);

    popBack(&v);

    assert (v.size == 0);
    assert (v.capacity == 1);
}

void test_popBack_notEmptyVector_2() {
    vector v = createVector(0);
    pushBack(&v, 10);
    pushBack(&v, 9);
    pushBack(&v, 8);

    popBack(&v);

    int data[] = {10, 9};
    vector expectedVector = (vector) {data, 2, 4};

    assert (isEqualVectors(v, expectedVector));
}

void test_popBack_notEmptyVector() {
    test_popBack_notEmptyVector_1();
    test_popBack_notEmptyVector_2();
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
}

int main() {
    test();
    test_popBack_notEmptyVector();

    vector v = createVector(3);
    popBack(&v);

    return 0;
}
