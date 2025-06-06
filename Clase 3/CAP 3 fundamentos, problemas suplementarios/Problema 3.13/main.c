#include <stdio.h>

// Función auxiliar que verifica si un número es primo
int esPrimo(int num) {
    if (num < 2) return 0;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0)
            return 0; // No es primo
    }
    return 1; // Es primo
}

int main() {
    int N1, N2;

    // Leer los dos números
    printf("Ingrese el primer número entero positivo: ");
    scanf("%d", &N1);

    printf("Ingrese el segundo número entero positivo: ");
    scanf("%d", &N2);

    // Asegurarse de que N1 sea menor que N2
    if (N1 > N2) {
        int temp = N1;
        N1 = N2;
        N2 = temp;
    }

    printf("Primos gemelos entre %d y %d:\n", N1, N2);

    // Buscar primos gemelos
    for (int i = N1; i <= N2 - 2; i++) {
        if (esPrimo(i) && esPrimo(i + 2)) {
            printf("(%d, %d)\n", i, i + 2);
        }
    }

    return 0;
}
