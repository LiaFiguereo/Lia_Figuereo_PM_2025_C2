#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Suma y promedio.
   El programa recibe varias cadenas de caracteres que contienen n�meros reales,
   los suma y obtiene su promedio. */

int main(void)
{
    char c, cad[10];
    int i = 0;
    float sum = 0.0;

    printf("\n�Desea ingresar una cadena de caracteres (S/N)? ");
    scanf(" %c", &c); // Espacio antes de %c para ignorar espacios previos

    while (c == 'S' || c == 's')
    {
        printf("\nIngrese la cadena de caracteres: ");
        scanf("%s", cad); // M�s seguro que gets()

        i++;
        sum += atof(cad); // Convierte la cadena a float

        printf("\n�Desea ingresar otra cadena de caracteres (S/N)? ");
        scanf(" %c", &c);
    }

    if (i > 0)
    {
        printf("\nSuma: %.2f", sum);
        printf("\nPromedio: %.2f\n", sum / i);
    }
    else
    {
        printf("\nNo se ingresaron datos.\n");
    }

    return 0;
}
