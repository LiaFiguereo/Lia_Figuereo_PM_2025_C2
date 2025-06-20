#include <stdio.h> // Se incluye la libreria estandar de entrada/salida

/* Apuntadores y arreglos */
int main(void) // Se cambia la firma de main a int main(void)
{
    // Se inicializan completamente ambos arreglos para evitar valores "basura"
    // V1 tiene 4 elementos: {2, 3, 4, 7}
    // V2 tiene 4 elementos: {6, 0, 0, 0} (el resto se inicializa a 0 si se especifica solo el primer elemento)
    int V1[4] = {2, 3, 4, 7};
    int V2[4] = {6, 0, 0, 0}; // Importante: Inicializar mas elementos de V2 o ser consciente de los valores por defecto

    int *AX, *AY; // Declaracion de punteros a enteros

    AX = &V1[3]; // AX apunta al cuarto elemento de V1 (V1[3], que contiene 7)
                 // *AX ahora es 7

    AY = &V2[2]; // AY apunta al tercer elemento de V2 (V2[2], que ahora es 0 debido a la inicializacion completa)
                 // *AY ahora es 0

    // V2[0] es 6, V1[2] es 4.
    // V2[0] - V1[2] = 6 - 4 = 2.
    // Asi que V1[2] = *AY (que es 0).
    // V1 pasa de {2, 3, 4, 7} a {2, 3, 0, 7}.
    V1[V2[0] - V1[2]] = *AY;

    // *AY = *AX - V1[0];
    // *AX es 7. V1[0] es 2.
    // *AY = 7 - 2 = 5.
    // Como AY apunta a V2[2], V2[2] cambia de 0 a 5.
    // V2 pasa de {6, 0, 0, 0} a {6, 0, 5, 0}.
    *AY = *AX - V1[0];

    // Primera impresion de los estados de los arreglos
    printf("\nV1[0]=%d V1[1]=%d V1[2]=%d V1[3]=%d \tV2[0]=%d V2[1]=%d V2[2]=%d V2[3]=%d",
           V1[0], V1[1], V1[2], V1[3], V2[0], V2[1], V2[2], V2[3]);

    // --- Segunda secuencia de operaciones con punteros ---

    // V2[1] = ++*AX;
    // ++*AX: Primero incrementa el valor al que apunta AX (*AX), y luego usa ese valor.
    // *AX (que es V1[3]) pasa de 7 a 8.
    // Luego, V2[1] se asigna ese nuevo valor (8).
    // V1 ahora es {2, 3, 0, 8}. V2 ahora es {6, 8, 5, 0}.
    V2[1] = ++*AX;

    // V2[3] = (*AY)++;
    // (*AY)++: Primero usa el valor al que apunta AY (*AY), y luego lo incrementa.
    // *AY es 5. V2[3] se asigna 5.
    // Luego, *AY (que es V2[2]) se incrementa a 6.
    // V2 ahora es {6, 8, 6, 5}.
    V2[3] = (*AY)++;

    // *AX += 2;
    // *AX (que es V1[3]) se incrementa en 2. Estaba en 8, ahora es 10.
    // V1 ahora es {2, 3, 0, 10}.
    *AX += 2;

    // Segunda impresion de los estados de los arreglos
    printf("\nV1[0]=%d V1[1]=%d V1[2]=%d V1[3]=%d \tV2[0]=%d V2[1]=%d V2[2]=%d V2[3]=%d",
           V1[0], V1[1], V1[2], V1[3], V2[0], V2[1], V2[2], V2[3]);

    return 0; // Indica que el programa finalizo correctamente
}
