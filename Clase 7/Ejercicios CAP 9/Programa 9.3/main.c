#include <stdio.h>
#include <string.h>

/* Archivos y cadenas de caracteres.
   El programa escribe cadenas de caracteres en un archivo. */

int main(void) {
    char cad[50];
    int res;
    FILE *ar;

    if ((ar = fopen("arc.txt", "w")) != NULL) {
        printf("\n�Desea ingresar una cadena de caracteres? S�-1 No-0: ");
        scanf("%d", &res);
        getchar(); // limpiar salto de l�nea pendiente

        while (res) {
            printf("Ingrese la cadena: ");
            fgets(cad, sizeof(cad), stdin);
            cad[strcspn(cad, "\n")] = '\0';  // eliminar salto de l�nea

            fputs(cad, ar);

            printf("\n�Desea ingresar otra cadena de caracteres? S�-1 No-0: ");
            scanf("%d", &res);
            getchar(); // limpiar salto de l�nea pendiente

            if (res)
                fputs("\n", ar);  // salto de l�nea entre cadenas
        }

        fclose(ar);
        printf("\nArchivo guardado exitosamente en 'arc.txt'.\n");
    } else {
        printf("No se puede abrir el archivo\n");
    }

    return 0;
}
