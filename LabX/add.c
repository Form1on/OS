#include <stdio.h>


void add(int *a, int *b, int *c, int *result) {
    *result = *a + *b + *c;
}

int main() {
    int a = 1, b = 2, c = 2, result;

    add(&a, &b, &c, &result);

    printf("sum: %d\n", result);

    return 0;
}
