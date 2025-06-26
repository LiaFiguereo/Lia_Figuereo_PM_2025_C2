#include <stdio.h>
#include <string.h>

/* Cuenta cadenas.
El programa, al recibir dos cadenas de caracteres, calcula e imprime cu�ntas
veces se encuentra la segunda cadena en la primera. */

int main(void)
{
    char cad1[50], cad2[50], cad0[50]; /* cad0 ahora es un arreglo, no un puntero a constante */
    int i = 0;

    printf("\nIngrese la primera cadena de caracteres: ");
    fgets(cad1, sizeof(cad1), stdin); /* Uso de fgets en lugar de gets */
    /* Eliminar salto de l�nea de cad1 */
    cad1[strcspn(cad1, "\n")] = '\0';

    printf("\nIngrese la cadena a buscar: ");
    fgets(cad2, sizeof(cad2), stdin); /* Uso de fgets para cad2 */
    /* Eliminar salto de l�nea de cad2 */
    cad2[strcspn(cad2, "\n")] = '\0';

    /* Verificar que cad2 no est� vac�a */
    if (strlen(cad2) == 0) {
        printf("\nLa cadena a buscar est� vac�a.\n");
        return 1;
    }

    strcpy(cad0, cad1); /* Copiar cad1 a cad0 */
    char *ptr = cad0; /* Puntero auxiliar para buscar */
    ptr = strstr(ptr, cad2); /* Buscar primera ocurrencia */

    while (ptr != NULL)
    {
        i++;
        ptr = strstr(ptr + 1, cad2); /* Buscar siguiente ocurrencia */
    }

    printf("\nEl n�mero de veces que aparece la segunda cadena es: %d\n", i);
    return 0; /* Retorno est�ndar */
}
