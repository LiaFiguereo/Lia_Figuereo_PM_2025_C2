#include <stdio.h>

int main() {
    int N = 10;  // N�mero de filas, seg�n el ejemplo

    // Bucle para cada fila desde 1 hasta N
    for (int i = 1; i <= N; i++) {
        int start = i % 10;      // N�mero inicial para la fila i
        int mid = i;             // Cantidad de n�meros ascendentes (el pico)
        int num = start;

        // Parte ascendente: imprimir 'mid' n�meros incrementando m�dulo 10
        for (int k = 1; k <= mid; k++) {
            printf("%d ", num);
            num = (num + 1) % 10;  // Sumar 1 y ajustar m�dulo 10
        }

        // Para la parte descendente, retrocedemos dos pasos para evitar repetir el pico
        num = (num - 2 + 10) % 10;

        // Parte descendente: imprimir 'mid - 1' n�meros decreciendo m�dulo 10
        for (int k = 1; k <= mid - 1; k++) {
            printf("%d ", num);
            num = (num - 1 + 10) % 10;  // Restar 1 y ajustar m�dulo 10
        }

        printf("\n");  // Salto de l�nea al terminar la fila
    }

    return 0;
}
