#include <stdio.h>
#include "libs/data_structures/vector/vector.h"


int main() {
    int n, newCapacity;
    scanf("%d %d", &n, &newCapacity);

    vector v = createVector(n);

    inputVector(&v, n);

    reserve(&v, newCapacity);

    shrinkToFit(&v);

    outputVector(v);
    printf("%d", v.capacity);

    return 0;
}
