#include <stdio.h>
/* Paso de una funci�n como par�metro por referencia. */
int Suma(int X, int Y)
/* La funci�n Suma regresa la suma de los par�metros de tipo entero X y Y. */
{
    return (X+Y);
}

int Resta(int X, int Y)
/* Esta funci�n regresa la resta de los par�metros de tipo entero X y Y. */
{
    return (X-Y);
}

int Control(int (*apf) (int, int), int X, int Y)
/* Esta funci�n recibe como par�metro otra funci�n �la direcci�n� y dependiendo de cu�l sea �sta, llama a la funci�n Suma o Resta. */
{
    int RES;
    RES = (*apf) (X, Y); /* Se llama a la funci�n Suma o Resta. */
    return (RES);
}

void main(void)
{
    int R1, R2;
    R1 = Control(Suma, 15, 5); /* Se pasa como par�metro la funci�n Suma. */
    R2 = Control(Resta, 10, 4); /* Se pasa como par�metro la funci�n Resta. */
    printf("\nResultado 1: %d", R1);
    printf("\nResultado 2: %d", R2);
}
