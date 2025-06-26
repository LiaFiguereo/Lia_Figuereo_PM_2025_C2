#include <stdio.h>
#include <ctype.h>

/* Decodifica.
El programa decodifica una cadena de caracteres compuesta por n�meros y letras. */
void interpreta(char *); /* Prototipo de funci�n. */

int main(void)
{
    char cad[50];
    printf("\nIngrese la cadena de caracteres: ");
    fgets(cad, sizeof(cad), stdin); /* Uso de fgets en lugar de gets */

    /* Eliminar el salto de l�nea que agrega fgets, si est� presente */
    for (int i = 0; cad[i] != '\0'; i++) {
        if (cad[i] == '\n') {
            cad[i] = '\0';
            break;
        }
    }

    interpreta(cad);
    printf("\n"); /* Agregar salto de l�nea al final para mejor formato */
    return 0; /* Retorno est�ndar */
}

void interpreta(char *cadena)
/* Esta funci�n se utiliza para decodificar la cadena de caracteres. */
{
    int i = 0, j, k;
    while (cadena[i] != '\0')
    {
        if (isalpha(cadena[i])) /* Verifica si el car�cter es una letra */
        {
            /* Verificar que hay un n�mero v�lido antes de la letra */
            if (i > 0 && isdigit(cadena[i - 1])) {
                k = cadena[i - 1] - '0'; /* Convertir car�cter num�rico a entero */
                for (j = 0; j < k; j++)
                    putchar(cadena[i]);
            }
        }
        i++;
    }
}
