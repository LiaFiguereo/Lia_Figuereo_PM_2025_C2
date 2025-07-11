#include <stdio.h>
/* Archivos y caracteres.
El programa lee caracteres de un archivo. */
void main(void)
{
char p1;
FILE *ar;
FILE *ar2;
ar = fopen("c:\\temp\\arc.txt", "r");
ar2 = fopen("c:\\temp\\arc.txt", "w");

if (ar != NULL && ar2 != NULL ) /* Se abre el archivo para lectura. */
/* Observa que las dos instrucciones del programa 9.1 necesarias para abrir un
➥archivo y verificar que éste en realidad se haya abierto, se pueden agrupar
➥en una sola instrucción. */
{
while (!feof(ar))
/* Se leen caracteres del archivo mientras no se detecte el fin del
➥archivo. */
{
p1 = fgetc(ar); /* Lee el caracter del archivo. */
putchar(p1); /* Despliega el caracter en la pantalla. */
fputchar(p1,ar2);
}
fclose(ar);
fclose(ar2);
}
else
printf("No se puede abrir el archivo");
}
