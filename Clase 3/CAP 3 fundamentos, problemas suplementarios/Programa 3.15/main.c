#include <stdio.h>
#include <stdlib.h>

int main()
{
   int n1, n2, temp;
   printf("Ingrese el primer numero: ");
   scanf("%d", &n1);

   printf("Ingrese el segundo numero: ");
   scanf("%d", &n2);

   while (n2 != 0){
    temp = n2;
    n2 = n1 % n2;
    n1 = temp;
   }
printf("El MCD es: %d\n", n1);
return 0;

}
