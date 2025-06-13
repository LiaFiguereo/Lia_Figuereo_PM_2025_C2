#include <stdio.h>
#include <math.h>
/* Expresi�n.
El programa escribe los valores de T, P y Q que satisfacen una determinada expresi�n. */
int Expression(int, int, int); /* Prototipo de funci�n. */

void main(void)
{
    int EXP, T = 0, P = 0, Q = 0;
    EXP = Expression(T, P, Q);
    while (EXP < 5500)
    {
        while (EXP < 5500)
        {
            while (EXP < 5500)
            {
                printf("\nT: %d, P: %d, Q: %d, Resultado: %d", T, P, Q, EXP);
                Q++;
                EXP = Expression(T, P, Q);
            }
            P++;
            Q = 0;
            EXP = Expression(T, P, Q);
        }
        T++;
        P = 0;
        Q = 0;
        EXP = Expression(T, P, Q);
    }
}

int Expression(int T, int P, int Q)
/* Esta funci�n obtiene el resultado de la expresi�n para los valores de T, P y Q. */
{
    int RES;
    RES = 15 * pow(T, 4) + 12 * pow(P, 5) + 9 * pow(Q, 6);
    return (RES);
}
