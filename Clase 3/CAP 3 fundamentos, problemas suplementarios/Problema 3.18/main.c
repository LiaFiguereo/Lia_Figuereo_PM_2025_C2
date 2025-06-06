#include <stdio.h>

int main() {
    int N;

    // Pedimos al usuario el valor de N
    printf("Ingrese N: ");
    scanf("%d", &N);

    // Bucle exterior que controla cada fila desde 1 hasta N
    for (int i = 1; i <= N; i++) {
        // Calculamos el l�mite para la fila actual
        // En la fila i, el l�mite es N - i + 1
        int limite = N - i + 1;

        // Imprimir n�meros ascendentes desde 1 hasta limite
        for (int j = 1; j <= limite; j++) {
            printf("%d ", j);
        }

        // Imprimir n�meros descendentes desde limite hasta 1
        for (int j = limite; j >= 1; j--) {
            printf("%d ", j);
        }

        // Salto de l�nea para pasar a la siguiente fila
        printf("\n");
    }

    return 0;
}
