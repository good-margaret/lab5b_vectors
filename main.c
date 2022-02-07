#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/voidVector/voidVector.h"


void test_pushBack_emptyVector_capacityLargerThanZero() {
    vector v = createVector(5);

    pushBack(&v, 8);

    int data[] = {8};
    vector expectedVector = (vector) {data, 1, 5};

    assert(isEqualVectors(v, expectedVector));

    deleteVector(&v);
}

void test_pushBack_emptyVector_zeroCapacity() {
    vector v = createVector(0);

    pushBack(&v, 8);

    int data[] = {8};
    vector expectedVector = (vector) {data, 1, 1};

    assert(isEqualVectors(v, expectedVector));

    deleteVector(&v);
}

void test_pushBack_emptyVector() {
    test_pushBack_emptyVector_capacityLargerThanZero();
    test_pushBack_emptyVector_zeroCapacity();
}

void test_pushBack_fullVector_1() {
    int *data1 = (int *) malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++)
        data1[i] = i + 1;

    vector v = (vector) {data1, 5, 5};

    pushBack(&v, 8);

    int data[] = {1, 2, 3, 4, 5, 8};
    vector expectedVector = (vector) {data, 6, 10};

    assert(isEqualVectors(v, expectedVector));

    deleteVector(&v);
}

void test_pushBack_fullVector_2() {
    int *data1 = (int *) malloc(sizeof(int));
    data1[0] = 1;

    vector v = (vector) {data1, 1, 1};
    pushBack(&v, 8);

    int data[] = {1, 8};
    vector expectedVector = (vector) {data, 2, 2};

    assert(isEqualVectors(v, expectedVector));

    deleteVector(&v);
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

    deleteVector(&v);
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

    deleteVector(&v);
}

void test_popBack_notEmptyVector() {
    test_popBack_notEmptyVector_1();
    test_popBack_notEmptyVector_2();
}

void test_atVector_notEmptyVector_1() {
    vector v = createVector(0);
    pushBack(&v, 1);

    assert(&v.data[0] == atVector(&v, 0));

    deleteVector(&v);
}

void test_atVector_notEmptyVector_2() {
    int data[] = {10, 9, 8, 9};
    vector v = (vector) {data, 4, 8};

    assert(&v.data[0] == atVector(&v, 0));
    assert(&v.data[1] == atVector(&v, 1));
    assert(&v.data[2] == atVector(&v, 2));
    assert(&v.data[3] == atVector(&v, 3));
}

void test_atVector_requestToLastElement_1() {
    int data[] = {1, 2, 3, 4};
    vector v = (vector) {data, 4, 4};

    assert(&v.data[3] == atVector(&v, 3));
}

void test_atVector_requestToLastElement_2() {
    int data[] = {1000, 2000, 3000, 4000};
    vector v = (vector) {data, 4, 8};

    assert(&v.data[3] == atVector(&v, 3));
}

void test_back_oneElementInVector_1() {
    vector v = createVector(0);
    pushBack(&v, 1);

    assert(&v.data[0] == back(&v));

    deleteVector(&v);
}

void test_back_oneElementInVector_2() {
    vector v = createVector(0);
    pushBack(&v, 8);

    assert(&v.data[0] == back(&v));

    deleteVector(&v);
}

void test_back_severalElementsInVector_1() {
    int data[] = {1, 2, 3, 4};
    vector v = (vector) {data, 4, 4};

    assert(&v.data[3] == back(&v));
}

void test_back_severalElementsInVector_2() {
    int data[] = {8, 7, 6, 5, 0};
    vector v = (vector) {data, 5, 50};

    assert(&v.data[4] == back(&v));
}

void test_front_oneElementInVector() {
    vector v = createVector(0);
    pushBack(&v, 8);

    assert(&v.data[0] == front(&v));

    deleteVector(&v);
}

void test_front_severalElementsInVector_1() {
    int data[] = {1, 2, 3, 4};
    vector v = (vector) {data, 4, 4};

    assert(&v.data[0] == front(&v));
}

void test_front_severalElementsInVector_2() {
    int data[] = {8, 7, 6, 5, 0};
    vector v = (vector) {data, 5, 50};

    assert(&v.data[0] == front(&v));
}

void test_getVectorValue_oneElement() {
    vector v = createVector(0);
    pushBack(&v, 8);

    assert(v.data[0] == getVectorValue(&v, 0));

    deleteVector(&v);
}

void test_getVectorValue_lastElement_1() {
    int data[] = {8, 7, 6, 5, 0};
    vector v = (vector) {data, 5, 50};

    assert(v.data[4] == getVectorValue(&v, 4));
}

void test_getVectorValue_lastElement_2() {
    int data[] = {1, 2, 3, 4};
    vector v = (vector) {data, 4, 4};

    assert(v.data[3] == getVectorValue(&v, 3));
}

void test_getVectorValue_randomElement_1() {
    int data[] = {1, 2, 3, 4, 5};
    vector v = (vector) {data, 5, 6};

    assert(v.data[3] == getVectorValue(&v, 3));
}

void test_getVectorValue_randomElement_2() {
    int data[] = {1, 2, 3, 4, 5};
    vector v = (vector) {data, 5, 6};

    assert(v.data[1] == getVectorValue(&v, 1));
}

void test_shrinkToFit_emptyVector() {
    vector v = (vector) {NULL, 0, 10};
    shrinkToFit(&v);

    vector expectedVector = (vector) {NULL, 0, 0};

    assert (isEqualVectors(v, expectedVector));
}

void test_shrinkToFit_fullVector() {
    int *data = (int *) malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++)
        data[i] = i + 1;

    vector v = (vector) {data, 5, 5};
    shrinkToFit(&v);

    vector expectedVector = (vector) {data, 5, 5};

    assert (isEqualVectors(v, expectedVector));

    deleteVector(&v);
}

void test_shrinkToFit_randomVector_1() {
    int *data = (int *) malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++)
        data[i] = i + 1;

    vector v = (vector) {data, 5, 10};
    shrinkToFit(&v);

    vector expectedVector = (vector) {data, 5, 5};

    assert (isEqualVectors(v, expectedVector));

    deleteVector(&v);
}

void test_shrinkToFit_randomVector_2() {
    int *data = (int *) malloc(sizeof(int) * 30);
    for (int i = 0; i < 10; i++)
        data[i] = (4 * i + 3) % 5;

    vector v = (vector) {data, 10, 30};
    shrinkToFit(&v);

    vector expectedVector = (vector) {data, 10, 10};

    assert (isEqualVectors(v, expectedVector));

    deleteVector(&v);
}

void test_reserve_fromZeroVector() {
    vector v = createVector(0);
    reserve(&v, 10);

    vector expectedVector = (vector) {malloc(sizeof(int) * 10), 0, 10};

    assert (isEqualVectors(v, expectedVector));

    deleteVector(&v);
}

void test_reserve_newCapacityIsLesserThanSize() {
    int *data = (int *) malloc(sizeof(int) * 30);
    for (int i = 0; i < 10; i++)
        data[i] = (4 * i + 3) % 5;

    vector v = (vector) {data, 10, 30};

    reserve(&v, 5);

    vector expectedVector = (vector) {data, 5, 5};

    assert (isEqualVectors(v, expectedVector));

    deleteVector(&v);
}

void test_reserve_newCapacityIsBiggerThanCapacity() {
    int *data = (int *) malloc(sizeof(int) * 15);
    for (int i = 0; i < 10; i++)
        data[i] = (4 * i + 3) % 5;

    vector v = (vector) {data, 10, 15};

    reserve(&v, 25);

    vector expectedVector = (vector) {data, 10, 25};

    assert (isEqualVectors(v, expectedVector));

    deleteVector(&v);
    deleteVector(&expectedVector);
}

void test_reserve() {
    test_reserve_fromZeroVector();
    test_reserve_newCapacityIsBiggerThanCapacity();
    test_reserve_newCapacityIsLesserThanSize();
}

void test_shrinkToFit_randomVector() {
    test_shrinkToFit_randomVector_1();
    test_shrinkToFit_randomVector_2();
}

void test_getVectorValue_randomElement() {
    test_getVectorValue_randomElement_1();
    test_getVectorValue_randomElement_2();
}

void test_getVectorValue_lastElement() {
    test_getVectorValue_lastElement_1();
    test_getVectorValue_lastElement_2();
}

void test_front_severalElementsInVector() {
    test_front_severalElementsInVector_1();
    test_front_severalElementsInVector_2();
}

void test_back_SeveralElementsInVector() {
    test_back_severalElementsInVector_1();
    test_back_severalElementsInVector_2();
}

void test_back_oneElementInVector() {
    test_back_oneElementInVector_1();
    test_back_oneElementInVector_2();
}

void test_atVector_requestToLastElement() {
    test_atVector_requestToLastElement_1();
    test_atVector_requestToLastElement_2();
}

void test_atVector_notEmptyVector() {
    test_atVector_notEmptyVector_1();
    test_atVector_notEmptyVector_2();
}

void test_atVector() {
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
}

void test_pushBack() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
}

void test_back() {
    test_back_SeveralElementsInVector();
    test_back_oneElementInVector();
}

void test_front() {
    test_front_oneElementInVector();
    test_front_severalElementsInVector();
}

void test_getVectorValue() {
    test_getVectorValue_lastElement();
    test_getVectorValue_oneElement();
    test_getVectorValue_randomElement();
}

void test_shrinkToFit() {
    test_shrinkToFit_fullVector();
    test_shrinkToFit_emptyVector();
    test_shrinkToFit_randomVector();
}

void test() {
    test_reserve();
    test_pushBack();
    test_atVector();
    test_back();
    test_front();
    test_getVectorValue();
    test_shrinkToFit();
}


void test_voidVector_reserve_newCapacityIsLesserThanSize() {
    int *data = (int *) malloc(sizeof(int) * 30);
    for (int i = 0; i < 10; i++)
        data[i] = (4 * i + 3) % 5;

    vectorVoid v = (vectorVoid) {data, 10, 30, sizeof(int)};

    reserveV(&v, 5);

    vectorVoid expectedVector = (vectorVoid) {data, 5, 5, sizeof(int)};

    assert (isEqualVectorsV(v, expectedVector));

    //deleteVector(&v);
}

int main() {
    test();
    test_voidVector_reserve_newCapacityIsLesserThanSize();
 //   vectorVoid v = (vectorVoid) {NULL, 0, 5, sizeof(int)};

    return 0;
}
