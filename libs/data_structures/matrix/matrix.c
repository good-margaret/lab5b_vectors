//
// Created by 1 on 12.02.2022.
//

#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <math.h>

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
        for (int j = i + 1; j < m.nCols; j++)
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

matrix mulMatrices(matrix m1, matrix m2) {
    matrix m = getMemMatrix(m1.nRows, m2.nCols);

    for (int i = 0; i < m1.nRows; i++)
        for (int j = 0; j < m2.nCols; j++) {
            m.values[i][j] = 0;

            for (int k = 0; k < m1.nCols; k++)
                m.values[i][j] += m1.values[i][k] * m2.values[k][j];
        }

    return m;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m))
        *m = mulMatrices(*m, *m);
}

int comp(const void *a, const void *b) {
    const long long *arg1 = a;
    const long long *arg2 = b;

    if (*arg1 < *arg2)
        return -1;
    else if (*arg1 > *arg2)
        return 1;
    else
        return 0;
}

bool isUnique(const long long *a, int n) {
    long long *b = (long long *) malloc(sizeof(long long) * n);

    memcpy(b, a, sizeof(long long) * n);

    qsort(b, n, sizeof(long long), comp);

    for (int i = 0; i < n - 1; i++)
        if (b[i] == b[i + 1]) {
            free(b);
            return false;
        }

    free(b);

    return true;
}

long long getSum(const int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];

    return sum;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    long long *sumArray = (long long *) malloc(sizeof(long long) * m.nRows);

    for (int i = 0; i < m.nRows; i++)
        sumArray[i] = getSum(m.values[i], m.nCols);

    if (isUnique(sumArray, m.nRows))
        transposeSquareMatrix(m);

    free(sumArray);
}

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix m = mulMatrices(m1, m2);
    bool isEMat = isEMatrix(m);
    freeMemMatrix(m);

    return isEMat;
}

/*long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    long long sumMax = 0;

    for (int i = 1; i < m.nCols; i++) {
        position pos = (position) {1, i + 1};
        int max = m.values[0][i];

        while (pos.rowIndex < m.nRows && pos.colIndex < m.nCols) {
            if (m.values[pos.rowIndex][pos.colIndex] > max)
                max = m.values[pos.rowIndex][pos.colIndex];
            pos.rowIndex++;
            pos.colIndex++;
        }

        sumMax += max;
    }

    for (int i = 1; i < m.nRows; i++) {
        position pos = (position) {i + 1, 1};
        int max = m.values[i][0];

        while (pos.rowIndex < m.nRows && pos.colIndex < m.nCols) {
            if (m.values[pos.rowIndex][pos.colIndex] > max)
                max = m.values[pos.rowIndex][pos.colIndex];
            pos.rowIndex++;
            pos.colIndex++;
        }

        sumMax += max;
    }

    return sumMax;
}
*/

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int *maxArray = (int *) malloc(sizeof(int) * (m.nRows + m.nCols - 1));
    for (int i = 1; i < m.nRows; i++) {
        maxArray[m.nRows - 1 - i] = m.values[i][0];
    }
    memcpy(maxArray + m.nRows - 1, m.values[0], sizeof(int) * m.nCols);

    for (int i = 1; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] > maxArray[m.nRows - i + j - 1])
                maxArray[m.nRows - i + j - 1] = m.values[i][j];

    long long sumOfMaxesOfPseudoDiagonal = getSum(maxArray, m.nRows + m.nCols - 1) - maxArray[m.nRows - 1];

    free(maxArray);

    return sumOfMaxesOfPseudoDiagonal;
}

int min2(int a, int b) {
    return a < b ? a : b;
}

int max2(int a, int b) {
    return a > b ? a : b;
}

int getMinInArea(matrix m) {
    position maxPos = getMaxValuePos(m);
    int min = m.values[maxPos.rowIndex][maxPos.colIndex];

    for (int i = 1; i <= maxPos.rowIndex; i++) {
        int leftCol = max2(maxPos.colIndex - i, 0);
        int rightCol = min2(maxPos.colIndex + i, m.nCols - 1);

        min = min2(min, getMin(m.values[maxPos.rowIndex - i] + leftCol, rightCol - leftCol + 1));
    }

    return min;
}

float getDistance(const int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i] * a[i];

    return sqrt(sum);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(const int *, int)) {
    float *criteriaArray = (float *) malloc(sizeof(float) * m.nRows);

    for (int i = 0; i < m.nRows; i++)
        criteriaArray[i] = criteria(m.values[i], m.nCols);

    for (int i = 1; i < m.nRows; i++) {
        int *t1 = m.values[i];
        float t2 = criteriaArray[i];
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

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

int cmp_long_long(const void *pa, const void *pb) {
    long long arg1 = *(long long *) pa;
    long long arg2 = *(long long *) pb;

    if (arg1 < arg2)
        return -1;
    else if (arg1 > arg2)
        return 1;
    else
        return 0;
}

int countNUnique(const long long *a, int n) {
    if (n == 0)
        return 0;

    long long curElement = a[0];
    int nUnique = 1;

    for (int i = 1; i < n; i++)
        if (a[i] != curElement) {
            nUnique++;
            curElement = a[i];
        }

    return nUnique;
}

int countEqClassesByRowsSum(matrix m) {
    long long *sumArray = (long long *) malloc(sizeof(long long) * m.nRows);

    for (int i = 0; i < m.nRows; i++)
        sumArray[i] = getSum(m.values[i], m.nCols);

    qsort(sumArray, m.nRows, sizeof(long long), cmp_long_long);

    int nUnique = countNUnique(sumArray, m.nRows);

    free(sumArray);

    return nUnique;
}

int getNSpecialElement(matrix m) {
    int nSpecial = 0;

    for (int i = 0; i < m.nCols; i++) {
        int *colArray = (int *) malloc(sizeof(int) * m.nRows);
        for (int j = 0; j < m.nRows; j++)
            colArray[j] = m.values[j][i];

        if (2 * getMax(colArray, m.nRows) - getSum(colArray, m.nRows) > 0)
            nSpecial++;

        free(colArray);
    }

    return nSpecial;
}

position getLeftMin(matrix m) {
    position posMin = (position) {0, 0};

    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] < m.values[posMin.rowIndex][posMin.colIndex] ||
                m.values[i][j] == m.values[posMin.rowIndex][posMin.colIndex] && j < posMin.colIndex)
                posMin = (position) {i, j};

    return posMin;
}

void swapThatRow(matrix m, int rowIndex) {
    int colIndex = getLeftMin(m).colIndex;
    int *newRow = (int *) malloc(sizeof(int) * m.nCols);

    for (int i = 0; i < m.nRows; i++)
        newRow[i] = m.values[i][colIndex];

    free(m.values[rowIndex]);

    m.values[rowIndex] = newRow;
}

void swapPenultimateRow(matrix m) {
    swapThatRow(m, m.nRows - 2);
}

bool isNonDescendingSorted(const int *a, int n) {
    for (int i = 1; i < n; i++)
        if (a[i] < a[i - 1])
            return false;

    return true;
}

bool hasAllNonDescendingRows(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        if (!isNonDescendingSorted(m.values[i], m.nCols))
            return false;

    return true;
}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int nonDescendingCount = 0;
    for (int i = 0; i < nMatrix; i++) {
        if (hasAllNonDescendingRows(ms[i]))
            nonDescendingCount++;
    }

    return nonDescendingCount;
}

int countValues(const int *a, int n, int value) {
    int countValuesInArray = 0;
    for (int i = 0; i < n; i++)
        countValuesInArray += a[i] == value;

    return countValuesInArray;
}

int countZeroRows(matrix m) {
    int nZeroRows = 0;
    for (int i = 0; i < m.nRows; i++)
        nZeroRows += countValues(m.values[i], m.nCols, 0) == m.nCols;

    return nZeroRows;
}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int *zeroRowsInMatrices = (int *) malloc(sizeof(int) * nMatrix);

    for (int i = 0; i < nMatrix; i++)
        zeroRowsInMatrices[i] = countZeroRows(ms[i]);

    int maxNumberOfZeroRows = getMax(zeroRowsInMatrices, nMatrix);

    for (int i = 0; i < nMatrix; i++)
        if (zeroRowsInMatrices[i] == maxNumberOfZeroRows)
            outputMatrix(ms[i]);

    free(zeroRowsInMatrices);
}
