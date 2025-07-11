#include <stdio.h>
/* Archivos y caracteres.
El programa escribe caracteres en un archivo. */
void main(void)
{
char p1;
FILE *ar;
ar = fopen("c:\\temp\\arc.txt", "r"); /* Se abre el archivo arc.txt para escritura. */
if (ar != NULL)

{
    printf("\nEscribir contenido de archivo:");
while ((p1=getchar()) != '\n')

{
    fputc(p1, ar);
}

fclose(ar); /* Se cierra el archivo. */
}
else
printf("No se puede abrir el archivo");
}
