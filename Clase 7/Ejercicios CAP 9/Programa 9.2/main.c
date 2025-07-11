#include <stdio.h>

/* Archivos y caracteres.
   El programa lee caracteres de un archivo. */

int main(void) {
    char p1;
    FILE *ar;

    // Abrimos el archivo para lectura
    if ((ar = fopen("arc.txt", "r")) != NULL) {
        // Leemos los caracteres uno por uno hasta llegar al fin del archivo
        while ((p1 = fgetc(ar)) != EOF) {
            putchar(p1);
        }
        fclose(ar); // Cerramos el archivo
    } else {
        printf("No se puede abrir el archivo\n");
    }

    return 0;
}
