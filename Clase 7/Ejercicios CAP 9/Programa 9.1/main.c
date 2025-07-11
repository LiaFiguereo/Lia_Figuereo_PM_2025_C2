#include <stdio.h>

/* Archivos y caracteres.
   El programa escribe caracteres en un archivo. */

int main(void) {
    char p1;
    FILE *ar;

    ar = fopen("arc.txt", "w");  // Abrir archivo para escritura

    if (ar != NULL) {
        printf("Escribe caracteres (termina con Enter):\n");
        while ((p1 = getchar()) != '\n') {
            fputc(p1, ar);  // Escribir car�cter en el archivo
        }
        fclose(ar);  // Cerrar archivo
        printf("Texto guardado correctamente en arc.txt\n");
    } else {
        printf("No se puede abrir el archivo\n");
    }

    return 0;
}
