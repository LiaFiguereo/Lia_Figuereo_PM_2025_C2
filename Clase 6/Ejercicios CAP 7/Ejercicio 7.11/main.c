#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Verifica si un car�cter en una posici�n espec�fica es una letra min�scula. */

int main(void)
{
    char p, cad[50];
    int n;

    printf("\nIngrese la cadena de caracteres (m�ximo 49): ");
    fgets(cad, sizeof(cad), stdin);

    // Eliminar el salto de l�nea si fgets lo almacena
    size_t len = strlen(cad);
    if (len > 0 && cad[len - 1] == '\n') {
        cad[len - 1] = '\0';
    }

    printf("\nIngrese la posici�n en la cadena que desea verificar: ");
    scanf("%d", &n);

    if (n >= 1 && n <= strlen(cad)) {
        p = cad[n - 1];  // n - 1 porque las posiciones inician desde 0
        if (islower(p))
            printf("\n'%c' es una letra min�scula.\n", p);
        else
            printf("\n'%c' no es una letra min�scula.\n", p);
    } else {
        printf("\nEl valor ingresado de n es incorrecto.\n");
    }

    return 0;
}
