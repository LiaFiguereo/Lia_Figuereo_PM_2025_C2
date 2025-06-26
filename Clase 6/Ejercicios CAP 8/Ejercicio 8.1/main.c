#include <stdio.h>
#include <string.h>

/* Estructuras-1.
El programa muestra la manera en que se declara una estructura, as� como la
forma en que se tiene acceso a los campos de las variables de tipo estructura
tanto para asignaci�n de valores como para lectura y escritura. */
struct alumno /* Declaraci�n de la estructura. */
{
    int matricula;
    char nombre[20];
    char carrera[20]; /* Campos de la estructura. */
    float promedio;
    char direccion[20];
}; /* Observa que la declaraci�n de una estructura termina con punto y coma. */

int main(void)
{
    /* Observa que las variables de tipo estructura se declaran como cualquier otra
    variable. a1, a2 y a3 son variables de tipo estructura alumno. */
    struct alumno a1 = {120, "Maria", "Contabilidad", 8.9, "Queretaro"}, a2, a3;
    char nom[20], car[20], dir[20];
    int mat;
    float pro;

    /* Los campos de a2 reciben valores por medio de una lectura. */
    printf("\nIngrese la matricula del alumno 2: ");
    scanf("%d", &a2.matricula);
    while (getchar() != '\n'); /* Limpiar el buffer de entrada */

    printf("Ingrese el nombre del alumno 2: ");
    if (fgets(a2.nombre, sizeof(a2.nombre), stdin) != NULL) {
        a2.nombre[strcspn(a2.nombre, "\n")] = '\0'; /* Eliminar salto de linea */
    }

    printf("Ingrese la carrera del alumno 2: ");
    if (fgets(a2.carrera, sizeof(a2.carrera), stdin) != NULL) {
        a2.carrera[strcspn(a2.carrera, "\n")] = '\0';
    }

    printf("Ingrese el promedio del alumno 2: ");
    scanf("%f", &a2.promedio);
    while (getchar() != '\n'); /* Limpiar el buffer de entrada */

    printf("Ingrese la direccion del alumno 2: ");
    if (fgets(a2.direccion, sizeof(a2.direccion), stdin) != NULL) {
        a2.direccion[strcspn(a2.direccion, "\n")] = '\0';
    }

    /* Los campos de a3 reciben valores por medio de asignaciones. */
    printf("\nIngrese la matricula del alumno 3: ");
    scanf("%d", &mat);
    a3.matricula = mat;
    while (getchar() != '\n'); /* Limpiar el buffer de entrada */

    printf("Ingrese el nombre del alumno 3: ");
    if (fgets(nom, sizeof(nom), stdin) != NULL) {
        nom[strcspn(nom, "\n")] = '\0';
    }
    strcpy(a3.nombre, nom);

    printf("Ingrese la carrera del alumno 3: ");
    if (fgets(car, sizeof(car), stdin) != NULL) {
        car[strcspn(car, "\n")] = '\0';
    }
    strcpy(a3.carrera, car);

    printf("Ingrese el promedio del alumno 3: ");
    scanf("%f", &pro);
    a3.promedio = pro;
    while (getchar() != '\n'); /* Limpiar el buffer de entrada */

    printf("Ingrese la direccion del alumno 3: ");
    if (fgets(dir, sizeof(dir), stdin) != NULL) {
        dir[strcspn(dir, "\n")] = '\0';
    }
    strcpy(a3.direccion, dir);

    /* Observe la forma en que se imprimen los campos de a1 y a2. */
    printf("\nDatos del alumno 1\n");
    printf("%d\n", a1.matricula);
    puts(a1.nombre);
    puts(a1.carrera);
    printf("%.2f\n", a1.promedio);
    puts(a1.direccion);

    printf("\nDatos del alumno 2\n");
    printf("%d\n", a2.matricula);
    puts(a2.nombre);
    puts(a2.carrera);
    printf("%.2f\n", a2.promedio);
    puts(a2.direccion);

    /* Observa otra forma de escribir los campos de la variable de tipo estructura a3. */
    printf("\nDatos del alumno 3\n");
    printf("%d \t %s \t %s \t %.2f \t %s\n", a3.matricula, a3.nombre, a3.carrera,
           a3.promedio, a3.direccion);

    return 0; /* Retorno est�ndar */
}
