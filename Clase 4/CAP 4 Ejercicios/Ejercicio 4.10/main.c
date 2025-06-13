#include <stdio.h>
/* M�ltiplo.
El programa, al recibir como datos dos n�meros enteros, determina si el segundo es m�ltiplo del primero. */
int multiple(int, int); /* Prototipo de funci�n. */

void main(void)
{
    int NU1, NU2, RES;
    printf("\nIngresa los dos n�meros: ");
    scanf("%d %d", &NU1, &NU2);
    RES = multiple(NU1, NU2);
    if (RES)
        printf("\nEl segundo n�mero es m�ltiplo del primero");
    else
        printf("\nEl segundo n�mero no es m�ltiplo del primero");
}

int multiple(int N1, int N2)
/* Esta funci�n determina si N2 es m�ltiplo de N1. */
{
    int RES;
    if ((N2 % N1) == 0)
        RES = 1;
    else
        RES = 0;
    return (RES);
}
