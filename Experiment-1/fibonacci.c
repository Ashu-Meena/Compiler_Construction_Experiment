#include <stdio.h>

int main() {
    int n, a = 0, b = 1, c, i;

    printf("Enter number of terms: ");
    if (scanf("%d", &n) != 1) return 0;

    printf("Fibonacci series: ");

    for (i = 1; i <= n; i++) {
        printf("%d ", a);

        c = a + b;
        a = b;
        b = c;
    }

    printf("\n");
    return 0;
}
