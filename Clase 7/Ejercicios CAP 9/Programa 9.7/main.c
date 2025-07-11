#include <stdio.h>

/* Archivos con variables enteras y reales.
   El programa lee informaci�n de los alumnos de una escuela, almacenada en un
   archivo. Utiliza una funci�n para realizar la lectura, pero el archivo se abre
   y cierra desde el programa principal. */

void promedio(FILE *);  // Prototipo de funci�n

int main(void) {
    FILE *ar;

    // Apertura del archivo
    if ((ar = fopen("arc9.txt", "r")) != NULL) {
        promedio(ar);  // Llamada a la funci�n que procesa los datos
        fclose(ar);
    } else {
        printf("No se puede abrir el archivo\n");
    }

    return 0;
}

void promedio(FILE *ar1) {
    int i, j, n, mat;
    float pro, cal;

    fscanf(ar1, "%d", &n);  // Leer cantidad de alumnos

    for (i = 0; i < n; i++) {
        fscanf(ar1, "%d", &mat);  // Leer matr�cula
        printf("%d\t", mat);

        pro = 0;
        for (j = 0; j < 5; j++) {
            fscanf(ar1, "%f", &cal);  // Leer calificaciones
            pro += cal;
        }

        printf("%.2f\n", pro / 5);  // Imprimir promedio
    }
}
