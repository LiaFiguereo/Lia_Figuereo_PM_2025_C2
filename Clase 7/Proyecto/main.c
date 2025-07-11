#include <stdio.h>   // Para funciones de entrada/salida (printf, scanf, fopen, fclose, etc.)
#include <stdlib.h>  // Para funciones generales (malloc, realloc, free, exit)
#include <string.h>  // Para funciones de manipulación de cadenas (strcpy, strcmp, strcspn)

// Define la estructura para almacenar los datos de un alumno.
// Usamos un tamaño fijo para el nombre para facilitar la lectura/escritura binaria.
typedef struct {
    char nombre[50]; // Nombre del alumno (cadena de caracteres)
    int id;          // ID del alumno (entero)
    float promedio;  // Promedio del alumno (número flotante)
} Alumno;

// --- Prototipos de Funciones ---
void agregar_alumno(const char *nombre_archivo);
// Carga alumnos del archivo a la memoria dinámica, devuelve el número de alumnos cargados
// y actualiza el puntero 'alumnos_ptr' para que apunte al arreglo cargado.
int cargar_alumnos(const char *nombre_archivo, Alumno **alumnos_ptr);
void imprimir_alumnos(Alumno *alumnos, int num_alumnos);
void ordenar_por_nombre(Alumno *alumnos, int num_alumnos);
void ordenar_por_promedio(Alumno *alumnos, int num_alumnos);

// --- Implementación de Funciones ---

void agregar_alumno(const char *nombre_archivo) {
    FILE *archivo;
    Alumno nuevo_alumno;

    // Abre el archivo en modo "append binary" (añadir binario).
    // Si el archivo no existe, lo crea. Si existe, añade al final.
    archivo = fopen(nombre_archivo, "ab");
    if (archivo == NULL) {
        perror("Error al abrir el archivo para agregar");
        exit(EXIT_FAILURE);
    }

    printf("\n--- Agregar Nuevo Alumno ---\n");
    // Limpiar el buffer de entrada antes de leer con fgets
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Nombre: ");
    fgets(nuevo_alumno.nombre, sizeof(nuevo_alumno.nombre), stdin);
    // Eliminar el salto de línea capturado por fgets
    nuevo_alumno.nombre[strcspn(nuevo_alumno.nombre, "\n")] = 0;

    printf("ID: ");
    scanf("%d", &nuevo_alumno.id);

    printf("Promedio: ");
    scanf("%f", &nuevo_alumno.promedio);

    // Escribe la estructura completa de Alumno en el archivo binario
    fwrite(&nuevo_alumno, sizeof(Alumno), 1, archivo);

    fclose(archivo); // Cierra el archivo
    printf("Alumno guardado exitosamente.\n");
}

int cargar_alumnos(const char *nombre_archivo, Alumno **alumnos_ptr) {
    FILE *archivo;
    Alumno temp_alumno;
    int count = 0;
    *alumnos_ptr = NULL; // Asegurarse de que el puntero inicial esté a NULL

    // Abre el archivo en modo "read binary" (lectura binaria)
    archivo = fopen(nombre_archivo, "rb");
    if (archivo == NULL) {
        // No se considera un error grave si el archivo no existe al cargar por primera vez
        // perror("Error al abrir el archivo para cargar o archivo no existe");
        return 0; // Devuelve 0 alumnos si hay error o no existe
    }

    // Lee el archivo alumno por alumno hasta el final del archivo (EOF)
    while (fread(&temp_alumno, sizeof(Alumno), 1, archivo) == 1) {
        // Redimensiona dinámicamente el arreglo de alumnos para añadir uno más
        *alumnos_ptr = (Alumno *)realloc(*alumnos_ptr, (count + 1) * sizeof(Alumno));
        if (*alumnos_ptr == NULL) {
            perror("Error de asignación de memoria (realloc)");
            fclose(archivo);
            exit(EXIT_FAILURE);
        }
        // Copia el alumno leído al arreglo dinámico
        (*alumnos_ptr)[count] = temp_alumno;
        count++;
    }

    fclose(archivo);
    return count; // Devuelve el número total de alumnos cargados
}

void imprimir_alumnos(Alumno *alumnos, int num_alumnos) {
    if (num_alumnos == 0) {
        printf("No hay alumnos para mostrar.\n");
        return;
    }
    printf("----------------------------------\n");
    printf("%-20s %-5s %-10s\n", "Nombre", "ID", "Promedio");
    printf("----------------------------------\n");
    for (int i = 0; i < num_alumnos; i++) {
        printf("%-20s %-5d %-10.2f\n", alumnos[i].nombre, alumnos[i].id, alumnos[i].promedio);
    }
    printf("----------------------------------\n");
}

// Algoritmo Bubble Sort para ordenar por nombre alfabéticamente
void ordenar_por_nombre(Alumno *alumnos, int num_alumnos) {
    int i, j;
    Alumno temp; // Variable temporal para el intercambio

    for (i = 0; i < num_alumnos - 1; i++) {
        for (j = 0; j < num_alumnos - 1 - i; j++) {
            // Compara los nombres usando strcmp
            if (strcmp(alumnos[j].nombre, alumnos[j+1].nombre) > 0) {
                // Intercambio de alumnos si están en el orden incorrecto
                temp = alumnos[j];
                alumnos[j] = alumnos[j+1];
                alumnos[j+1] = temp;
            }
        }
    }
    printf("\nAlumnos ordenados por nombre (A-Z):\n");
}

// Algoritmo Bubble Sort para ordenar por promedio (de menor a mayor)
void ordenar_por_promedio(Alumno *alumnos, int num_alumnos) {
    int i, j;
    Alumno temp;

    for (i = 0; i < num_alumnos - 1; i++) {
        for (j = 0; j < num_alumnos - 1 - i; j++) {
            // Compara los promedios
            if (alumnos[j].promedio > alumnos[j+1].promedio) {
                // Intercambio de alumnos si están en el orden incorrecto
                temp = alumnos[j];
                alumnos[j] = alumnos[j+1];
                alumnos[j+1] = temp;
            }
        }
    }
    printf("\nAlumnos ordenados por promedio (menor a mayor):\n");
}

// --- Función Principal (Main) ---
int main() {
    const char *nombre_archivo = "alumnos.dat"; // Nombre del archivo binario
    Alumno *alumnos = NULL; // Puntero al arreglo dinámico de alumnos en memoria
    int num_alumnos = 0;    // Contador de alumnos cargados
    int opcion;             // Para el menú de opciones

    do {
        printf("\n--- GESTION DE ALUMNOS ---\n");
        printf("1. Agregar nuevo alumno\n");
        printf("2. Imprimir alumnos por nombre\n");
        printf("3. Imprimir alumnos por promedio\n");
        printf("4. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregar_alumno(nombre_archivo);
                break;
            case 2:
                // Liberar memoria si ya se habían cargado alumnos antes
                if (alumnos != NULL) {
                    free(alumnos);
                    alumnos = NULL; // Importante ponerlo a NULL después de liberar
                }
                num_alumnos = cargar_alumnos(nombre_archivo, &alumnos);
                if (num_alumnos > 0) {
                    ordenar_por_nombre(alumnos, num_alumnos);
                    imprimir_alumnos(alumnos, num_alumnos);
                } else {
                    printf("No hay alumnos cargados para ordenar.\n");
                }
                break;
            case 3:
                // Liberar memoria si ya se habían cargado alumnos antes
                if (alumnos != NULL) {
                    free(alumnos);
                    alumnos = NULL;
                }
                num_alumnos = cargar_alumnos(nombre_archivo, &alumnos);
                if (num_alumnos > 0) {
                    ordenar_por_promedio(alumnos, num_alumnos);
                    imprimir_alumnos(alumnos, num_alumnos);
                } else {
                    printf("No hay alumnos cargados para ordenar.\n");
                }
                break;
            case 4:
                printf("Saliendo del programa. ¡Hasta luego!\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while (opcion != 4);

    // Liberar la memoria asignada dinámicamente antes de que el programa termine
    if (alumnos != NULL) {
        free(alumnos);
    }

    return 0;
}
