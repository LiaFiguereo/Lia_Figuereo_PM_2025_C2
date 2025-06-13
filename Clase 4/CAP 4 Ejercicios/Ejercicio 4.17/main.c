#include <stdio.h>
/* Lluvias.
El programa permite calcular el promedio mensual de las lluvias ca�das en tres regiones importantes del pa�s. Determina tambi�n cu�l es la regi�n con mayor promedio de lluvia anual. */
void Mayor(float, float, float); /* Prototipo de funci�n. */

void main(void)
{
    int I;
    float GOL, PAC, CAR, AGOL = 0, APAC = 0, ACAR = 0;
    for (I = 1; I <= 12; I++)
    {
        printf("\n\nIngrese las lluvias del mes %d", I);
        printf("\nRegiones Golfo, Pac�fico y Caribe: ");
        scanf("%f %f %f", &GOL, &PAC, &CAR);
        AGOL += GOL;
        APAC += PAC;
        ACAR += CAR;
    }
    printf("\n\nPromedio de lluvias Regi�n Golfo: %6.2f", (AGOL / 12));
    printf("\nPromedio de lluvias Regi�n Pac�fico: %6.2f", (APAC / 12));
    printf("\nPromedio de lluvias Regi�n Caribe: %6.2f \n", (ACAR / 12));
    Mayor(AGOL, APAC, ACAR);
    /* Se llama a la funci�n Mayor. Paso de par�metros por valor. */
}

void Mayor(float R1, float R2, float R3)
/* Esta funci�n obtiene la regi�n con mayor promedio de lluvia anual. */
{
    if (R1 > R2)
        if (R1 > R3)
            printf("\nRegi�n con mayor promedio: Regi�n Golfo. Promedio: %6.2f", R1 / 12);
        else
            printf("\nRegi�n con mayor promedio: Regi�n Caribe. Promedio: %6.2f", R3 / 12);
    else
        if (R2 > R3)
            printf("\nRegi�n con mayor promedio: Regi�n Pac�fico. Promedio: %6.2f", R2 / 12);
        else
            printf("\nRegi�n con mayor promedio: Regi�n Caribe. Promedio: %6.2f", R3 / 12);
}
