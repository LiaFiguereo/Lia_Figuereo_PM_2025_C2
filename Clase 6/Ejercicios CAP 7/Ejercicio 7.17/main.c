#include <stdio.h>
#include <string.h>

/* Cadena invertida.
El programa obtiene la cadena invertida. */
char *inverso(char *); /* Prototipo de funci�n. */

int main(void)
{
    char fra[50], aux[50];
    printf("\nIngrese la l�nea de texto: ");
    fgets(fra, sizeof(fra), stdin); /* Uso de fgets en lugar de gets */
    /* Eliminar salto de l�nea de fra */
    fra[strcspn(fra, "\n")] = '\0';

    /* Verificar que la cadena no est� vac�a */
    if (strlen(fra) == 0) {
        printf("\nLa cadena est� vac�a.\n");
        return 1;
    }

    strcpy(aux, inverso(fra)); /* Copiar el resultado de inverso a aux */
    printf("\nEscribe la l�nea de texto en forma inversa: ");
    puts(aux);
    printf("\n"); /* Salto de l�nea para mejor formato */
    return 0; /* Retorno est�ndar */
}

char *inverso(char *cadena)
/* La funci�n calcula el inverso de una cadena y regresa el resultado al
programa principal. */
{
    int i = 0, j, lon;
    lon = strlen(cadena);
    j = lon - 1;

    while (i < (lon / 2)) /* Simplificado: hasta la mitad de la cadena */
    {
        /* Intercambio de caracteres sin variable adicional */
        char temp = cadena[i];
        cadena[i] = cadena[j];
        cadena[j] = temp;
        i++;
        j--;
    }
    return cadena;
}
