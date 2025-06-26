#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Min�sculas y may�sculas.
   El programa, al recibir como dato un arreglo unidimensional de tipo
   cadena de caracteres, determina el n�mero de min�sculas y may�sculas
   que hay en cada cadena. */

void minymay(char *cadena); // Prototipo de funci�n

int main(void)
{
    int i, n;
    char FRA[20][50]; // Arreglo de 20 filas con hasta 49 caracteres + '\0'

    printf("\nIngrese el n�mero de filas del arreglo: ");
    scanf("%d", &n);
    getchar(); // Limpia el buffer para evitar problemas con fgets

    for (i = 0; i < n; i++)
    {
        printf("Ingrese la l�nea %d de texto: ", i + 1);
        fgets(FRA[i], sizeof(FRA[i]), stdin);

        // Elimina el salto de l�nea final si existe
        size_t len = strlen(FRA[i]);
        if (len > 0 && FRA[i][len - 1] == '\n') {
            FRA[i][len - 1] = '\0';
        }
    }

    printf("\n\n");
    for (i = 0; i < n; i++)
        minymay(FRA[i]);

    return 0;
}

void minymay(char *cadena)
/* Esta funci�n se utiliza para calcular el n�mero de min�sculas
   y may�sculas que hay en cada cadena. */
{
    int i = 0, mi = 0, ma = 0;

    while (cadena[i] != '\0')
    {
        if (islower((unsigned char)cadena[i]))
            mi++;
        else if (isupper((unsigned char)cadena[i]))
            ma++;
        i++;
    }

    printf("\n\nN�mero de letras min�sculas: %d", mi);
    printf("\nN�mero de letras may�sculas: %d\n", ma);
}
