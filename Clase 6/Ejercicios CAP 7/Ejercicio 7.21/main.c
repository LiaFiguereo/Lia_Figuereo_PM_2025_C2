#include <stdio.h>
#include <string.h>

/* Prototipo de funci�n. */
void intercambia(char FRA[][30], int);

int main(void)
{
    int i, n;
    char FRA[20][30];

    printf("\nIngrese el n�mero de filas del arreglo: ");
    scanf("%d", &n);

    /* Validar que n no exceda el tama�o del arreglo */
    if (n <= 0 || n > 20) {
        printf("\nN�mero de filas inv�lido. Debe estar entre 1 y 20.\n");
        return 1;
    }

    /* Limpiar el buffer de entrada despu�s de scanf */
    while (getchar() != '\n');

    for (i = 0; i < n; i++) {
        printf("\nIngrese la l�nea de texto n�mero %d: ", i + 1);
        if (fgets(FRA[i], sizeof(FRA[i]), stdin) == NULL) {
            printf("\nError al leer la entrada.\n");
            return 1;
        }
        /* Eliminar salto de l�nea de FRA[i] */
        FRA[i][strcspn(FRA[i], "\n")] = '\0';
    }

    printf("\n\n");
    intercambia(FRA, n);
    for (i = 0; i < n; i++) {
        printf("\nImpresi�n de la l�nea de texto %d: ", i + 1);
        puts(FRA[i]);
    }
    printf("\n"); /* Salto de l�nea para mejor formato */
    return 0; /* Retorno est�ndar */
}

void intercambia(char FRA[][30], int n)
{
    /* Esta funci�n intercambia las filas del arreglo. */
    int i, j;
    char cad[30];
    for (i = 0; i < (n / 2); i++) {
        j = n - 1 - i; /* Calcular el �ndice opuesto correctamente */
        strcpy(cad, FRA[i]);
        strcpy(FRA[i], FRA[j]);
        strcpy(FRA[j], cad);
    }
}
