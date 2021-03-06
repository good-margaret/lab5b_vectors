#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "libs/data_structures/matrix/matrix.h"

int criteria (int *a, int n) {
    return a[0];
}

void test_swapRows_1() {
    matrix m = createMatrixFromArray((int[]) {1, 1, 1, 1,
                                                  2, 2, 2, 2,
                                                  3, 3, 3, 3}, 3, 4);
    swapRows(m, 0, 2);

    matrix expectedResult = createMatrixFromArray((int[]) {3, 3, 3, 3,
                                                              2, 2, 2, 2,
                                                              1, 1, 1, 1}, 3, 4);
    assert(areTwoMatricesEqual(m, expectedResult));

    freeMemMatrix(m);
    freeMemMatrix(expectedResult);
}

void test_swapRows_2() {
    matrix m = createMatrixFromArray((int[]) {1, 1, 1, 1,
                                                 2, 2, 2, 2,
                                                 3, 3, 3, 3,
                                                 4, 4, 4, 4}, 4, 4);
    swapRows(m, 3, 3);

    matrix expectedResult = createMatrixFromArray((int[]) {1, 1, 1, 1,
                                                              2, 2, 2, 2,
                                                              3, 3, 3, 3,
                                                              4, 4, 4, 4}, 4, 4);
    assert(areTwoMatricesEqual(m, expectedResult));

    freeMemMatrix(m);
    freeMemMatrix(expectedResult);
}

void test_swapCols_1() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 4,
                                              1, 2, 3, 4,
                                              1, 2, 3, 4}, 3, 4);
    swapColumns(m, 0, 3);

    matrix expectedResult = createMatrixFromArray((int[]) {4, 2, 3, 1,
                                                           4, 2, 3, 1,
                                                           4, 2, 3, 1}, 3, 4);
    assert(areTwoMatricesEqual(m, expectedResult));

    freeMemMatrix(m);
    freeMemMatrix(expectedResult);
}

void test_swapCols_2() {
    matrix m = createMatrixFromArray((int[]) {1, 5, 9, 13,
                                              2, 6, 10, 14,
                                              3, 7, 11, 15,
                                              4, 8, 12, 16}, 4, 4);
    swapRows(m, 0, 0);

    matrix expectedResult = createMatrixFromArray((int[]) {1, 5, 9, 13,
                                                           2, 6, 10, 14,
                                                           3, 7, 11, 15,
                                                           4, 8, 12, 16}, 4, 4);
    assert(areTwoMatricesEqual(m, expectedResult));

    freeMemMatrix(m);
    freeMemMatrix(expectedResult);
}

int criteria1(const int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
     sum += a[i];

    return sum;
}

int criteria2(const int *a, int n) {
    int product = 1;
    for (int i = 0; i < n; i++)
        product *= a[i];

    return product;
}

void test_insertionSortRows_1() {
    matrix m = createMatrixFromArray((int[]) {1, 5, 9, 1000,
                                              2, 6, 10, 150,
                                              3, 7, 11, 100,
                                              4, 8, 12, 16}, 4, 4);
    insertionSortRowsMatrixByRowCriteria(m, criteria1);

    matrix expectedResult = createMatrixFromArray((int[]) {4, 8, 12, 16,
                                                           3, 7, 11, 100,
                                                           2, 6, 10, 150,
                                                           1, 5, 9, 1000}, 4, 4);
    assert(areTwoMatricesEqual(m, expectedResult));

    freeMemMatrix(m);
    freeMemMatrix(expectedResult);
}

void test_insertionSortRows_2() {
    matrix m = createMatrixFromArray((int[]) {1, 1, 1,
                                              2, 1, 2,
                                              1, 5, 1,
                                              1, 2, 2}, 4, 3);

    insertionSortRowsMatrixByRowCriteria(m, criteria2);

    matrix expectedResult = createMatrixFromArray((int[]) {1, 1, 1,
                                                           2, 1, 2,
                                                           1, 2, 2,
                                                           1, 5, 1}, 4, 3);
    assert(areTwoMatricesEqual(m, expectedResult));

    freeMemMatrix(m);
    freeMemMatrix(expectedResult);
}

void test_insertionSortCols_1() {
    matrix m = createMatrixFromArray((int[]) {1, 5, 9, 10,
                                              2, 6, 10, 150,
                                              3, 7, 11, 100,
                                              4, 8, 12, 16}, 4, 4);

    insertionSortColsMatrixByColCriteria(m, criteria1);

    matrix expectedResult = createMatrixFromArray((int[]) {1, 5, 9, 10,
                                                           2, 6, 10, 150,
                                                           3, 7, 11, 100,
                                                           4, 8, 12, 16}, 4, 4);
    assert(areTwoMatricesEqual(m, expectedResult));

    freeMemMatrix(m);
    freeMemMatrix(expectedResult);
}

void test_insertionSortCols_2() {
    matrix m = createMatrixFromArray((int[]) {1, 1, 1,
                                              2, 1, 2,
                                              1, 5, 1,
                                              1, 2, 2}, 4, 3);

    insertionSortColsMatrixByColCriteria(m, criteria2);

    matrix expectedResult = createMatrixFromArray((int[]) {1, 1, 1,
                                                           2, 2, 1,
                                                           1, 1, 5,
                                                           1, 2, 2}, 4, 3);
    assert(areTwoMatricesEqual(m, expectedResult));

    freeMemMatrix(m);
    freeMemMatrix(expectedResult);
}

void test_insertionSortCols_3() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 2, 1,
                                                 2, 1, 1, 1,
                                                 3, 2, 1, 1,
                                                 4, 2, 2, 1}, 4, 4);

    insertionSortColsMatrixByColCriteria(m, criteria2);

    matrix expectedResult = createMatrixFromArray((int[]) {1, 2, 2, 1,
                                                           1, 1, 1, 2,
                                                           1, 1, 2, 3,
                                                           1, 2, 2, 4}, 4, 4);
    assert(areTwoMatricesEqual(m, expectedResult));

    freeMemMatrix(m);
    freeMemMatrix(expectedResult);
}

void test_squareMatrix_1() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 2, 1,
                                                           1, 1, 1, 2,
                                                           1, 1, 2, 3,
                                                           1, 2, 2, 4}, 4, 4);
    assert(isSquareMatrix(m));

    freeMemMatrix(m);
}

void test_squareMatrix_2() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 2, 1,
                                              1, 1, 1, 2,
                                              1, 1, 2, 3}, 3, 4);
    assert(!isSquareMatrix(m));

    freeMemMatrix(m);
}

void test_eMatrix_1() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 2, 1,
                                              1, 1, 1, 2,
                                              1, 1, 2, 3,
                                              1, 2, 2, 4}, 4, 4);
    assert(!isEMatrix(m));

    freeMemMatrix(m);
}

void test_eMatrix_2() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 2, 1,
                                              1, 1, 1, 2,
                                              1, 1, 2, 3}, 3, 4);
    assert(!isEMatrix(m));

    freeMemMatrix(m);
}

void test_eMatrix_3() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 0, 0,
                                              0, 1, 0, 0,
                                              0, 0, 1, 0,
                                              0, 0, 0, 1}, 4, 4);
    assert(isEMatrix(m));

    freeMemMatrix(m);
}

void test_isSymmetricMatrix_1() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 0, 9,
                                              0, 1, 0, 0,
                                              0, 0, 1, 0,
                                              9, 0, 0, 1}, 4, 4);
    assert(isSymmetricMatrix(m));

    freeMemMatrix(m);
}

void test_isSymmetricMatrix_2() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 0, 9,
                                              0, 1, 0, 0,
                                              0, 0, 1, 0,
                                              7, 0, 0, 1}, 4, 4);
    assert(!isSymmetricMatrix(m));

    freeMemMatrix(m);
}

void test_isSymmetricMatrix_3() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 0, 9,
                                              0, 1, 0, 0,
                                              0, 0, 1, 0}, 3, 4);
    assert(!isSymmetricMatrix(m));

    freeMemMatrix(m);
}

void test_getMinValuePos_1() {
    matrix m = createMatrixFromArray((int[]) {1, 5, 9, 10,
                                              2, 6, 10, 150,
                                              3, 7, 11, 100,
                                              4, 8, 12, 16}, 4, 4);
    position minPos = getMinValuePos(m);

    assert(minPos.rowIndex == 0 && minPos.colIndex == 0);

    freeMemMatrix(m);
}

void test_getMinValuePos_2() {
    matrix m = createMatrixFromArray((int[]) {19, 5, 9, 10,
                                              2, 6, 10, 150,
                                              3, 7, 11, 100,
                                              4, 8, 12, 1}, 4, 4);
    position minPos = getMinValuePos(m);

    assert(minPos.rowIndex == 3 && minPos.colIndex == 3);

    freeMemMatrix(m);
}

void test_getMinValuePos_3() {
    matrix m = createMatrixFromArray((int[]) {10, 5, 9, 10,
                                              2, 6, 1, 150,
                                              3, 7, 11, 100,
                                              4, 8, 12, 16}, 4, 4);
    position minPos = getMinValuePos(m);

    assert(minPos.rowIndex == 1 && minPos.colIndex == 2);

    freeMemMatrix(m);
}

void test_getMinValuePos_4() {
    matrix m = createMatrixFromArray((int[]) {10, 5, 9, 10,
                                              2, 6, 1, 1,
                                              3, 7, 11, 100,
                                              4, 8, 12, 16}, 4, 4);
    position minPos = getMinValuePos(m);

    assert(minPos.rowIndex == 1 && minPos.colIndex == 2);

    freeMemMatrix(m);
}

void test_getMaxValuePos_1() {
    matrix m = createMatrixFromArray((int[]) {1000, 5, 9, 10,
                                              2, 6, 10, 150,
                                              3, 7, 11, 100,
                                              4, 8, 12, 16}, 4, 4);
    position maxPos = getMaxValuePos(m);

    assert(maxPos.rowIndex == 0 && maxPos.colIndex == 0);

    freeMemMatrix(m);
}

void test_getMaxValuePos_2() {
    matrix m = createMatrixFromArray((int[]) {19, 5, 9, 10,
                                              2, 6, 10, 150,
                                              3, 7, 11, 100,
                                              4, 8, 12, 1000}, 4, 4);
    position maxPos = getMaxValuePos(m);

    assert(maxPos.rowIndex == 3 && maxPos.colIndex == 3);

    freeMemMatrix(m);
}

void test_getMaxValuePos_3() {
    matrix m = createMatrixFromArray((int[]) {10, 5, 9, 10,
                                              2, 6, 1, 150,
                                              3, 7, 11, 100,
                                              4, 8, 12, 16}, 4, 4);
    position maxPos = getMaxValuePos(m);

    assert(maxPos.rowIndex == 1 && maxPos.colIndex == 3);

    freeMemMatrix(m);
}

void test_getMaxValuePos_4() {
    matrix m = createMatrixFromArray((int[]) {10, 5, 9, 10,
                                              2, 6, 1, 150,
                                              3, 150, 11, 100,
                                              4, 8, 12, 16}, 4, 4);
    position maxPos = getMaxValuePos(m);

    assert(maxPos.rowIndex == 1 && maxPos.colIndex == 3);

    freeMemMatrix(m);
}

void test_getMaxValuePos() {
    test_getMaxValuePos_1();
    test_getMaxValuePos_2();
    test_getMaxValuePos_3();
    test_getMaxValuePos_4();
}

void test_getMinValuePos() {
    test_getMinValuePos_1();
    test_getMinValuePos_2();
    test_getMinValuePos_3();
    test_getMinValuePos_4();
}

void test_isSymmetricMatrix() {
    test_isSymmetricMatrix_1();
    test_isSymmetricMatrix_2();
    test_isSymmetricMatrix_3();
}

void test_eMatrix() {
    test_eMatrix_1();
    test_eMatrix_2();
    test_eMatrix_3();
}

void test_squareMatrix() {
    test_squareMatrix_1();
    test_squareMatrix_2();
}

void test_insertionSortCols() {
    test_insertionSortCols_1();
    test_insertionSortCols_2();
    test_insertionSortCols_3();
}

void test_insertionSortRows() {
    test_insertionSortRows_1();
    test_insertionSortRows_2();
}

void test_swapRows() {
    test_swapRows_1();
    test_swapRows_2();
}

void test_swapCols(){
    test_swapCols_1();
    test_swapCols_2();
}

void test_firstPartOfAssigment() {
    test_swapRows();
    test_swapCols();
    test_insertionSortRows();
    test_insertionSortCols();
    test_squareMatrix();
    test_eMatrix();
    test_isSymmetricMatrix();
    test_getMinValuePos();
    test_getMaxValuePos();
}

void test_swapRowsContainingMinAndMaxElements_1() {
    matrix m = createMatrixFromArray((int[]) {10, 5, 9, 10,
                                              2, 6, 1, 15,
                                              3, 150, 11, 100,
                                              4, 8, 12, 16}, 4, 4);

    swapRowsContainingMinAndMaxElements(m);

    matrix expectedResult = createMatrixFromArray((int[]) {10, 5, 9, 10,
                                                               3, 150, 11, 100,
                                                               2, 6, 1, 15,
                                                               4, 8, 12, 16}, 4, 4);

    assert(areTwoMatricesEqual(m, expectedResult));

    freeMemMatrix(m);
    freeMemMatrix(expectedResult);
}

void test_swapRowsContainingMinAndMaxElements_2() {
    matrix m = createMatrixFromArray((int[]) {10, 5, 9, 10,
                                              2, 6, 1, 150,
                                              3, 111, 11, 100,
                                              4, 8, 12, 16}, 4, 4);

    swapRowsContainingMinAndMaxElements(m);

    matrix expectedResult = createMatrixFromArray((int[]) {10, 5, 9, 10,
                                                           2, 6, 1, 150,
                                                           3, 111, 11, 100,
                                                           4, 8, 12, 16}, 4, 4);

    assert(areTwoMatricesEqual(m, expectedResult));

    freeMemMatrix(m);
    freeMemMatrix(expectedResult);
}

void test_swapRowsContainingMinAndMaxElements_3() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              8, 7, 6,
                                              9, 10, 11}, 3, 3);

    swapRowsContainingMinAndMaxElements(m);

    matrix expectedResult = createMatrixFromArray((int[]) {9, 10, 11,
                                                           8, 7, 6,
                                                           1, 2, 3}, 3, 3);

    assert(areTwoMatricesEqual(m, expectedResult));

    freeMemMatrix(m);
    freeMemMatrix(expectedResult);
}

void test_sortRowsByMaxElement_1() {
    matrix m = createMatrixFromArray((int[]) {9, 10, 11,
                                              8, 7, 6,
                                              1, 2, 3}, 3, 3);

    sortRowsByMaxElement(m);

    matrix expectedResult = createMatrixFromArray((int[]) {1, 2, 3,
                                              8, 7, 6,
                                              9, 10, 11}, 3, 3);

    assert(areTwoMatricesEqual(m, expectedResult));

    freeMemMatrix(m);
    freeMemMatrix(expectedResult);
}

void test_sortRowsByMaxElement_2() {
    matrix m = createMatrixFromArray((int[]) {10, 5, 9, 10,
                                              2, 6, 1, 150,
                                              3, 111, 11, 100,
                                              4, 8, 12, 16}, 4, 4);

    sortRowsByMaxElement(m);

    matrix expectedResult = createMatrixFromArray((int[]) {10, 5, 9, 10,
                                                           4, 8, 12, 16,
                                                           3, 111, 11, 100,
                                                           2, 6, 1, 150}, 4, 4);

    assert(areTwoMatricesEqual(m, expectedResult));

    freeMemMatrix(m);
    freeMemMatrix(expectedResult);
}

void test_sortRowsByMaxElement_3() {
    matrix m = createMatrixFromArray((int[]) {11, 11, 11,
                                              7, 7, 7,
                                              11, 11, 11,
                                              7, 7, 7}, 4, 3);

    sortRowsByMaxElement(m);

    matrix expectedResult = createMatrixFromArray((int[]) {7, 7, 7,
                                                           7, 7, 7,
                                                           11, 11, 11,
                                                           11, 11, 11}, 4, 3);

    assert(areTwoMatricesEqual(m, expectedResult));

    freeMemMatrix(m);
    freeMemMatrix(expectedResult);
}

void test_sortColsByMinElement_1() {
    matrix m = createMatrixFromArray((int[]) {100, 5, 9, 10,
                                                   2, 6, 10, 150,
                                                   3, 7, 11, 100,
                                                   4, 8, 12, 1}, 4, 4);

    sortColsByMinElement(m);

    matrix expectedResult = createMatrixFromArray((int[]) {10, 100, 5, 9,
                                                           150, 2, 6, 10,
                                                           100, 3, 7, 11,
                                                           1, 4, 8, 12}, 4, 4);
    assert(areTwoMatricesEqual(m, expectedResult));

    freeMemMatrix(m);
    freeMemMatrix(expectedResult);
}

void test_sortColsByMinElement_2() {
    matrix m = createMatrixFromArray((int[]) {1, 1, 1,
                                              2, 1, 2,
                                              1, 5, 1,
                                              1, 2, 2}, 4, 3);

    sortColsByMinElement(m);

    matrix expectedResult = createMatrixFromArray((int[]) {1, 1, 1,
                                                           2, 1, 2,
                                                           1, 5, 1,
                                                           1, 2, 2}, 4, 3);
    assert(areTwoMatricesEqual(m, expectedResult));

    freeMemMatrix(m);
    freeMemMatrix(expectedResult);
}

void test_sortColsByMinElement_3() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 2, 0,
                                                 2, 1, 1, 1,
                                                 3, 2, 1, 1,
                                                 4, 2, 2, 1}, 4, 4);

    sortColsByMinElement(m);

    matrix expectedResult = createMatrixFromArray((int[]) {0, 2, 2, 3,
                                                           1, 1, 1, 2,
                                                           1, 2, 1, 3,
                                                           1, 2, 2, 4}, 4, 4);
    assert(areTwoMatricesEqual(m, expectedResult));

    freeMemMatrix(m);
    freeMemMatrix(expectedResult);
}

void test_getSquareOfMatrixIfSymmetric_1() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 1,
                                              0, 1, 0,
                                              1, 0, 0}, 3, 3);

    getSquareOfMatrixIfSymmetric(&m);

    matrix expectedResult = createMatrixFromArray((int[]) {2, 0, 1,
                                                           0, 1, 0,
                                                           1, 0, 1}, 3, 3);
    assert(areTwoMatricesEqual(m, expectedResult));

    freeMemMatrix(m);
    freeMemMatrix(expectedResult);
}

void test_getSquareOfMatrixIfSymmetric_2() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 1,
                                              0, 1, 0,
                                              1, 1, 0}, 3, 3);

    getSquareOfMatrixIfSymmetric(&m);

    matrix expectedResult = createMatrixFromArray((int[]) {1, 0, 1,
                                                           0, 1, 0,
                                                           1, 1, 0}, 3, 3);
    assert(areTwoMatricesEqual(m, expectedResult));

    freeMemMatrix(m);
    freeMemMatrix(expectedResult);
}

void test_getSquareOfMatrixIfSymmetric_3() {
    matrix m = createMatrixFromArray((int[]) {1, 1, 1, 1,
                                              1, 1, 1, 1,
                                              1, 1, 1, 1,
                                              1, 1, 1, 1}, 4, 4);

    getSquareOfMatrixIfSymmetric(&m);

    matrix expectedResult = createMatrixFromArray((int[]) {4, 4, 4, 4,
                                                           4, 4, 4, 4,
                                                           4, 4, 4, 4,
                                                           4, 4, 4, 4}, 4, 4);
    assert(areTwoMatricesEqual(m, expectedResult));

    freeMemMatrix(m);
    freeMemMatrix(expectedResult);
}

void test_getSquareOfMatrixIfSymmetric_4() {
    matrix m = createMatrixFromArray((int[]) {1, 1, 1, 1,
                                              1, 1, 1, 1,
                                              1, 1, 1, 1}, 3, 4);

    getSquareOfMatrixIfSymmetric(&m);

    matrix expectedResult = createMatrixFromArray((int[]) {1, 1, 1, 1,
                                                           1, 1, 1, 1,
                                                           1, 1, 1, 1}, 3, 4);
    assert(areTwoMatricesEqual(m, expectedResult));

    freeMemMatrix(m);
    freeMemMatrix(expectedResult);
}

void test_transposeIfMatrixHasNotEqualSumOfRows_1() {
    matrix m = createMatrixFromArray((int[]) {1, 1, 1, 2,
                                              1, 1, 1, 3,
                                              1, 1, 1, 4,
                                              1, 1, 1, 5}, 4, 4);

    transposeIfMatrixHasNotEqualSumOfRows(m);

    matrix expectedResult = createMatrixFromArray((int[]) {1, 1, 1, 1,
                                                           1, 1, 1, 1,
                                                           1, 1, 1, 1,
                                                           2, 3, 4, 5}, 4, 4);

    assert(areTwoMatricesEqual(m, expectedResult));

    freeMemMatrix(m);
    freeMemMatrix(expectedResult);
}

void test_transposeIfMatrixHasNotEqualSumOfRows_2() {
    matrix m = createMatrixFromArray((int[]) {1, 1, 1, 1,
                                                 1, 1, 1, 1,
                                                 1, 1, 1, 1,
                                                 2, 3, 4, 5}, 4, 4);

    transposeIfMatrixHasNotEqualSumOfRows(m);

    matrix expectedResult = createMatrixFromArray((int[]) {1, 1, 1, 1,
                                                           1, 1, 1, 1,
                                                           1, 1, 1, 1,
                                                           2, 3, 4, 5}, 4, 4);

    assert(areTwoMatricesEqual(m, expectedResult));

    freeMemMatrix(m);
    freeMemMatrix(expectedResult);
}

void test_transposeIfMatrixHasNotEqualSumOfRows_3() {
    matrix m = createMatrixFromArray((int[]) {1, 1, 3,
                                              1, 1, 1,
                                              2, 1, 1}, 3, 3);

    transposeIfMatrixHasNotEqualSumOfRows(m);

    matrix expectedResult = createMatrixFromArray((int[]) {1, 1, 2,
                                                           1, 1, 1,
                                                           3, 1, 1}, 3, 3);

    assert(areTwoMatricesEqual(m, expectedResult));

    freeMemMatrix(m);
    freeMemMatrix(expectedResult);
}

void test_isMutuallyInverseMatrices_1() {
    matrix m1 = createMatrixFromArray((int[]) {1, 1, 3,
                                              1, 1, 1,
                                              2, 1, 1}, 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {1, 1, 2,
                                               1, 1, 1,
                                               3, 1, 1}, 3, 3);

    assert(!isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_isMutuallyInverseMatrices_2() {
    matrix m1 = createMatrixFromArray((int[]) {1, 0, 0,
                                               0, 1, 0,
                                               0, 0, 1}, 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {1, 0, 0,
                                               0, 1, 0,
                                               0, 0, 1}, 3, 3);

    assert(isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_isMutuallyInverseMatrices_3() {
    matrix m1 = createMatrixFromArray((int[]) {1, -2, 1,
                                               2, 1, -1,
                                               3, 2, -2}, 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {0, 2, -1,
                                               -1, 5, -3,
                                               -1, 8, -5}, 3, 3);

    assert(isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_isMutuallyInverseMatrices_4() {
    matrix m1 = createMatrixFromArray((int[]) {1, -2, 1,
                                               2, 0, -1,
                                               3, 2, -2}, 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {0, 2, -1,
                                               -1, 5, -3,
                                               -1, 8, -5}, 3, 3);

    assert(!isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_findSumOfMaxesOfPseudoDiagonal_1() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 5, 4,
                                                 1, 3, 6, 3,
                                                 3, 2, 1, 2}, 3, 4);

    assert(findSumOfMaxesOfPseudoDiagonal(m) == 20);

    freeMemMatrix(m);
}

void test_findSumOfMaxesOfPseudoDiagonal_2() {
    matrix m = createMatrixFromArray((int[]) {3, 2,
                                                 1, 3,
                                                 3, 2}, 3, 2);

    assert(findSumOfMaxesOfPseudoDiagonal(m) == 7);

    freeMemMatrix(m);
}

void test_findSumOfMaxesOfPseudoDiagonal_3() {
    matrix m = createMatrixFromArray((int[]) {3, 2,
                                              1, 3}, 2, 2);

    assert(findSumOfMaxesOfPseudoDiagonal(m) == 3);

    freeMemMatrix(m);
}

void test_getMinInArea_1() {
    matrix m = createMatrixFromArray((int[]) {10, 7, 5, 6,
                                              3, 11, 8, 9,
                                              4, 1, 12, 2}, 3, 4);

    assert(getMinInArea(m) == 5);

    freeMemMatrix(m);
}

void test_getMinInArea_2() {
    matrix m = createMatrixFromArray((int[]) {6, 8, 9, 2,
                                              7, 12, 3, 4,
                                              10, 11, 5, 1}, 3, 4);

    assert(getMinInArea(m) == 6);

    freeMemMatrix(m);
}

void test_getMinInArea_3() {
    matrix m = createMatrixFromArray((int[]) {6, 8, 1, 2,
                                              7, 12, 3, 4,
                                              10, 11, 5, 9}, 3, 4);

    assert(getMinInArea(m) == 1);

    freeMemMatrix(m);
}

void test_sortByDistances_1() {
    matrix m = createMatrixFromArray((int[]) {3, 2,
                                              1, 3}, 2, 2);

    sortByDistances(m);

    matrix expectedResult = createMatrixFromArray((int[]) {1, 3,
                                                           3, 2}, 2, 2);

    assert(areTwoMatricesEqual(m, expectedResult));

    freeMemMatrix(m);
    freeMemMatrix(expectedResult);
}

void test_sortByDistances_2() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 1,
                                              1, 3, 1,
                                              3, 3, 3}, 3, 3);

    sortByDistances(m);

    matrix expectedResult = createMatrixFromArray((int[]) {1, 3, 1,
                                                           3, 2, 1,
                                                           3, 3, 3}, 3, 3);

    assert(areTwoMatricesEqual(m, expectedResult));

    freeMemMatrix(m);
    freeMemMatrix(expectedResult);
}

void test_sortByDistances_3() {
    matrix m = createMatrixFromArray((int[]) {-3, -2, 1,
                                              1, -3, 1,
                                              3, 2, -3}, 3, 3);

    sortByDistances(m);

    matrix expectedResult = createMatrixFromArray((int[]) {1, -3, 1,
                                                           -3, -2, 1,
                                                           3, 2, -3}, 3, 3);

    assert(areTwoMatricesEqual(m, expectedResult));

    freeMemMatrix(m);
    freeMemMatrix(expectedResult);
}

void test_countEqClassesByRowsSum_1() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 1,
                                              1, 3, 1,
                                              3, 2, 3,
                                              1, 1, 1}, 4, 3);

    assert(countEqClassesByRowsSum(m) == 4);

    freeMemMatrix(m);
}

void test_countEqClassesByRowsSum_2() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 1,
                                              2, 2, 2,
                                              3, 2, 1,
                                              1, 2, 3}, 4, 3);

    assert(countEqClassesByRowsSum(m) == 1);

    freeMemMatrix(m);
}

void test_countEqClassesByRowsSum_3() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 1}, 1, 3);

    assert(countEqClassesByRowsSum(m) == 1);

    freeMemMatrix(m);
}

void test_countEqClassesByRowsSum_4() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 1,
                                              12, 12, 0,
                                              3, 2, 1,
                                              1, 2, 3,
                                              7, 8, 9}, 5, 3);

    assert(countEqClassesByRowsSum(m) == 2);

    freeMemMatrix(m);
}

void test_getNSpecialElement_1() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 1,
                                              12, 12, 0,
                                              3, 2, 1,
                                              1, 2, 3,
                                              7, 8, 9}, 5, 3);

    assert(getNSpecialElement(m) == 1);

    freeMemMatrix(m);
}

void test_getNSpecialElement_2() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 1,
                                              122, 12, 0,
                                              3, 80, 1,
                                              1, 2, 3,
                                              7, 8, 9}, 5, 3);

    assert(getNSpecialElement(m) == 3);

    freeMemMatrix(m);
}

void test_getNSpecialElement_3() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 1,
                                              12, 12, 1,
                                              3, 8, 1,
                                              1, 2, 3}, 4, 3);

    assert(getNSpecialElement(m) == 1);

    freeMemMatrix(m);
}

void test_getNSpecialElement_4() {
    matrix m = createMatrixFromArray((int[]) {10, 2, 1,
                                              12, 12, 1,
                                              1, 8, 1,
                                              1, 2, 3}, 4, 3);

    assert(getNSpecialElement(m) == 0);

    freeMemMatrix(m);
}

void test_swapPenultimateRow_1() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 1,
                                              1, 3, 5,
                                              3, 2, 3}, 3, 3);

    swapPenultimateRow(m);

    matrix expectedResult = createMatrixFromArray((int[]) {3, 2, 1,
                                                           3, 1, 3,
                                                           3, 2, 3}, 3, 3);

    assert(areTwoMatricesEqual(m, expectedResult));

    freeMemMatrix(m);
    freeMemMatrix(expectedResult);
}

void test_swapPenultimateRow_2() {
    matrix m = createMatrixFromArray((int[]) {3, 1, 1,
                                              6, 3, 5,
                                              3, 2, 3}, 3, 3);

    swapPenultimateRow(m);

    matrix expectedResult = createMatrixFromArray((int[]) {3, 1, 1,
                                                           1, 3, 2,
                                                           3, 2, 3}, 3, 3);

    assert(areTwoMatricesEqual(m, expectedResult));

    freeMemMatrix(m);
    freeMemMatrix(expectedResult);
}

void test_swapPenultimateRow_3() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 1,
                                              1, 3, 2,
                                              3, 1, 3}, 3, 3);

    swapPenultimateRow(m);

    matrix expectedResult = createMatrixFromArray((int[]) {3, 2, 1,
                                                           3, 1, 3,
                                                           3, 1, 3}, 3, 3);

    assert(areTwoMatricesEqual(m, expectedResult));

    freeMemMatrix(m);
    freeMemMatrix(expectedResult);
}

void test_swapPenultimateRow_4() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 1, 0,
                                              1, 3, 2, 8,
                                              3, 1, 3, 6,
                                              5, 5, 5, 5}, 4, 4);

    swapPenultimateRow(m);

    matrix expectedResult = createMatrixFromArray((int[]) {3, 2, 1, 0,
                                                           1, 3, 2, 8,
                                                           0, 8, 6, 5,
                                                           5, 5, 5, 5}, 4, 4);

    assert(areTwoMatricesEqual(m, expectedResult));

    freeMemMatrix(m);
    freeMemMatrix(expectedResult);
}

void test_countNonDescendingRowsMatrices_1() {
    matrix *ms = createArrayOfMatrixFromArray((int[]) {1, 2,
                                                             3, 4, 5, 6,
                                                                   7, 8, 1, 5,
                                                                         0, 5}, 3, 2, 2);

    assert(countNonDescendingRowsMatrices(ms, 3) == 3);

    freeMemMatrices(ms, 3);
}

void test_countNonDescendingRowsMatrices_2() {
    matrix *ms = createArrayOfMatrixFromArray((int[]) {1, 1,
                                                             3, 4, 5, 5,
                                                                   7, 7, 1, 1,
                                                                         0, 0}, 3, 2, 2);

    assert(countNonDescendingRowsMatrices(ms, 3) == 3);

    freeMemMatrices(ms, 3);
}

void test_countNonDescendingRowsMatrices_3() {
    matrix *ms = createArrayOfMatrixFromArray((int[]) {1, 2, 3,
                                                             3, 4, 5,
                                                             6, 7, 8,
                                                                     1, 5, 0,
                                                                     3, 4, 3,
                                                                     8, 9, 9}, 2, 3, 3);

    assert(countNonDescendingRowsMatrices(ms, 2) == 1);

    freeMemMatrices(ms, 2);
}

void test_countNonDescendingRowsMatrices_4() {
    matrix *ms = createArrayOfMatrixFromArray((int[]) {1, 2, 3,
                                                             3, 4, 5,
                                                             9, 7, 8,
                                                                     1, 5, 0,
                                                                     3, 4, 3,
                                                                     8, 9, 9}, 2, 3, 3);

    assert(countNonDescendingRowsMatrices(ms, 2) == 0);

    freeMemMatrices(ms, 2);
}

void test_countZeroRows_1() {
    matrix m = createMatrixFromArray((int[]) {10, 2, 1,
                                              12, 12, 1,
                                              1, 8, 1,
                                              1, 2, 3}, 4, 3);

    assert(countZeroRows(m) == 0);

    freeMemMatrix(m);
}

void test_countZeroRows_2() {
    matrix m = createMatrixFromArray((int[]) {10, 0, 0,
                                              0, 12, 1,
                                              1, 8, 0,
                                              1, 2, 3}, 4, 3);

    assert(countZeroRows(m) == 0);

    freeMemMatrix(m);
}

void test_countZeroRows_3() {
    matrix m = createMatrixFromArray((int[]) {0, 0, 0,
                                              12, 12, 1,
                                              1, 8, 1,
                                              0, 0, 0}, 4, 3);

    assert(countZeroRows(m) == 2);

    freeMemMatrix(m);
}

void test_countZeroRows_4() {
    matrix m = createMatrixFromArray((int[]) {10, 0, 1,
                                              12, 0, 1,
                                              0, 0, 1,
                                              1, 0, 3}, 4, 3);

    assert(countZeroRows(m) == 0);

    freeMemMatrix(m);
}

void test_countZeroRows_5() {
    matrix m = createMatrixFromArray((int[]) {0, 0, 0,
                                              0, 0, 0,
                                              0, 0, 0}, 3, 3);

    assert(countZeroRows(m) == 3);

    freeMemMatrix(m);
}

void test_getNorm_1() {
    matrix m = createMatrixFromArray((int[]) {3, 4, 5,
                                              6, 7, -7,
                                              -6, -5, -2}, 3, 3);

    assert(getNorm(m) == 7);

    freeMemMatrix(m);
}

void test_getNorm_2() {
    matrix m = createMatrixFromArray((int[]) {3, 9, 5,
                                              6, 7, -7,
                                              -6, -5, 2}, 3, 3);

    assert(getNorm(m) == 9);

    freeMemMatrix(m);
}

void test_getNorm_3() {
    matrix m = createMatrixFromArray((int[]) {3, 4, 5,
                                              6, 7, -7,
                                              -6, -5, -2,
                                              1, -10, -1}, 4, 3);

    assert(getNorm(m) == 10);

    freeMemMatrix(m);
}

void test_getNorm_4() {
    matrix m = createMatrixFromArray((int[]) {13, 4, 5,
                                              6, 7, -7,
                                              -6, -5, -2,
                                              1, 2, -12}, 4, 3);

    assert(getNorm(m) == 13);

    freeMemMatrix(m);
}

void test_getNorm() {
    test_getNorm_1();
    test_getNorm_2();
    test_getNorm_3();
    test_getNorm_4();
}

void test_countZeroRows() {
    test_countZeroRows_1();
    test_countZeroRows_2();
    test_countZeroRows_3();
    test_countZeroRows_4();
    test_countZeroRows_5();
}

void test_countNonDescendingRowsMatrices() {
    test_countNonDescendingRowsMatrices_1();
    test_countNonDescendingRowsMatrices_2();
    test_countNonDescendingRowsMatrices_3();
    test_countNonDescendingRowsMatrices_4();
}

void test_swapPenultimateRow() {
    test_swapPenultimateRow_1();
    test_swapPenultimateRow_2();
    test_swapPenultimateRow_3();
    test_swapPenultimateRow_4();
}

void test_getNSpecialElement() {
    test_getNSpecialElement_1();
    test_getNSpecialElement_2();
    test_getNSpecialElement_3();
    test_getNSpecialElement_4();
}

void test_countEqClassesByRowsSum() {
    test_countEqClassesByRowsSum_1();
    test_countEqClassesByRowsSum_2();
    test_countEqClassesByRowsSum_3();
    test_countEqClassesByRowsSum_4();
}

void test_sortByDistances() {
    test_sortByDistances_1();
    test_sortByDistances_2();
    test_sortByDistances_3();
}

void test_getMinInArea() {
   test_getMinInArea_1();
   test_getMinInArea_2();
   test_getMinInArea_3();
}

void test_findSumOfMaxesOfPseudoDiagonal() {
    test_findSumOfMaxesOfPseudoDiagonal_1();
    test_findSumOfMaxesOfPseudoDiagonal_2();
    test_findSumOfMaxesOfPseudoDiagonal_3();
}

void test_isMutuallyInverseMatrices() {
    test_isMutuallyInverseMatrices_1();
    test_isMutuallyInverseMatrices_2();
    test_isMutuallyInverseMatrices_3();
    test_isMutuallyInverseMatrices_4();
}

void test_transposeIfMatrixHasNotEqualSumOfRows() {
    test_transposeIfMatrixHasNotEqualSumOfRows_1();
    test_transposeIfMatrixHasNotEqualSumOfRows_2();
    test_transposeIfMatrixHasNotEqualSumOfRows_3();
}

void test_getSquareOfMatrixIfSymmetric() {
    test_getSquareOfMatrixIfSymmetric_1();
    test_getSquareOfMatrixIfSymmetric_2();
    test_getSquareOfMatrixIfSymmetric_3();
    test_getSquareOfMatrixIfSymmetric_4();
}

void test_sortColsByMinElement() {
    test_sortColsByMinElement_1();
    test_sortColsByMinElement_2();
    test_sortColsByMinElement_3();
}

void test_sortRowsByMaxElement() {
    test_sortRowsByMaxElement_1();
    test_sortRowsByMaxElement_2();
    test_sortRowsByMaxElement_3();
}

void test_swapRowsContainingMinAndMaxElements() {
    test_swapRowsContainingMinAndMaxElements_1();
    test_swapRowsContainingMinAndMaxElements_2();
    test_swapRowsContainingMinAndMaxElements_3();
}

void test_secondPartOfAssigment() {
    test_swapRowsContainingMinAndMaxElements();
    test_sortRowsByMaxElement();
    test_sortColsByMinElement();
    test_getSquareOfMatrixIfSymmetric();
    test_transposeIfMatrixHasNotEqualSumOfRows();
    test_isMutuallyInverseMatrices();
    test_findSumOfMaxesOfPseudoDiagonal();
    test_getMinInArea();
    test_sortByDistances();
    test_countEqClassesByRowsSum();
    test_getNSpecialElement();
    test_swapPenultimateRow();
    test_countNonDescendingRowsMatrices();
    test_countZeroRows();
    test_getNorm();
}

int main() {
    test_firstPartOfAssigment();
    test_secondPartOfAssigment();

    matrix *ms = createArrayOfMatrixFromArray((int[]) {2, -1,
                                                       3, 4,
                                                       9, 9, -8, 9,
                                                              -2, 10,
                                                              3, 3, 1, 1,
                                                                    9, 7,
                                                                    5, 6}, 3, 3, 2);
    printMatricesWithMinNorms(ms, 3);

    freeMemMatrices(ms, 3);

    return 0;
}
