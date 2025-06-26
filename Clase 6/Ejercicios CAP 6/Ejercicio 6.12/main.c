#include <stdio.h>
/* Lluvias.
El programa, al recibir como dato un arreglo tridimensional que contiene
informaci�n sobre lluvias, genera informaci�n estad�stica. */

const int PRO = 24;
const int MES = 12;
const int ANIO = 10;

void Lectura(float [PRO][MES][ANIO], int, int, int);
void Funcion1(float [PRO][MES][ANIO], int, int, int);
void Funcion2(float [PRO][MES][ANIO], int, int, int);
void Funcion3(float [PRO][MES][ANIO], int, int, int);

int main(void)
{
    float LLU[PRO][MES][ANIO];
    Lectura(LLU, PRO, MES, ANIO);
    Funcion1(LLU, PRO, MES, ANIO);
    Funcion2(LLU, PRO, MES, ANIO);
    Funcion3(LLU, 18, MES, 5);
    return 0;
}

void Lectura(float A[][MES][ANIO], int F, int C, int P)
/* Esta funci�n se utiliza para leer un arreglo tridimensional de tipo real de
F filas, C columnas y P planos de profundidad. */
{
    int K, I, J;
    for (K = 0; K < P; K++)
        for (I = 0; I < F; I++)
            for (J = 0; J < C; J++)
            {
                printf("A�o: %d\tProvincia: %d\tMes: %d : ", K + 1, I + 1, J + 1);
                scanf("%f", &A[I][J][K]);
            }
}

void Funcion1(float A[][MES][ANIO], int F, int C, int P)
/* Localiza la provincia con mayor registro promedio de lluvia en los �ltimos P a�os. */
{
    int I, K, J, EMAY = -1;
    float ELLU = -1.0, SUM;
    for (I = 0; I < F; I++)
    {
        SUM = 0.0;
        for (K = 0; K < P; K++)
            for (J = 0; J < C; J++)
                SUM += A[I][J][K];
        SUM /= (P * C);
        if (SUM > ELLU)
        {
            ELLU = SUM;
            EMAY = I;
        }
    }
    printf("\n\nProvincia con mayor registro promedio de lluvias: %d", EMAY + 1);
    printf("\nRegistro promedio: %.2f\n", ELLU);
}

void Funcion2(float A[][MES][ANIO], int F, int C, int P)
/* Localiza la provincia con menor registro promedio de lluvias en el �ltimo a�o (P-1). */
{
    int I, J, EMEN = -1;
    float ELLU = 100000.0, SUM;
    for (I = 0; I < F; I++)
    {
        SUM = 0;
        for (J = 0; J < C; J++)
            SUM += A[I][J][P - 1];
        SUM /= C;
        if (SUM < ELLU)
        {
            ELLU = SUM;
            EMEN = I;
        }
    }
    printf("\nProvincia con menor registro anual de lluvias en el �ltimo a�o: %d", EMEN + 1);
    printf("\nRegistro anual promedio: %.2f\n", ELLU);
}

void Funcion3(float A[][MES][ANIO], int F, int C, int P)
/* Localiza el mes con mayor registro de lluvias en la provincia F en el a�o P. */
{
    int J, EMES = -1;
    float ELLU = -1.0;
    for (J = 0; J < C; J++)
    {
        if (A[F - 1][J][P - 1] > ELLU)
        {
            ELLU = A[F - 1][J][P - 1];
            EMES = J;
        }
    }
    printf("\nMes con mayor lluvia en provincia %d, a�o %d: %d", F, P, EMES + 1);
    printf("\nRegistro de lluvias: %.2f\n", ELLU);
}
