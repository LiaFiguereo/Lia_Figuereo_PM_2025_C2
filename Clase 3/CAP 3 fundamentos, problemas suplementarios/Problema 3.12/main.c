#include <stdio.h>
#include <stdlib.h>

int main()
{
    int NUM;

    //leer numero entero positivo
    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &NUM);

    printf("Numeros primos menores que %d:\n", NUM);

// Recorre los números desde 2 hasta NUM -1
    for (int i = 2; i < NUM; i++) {
        int esPrimo = 1;  // Suponemos que i es primo

        // Verificar si i es divisible por algún número entre 2 e i/2
        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                esPrimo = 0;  // No es primo
                break;        // Salimos del ciclo
            }
        }

        if (esPrimo) {
            printf("%d ", i);  // Imprime si es primo
        }
    }

    printf("\n");
    return 0;
}
