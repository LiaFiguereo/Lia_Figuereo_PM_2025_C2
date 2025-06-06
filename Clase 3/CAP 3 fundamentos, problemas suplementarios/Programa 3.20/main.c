#include <stdio.h>
#include <math.h>  // Para usar pow()

int main() {
    int T, P, R;
    double valor;

    // Rango de búsqueda para T, P y R
    for (T = 1; T <= 10; T++) {
        for (P = 1; P <= 10; P++) {
            for (R = 1; R <= 10; R++) {
                // Calculamos el valor de la expresión
                valor = 7 * pow(T, 4) - 6 * pow(P, 3) + 12 * pow(R, 5);

                // Verificamos si cumple la condición
                if (valor < 5850) {
                    printf("T=%d, P=%d, R=%d => Valor = %.2f\n", T, P, R, valor);
                }
            }
        }
    }

    return 0;
}
