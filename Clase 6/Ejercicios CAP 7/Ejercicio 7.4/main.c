#include <stdio.h>
#include <string.h>  // Necesaria para funciones como strcspn

/* Declaración de cadenas de caracteres y asignación de valores. */
void main(void)
{
    char *cad0;
    cad0 = "Argentina"; /* La declaración y la asignación son correctas. */
    puts(cad0);
    cad0 = "Brasil";
    /* Correcto. Se modifica el contenido de la posición en memoria a la que apunta
    ➥la variable cad0 —apuntador de tipo cadena de caracteres. */
    puts(cad0);

    char cad1[50];
    printf("\nIngrese una línea de texto —se lee con fgets—: \n");
    fgets(cad1, sizeof(cad1), stdin);
    cad1[strcspn(cad1, "\n")] = '\0';
    /* Correcto. Primero se le asigna un valor a la posición de memoria a la que
    ➥apunta cad1. Luego podemos modificar el contenido de esta posición de memoria
    ➥utilizando la función gets. */

    // char cad1[];
    /* Incorrecto. Se genera un error en la compilación del programa, porque no
    ➥se reserva el espacio correspondiente. */

    char cad2[20] = "México"; /* Correcto. */
    puts(cad2);

    printf("\nIngrese una línea de texto —se lee con fgets—: \n");
    fgets(cad2, sizeof(cad2), stdin);
    cad2[strcspn(cad2, "\n")] = '\0';
    /* El valor de una cadena (declarada como cadena[longitud]) se puede modificar
    ➥por medio de lecturas o utilizando funciones de la biblioteca string.h
    (ejemplo 7.6). */
    puts(cad2);

    // cad2[10] = "Guatemala";
    /* Incorrecto. Observa cuidadosamente el caso anterior y analiza la diferencia
    ➥que existe con éste. Aquí se produce un error en la compilación del programa,
    ➥al tratar de asignar la cadena de caracteres ”Guatemala” al caracter 11 de la
    ➥cadena. */
}
