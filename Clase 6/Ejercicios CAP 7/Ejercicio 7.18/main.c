#include <stdio.h>
#include <string.h> /* Incluye esta l�nea para strcspn y strlen */

/* Cadena invertida resuelta en forma recursiva. */
void inverso(char *); /* Prototipo de funci�n. */

int main(void)
{
    char fra[50];

    printf("\nIngrese la l�nea de caracteres: ");
    if (fgets(fra, sizeof(fra), stdin) == NULL) {
        printf("\nError al leer la entrada.\n");
        return 1;
    }
    fra[strcspn(fra, "\n")] = '\0'; /* L�nea 13: Eliminar salto de l�nea */

    if (strlen(fra) == 0) { /* L�nea 16: Verificar si la cadena est� vac�a */
        printf("\nLa cadena est� vac�a.\n");
        return 1;
    }

    printf("\nEscribe la l�nea de texto en forma inversa: ");
    inverso(fra);
    printf("\n"); /* Salto de l�nea para mejor formato */
    return 0;
}

void inverso(char *cadena)
{
    if (cadena[0] != '\0') {
        inverso(cadena + 1);
        putchar(cadena[0]);
    }
}
