#include <stdio.h>

/* Incremento de precio.
El programa, al recibir como dato el precio de un producto, incrementa al
mismo 11% si es menos a 1500$ y un 8% en caso contrario (mayor o igual).

PRE y NPR: varibales de tipo real. */

void main (void)
{
float PRE, NPR;
printf("Ingrese el precio del producto: ");
scanf("%f", &PRE);
if (PRE < 1500)
    NPR = PRE * 1.11;
else
    NPR = PRE * 1.08;
printf("\nNuevo precio del producto: %8.2f", NPR);
}
