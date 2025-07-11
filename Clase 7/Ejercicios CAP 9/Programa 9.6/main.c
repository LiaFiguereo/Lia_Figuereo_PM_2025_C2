#include <stdio.h>

/* Archivos con variables enteras y reales.
   El programa lee datos de alumnos almacenados en un archivo
   y escribe la matr�cula y el promedio de cada alumno. */

int main(void) {
    int i, j, n, mat;
    float cal, pro;
    FILE *ar;

    if ((ar = fopen("arc9.txt", "r")) != NULL) {
        fscanf(ar, "%d", &n);  // Leer n�mero de alumnos

        for (i = 0; i < n; i++) {
            fscanf(ar, "%d", &mat);  // Leer matr�cula
            printf("%d\t", mat);
            pro = 0;

            for (j = 0; j < 5; j++) {
                fscanf(ar, "%f", &cal);  // Leer calificaciones
                pro += cal;
            }

            printf("%.2f\n", pro / 5);  // Mostrar promedio
        }

        fclose(ar);
    } else {
        printf("No se puede abrir el archivo\n");
    }

    return 0;
}
