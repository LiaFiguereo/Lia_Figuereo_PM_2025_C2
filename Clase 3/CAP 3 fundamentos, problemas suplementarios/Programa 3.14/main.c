#include <stdio.h>
#include <math.h>

int main() {
    double x, termino, sen = 0.0;
    int n = 0;

    // Leer el valor de X
    printf("Ingrese el valor de x en radianes: ");
    scanf("%lf", &x);

    termino = x;  // Primer término de la serie (x)

    // Calcular seno usando la serie de Taylor
    while (fabs(termino) > 0.001) {
        sen += termino;
        n++;
        // Calcular el siguiente término usando fórmula
        termino = -termino * x * x / ( (2 * n) * (2 * n + 1) );
    }

    // Mostrar resultados
    printf("sen(%.4lf) ≈ %.6lf\n", x, sen);
    printf("Número de términos usados: %d\n", n);

    return 0;
}
