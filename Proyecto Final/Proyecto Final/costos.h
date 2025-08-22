#ifndef COSTOS_H_INCLUDED
#define COSTOS_H_INCLUDED
#include "vehiculo.h" // Utilizamos Vehiculo para los calculos

//PROTOTIPOS para funciones de calculo de costos
void ingresar_costos_combustible(float *costo_gasolina, float *costo_gasoil); //Ingresa costos de combustible
void calcular_costo_viaje(Vehiculo vehiculos[], float costo_gasolina, float costo_gasoil); //Calcula costo de viaje

#endif // COSTOS_H_INCLUDED
