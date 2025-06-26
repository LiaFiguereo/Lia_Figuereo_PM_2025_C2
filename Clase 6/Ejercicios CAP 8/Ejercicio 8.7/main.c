#include <stdio.h>
#include <string.h>

/* Escuela.
El programa genera informaci�n importante de los alumnos de una escuela. */
typedef struct /* Declaraci�n de la estructura matpro. */
{
    char mat[20]; /* Materia. */
    float pro; /* Promedio, cambiado a float para consistencia con la salida. */
} matpro;

typedef struct /* Declaraci�n de la estructura alumno. */
{
    int matri; /* Matr�cula. */
    char nom[20]; /* Nombre del alumno. */
    matpro cal[5]; /* Observa que cal es un arreglo unidimensional de tipo estructura matpro. */
} alumno;

void Lectura(alumno *, int);
void F1(alumno *, int);
void F2(alumno *, int); /* Prototipos de funciones. */
void F3(alumno *, int);

int main(void)
{
    alumno ALU[50]; /* ALU es un arreglo unidimensional de tipo alumno. */
    int TAM;

    do
    {
        printf("Ingrese el tama�o del arreglo: ");
        scanf("%d", &TAM);
    } while (TAM > 50 || TAM < 1); /* Se verifica que el tama�o del arreglo sea correcto. */

    Lectura(ALU, TAM);
    F1(ALU, TAM);
    F2(ALU, TAM);
    F3(ALU, TAM);

    return 0; /* Retorno est�ndar */
}

void Lectura(alumno *A, int T)
/* Esta funci�n se utiliza para leer la informaci�n de un arreglo unidimensional
de tipo estructura alumno de T elementos. */
{
    int I, J;
    for (I = 0; I < T; I++)
    {
        printf("\nIngrese los datos del alumno %d", I + 1);
        printf("\nIngrese la matricula del alumno: ");
        scanf("%d", &A[I].matri);
        while (getchar() != '\n'); /* Limpiar buffer */

        printf("Ingrese el nombre del alumno: ");
        if (fgets(A[I].nom, sizeof(A[I].nom), stdin) != NULL) {
            A[I].nom[strcspn(A[I].nom, "\n")] = '\0';
        }

        for (J = 0; J < 5; J++)
        {
            printf("\tMateria %d: ", J + 1);
            if (fgets(A[I].cal[J].mat, sizeof(A[I].cal[J].mat), stdin) != NULL) {
                A[I].cal[J].mat[strcspn(A[I].cal[J].mat, "\n")] = '\0';
            }

            printf("\tPromedio %d: ", J + 1);
            scanf("%f", &A[I].cal[J].pro);
            while (getchar() != '\n'); /* Limpiar buffer */
        }
    }
}

void F1(alumno *A, int T)
/* Esta funci�n se utiliza para obtener la matr�cula y el promedio general de
cada alumno. */
{
    int I, J;
    float SUM;
    for (I = 0; I < T; I++)
    {
        printf("\nMatricula del alumno: %d", A[I].matri);
        SUM = 0.0;
        for (J = 0; J < 5; J++)
            SUM = SUM + A[I].cal[J].pro;
        SUM = SUM / 5;
        printf("\tPromedio: %.2f\n", SUM);
    }
}

void F2(alumno *A, int T)
/* Esta funci�n se utiliza para obtener las matr�culas de los alumnos cuya
calificaci�n en la tercera materia es mayor a 9. */
{
    int I;
    printf("\nAlumnos con calificacion mayor a 9 en la tercera materia\n");
    for (I = 0; I < T; I++)
        if (A[I].cal[2].pro > 9)
            printf("Matricula del alumno: %d\n", A[I].matri);
}

void F3(alumno *A, int T)
/* Esta funci�n se utiliza para obtener el promedio general de la cuarta materia. */
{
    int I;
    float SUM = 0.0;
    for (I = 0; I < T; I++)
        SUM = SUM + A[I].cal[3].pro;
    SUM = SUM / T;
    printf("\nPromedio de la cuarta materia: %.2f\n", SUM);
}
