#include <stdio.h>

int main(void)
{
    char *cad0 = "Buenos d�as"; // Cadena literal apuntada por cad0
    char cad1[20] = "Hola";     // Cadena con espacio reservado
    char cad2[] = "M�xico";     // Cadena sin tama�o especificado
    char cad3[] = {'B', 'i', 'e', 'n', 'v', 'e', 'n', 'i', 'd', 'o', '\0'}; // Cadena car�cter por car�cter
    char cad4[20], cad5[20], cad6[20];

    printf("\nLa cadena cad0 es: ");
    puts(cad0);

    printf("\nLa cadena cad1 es: ");
    printf("%s\n", cad1);

    printf("\nLa cadena cad2 es: ");
    puts(cad2);

    printf("\nLa cadena cad3 es: ");
    puts(cad3);

    printf("\nIngrese una l�nea de texto �se lee con fgets�:\n");
    fgets(cad4, sizeof(cad4), stdin); // fgets reemplaza a gets por seguridad

    printf("\nLa cadena cad4 es: ");
    puts(cad4);

    printf("\nIngrese una l�nea de texto �se lee con scanf (solo una palabra)�:\n");
    scanf("%s", cad5); // Lee solo la primera palabra

    printf("\nLa cadena cad5 es: ");
    printf("%s\n", cad5);

    while (getchar() != '\n'); // Limpiar el b�fer antes de usar getchar

    char p;
    int i = 0;

    printf("\nIngrese una l�nea de texto �se lee cada caracter con getchar�:\n");
    while ((p = getchar()) != '\n' && i < sizeof(cad6) - 1) {
        cad6[i++] = p;
    }
    cad6[i] = '\0'; // Terminador nulo

    printf("\nLa cadena cad6 es: ");
    puts(cad6);

    return 0;
}
