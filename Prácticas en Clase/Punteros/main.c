#include <stdio.h>
#include <stdlib.h>

int main()
{
 //punteros y direcciones
 //aritmetica de punteros

char g = 'a';
 int a = 0;
 int b = 0;
 double c = 0.0;

// int *p;
printf("\nValor de p: %p",&g);
printf("\nValor de p: %p",&a);
printf("\nValor de p: %p",&b);
printf("\nValor de p: %p",&c);


return 0;
 /*p = &a;
 *p = 55;
  printf("\nValor de a: %i",*p);
  printf("\nValor de p: %p",*p);

 p = &b;
 *p = 555;//b = a;
  printf("\nValor de b: %i",*p);
  printf("\nValor de p: %p",p);

 printf("\nDireccion de a: %p",&a);
 printf("\nDireccion de b: %p",&b);/






}
