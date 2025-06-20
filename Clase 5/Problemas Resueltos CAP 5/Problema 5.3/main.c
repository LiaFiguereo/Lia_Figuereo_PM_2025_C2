#include <stdio.h>
/* Primos.
El programa almacena en un arreglo unidimensional los primeros 100 números
➥primos. */

#define TAM 100 // Use #define for the array size


// Prototipos de funciones.
void Imprime(int *, int);
void Primo(int, int *);

void main(void)
{
    // Inicializamos P[0] con 2, el primer numero primo real.
    // El bucle comenzara a buscar desde el siguiente primo (3).
    int P[TAM] = {2};
    int FLA = 0;         // Indicador si el numero es primo (1) o no (0).
    int J =1;          // Indice para el arreglo P, ya que P[0] ya tiene el 2.
    int PRI = 3;        // El numero candidato a ser primo, empezamos con 3.

    // El bucle continua hasta que encontramos 'TAM' (100) numeros primos.
    while (J < TAM) // Cambiado a 'J < TAM' porque el indice va de 0 a 99.
    {
        FLA = 1;            // Asumimos que PRI es primo al inicio de cada iteracion.
        Primo(PRI, &FLA);   /* Se llama a la funcion que determina si PRI es primo. */

        if (FLA)            /* Si FLA es 1, entonces PRI es primo. */
        {
            P[J] = PRI;     // Almacena el numero primo en el arreglo.
            J++;            // Incrementa el indice para el siguiente primo.
        }
        PRI += 2;           // Incrementa PRI en 2 para revisar solo numeros impares.
    }
    Imprime(P, TAM); // Imprime el arreglo de los primeros 100 numeros primos.
}

void Primo(int A, int *B)
/* Esta funcion determina si A es primo, en cuyo caso el valor de *B no se
➥altera (sigue siendo 1). Si no es primo, *B se convierte en 0. */
{
    int DI = 3; // DI (divisor) empieza en 3.
    // Optimizacion: solo necesitamos verificar divisores hasta la raiz cuadrada de A.
    // Ademas, solo verificamos divisores impares, ya que 'A' ya es impar (despues de 2).
    while (*B && (DI * DI <= A)) // Condicion optimizada: DI * DI <= A
    {
        if ((A % DI) == 0) // Si A es divisible por DI, no es primo.
        {
            *B = 0;        // Marca A como no primo.
        }
        DI += 2;           // Incrementa el divisor en 2 para verificar solo impares.
    }
}

void Imprime(int Primos[], int T)
/* Esta funcion imprime el arreglo unidimensional de numeros primos. */
{
    int I;
    printf("Los primeros %d numeros primos son:\n", T); // Encabezado para la impresion.
    for (I = 0; I < T; I++)
    {
        printf("Primos[%d]: %d\n", I, Primos[I]); // Mejorado el formato de impresion.
    }
}
