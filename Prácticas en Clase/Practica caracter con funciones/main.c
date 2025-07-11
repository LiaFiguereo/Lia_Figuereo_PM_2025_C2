#include <stdio.h>
#include <stdlib.h>

//completar codigooo

int esMayuscula (char);

int esMiniscula (char);

int main(void)
{
char caracter;

printf("\nIngrese un caracter: ");
scanf ("%c", &caracter);

if (caracter >= 'A' && caracter <= 'Z');
{
    return 1;
} else {
return 0;
}

}
