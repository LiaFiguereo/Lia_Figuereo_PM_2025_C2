#include <stdio.h>
#include <string.h>

/* Escuela.
El programa genera informaci�n estad�stica de los alumnos de una escuela. */
typedef struct /* Declaraci�n de la estructura alumno utilizando un typedef. */
{
    int matricula;
    char nombre[30];
    float cal[5];
    /* Observa que el campo de la estructura alumno es un arreglo unidimensional. */
} alumno;

void Lectura(alumno *, int T); /* Prototipo de funciones corregido */
void F1(alumno *, int TAM);
void F2(alumno *, int TAM);
void F3(alumno *, int TAM);

int main(void)
{
    alumno ARRE[50]; /* Se declara un arreglo unidimensional de tipo alumno. */
    int TAM;

    do
    {
        printf("Ingrese el tama�o del arreglo: ");
        scanf("%d", &TAM);
    } while (TAM > 50 || TAM < 1); /* Se verifica que el tama�o del arreglo sea correcto. */

    Lectura(ARRE, TAM);
    F1(ARRE, TAM);
    F2(ARRE, TAM);
    F3(ARRE, TAM);

    return 0; /* Retorno est�ndar */
}

void Lectura(alumno *A, int T)
/* La funci�n Lectura se utiliza para leer un arreglo unidimensional de tipo
estructura alumno de T elementos. */
{
    int I, J;
    for (I = 0; I < T; I++)
    {
        printf("\nIngrese los datos del alumno %d", I + 1);
        printf("\nIngrese la matricula del alumno: ");
        scanf("%d", &A[I].matricula);
        while (getchar() != '\n'); /* Limpiar buffer */

        printf("Ingrese el nombre del alumno: ");
        if (fgets(A[I].nombre, sizeof(A[I].nombre), stdin) != NULL) {
            A[I].nombre[strcspn(A[I].nombre, "\n")] = '\0'; /* Eliminar salto de linea */
        }

        for (J = 0; J < 5; J++)
        {
            printf("\tIngrese la calificacion %d del alumno %d: ", J + 1, I + 1);
            scanf("%f", &A[I].cal[J]);
            while (getchar() != '\n'); /* Limpiar buffer */
        }
    }
}

void F1(alumno *A, int T)
/* La funci�n F1 obtiene la matr�cula y el promedio de cada alumno. */
{
    int I, J;
    float SUM, PRO;
    for (I = 0; I < T; I++)
    {
        printf("\nMatricula del alumno: %d", A[I].matricula);
        SUM = 0.0;
        for (J = 0; J < 5; J++)
            SUM = SUM + A[I].cal[J];
        PRO = SUM / 5;
        printf("\t\tPromedio: %.2f\n", PRO);
    }
}

void F2(alumno *A, int T)
/* La funci�n F2 obtiene las matr�culas de los alumnos cuya calificaci�n en la
tercera materia es mayor a 9. */
{
    int I;
    printf("\nAlumnos con calificacion en la tercera materia > 9\n");
    for (I = 0; I < T; I++)
        if (A[I].cal[2] > 9)
            printf("Matricula del alumno: %d\n", A[I].matricula);
}

void F3(alumno *A, int T)
/* Esta funci�n obtiene el promedio general del grupo de la materia 4. */
{
    int I;
    float PRO, SUM = 0.0;
    for (I = 0; I < T; I++)
        SUM = SUM + A[I].cal[3];
    PRO = SUM / T;
    printf("\nPromedio de la materia 4: %.2f\n", PRO);
}
