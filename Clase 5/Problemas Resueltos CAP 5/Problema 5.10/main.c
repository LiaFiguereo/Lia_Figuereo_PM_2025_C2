#include <stdio.h> // Se incluye la libreria estandar de entrada/salida para usar printf

/* Apuntadores y arreglos */
int main(void) // La funcion principal del programa
{
    // Declaracion e inicializacion de variables y arreglo
    int X = 5, Y = 8, V[5] = {1, 3, 5, 7, 9};
    int *AY, *AX; // Declaracion de punteros a enteros

    // --- Primera secuencia de operaciones con punteros ---

    AY = &Y; // AY apunta a la direccion de memoria de la variable Y.
             // Esto significa que *AY ahora representa el valor de Y.

    X = *AY; // X toma el valor al que apunta AY. Como AY apunta a Y (que vale 8),
             // X se convierte en 8.

    *AY = V[3] + V[2]; // El valor al que apunta AY (es decir, Y) se actualiza.
                       // V[3] es 7 y V[2] es 5.
                       // Asi que *AY = 7 + 5 = 12. Por lo tanto, Y se convierte en 12.

    // Imprime el estado de las variables y el arreglo despues de la primera secuencia
    printf("\nX=%d Y=%d V[0]=%d V[1]=%d V[2]=%d V[3]=%d V[4]=%d", X,
           Y, V[0], V[1], V[2], V[3], V[4]);
    // En este punto, la salida sera: X=8 Y=12 V[0]=1 V[1]=3 V[2]=5 V[3]=7 V[4]=9

    // --- Segunda secuencia de operaciones con punteros ---

    // AX apunta a un elemento del arreglo V.
    // La expresion V[0]*V[1] se calcula primero: 1 * 3 = 3.
    // Asi que AX apunta a la direccion de memoria de V[3].
    // V[3] actualmente contiene el valor 7.
    AX = &V[V[0]*V[1]];

    X = *AX; // X toma el valor al que apunta AX. Como AX apunta a V[3] (que vale 7),
             // X se convierte en 7.

    Y = *AX * V[1]; // Y toma el valor al que apunta AX (7) multiplicado por V[1] (3).
                    // Asi que Y = 7 * 3 = 21.

    *AX = *AY - 3; // El valor al que apunta AX (es decir, V[3]) se actualiza.
                   // *AY vale 12 (el valor actual de Y).
                   // Asi que *AX = 12 - 3 = 9.
                   // Por lo tanto, V[3] en el arreglo cambia de 7 a 9.

    // Imprime el estado de las variables y el arreglo despues de la segunda secuencia
    printf("\nX=%d Y=%d V[0]=%d V[1]=%d V[2]=%d V[3]=%d V[4]=%d", X,
           Y, V[0], V[1], V[2], V[3], V[4]);
    // En este punto, la salida sera: X=7 Y=21 V[0]=1 V[1]=3 V[2]=5 V[3]=9 V[4]=9

    return 0; // Indica que el programa finalizo correctamente
}
