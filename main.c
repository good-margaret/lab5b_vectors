#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "libs/data_structures/matrix/matrix.h"



int main() {
    matrix m = getMemMatrix(5, 5);
    inputMatrix(m);
    swapRows(m, 0, 4);
    outputMatrix(m);

    return 0;
}
