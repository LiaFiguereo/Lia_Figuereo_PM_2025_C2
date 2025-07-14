#include <stdio.h> // Para entrada/salida estándar (printf, scanf, fopen, etc.)
#include <stdlib.h> // Para manejo de memoria dinámica (malloc, free, exit)
#include <string.h> // Para funciones de cadenas (strcpy, strlen)

//Estructura para representar a un alumno

typedef struct Alumno
{
    int id;
    char nombre[50];
    int edad;
    struct Alumno *siguiente; // puntero para poder enlazar al siguiente alumno
} Alumno;

//Prototipos de funciones
void grabar_alumno_en_disco(const char *nombre_archivo, Alumno *nuevo_alumno);
Alumno* leer_alumnos_desde_disco(const char *nombre_archivo);
void imprimir_lista_alumnos(Alumno *head);
void liberar_memoria(Alumno *head);

//funcion principal
int main()
{
    char nombre_archivo[] = "alumnos.dat";
    int opcion;
    Alumno *lista_alumnos = NULL; //puntero al inicio de la lista de alumnos

    do{
        printf("\n--- Menu de gestion de alumnos ---\n");
        printf("1. \nGrabar nuevo alumno");
        printf("2. \nLeer todos los alumnos del disco");
        printf("3. \nSalir");
        scanf("%d", &opcion);

        switch (opcion){
            case 1:{
                //creacion de un nuevo alumno dinamicamente
        Alumno *nuevo_alumno = (Alumno *) malloc(sizeof(Alumno));
        if (nuevo_alumno == NULL) {
            perror("Error al asignar memoria para nuevo alumno");
            exit(EXIT_FAILURE);
        }
        printf("\n--- INGRESO DE NUEVO ALUMNO ---\n");
                printf("ID del alumno: ");
                scanf("%d", &nuevo_alumno->id);
                printf("Nombre del alumno (sin espacios): ");
                scanf("%s", nuevo_alumno->nombre); // Usar %s para leer sin espacios
                printf("Edad del alumno: ");
                scanf("%d", &nuevo_alumno->edad);
                nuevo_alumno->siguiente = NULL; // Por ahora, no apunta a nadie

                grabar_alumno_en_disco(nombre_archivo,nuevo_alumno);
                printf("\nAlumno grabado con exito.");
                free(nuevo_alumno); //liberamos la memoria del alumno temporal
                break;
            }
            case 2: {
            //Liberar memoria de la lista anterior si existe
            liberar_memoria(lista_alumnos);
            //Leer todos los alumnos del disco y crear la lista enlazada en memoria
            lista_alumnos = leer_alumnos_desde_disco(nombre_archivo);
            if (lista_alumnos == NULL) {
                printf("\nNo hay alumnos en el archivo o el archivo no existe.");
            } else {
            printf("\n--- Alumnos leidos del disco ---\n");
            imprimir_lista_alumnos(lista_alumnos);

            }
            break;

            }
            case 3:
                printf("\nSaliendo del programa. Hasta luego!");
                break;
            default:
                printf("\nOpcion invalida. Por favor, intente de nuevo.");

        }
    } while (opcion != 3);
    //liberar la memoria de todos los alumnos antes de salir
    liberar_memoria(lista_alumnos);
    return 0; //el programa finalizo con exito
}

//funcion para grabar un alumno en el disco
void grabar_alumno_en_disco(const char *nombre_archivo, Alumno *nuevo_alumno) {
    FILE *archivo = fopen(nombre_archivo, "ab"); // "ab" para abrir en modo append binario
    if (archivo == NULL) {
        perror("Error al abrir el archivo para escritura");
        exit(EXIT_FAILURE);
    }

    // Escribir la estructura del alumno directamente en el archivo
    // No escribimos el puntero 'siguiente' ya que es para la memoria.
    fwrite(nuevo_alumno, sizeof(Alumno) - sizeof(Alumno *), 1, archivo);
    fclose(archivo);
}

//funcion para leer todo slos alumnos del disco y crear una lista enlazada
Alumno* leer_alumnos_desde_disco(const char *nombre_archivo) {
    FILE *archivo = fopen(nombre_archivo, "rb"); // "rb" para abrir en modo lectura binaria
    if (archivo == NULL) {
        // Si el archivo no existe, no es un error fatal, simplemente no hay alumnos
        return NULL;
    }

    Alumno *head = NULL; // Puntero al primer alumno de la lista
    Alumno *current = NULL; // Puntero al alumno actual en la lista

    // Leer hasta que se llegue al final del archivo
    while (!feof(archivo)) {
        Alumno *temp_alumno = (Alumno *) malloc(sizeof(Alumno));
        if (temp_alumno == NULL) {
            perror("Error al asignar memoria para leer alumno");
            liberar_memoria(head); // Liberar lo que ya se había asignado
            exit(EXIT_FAILURE);
        }

        // Intentar leer una estructura de alumno del archivo
        size_t leidos = fread(temp_alumno, sizeof(Alumno) - sizeof(Alumno *), 1, archivo);

        if (leidos == 1) {
            temp_alumno->siguiente = NULL; // Asegurarse de que el siguiente sea NULL por defecto

            if (head == NULL) {
                head = temp_alumno; // Si es el primer alumno, lo ponemos como cabeza
            } else {
                current->siguiente = temp_alumno; // Si no, lo enlazamos al final de la lista
            }
            current = temp_alumno; // Mover el puntero actual al nuevo alumno
        } else {
            // Si no se leyó una estructura completa, es el final del archivo o un error
            free(temp_alumno); // Liberar la memoria no utilizada
            break; // Salir del bucle
        }
    }
    fclose(archivo);
    return head;
}

// Función para imprimir la lista de alumnos
void imprimir_lista_alumnos(Alumno *head) {
    if (head == NULL) {
        printf("La lista de alumnos esta vacia.\n");
        return;
    }
    Alumno *actual = head;
    while (actual != NULL) {
        printf("ID: %d, Nombre: %s, Edad: %d\n", actual->id, actual->nombre, actual->edad);
        actual = actual->siguiente; // Moverse al siguiente alumno usando el puntero
    }
}

// Función para liberar toda la memoria asignada dinámicamente
void liberar_memoria(Alumno *head) {
    Alumno *actual = head;
    Alumno *siguiente;
    while (actual != NULL) {
        siguiente = actual->siguiente; // Guardar el siguiente antes de liberar el actual
        free(actual); // Liberar la memoria del alumno actual
        actual = siguiente; // Moverse al siguiente
    }
}
