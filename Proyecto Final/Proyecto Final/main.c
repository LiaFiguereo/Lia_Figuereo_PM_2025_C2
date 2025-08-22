#include <stdio.h>
#include <stdlib.h>
#include "vehiculo.h" //Incluye funciones y definiciones de vehiculos
#include "costos.h" //Incluye funciones de calculo de costos

//Variables globales del sistema
//Son accesibles desde cualquier funcion de este archivo

Vehiculo vehiculos[MAX_VEHICULOS]; //Array que almacena todos los vehiculos
float costo_gasolina = 0.0; //Precio actual de gasolina por galon
float costo_gasoil = 0.0; //Precio actual de gasoil por galon

//CONSTANTES del sistema
#define ARCHIVO_DATOS "datos_vehiculos.bin" //Archivo de persistencia
#define NOMBRE_AGENCIA "Agencia de Vehiculos AutoSpot Figuereo"

//Funcion cargar_datos()
//Proposito: Lee datos guardados previamente desde archivo binario

void cargar_datos() {
FILE *file = fopen(ARCHIVO_DATOS, "rb"); //Abrimos en modo lectura binaria
if(file == NULL) { //Si no existe archivo previo, empezamos con datos vacios.
    printf("No se encontro archivo de datos. Iniciamos vacio.\n");
    return;
}

//Intenta leer los datos en secuencia: costos + array de vehiculos
//fread retorna numeros de elementos leidos exitosamente
if (fread(&costo_gasolina, sizeof(float), 1, file) != 1 ||
    fread(&costo_gasoil, sizeof(float), 1, file) != 1 ||
    fread(vehiculos, sizeof(Vehiculo), MAX_VEHICULOS, file) != MAX_VEHICULOS){
        printf("Error al leer datos del archivo.\n");
        fclose(file);
        return;
    }
fclose(file); //Cerramos el archivo
printf("Datos cargados exitosamente.\n");
}

//Funcion: guardar_datos()
//Proposito: Escribe todos los datos actuales al archivo binario

void guardar_datos(){
FILE *file = fopen(ARCHIVO_DATOS, "wb"); //Abrimos en modo escritura binaria
if (file == NULL) { //Si hay error al abrir
    printf("Error al guardar datos.\n");
    return;
}

//Escribe datos en el mismo orden que los lee cargar_datos()
if (fwrite(&costo_gasolina, sizeof(float), 1, file) != 1 ||
    fwrite(&costo_gasoil, sizeof(float), 1, file) != 1 ||
    fwrite(vehiculos, sizeof(Vehiculo), MAX_VEHICULOS, file) != MAX_VEHICULOS){
        printf("Error al escribir datos del archivo.\n");
        fclose(file);
        return;
    }
fclose(file); //Cerramos el archivo
printf("Datos guardados exitosamente.\n");
}

//Funcion principal: main()
//Proposito: punto de entrada del programa - controla el flujo principal
//Flujo: 1. Inicializa el sistema
//2. Carga datos previos
//3. Muesra interfaz de bienvenida
//4. Bucle principal del menu
//5. Guarda datos al salir.

int main() {
inicializar_vehiculos(vehiculos); //Inicializamos el array
cargar_datos(); //Intentamos cargar datos previos

//INTERFAZ DE BIENVENIDA
printf("=====================================\n");
printf("   Bienvenido a %s\n", NOMBRE_AGENCIA);
printf("   Sistema de Gestion de Vehículos\n");
printf("=====================================\n");

//VARIABLES para control del menu
int opcion; //Almacena la opcion seleccionada por el usuario
char c; //Para limpiar el buffer de entrada

//Bucle principal DO-WHILE
//Se ejecuta ala menos una vez
//Continua hasta que el usuario elija salir (opcion 7)
//Cada iteracion muestra menu y procesa una accion
do{
        //MOSTRAR MENU DE OPCIONES
        printf("\nMenu principal:\n");
        printf("1. Agregar vehiculo\n");
        printf("2. Modificar vehiculo\n");
        printf("3. Borrar vehiculo\n");
        printf("4. Listar vehiculos\n");
        printf("5. Ingresar costos de  combustible\n");
        printf("6. Calcular costo de viaje\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");

//Validacion de entrada
//scanf retorna 1 si lee exitosamente un entero
//Valida que este en rango valido (1-7)
//Si hay error, limpia buffer y pide de nuevo.
        while (scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 7) {
               printf("Entrada invalida (debe ser 1-7). Ingrese nuevamente: ");
               //Limpia caracteres invalidos del buffer de entrada
               while ((c = getchar()) != '\n' && c != EOF);
               }
               //Limpia buffer despues de entrada valida
         while ((c = getchar()) != '\n' && c != EOF);

        //SWITCH: Ejecuta accion segun opcion seleccionada
        //Cada case llama a la funcion correspondiente

        switch (opcion) { //Ejecutamos segun la opcion
        case 1:
            agregar_vehiculo(vehiculos); //Llamamos funcion para agregar
            break;
        case 2:
            modificar_vehiculo(vehiculos); //Llamamos funcion para modificar
            break;
        case 3:
            borrar_vehiculo(vehiculos); //Llamamos funcion para borrar
            break;
        case 4:
            listar_vehiculos(vehiculos); //Llamamos funcion para listar
            break;
        case 5:
            //Pasa direcciones de variables para modificarlas
            ingresar_costos_combustible(&costo_gasolina, &costo_gasoil); //Actualizamos costos
            break;
        case 6:
            calcular_costo_viaje(vehiculos, costo_gasolina, costo_gasoil); //Calculamos viaje
            break;
        case 7:
            guardar_datos(); //Persiste datos antes de salir
            printf("Saliendo...\n");
            break;
        }
    }while (opcion != 7); //Continuamos hasta que se elija 7/Condicion de salida del bucle

    return 0; //Codigo de salida exitosa para el sistema operativo
}
