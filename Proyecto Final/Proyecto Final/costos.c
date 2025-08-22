#include "costos.h"
#include <stdio.h>

//FUNCION: ingresar_costos_combustible()
//Proposito: Actualiza precios actuales de combustible con validacion
//Parametros: Punteros a variables globales para modificarlas directamente
//Solicita y valida cada precio y actualiza las variables referenciadas

void ingresar_costos_combustible(float *costo_gasolina, float *costo_gasoil) {
    char c; //Para limpiar buffer

//ENTRADA DE COSTO DE GASOLINA
printf("Ingrese costo de gasolina por galon: ");
//Validacion: debe ser numero valido y mayor que 0.
while (scanf("%f", costo_gasolina) != 1 || *costo_gasolina <= 0) {
    printf("Valor invalido (debe ser >0). Ingrese nuevamente: ");
    while ((c = getchar()) != '\n' && c != EOF); //Limpia buffer
}
while ((c = getchar()) != '\n' && c != EOF); //Limpia buffer final

//ENTRADA DE COSTO DE GASOIL
printf("Ingrese costo de gasoil por galon: ");
while (scanf("%f", costo_gasoil) != 1 || *costo_gasoil <= 0) {
    printf("Valor invalido (debe ser >0). Ingrese nuevamente: ");
    while ((c = getchar()) != '\n' && c != EOF);
}

while ((c = getchar()) != '\n' && c != EOF);

printf("Costos actualizados.\n");

}

//FUNCION: calcular_costo_viaje()
//Proposito: Calcula costo total de un viaje desglosado por componentes
//Parametros: Array de vehiculos y precios actuales de combustible
//1. Selecciona un vehiculo
//2. Obtiene datos del viaje
//3. Calcula cada componente de costo
//4. Muestra desglose detallado

void calcular_costo_viaje(Vehiculo vehiculos[], float costo_gasolina, float costo_gasoil){
    //1. Seleccion de vehiculo
listar_vehiculos(vehiculos); //Mostramos vehiculos disponibles

int index;
char c;
printf("Seleccione el numero del vehiculo: ");
//Validacion completa: numero valido, en rango y vehiculo activo.
while (scanf("%d", &index) !=  1 || index < 0 || index >= MAX_VEHICULOS || !vehiculos[index].activo){ //Validamos el indice
   printf("Indice invalido. Ingrese nuevamente: " );
   while ((c = getchar()) != '\n' && c != EOF);
}
while ((c = getchar()) != '\n' && c != EOF);

//Copia el vehiculo seleccionado para trabajar localmente
Vehiculo v = vehiculos[index];

//2. Obtener datos del viaje
float km_total;
printf("Ingrese los km totales del viaje: ");
while (scanf("%f", &km_total) != 1 || km_total <= 0){ //Validamos positivo
    printf("Valor invalido (debe ser >0). Ingrese nuevamente: ");
    while ((c = getchar()) != '\n' && c != EOF);
}
while ((c = getchar()) != '\n' && c != EOF);

//Pedimos porcentaje en ciudad
float porcentaje_ciudad;
printf("Ingrese el porcentaje de km en ciudad (0-100): ");
while (scanf("%f", &porcentaje_ciudad) != 1 || porcentaje_ciudad < 0 || porcentaje_ciudad > 100){ //Validamos rango
    printf("Valor invalido (0-100). Ingrese nuevamente: ");
    while ((c = getchar()) != '\n' && c != EOF);
}
while ((c = getchar()) != '\n' && c != EOF);

//3. Calculos preparatorios
float porcentaje_carretera = 100 - porcentaje_ciudad; //Calculamos porcentaje en carretera
float km_ciudad = km_total * (porcentaje_ciudad / 100); //Calculamos km en ciudad
float km_carretera = km_total * (porcentaje_carretera / 100);//Calculamos km en carretera

//CALCULO DE COSTO DE COMBUSTIBLE
//1. Selecciona el precio segun tipo de combustible
//2. Calcula galones necesarios para ciudad y carretera por separado
//3. Suma galones totales y multiplica por precio

float costo_combustible_por_galon = (v.tipo_combustible == GASOLINA) ? costo_gasolina : costo_gasoil;
float galones_ciudad = km_ciudad / v.km_por_galon_ciudad;
float galones_carretera = km_carretera / v.km_por_galon_carretera;
float galones_total = galones_ciudad + galones_carretera;
float costo_combustible = galones_total * costo_combustible_por_galon;

//CALCULOS DE COSTOS POR KILOMETRO
//Cada componente se calcula como: (costo toal/km_cobertura) * km_viaje

//Costo de gomas: desgaste proporcional
float costo_gomas_por_km = v.costo_gomas / v.km_vida_gomas;
float costo_gomas_total = costo_gomas_por_km * km_total;

//Costo de seguro: prorrateo anual
float costo_seguro_por_km = v.costo_seguro_anual / v.promedio_km_por_ano;
float costo_seguro_total = costo_seguro_por_km * km_total;

//Costo de mantenimiento: segun intervalos
float costo_mantenimiento_por_km = v.costo_mantenimiento / v.km_cubiertos_mantenimientos;
float costo_mantenimiento_total = costo_mantenimiento_por_km * km_total;

//Costo de depreciacion: desgaste del vehiculo
float costo_depreciacion_por_km = v.depreciacion_anual / v.promedio_km_por_ano;
float costo_vehiculo_total = costo_depreciacion_por_km * km_total;

//4. Totales y presentacion de resultados
float costo_total = costo_combustible + costo_gomas_total + costo_seguro_total
+ costo_mantenimiento_total + costo_vehiculo_total;
float costo_por_km = (km_total > 0) ? costo_total / km_total : 0; //Evitamos division por 0

//DESGLOSE DETALLADO DE COSTOS
printf("\nDesglose de costos para el viaje: \n");
printf("Costo de combustible: %.2f\n", costo_combustible); //El %.2f muestra 2 decimales
printf("Costo de gomas: %.2f\n", costo_gomas_total);
printf("Costo de seguro: %.2f\n", costo_seguro_total);
printf("Costo de mantenimiento: %.2f\n", costo_mantenimiento_total);
printf("Costo del vehiculo (depreciacion): %.2f\n", costo_vehiculo_total);
printf("Costo total del viaje: %.2f\n", costo_total);
printf("Costo por kilometro: %.2f\n", costo_por_km);
}
