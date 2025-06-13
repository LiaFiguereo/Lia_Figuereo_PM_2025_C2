#include <stdio.h>
/* Productoria.
El programa calcula la productoria de los N primeros n�meros naturales. */
int Productoria(int); /* Prototipo de funci�n. */

void main(void)
{
    int NUM;
    /* Se escribe un do-while para verificar que el n�mero del cual se quiere calcular la productoria sea correcto. */
    do
    {
        printf("Ingresa el n�mero del cual quieres calcular la productoria: ");
        scanf("%d", &NUM);
    }
    while (NUM > 100 || NUM < 1);
    printf("\nLa productoria de %d es: %d", NUM, Productoria(NUM));
}

int Productoria(int N)
/* La funci�n calcula la productoria de N. */
{
    int I, PRO = 1;
    for (I = 1; I <= N; I++)
        PRO *= I;
    return (PRO);
}
