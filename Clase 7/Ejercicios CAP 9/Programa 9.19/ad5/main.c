#include <stdio.h>
#include <string.h>

typedef struct
{
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

void mostrar_contenido_binario(const char *nombre_archivo)
{
    FILE *ar;
    alumno alu;

    printf("\n--- Contenido de '%s': ---\n", nombre_archivo);
    ar = fopen(nombre_archivo, "rb");

    if (ar == NULL)
    {
        printf("ERROR: No se pudo abrir '%s' para leer su contenido.\n", nombre_archivo);
        return;
    }

    while (fread(&alu, sizeof(alumno), 1, ar) == 1)
    {
        printf("Matricula: %d, Nombre: %s, Carrera: %d, Promedio: %.2f\n",
               alu.matricula, alu.nombre, alu.carrera, alu.promedio);
    }
    printf("--- Fin del contenido de '%s' ---\n", nombre_archivo);
    fclose(ar);
}

int main()
{
    FILE *ar_salida;
    alumno datos_alu;
    char respuesta;

    ar_salida = fopen("ad5.dat", "wb");

    if (ar_salida == NULL)
    {
        printf("Error: No se pudo abrir ad5.dat para escritura. Verifica permisos.\n");
        return 1;
    }

    printf("--- Creando ad5.dat con datos de alumnos ---\n");
    do
    {
        printf("\nIngresa los datos del alumno:\n");
        printf("Matricula: ");
        scanf("%d", &datos_alu.matricula);
        while (getchar() != '\n');

        printf("Nombre (max 19 caracteres): ");
        fgets(datos_alu.nombre, sizeof(datos_alu.nombre), stdin);
        datos_alu.nombre[strcspn(datos_alu.nombre, "\n")] = 0;

        printf("Carrera (numero entero): ");
        scanf("%d", &datos_alu.carrera);
        printf("Promedio: ");
        scanf("%f", &datos_alu.promedio);

        fwrite(&datos_alu, sizeof(alumno), 1, ar_salida);

        printf("¿Agregar otro alumno? (s/n): ");
        while (getchar() != '\n');
        scanf("%c", &respuesta);

    } while (respuesta == 's' || respuesta == 'S');

    fclose(ar_salida);
    printf("\nad5.dat creado exitosamente.\n");

    mostrar_contenido_binario("ad5.dat");

    return 0;
}
