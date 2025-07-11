#include <stdio.h>
#include <string.h> // Para strcpy y strcspn

// Definición de las estructuras (iguales a las de tu programa principal)
typedef struct
{
    char materia[20];
    int calificacion;
} matcal;

typedef struct
{
    int matricula;
    char nombre[20];
    matcal cal[5]; // Un campo es a su vez una estructura
} alumno;

// --- Función auxiliar para mostrar el contenido de un archivo binario ---
// Esto te ayudará a verificar que los datos se guardaron correctamente
void mostrar_contenido_esc_dat(const char *nombre_archivo)
{
    FILE *ar;
    alumno alu;
    int j;

    printf("\n--- Contenido actual de '%s': ---\n", nombre_archivo);
    ar = fopen(nombre_archivo, "rb"); // Abrir en modo lectura binaria

    if (ar == NULL)
    {
        printf("ERROR: No se pudo abrir '%s' para leer su contenido.\n", nombre_archivo);
        return;
    }

    // Leer y mostrar cada registro hasta el final del archivo
    while (fread(&alu, sizeof(alumno), 1, ar) == 1)
    {
        printf("\nMatricula: %d\n", alu.matricula);
        printf("Nombre: %s\n", alu.nombre);
        printf("Calificaciones:\n");
        for (j = 0; j < 5; j++)
        {
            printf("  Materia %d: %s, Calificacion: %d\n", j + 1, alu.cal[j].materia, alu.cal[j].calificacion);
        }
    }
    printf("--- Fin del contenido de '%s' ---\n", nombre_archivo);
    fclose(ar);
}
// --------------------------------------------------------------------------

int main()
{
    FILE *ar_salida;
    alumno nuevo_alumno;
    char respuesta;
    int i;

    // Abre esc.dat en modo escritura binaria. Esto lo creará o lo sobrescribirá.
    ar_salida = fopen("esc.dat", "wb");

    if (ar_salida == NULL)
    {
        printf("Error: No se pudo abrir esc.dat para escritura. Verifica permisos.\n");
        return 1;
    }

    printf("--- Creando esc.dat con datos de alumnos ---\n");
    do
    {
        printf("\nIngresa datos del alumno:\n");
        printf("Matricula: ");
        scanf("%d", &nuevo_alumno.matricula);
        while (getchar() != '\n'); // Limpiar buffer de entrada

        printf("Nombre (max 19 caracteres): ");
        fgets(nuevo_alumno.nombre, sizeof(nuevo_alumno.nombre), stdin);
        nuevo_alumno.nombre[strcspn(nuevo_alumno.nombre, "\n")] = 0; // Eliminar salto de línea

        printf("Ingresa 5 materias y calificaciones:\n");
        for (i = 0; i < 5; i++)
        {
            printf("  Materia %d Nombre (max 19 chars): ", i + 1);
            fgets(nuevo_alumno.cal[i].materia, sizeof(nuevo_alumno.cal[i].materia), stdin);
            nuevo_alumno.cal[i].materia[strcspn(nuevo_alumno.cal[i].materia, "\n")] = 0;

            printf("  Materia %d Calificacion (0-10): ", i + 1);
            scanf("%d", &nuevo_alumno.cal[i].calificacion);
            while (getchar() != '\n'); // Limpiar buffer
        }

        // Escribir la estructura completa del alumno en el archivo
        fwrite(&nuevo_alumno, sizeof(alumno), 1, ar_salida);

        printf("\n¿Agregar otro alumno? (s/n): ");
        scanf("%c", &respuesta);
        while (getchar() != '\n'); // Limpiar buffer
    } while (respuesta == 's' || respuesta == 'S');

    fclose(ar_salida);
    printf("\nesc.dat creado exitosamente.\n");

    // Llama a la función para verificar el contenido justo después de crearlo
    mostrar_contenido_esc_dat("esc.dat");

    return 0;
}
