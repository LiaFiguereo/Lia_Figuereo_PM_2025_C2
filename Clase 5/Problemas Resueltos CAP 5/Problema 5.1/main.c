#include <stdio.h>
#include <math.h>
/* Suma-cuadrados.
El programa calcula la suma del cuadrado de los elementos de un arreglo
unidimensional de 100 elementos de tipo real. */
const int MAX = 100;
/* MAX se utiliza para reservar el espacio m�ximo que podr� ocupar el arreglo. */
void Lectura(float *, int); /* Prototipos de funciones. */
double Suma(float *, int);
int main(void)
{
float VEC[MAX];
double RES;
Lectura(VEC, MAX);
RES = Suma(VEC, MAX);
/* Se llama a la funci�n Suma y se almacena el resultado en la variable RES. */
printf("\n\nSuma del arreglo: %.2f", RES);
return 0;
}
void Lectura(float A[], int T)
/* La funci�n Lectura se utiliza para leer un arreglo unidimensional de T
elementos de tipo real. */
{
int I;
for (I=0; I<T; I++)
{
printf("Ingrese el elemento %d: ", I+1);
scanf("%f", &A[I]);
}
}
double Suma(float A[], int T)
/* La funci�n Suma se utiliza para calcular la suma del cuadrado de los
componentes de un arreglo unidimensional de T elementos de tipo real. */
{
int I;
double AUX = 0.0;
for (I=0; I<T; I++)
AUX += pow(A[I], 2);
return(AUX);
}
