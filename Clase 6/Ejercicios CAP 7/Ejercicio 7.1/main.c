#include <stdio.h>

int main(void)
{
    char p1, p2, p3 = '$'; // Comillas simples correctas

    // Ingreso con getchar
    printf("\nIngrese un caracter: ");
    p1 = getchar(); // Lee un caracter
    putchar(p1);    // Imprime ese caracter
    printf("\n");

    // Limpieza del b�fer de entrada
    while (getchar() != '\n'); // Limpia el salto de l�nea pendiente

    // Muestra el contenido de p3
    printf("\nEl caracter p3 es: ");
    putchar(p3);
    printf("\n");

    // Ingreso con scanf
    printf("\nIngrese otro caracter: ");
    scanf(" %c", &p2); // Nota: el espacio antes de %c ignora espacios en blanco
    printf("%c\n", p2); // Imprime el caracter ingresado

    return 0;
}
