#include <stdio.h>
#include <stdlib.h>

int main (void){
char caracter;

printf ("\nIngrese un caracter: ");
scanf ("%c", &caracter);

if (caracter >= 'A' && caracter <= 'Z')
{
    printf("\nEl caracter '%c' esta en Mayuscula.\n", caracter);
} else {
printf("\nEl caracter '%c' esta en Miniscula.\n", caracter);
}
return 0;
}
