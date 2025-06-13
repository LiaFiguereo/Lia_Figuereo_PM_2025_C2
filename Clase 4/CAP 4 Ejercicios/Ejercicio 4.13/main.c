#include <stdio.h>
#include <math.h>
/* Pares e impares.
El programa, al recibir como datos N n�meros enteros, calcula cu�ntos de ellos son pares y cu�ntos impares, con la ayuda de una funci�n. */
void parimp(int, int *, int *); /* Prototipo de funci�n. */

void main(void)
{
    int I, N, NUM, PAR = 0, IMP = 0;
    printf("Ingresa el n�mero de datos: ");
    scanf("%d", &N);
    for (I = 1; I <= N; I++)
    {
        printf("Ingresa el n�mero %d:", I);
        scanf("%d", &NUM);
        parimp(NUM, &PAR, &IMP);
        /* Llamada a la funci�n. Paso de par�metros por valor y por referencia. */
    }
    printf("\nN�mero de pares: %d", PAR);
    printf("\nN�mero de impares: %d", IMP);
}

void parimp(int NUM, int *P, int *I)
/* La funci�n incrementa el par�metro *P o *I, seg�n sea el n�mero par o impar. */
{
    int RES;
    RES = pow(-1, NUM);
    if (RES > 0)
        *P += 1;
    else
        if (RES < 0)
            *I += 1;
}
