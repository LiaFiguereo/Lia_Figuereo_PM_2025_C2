#include <stdio.h>
#include <string.h>
#include <stdlib.h> /* Para malloc y free */

/* Estructuras-3.
El programa muestra la manera en que se declara una estructura anidada, as�
como la forma de acceso a los campos de las variables o apuntadores de tipo
estructura, tanto para lectura como para escritura. Se utiliza adem�s una
funci�n que recibe como par�metro un apuntador de tipo estructura. */
typedef struct /* Declaraci�n de la estructura domicilio utilizando un typedef. */
{
    char calle[20];
    int numero;
    int cp;
    char localidad[20];
} domicilio;

struct empleado /* Declaraci�n de la estructura anidada empleado. */
{
    char nombre[20];
    char departamento[20];
    float sueldo;
    domicilio direccion; /* direccion es un campo de tipo estructura domicilio */
};

void Lectura(struct empleado *); /* Prototipo de funci�n. */

int main(void)
{
    /* Inicializaci�n correcta de e0 con estructura anidada */
    struct empleado e0 = {"Arturo", "Compras", 15500.75, {"San Jeronimo", 120, 3490, "Toluca"}};
    struct empleado *e1, *e2, e3, e4;

    /* Asignar memoria din�micamente para e1 */
    e1 = (struct empleado *)malloc(sizeof(struct empleado));
    if (e1 == NULL) {
        printf("\nError: No se pudo asignar memoria para e1.\n");
        return 1;
    }

    /* Leer datos para e1 */
    printf("\nIngrese el nombre del empleado 1: ");
    scanf("%19s", e1->nombre); /* Limita a 19 caracteres para dejar espacio para '\0' */
    while (getchar() != '\n'); /* Limpiar buffer */

    printf("Ingrese el departamento de la empresa: ");
    if (fgets(e1->departamento, sizeof(e1->departamento), stdin) != NULL) {
        e1->departamento[strcspn(e1->departamento, "\n")] = '\0';
    }

    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &e1->sueldo);
    while (getchar() != '\n'); /* Limpiar buffer */

    printf("----Ingrese la direcci�n del empleado----\n");
    printf("\tCalle: ");
    if (fgets(e1->direccion.calle, sizeof(e1->direccion.calle), stdin) != NULL) {
        e1->direccion.calle[strcspn(e1->direccion.calle, "\n")] = '\0';
    }

    printf("\tNumero: ");
    scanf("%d", &e1->direccion.numero);
    while (getchar() != '\n'); /* Limpiar buffer */

    printf("\tC�digo Postal: ");
    scanf("%d", &e1->direccion.cp);
    while (getchar() != '\n'); /* Limpiar buffer */

    printf("\tLocalidad: ");
    if (fgets(e1->direccion.localidad, sizeof(e1->direccion.localidad), stdin) != NULL) {
        e1->direccion.localidad[strcspn(e1->direccion.localidad, "\n")] = '\0';
    }

    /* Leer datos para e3 */
    printf("\nIngrese el nombre del empleado 3: ");
    scanf("%19s", e3.nombre);
    while (getchar() != '\n'); /* Limpiar buffer */

    printf("Ingrese el departamento de la empresa: ");
    if (fgets(e3.departamento, sizeof(e3.departamento), stdin) != NULL) {
        e3.departamento[strcspn(e3.departamento, "\n")] = '\0';
    }

    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &e3.sueldo);
    while (getchar() != '\n'); /* Limpiar buffer */

    printf("----Ingrese la direcci�n del empleado----\n");
    printf("\tCalle: ");
    if (fgets(e3.direccion.calle, sizeof(e3.direccion.calle), stdin) != NULL) {
        e3.direccion.calle[strcspn(e3.direccion.calle, "\n")] = '\0';
    }

    printf("\tNumero: ");
    scanf("%d", &e3.direccion.numero);
    while (getchar() != '\n'); /* Limpiar buffer */

    printf("\tC�digo Postal: ");
    scanf("%d", &e3.direccion.cp);
    while (getchar() != '\n'); /* Limpiar buffer */

    printf("\tLocalidad: ");
    if (fgets(e3.direccion.localidad, sizeof(e3.direccion.localidad), stdin) != NULL) {
        e3.direccion.localidad[strcspn(e3.direccion.localidad, "\n")] = '\0';
    }

    /* Asignar memoria din�micamente para e2 */
    e2 = (struct empleado *)malloc(sizeof(struct empleado));
    if (e2 == NULL) {
        printf("\nError: No se pudo asignar memoria para e2.\n");
        free(e1); /* Liberar memoria asignada a e1 */
        return 1;
    }

    Lectura(e2); /* Pasar apuntador e2 a la funci�n Lectura */
    Lectura(&e4); /* Pasar direcci�n de e4 a la funci�n Lectura */

    /* Imprimir datos */
    printf("\nDatos del empleado 0\n");
    printf("%s\t%s\t%.2f\t%s\t%d\t%d\t%s\n", e0.nombre, e0.departamento, e0.sueldo,
           e0.direccion.calle, e0.direccion.numero, e0.direccion.cp, e0.direccion.localidad);

    printf("Datos del empleado 1\n");
    printf("%s\t%s\t%.2f\t%s\t%d\t%d\t%s\n", e1->nombre, e1->departamento, e1->sueldo,
           e1->direccion.calle, e1->direccion.numero, e1->direccion.cp, e1->direccion.localidad);

    printf("Datos del empleado 3\n");
    printf("%s\t%s\t%.2f\t%s\t%d\t%d\t%s\n", e3.nombre, e3.departamento, e3.sueldo,
           e3.direccion.calle, e3.direccion.numero, e3.direccion.cp, e3.direccion.localidad);

    printf("Datos del empleado 4\n");
    printf("%s\t%s\t%.2f\t%s\t%d\t%d\t%s\n", e4.nombre, e4.departamento, e4.sueldo,
           e4.direccion.calle, e4.direccion.numero, e4.direccion.cp, e4.direccion.localidad);

    /* Liberar memoria asignada din�micamente */
    free(e1);
    free(e2);

    return 0; /* Retorno est�ndar */
}

void Lectura(struct empleado *a)
{
    /* Funci�n que permite leer los campos de un apuntador de tipo estructura empleado. */
    printf("\nIngrese el nombre del empleado: ");
    if (fgets(a->nombre, sizeof(a->nombre), stdin) != NULL) {
        a->nombre[strcspn(a->nombre, "\n")] = '\0';
    }

    printf("Ingrese el departamento de la empresa: ");
    if (fgets(a->departamento, sizeof(a->departamento), stdin) != NULL) {
        a->departamento[strcspn(a->departamento, "\n")] = '\0';
    }

    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &a->sueldo);
    while (getchar() != '\n'); /* Limpiar buffer */

    printf("----Ingrese la direcci�n del empleado----\n");
    printf("\tCalle: ");
    if (fgets(a->direccion.calle, sizeof(a->direccion.calle), stdin) != NULL) {
        a->direccion.calle[strcspn(a->direccion.calle, "\n")] = '\0';
    }

    printf("\tNumero: ");
    scanf("%d", &a->direccion.numero);
    while (getchar() != '\n'); /* Limpiar buffer */

    printf("\tC�digo Postal: ");
    scanf("%d", &a->direccion.cp);
    while (getchar() != '\n'); /* Limpiar buffer */

    printf("\tLocalidad: ");
    if (fgets(a->direccion.localidad, sizeof(a->direccion.localidad), stdin) != NULL) {
        a->direccion.localidad[strcspn(a->direccion.localidad, "\n")] = '\0';
    }
}
