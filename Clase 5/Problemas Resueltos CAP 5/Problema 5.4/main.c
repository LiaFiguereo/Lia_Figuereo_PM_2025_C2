#include <stdio.h>
/* B�squeda secuencial en arreglos desordenados. */
const int MAX = 100;
void Lectura(int[], int); /* Prototipo corregido */
int Busca(int *, int, int);
void main(void)
{
    int RES, ELE, TAM, VEC[MAX];
    do
    {
        printf("Ingrese el tama�o del arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM > MAX || TAM < 1); /* Se verifica que el tama�o del arreglo sea correcto. */
    Lectura(VEC, TAM);
    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &ELE);
    RES = Busca(VEC, TAM, ELE); /* Se llama a la funci�n que busca en el arreglo. */
    if (RES)
        /* Si RES tiene un valor verdadero �diferente de 0�, se escribe la posici�n
        en la que se encontr� el elemento. */
        printf("\nEl elemento se encuentra en la posici�n %d", RES);
    else
        printf("\nEl elemento no se encuentra en el arreglo");
}
void Lectura(int A[], int T)
/* La funci�n Lectura se utiliza para leer un arreglo unidimensional de T elementos de tipo entero. */
{
    int I;
    printf("\n");
    for (I = 0; I < T; I++)
    {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}
int Busca(int A[], int T, int E)
/* La funci�n Busca realiza una b�squeda secuencial en el arreglo A de tama�o T
y devuelve la posici�n (1 a T) del elemento E, o 0 si no se encuentra. */
{
    int I;
    for (I = 0; I < T; I++)
        if (A[I] == E)
            return I + 1; /* Devuelve la posici�n (basada en 1) */
    return 0; /* No encontrado */
}
