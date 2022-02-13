#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "libs/data_structures/matrix/matrix.h"

int criteria (int *a, int n) {
    return a[0];
}

int main() {
    matrix m = getMemMatrix(4, 4);
    inputMatrix(m);

    insertionSortColsMatrixByColCriteria(m, criteria);

    outputMatrix(m);

    return 0;
}
