#include <stdio.h>

int main() {
    int N = 10;  // Número de filas, según el ejemplo

    // Bucle para cada fila desde 1 hasta N
    for (int i = 1; i <= N; i++) {
        int start = i % 10;      // Número inicial para la fila i
        int mid = i;             // Cantidad de números ascendentes (el pico)
        int num = start;

        // Parte ascendente: imprimir 'mid' números incrementando módulo 10
        for (int k = 1; k <= mid; k++) {
            printf("%d ", num);
            num = (num + 1) % 10;  // Sumar 1 y ajustar módulo 10
        }

        // Para la parte descendente, retrocedemos dos pasos para evitar repetir el pico
        num = (num - 2 + 10) % 10;

        // Parte descendente: imprimir 'mid - 1' números decreciendo módulo 10
        for (int k = 1; k <= mid - 1; k++) {
            printf("%d ", num);
            num = (num - 1 + 10) % 10;  // Restar 1 y ajustar módulo 10
        }

        printf("\n");  // Salto de línea al terminar la fila
    }

    return 0;
}
