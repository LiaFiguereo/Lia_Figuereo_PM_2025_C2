#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Cuenta palabras.
El programa calcula el n�mero de palabras que hay en la cadena de caracteres. */
int cuentap(char *); /* Prototipo de funci�n. */

int main(void)
{
    int i;
    char fra[50];

    printf("\nIngrese la l�nea de texto: ");
    if (fgets(fra, sizeof(fra), stdin) == NULL) {
        printf("\nError al leer la entrada.\n");
        return 1;
    }
    /* Eliminar salto de l�nea de fra */
    fra[strcspn(fra, "\n")] = '\0';

    /* Agregar un espacio al final para manejar la �ltima palabra */
    strncat(fra, " ", sizeof(fra) - strlen(fra) - 1);

    i = cuentap(fra);
    printf("\nLa l�nea de texto tiene %d palabras\n", i); /* Salto de l�nea agregado */
    return 0; /* Retorno est�ndar */
}

int cuentap(char *cad)
{
    /* La funci�n cuenta el n�mero de palabras que hay en la cadena de caracteres. */
    int i = 0;
    char *cad0 = cad; /* Puntero inicial a la cadena */

    while (*cad0 != '\0') {
        /* Avanzar hasta el inicio de una palabra (ignorar espacios) */
        while (*cad0 == ' ') {
            cad0++;
        }
        if (*cad0 != '\0') { /* Si no es el final de la cadena */
            i++; /* Contar una nueva palabra */
            /* Avanzar hasta el siguiente espacio o fin de cadena */
            while (*cad0 != ' ' && *cad0 != '\0') {
                cad0++;
            }
        }
    }
    return i;
}
