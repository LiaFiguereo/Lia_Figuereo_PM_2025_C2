#include <stdio.h>
/* Mayor divisor.
El programa, al recibir como dato un n�mero entero positivo, calcula su mayor divisor. */
int mad(int); /* Prototipo de funci�n. */

void main(void)
{
    int NUM, RES;
    printf("\nIngresa el n�mero: ");
    scanf("%d", &NUM);
    RES = mad(NUM);
    printf("\nEl mayor divisor de %d es: %d", NUM, RES);
}

int mad(int N1)
/* Esta funci�n calcula el mayor divisor del n�mero N1. */
{
    int I = (N1 / 2);
    /* I se inicializa con el m�ximo valor posible que puede ser divisor de N1. */
    while (N1 % I)
    /* El ciclo se mantiene activo mientras (N1 % I) sea distinto de cero. Cuando el resultado sea 0, se detiene, ya que se habr� encontrado el mayor divisor de N1. */
        I--;
    return I;
}
