#ifndef VEHICULO_H_INCLUDED
#define VEHICULO_H_INCLUDED
#include <stdio.h> //para printf y scanf

//Constante global: Define el limite maximo de vehiculos que puede manejar el sistema
#define MAX_VEHICULOS 10

//ENUMERACION para tipos de combustible
//Un enum asigna valores enteros automaticamente (GASOLINA=0, GASOIL=1)

typedef enum {
GASOLINA, // Valor 0 - Representa combustible gasolina
GASOIL // Valor 1 - Representa combustible gasolina
} TipodeCombustible;

//Estructura (struct) que define todos los datos de un vehiculo
//Una struct agrupa varias variables relacionadas en un solo ''objeto'' / unidad logica

typedef struct {
char placa [20]; //Placa del vehiculo (cadena, max 20 caracteres)
char marca[50]; //Marca del vehiculo (cadena, max 50 caracteres)
char modelo [50]; //Modelo del vehiculo (cadena, max 50 caracteres)
TipodeCombustible tipo_combustible; //Tipo de combustible (GASOLINA O GASOIL, enum)

//EFICIENCIA DE COMBUSTIBLE
float km_por_galon_carretera; //Rendimiento en autopistas/carreteras
float km_por_galon_ciudad; //Rendimiento en trafico urbano

//COSTOS DE GOMA
float costo_gomas; //Precio de un juego completo de gomas
float km_vida_gomas; //Kilometros que duran las gomas

//COSTOS ANUALES
float costo_seguro_anual; //Prima de seguro por 12 meses
float promedio_km_por_ano; //Kilometros promedio recorridos al ano

//COSTO DE MANTENIMIENTO
float costo_mantenimiento; //Costo de un servicio de mantenimiento
float km_cubiertos_mantenimientos; //Kilometros entre mantenimientos

//DEPRECIACION DEL VEHICULO
float costo_vehiculo; //Valor original/actual del vehiculo
float vida_util_estimada; //Vida util estimada en anos
float depreciacion_anual; //Perdida de valor por ano

//CONTROL DE ESTADO
int activo; //1= vehiculo activo, 0= borrado
} Vehiculo;

//PROTOTIPOS DE FUNCIONES (Declaraciones - implementadas en vehiculo.c)
//Estas funciones se implementan en vehiculo.c
void inicializar_vehiculos(Vehiculo vehiculos[]); //Inicializar el array de vehiculos vacio
void agregar_vehiculo(Vehiculo vehiculos[]); //Agrega un nuevo vehiculo
void listar_vehiculos(Vehiculo vehiculos[]); //Muestra la lista de vehiculos activos
void modificar_vehiculo(Vehiculo vehicuclos[]); //Modifica un vehiculo existente
void borrar_vehiculo(Vehiculo vehiculos[]); //Marca un vehiculo como inactivo


#endif // VEHICULO_H_INCLUDED
