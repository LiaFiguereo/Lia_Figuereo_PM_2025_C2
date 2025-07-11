#include <stdio.h>

/* Archivos y cadenas de caracteres.
   El programa lee cadenas de caracteres de un archivo. */

int main(void) {
    char cad[50];
    FILE *ap;

    // Abre el archivo para lectura y verifica si se abri� correctamente
    if ((ap = fopen("arc.txt", "r")) != NULL) {
        while (fgets(cad, sizeof(cad), ap) != NULL) {
            puts(cad);  // Muestra la l�nea le�da en pantalla
        }
        fclose(ap);  // Cierra el archivo
    } else {
        printf("No se puede abrir el archivo\n");
    }

    return 0;
}
