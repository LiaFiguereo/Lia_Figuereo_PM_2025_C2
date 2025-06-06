#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;

    printf("Ingrese N: ");
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        // Parte ascendente
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        // Parte descendente
        for (int j = i - 1; j >= 1; j--) {
            printf("%d ", j);
        }
        printf("\n"); // salto de línea
    }

    return 0;
}
