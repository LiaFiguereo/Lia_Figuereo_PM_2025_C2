#include <stdio.h>

/* Nomina.
El programa, al recibir los salarios de 5 profesores, obtiene el total de la
nomina de la universidad.

I: Variable de tipo entero.
SAL y NOM: variables de tipo real. */

void main (void)
{
    int I;
    float SAL, NOM;
    NOM = 0;
    for (I = 1; I <= 5; I++)
    {
        printf("\nIngrese el salario del profesor % d:\t",I);
        scanf("%f",&SAL);
        NOM = NOM + SAL;
    }
    //imrpimir el pago de los profesores
    //por cada uno menos el 20%
    //imprimir el pago de nomina
    //imprimir el total a los profesores sin el impuesto
    //imprimir el total de impuestos
    printf("\nEl total de la nomina es: %.2f",NOM);
}
