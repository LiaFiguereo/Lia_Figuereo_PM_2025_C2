#include <stdio.h>
#include <ctype.h>
#include <string.h> // Asegúrate de que esta librería esté incluida para las funciones de cadena

/* Reemplaza palabras.
El programa lee cadenas de caracteres de un archivo y cada que vez que
➥encuentra la palabra México escrita en forma incorrecta —la primera con
➥minúscula— la reemplaza por su forma correcta y escribe la cadena en otro
➥archivo. */
void cambia(FILE *, FILE *);
/* Prototipo de función. Se pasan dos archivos como parámetros. */

void main(void)
{
    FILE *ar;
    FILE *ap;

    // Intentamos abrir ambos archivos
    ar = fopen("arc.txt", "r");   /* Se abre el archivo arc.txt para lectura. */
    ap = fopen("arc1.txt", "w"); /* Se abre el archivo arc1.txt para escritura. */

    if ((ar != NULL) && (ap != NULL))
    {
        printf("Archivos 'arc.txt' y 'arc1.txt' abiertos exitosamente.\n");
        cambia(ar, ap);
        fclose(ar);
        fclose(ap);
        printf("Proceso completado. Por favor, revisa el archivo 'arc1.txt'.\n");
    }
    else
    {
        // Mensajes de error más específicos para ayudarte a depurar
        if (ar == NULL)
            printf("Error: No se pudo abrir 'arc.txt'. Asegúrate de que exista y esté en la misma carpeta que el programa.\n");
        if (ap == NULL)
            printf("Error: No se pudo abrir/crear 'arc1.txt'. Verifica los permisos de escritura en la carpeta.\n");
    }
}

void cambia(FILE *ap1, FILE *ap2)
{
    char cad[256]; // Aumentado el tamaño del búfer. 30 caracteres es muy pequeño para una línea típica.
    char *cad_encontrada; // Puntero para almacenar el resultado de strstr

    // Bucle para leer línea por línea de forma robusta.
    // 'fgets' devuelve NULL cuando llega al final del archivo o si hay un error.
    while (fgets(cad, sizeof(cad), ap1) != NULL)
    {
        // DEBUG: Imprime la línea original que se está leyendo
        printf("Leyendo linea: %s", cad);

        // Busca la primera ocurrencia de "méxico" (con 'm' minúscula)
        cad_encontrada = strstr(cad, "méxico");

        // Bucle para procesar todas las ocurrencias de "méxico" en la misma línea
        while (cad_encontrada != NULL)
        {
            cad_encontrada[0] = 'M'; // Cambia la 'm' minúscula por 'M' mayúscula

            // DEBUG: Muestra la línea después del reemplazo
            printf("  Reemplazado 'méxico' en: %s", cad);

            // Busca la siguiente ocurrencia de "méxico" a partir de donde terminó la anterior
            // Esto asegura que si hay múltiples "méxico" en una línea, todos se procesen.
            cad_encontrada = strstr(cad_encontrada + strlen("méxico"), "méxico");
        }
        // Después de procesar la línea (con o sin cambios), la escribe en el archivo de salida
        fputs(cad, ap2);
    }
    printf("Fin de la lectura del archivo de entrada.\n");
}
