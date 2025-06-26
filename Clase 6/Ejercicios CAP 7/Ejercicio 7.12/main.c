#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Cuenta letras min�sculas y may�sculas en una cadena de caracteres. */

int main(void)
{
    char cad[50];
    int i = 0, mi = 0, ma = 0;

    printf("\nIngrese la cadena de caracteres (m�ximo 49 caracteres): ");
    fgets(cad, sizeof(cad), stdin);

    // Eliminar el salto de l�nea si lo hay
    size_t len = strlen(cad);
    if (len > 0 && cad[len - 1] == '\n') {
        cad[len - 1] = '\0';
    }

    while (cad[i] != '\0')
    {
        if (islower(cad[i]))
            mi++;
        else if (isupper(cad[i]))
            ma++;
        i++;
    }

    printf("\n\nN�mero de letras min�sculas: %d", mi);
    printf("\nN�mero de letras may�sculas: %d\n", ma);

    return 0;
}
