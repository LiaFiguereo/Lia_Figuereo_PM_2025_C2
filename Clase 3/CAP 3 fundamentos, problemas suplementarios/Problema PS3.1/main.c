#include <stdio.h>

int main() {
    int N;
    printf("Ingrese el número de años: ");
    scanf("%d", &N);

    float VIN[N][4];
    float totalTipo[4] = {0, 0, 0, 0};
    float totalAnual[N];

    // Inicializar totales anuales
    for (int i = 0; i < N; i++) {
        totalAnual[i] = 0;
    }

    // Entrada de datos
    for (int i = 0; i < N; i++) {
        printf("Año %d:\n", i + 1);
        for (int j = 0; j < 4; j++) {
            printf("  Litros de vino tipo %d: ", j + 1);
            scanf("%f", &VIN[i][j]);

            totalTipo[j] += VIN[i][j];      // Acumula por tipo
            totalAnual[i] += VIN[i][j];     // Acumula por año
        }
    }

    // Mostrar total por tipo de vino
    printf("\nTotal producido por tipo de vino:\n");
    for (int j = 0; j < 4; j++) {
        printf("  Tipo %d: %.2f litros\n", j + 1, totalTipo[j]);
    }

    // Mostrar total por año
    printf("\nTotal de producción por año:\n");
    for (int i = 0; i < N; i++) {
        printf("  Año %d: %.2f litros\n", i + 1, totalAnual[i]);
    }

    return 0;
}
