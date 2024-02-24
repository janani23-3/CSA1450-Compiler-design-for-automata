#include <stdio.h>

int main() {
    int a = 5, b = 10, c = 15, d = 20, e, f, g;

    // Original code
    e = a + b * c;
    f = a + b * c;
    g = a * b + c;

    printf("Original code:\n");
    printf("e = %d\n", e);
    printf("f = %d\n", f);
    printf("g = %d\n", g);

    // Optimized code
    int temp = b * c;
    e = a + temp;
    f = a + temp;
    g = a * b + c;

    printf("\nOptimized code (after common subexpression elimination):\n");
    printf("e = %d\n", e);
    printf("f = %d\n", f);
    printf("g = %d\n", g);

    return 0;
}

