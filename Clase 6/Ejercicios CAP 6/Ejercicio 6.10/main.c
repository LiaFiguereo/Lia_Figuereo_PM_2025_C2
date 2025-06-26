#include <stdio.h>
/* Cuadrado m�gico.
El programa genera un cuadrado m�gico siguiendo los criterios enunciados anteriormente. */
const int MAX = 50;

void Cuadrado(int [][MAX], int);
void Imprime(int [][MAX], int);

int main(void) {
    int CMA[MAX][MAX] = {0}, TAM;

    do {
        printf("Ingrese el tama�o impar de la matriz: ");
        scanf("%d", &TAM);
    } while ((TAM > MAX || TAM < 1) || (TAM % 2 == 0));
    /* Se verifica que TAM sea v�lido y adem�s impar */

    Cuadrado(CMA, TAM);
    Imprime(CMA, TAM);

    return 0;
}

void Cuadrado(int A[][MAX], int N) {
    int I = 1, FIL = 0, COL = N / 2, NUM = N * N;

    while (I <= NUM) {
        A[FIL][COL] = I;
        if (I % N != 0) {
            FIL = (FIL - 1 + N) % N;  // Mover hacia arriba (con wrap-around)
            COL = (COL + 1) % N;      // Mover hacia la derecha (con wrap-around)
        } else {
            FIL++;  // Mover hacia abajo si es m�ltiplo de N
        }
        I++;
    }
}

void Imprime(int A[][MAX], int N) {
    int I, J;
    printf("\nCuadrado m�gico de orden %d:\n", N);
    for (I = 0; I < N; I++) {
        for (J = 0; J < N; J++) {
            printf("%4d ", A[I][J]);
        }
        printf("\n");
    }
}
