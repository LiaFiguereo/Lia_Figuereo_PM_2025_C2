#include <stdio.h>
#include <string.h>

/* Calcula longitud.
   El programa calcula la longitud de la cadena sin utilizar strlen. */

int cuenta(char *); // Prototipo de funci�n

int main(void)
{
    int i;
    char cad[50];

    printf("\nIngrese la cadena de caracteres: ");
    fgets(cad, sizeof(cad), stdin);

    // Eliminar el salto de l�nea final si existe
    size_t len = strlen(cad);
    if (len > 0 && cad[len - 1] == '\n') {
        cad[len - 1] = '\0';
    }

    i = cuenta(cad);

    printf("\nLongitud de la cadena: %d\n", i);
    return 0;
}

int cuenta(char *cadena)
/* La funci�n calcula la longitud de la cadena manualmente. */
{
    int c = 0;
    while (cadena[c] != '\0')
        c++;
    return c;
}
