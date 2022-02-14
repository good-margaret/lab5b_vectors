//
// Created by 1 on 12.02.2022.
//

#include "matrix.h"
#include <malloc.h>
#include <stdio.h>
#include <memory.h>

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);

    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);

    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *matrices = (matrix *) malloc(sizeof(matrix) * nMatrices);

    for (int i = 0; i < nMatrices; i++)
        matrices[i] = getMemMatrix(nRows, nCols);

    return matrices;
}

void freeMemMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        free(m.values[i]);

    free(m.values);
}

void freeMemMatrices(matrix *matrices, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix(matrices[i]);
}

void inputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            scanf("%d", &m.values[i][j]);
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        inputMatrix(ms[i]);
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++)
            printf("%d ", m.values[i][j]);

        printf("\n");
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        outputMatrix(ms[i]);

    printf("\n");
}

void swapRows(matrix m, int i1, int i2) {
    int *t = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = t;
}

void swapColumns(matrix m, int j1, int j2) {
    for (int i = 0; i < m.nRows; i++) {
        int t = m.values[i][j1];
        m.values[i][j1] = m.values[i][j2];
        m.values[i][j2] = t;
    }
}


void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(const int *, int)) {
    int *criteriaArray = (int *) malloc(sizeof(int) * m.nRows);

    for (int i = 0; i < m.nRows; i++)
        criteriaArray[i] = criteria(m.values[i], m.nCols);

    for (int i = 1; i < m.nRows; i++) {
        int *t1 = m.values[i];
        int t2 = criteriaArray[i];
        int j = i - 1;
        while (j >= 0 && t2 < criteriaArray[j]) {
            criteriaArray[j + 1] = criteriaArray[j];
            m.values[j + 1] = m.values[j];
            j--;
        }

        criteriaArray[j + 1] = t2;
        m.values[j + 1] = t1;
    }

    free(criteriaArray);
}

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(const int *, int)) {
    int *criteriaArray = (int *) malloc(sizeof(int) * m.nCols);

    for (int i = 0; i < m.nCols; i++) {
        int *col = (int *) malloc(sizeof(int) * m.nRows);

        for (int j = 0; j < m.nRows; j++)
            col[j] = m.values[j][i];

        criteriaArray[i] = criteria(col, m.nRows);

        free(col);
    }

    for (int i = 1; i < m.nCols; i++) {
        int t = criteriaArray[i];
        int j = i - 1;
        while (j >= 0 && t < criteriaArray[j]) {
            criteriaArray[j + 1] = criteriaArray[j];
            swapColumns(m, j + 1, j);
            j--;
        }

        criteriaArray[j + 1] = t;
    }

    free(criteriaArray);
}

bool isSquareMatrix(matrix m) {
    return m.nCols == m.nRows;
}

bool areTwoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;

    for (int i = 0; i < m1.nRows; i++)
        if (memcmp(m1.values[i], m2.values[i], sizeof(int) * m1.nCols) != 0)
            return false;

    return true;
}

bool isEMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return false;

    for (int i = 0; i < m.nRows; i++) {
        int *eMatrixRow = (int *) calloc(m.nCols, sizeof(int));
        eMatrixRow[i] = 1;

        if (memcmp(m.values[i], eMatrixRow, sizeof(int) * m.nCols) != 0)
            return false;

        free(eMatrixRow);
    }

    return true;
}

bool isSymmetricMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return false;

    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] != m.values[j][i])
                return false;

    return true;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void transposeSquareMatrix(matrix m) {
    for (int i = 0; i < m.nCols; i++)
        for (int j = i; j < m.nRows; j++)
            swap(&m.values[i][j], &m.values[j][i]);
}

position getMinValuePos(matrix m) {
    position minPos = (position) {0, 0};

    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] < m.values[minPos.rowIndex][minPos.colIndex])
                minPos = (position) {i, j};

    return minPos;
}

position getMaxValuePos(matrix m) {
    position maxPos = (position) {0, 0};

    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] > m.values[maxPos.rowIndex][maxPos.colIndex])
                maxPos = (position) {i, j};

    return maxPos;
}

matrix createMatrixFromArray(const int *a, int nRows, int nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values,
                                     int nMatrices, int nRows, int nCols) {
    matrix *matrices = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                matrices[k].values[i][j] = values[l++];

    return matrices;
}

void swapRowsContainingMinAndMaxElements(matrix m) {
    swapRows(m, getMinValuePos(m).rowIndex, getMaxValuePos(m).rowIndex);
}

int getMax(const int *a, int n) {
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    return max;
}

void sortRowsByMaxElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

int getMin(const int *a, int n) {
    int min = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < min)
            min = a[i];

    return min;
}

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}
