#include <stdio.h>

/* Calificaciones.
El programa calcula el promedio de 5 calificaciones por alumno,
y determina el alumno con mejor y peor promedio.
*/

int main(void)
{
    int I, MAT, MAMAT, MEMAT;
    float SUM, PRO, CAL, MAPRO = 0.0, MEPRO = 11.0;

    printf("Ingrese la matrícula del primer alumno (0 para terminar): ");
    scanf("%d", &MAT);

    while (MAT)
    {
        SUM = 0;
        for (I = 1; I <= 5; I++)
        {
            printf("\tIngrese la calificación %d del alumno: ", I);
            scanf("%f", &CAL);
            SUM += CAL;
        }

        PRO = SUM / 5;
        printf("\nMatrícula: %d\tPromedio: %5.2f\n", MAT, PRO);

        if (PRO > MAPRO)
        {
            MAPRO = PRO;
            MAMAT = MAT;
        }

        if (PRO < MEPRO)
        {
            MEPRO = PRO;
            MEMAT = MAT;
        }

        printf("\nIngrese la matrícula del siguiente alumno (0 para terminar): ");
        scanf("%d", &MAT);
    }

    printf("\n\nAlumno con mejor Promedio:\t%d\t%5.2f", MAMAT, MAPRO);
    printf("\nAlumno con peor Promedio:\t%d\t%5.2f\n", MEMAT, MEPRO);

    return 0;
}
