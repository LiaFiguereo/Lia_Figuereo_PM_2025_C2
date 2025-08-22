#include "vehiculo.h" //Incluye definiciones de vehiculo.h
#include <string.h> //Para funciones de manejo de cadenas
#include <stdlib.h> //Para funciones estandar

//FUNCION: inicializar_vehiculos()
//Proposito: Prepara el array marcando todos los slots como vacios
//Recorre cada posicion y marca activo=0 (slot dispobible)

void inicializar_vehiculos(Vehiculo vehiculos[]){
    //BUCLE FOR: Itera por cada slot del array
for (int i= 0; i < MAX_VEHICULOS; i++){
        vehiculos[i].activo = 0; //0 = slot vacio, 1 = slot ocupado
        }
    }

//FUNCION: agregar_vehiculo()
//Proposito: Crea un vehiculo con validacion completa de datos
//1. Busca slot vacio
//2. Solicita cada campo con validacion
//3. Marca vehiculo como activo

void agregar_vehiculo(Vehiculo vehiculos[]){
//1. Buscar slot dispobible (activo == 0)
int index = -1; //-1 indica "no encontrado"
for (int i = 0; i <MAX_VEHICULOS; i++){
    if (vehiculos[i].activo == 0){ //Encontramos un slot vacio
        index = i;
        break; //Sale del bucle inmediatamente
    }
}

//Validar que hay espacio disponible
if (index == -1){ //Si no hay espacio
        printf("No hay espacio para mas vehiculos.\n");
        return; //Terminar funcion sin agregar
}

//2. Configurar puntero para facilitar el acceso
Vehiculo *v = &vehiculos[index]; //Puntero al vehiculo en el slot seleccionado

//Variables auxiliares para entrada de datos
char c; //Para limpiar buffer
char buffer[50]; //Buffer para entradas de cadena

//ENTRADA DE PLACA con validacion
//fgets lee linea completa incluyendo espacios
//strcspn encuentra posicion de '\n' y lo reemplaza con '\0'
//Valida que no este vacia
//strncpy copia de forma segura con limite

   printf("Ingrese la placa: ");
fgets(buffer, sizeof(buffer), stdin);
buffer[strcspn(buffer, "\n")] = 0; //Eliminamos el salto de linea
while (strlen(buffer) == 0) {  // Verifica que no esté vacía
    printf("Placa invalida (no puede estar vacia). Ingrese nuevamente: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
}
//Copia segura con limites de caracteres
strncpy(v->placa, buffer, sizeof(v->placa) - 1);
v->placa[sizeof(v->placa) - 1] = '\0'; //Asegura terminacion nula
while ((c = getchar()) != '\n' && c != EOF);  // Limpiamos buffer

//ENTRADA DE MARCA
printf("Ingrese la marca: ");
    fgets(buffer, sizeof(buffer), stdin);
buffer[strcspn(buffer, "\n")] = 0; //Eliminamos el salto de linea
while (strlen(buffer) == 0) {  // Verifica que no esté vacía
    printf("Marca invalida (no puede estar vacia). Ingrese nuevamente: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
}
strncpy(v->marca, buffer, sizeof(v->marca) - 1);
v->marca[sizeof(v->marca) - 1] = '\0'; //Asegura terminacion nula
while ((c = getchar()) != '\n' && c != EOF);  // Limpiamos buffer

    // ENTRADA DE MODELO
    printf("Ingrese el modelo: ");
    fgets(buffer, sizeof(buffer), stdin);
buffer[strcspn(buffer, "\n")] = 0; //Eliminamos el salto de linea
while (strlen(buffer) == 0) {  // Verifica que no esté vacía
    printf("Modelo invalido (no puede estar vacio). Ingrese nuevamente: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
}
strncpy(v->modelo, buffer, sizeof(v->modelo) - 1);
v->modelo[sizeof(v->modelo) - 1] = '\0'; //Asegura terminacion nula
while ((c = getchar()) != '\n' && c != EOF);  // Limpiamos buffer

    // ENTRADA DE TIPO DE COMBUSTBLE
    //Acepta solo 0 (gasolina) o 1 (gasoil)
    //Convierte a enum para mejor legibilidadd

    int tipo;
    printf("Tipo de Combustible (0 para Gasolina, 1 para Gasoil): ");
    while (scanf("%d", &tipo) != 1 || (tipo != 0 && tipo != 1)) {  // Validamos entrada numérica y rango
        printf("Tipo invalido. Ingrese 0 (Gasolina) o 1 (Gasoil): ");
        while ((c = getchar()) != '\n' && c != EOF);  // Limpiamos buffer
    }
    v->tipo_combustible = (tipo == 0) ? GASOLINA : GASOIL;  // Asignamos según input
    while ((c = getchar()) != '\n' && c != EOF);  // Limpiamos buffer final

    // Rendimiento en carretera
    printf("Km por galon en carretera: ");
    while (scanf("%f", &v->km_por_galon_carretera) != 1 || v->km_por_galon_carretera <= 0) {
        printf("Valor invalido (debe ser >0). Ingrese nuevamente: ");
        while ((c = getchar()) != '\n' && c != EOF);  // Limpiamos buffer
    }
    while ((c = getchar()) != '\n' && c != EOF);

    // Rendimiento en ciudad
    printf("Km por galon en ciudad: ");
    while (scanf("%f", &v->km_por_galon_ciudad) != 1 || v->km_por_galon_ciudad <= 0) {
        printf("Valor invalido (debe ser >0). Ingrese nuevamente: ");
        while ((c = getchar()) != '\n' && c != EOF);
    }
    while ((c = getchar()) != '\n' && c != EOF);

    // Costo de gomas
    printf("Costo de gomas: ");
    while (scanf("%f", &v->costo_gomas) != 1 || v->costo_gomas <= 0) {
        printf("Valor invalido (debe ser >0). Ingrese nuevamente: ");
        while ((c = getchar()) != '\n' && c != EOF);
    }
    while ((c = getchar()) != '\n' && c != EOF);

    // Km de vida útil de gomas
    printf("Km de vida util de gomas: ");
    while (scanf("%f", &v->km_vida_gomas) != 1 || v->km_vida_gomas <= 0) {
        printf("Valor invalido (debe ser >0). Ingrese nuevamente: ");
        while ((c = getchar()) != '\n' && c != EOF);
    }
    while ((c = getchar()) != '\n' && c != EOF);

    // Costo de seguro anual
    printf("Costo de seguro por 12 meses: ");
    while (scanf("%f", &v->costo_seguro_anual) != 1 || v->costo_seguro_anual <= 0) {
        printf("Valor invalido (debe ser >0). Ingrese nuevamente: ");
        while ((c = getchar()) != '\n' && c != EOF);
    }
    while ((c = getchar()) != '\n' && c != EOF);

    // Costo de mantenimiento
    printf("Costo de mantenimiento: ");
    while (scanf("%f", &v->costo_mantenimiento) != 1 || v->costo_mantenimiento <= 0) {
        printf("Valor invalido (debe ser >0). Ingrese nuevamente: ");
        while ((c = getchar()) != '\n' && c != EOF);
    }
    while ((c = getchar()) != '\n' && c != EOF);

    // Km cubiertos por mantenimiento
    printf("Km cubiertos por mantenimiento: ");
    while (scanf("%f", &v->km_cubiertos_mantenimientos) != 1 || v->km_cubiertos_mantenimientos <= 0) {
        printf("Valor invalido (debe ser >0). Ingrese nuevamente: ");
        while ((c = getchar()) != '\n' && c != EOF);
    }
    while ((c = getchar()) != '\n' && c != EOF);

    // Costo del vehículo
    printf("Costo del vehiculo: ");
    while (scanf("%f", &v->costo_vehiculo) != 1 || v->costo_vehiculo <= 0) {
        printf("Valor invalido (debe ser >0). Ingrese nuevamente: ");
        while ((c = getchar()) != '\n' && c != EOF);
    }
    while ((c = getchar()) != '\n' && c != EOF);

    // Vida útil estimada
    printf("Vida util estimada (años): ");
    while (scanf("%f", &v->vida_util_estimada) != 1 || v->vida_util_estimada <= 0) {
        printf("Valor invalido (debe ser >0). Ingrese nuevamente: ");
        while ((c = getchar()) != '\n' && c != EOF);
    }
    while ((c = getchar()) != '\n' && c != EOF);

    // Depreciación anual (puede ser 0)
    printf("Depreciacion anual: ");
    while (scanf("%f", &v->depreciacion_anual) != 1 || v->depreciacion_anual < 0) {
        printf("Valor invalido (debe ser >=0). Ingrese nuevamente: ");
        while ((c = getchar()) != '\n' && c != EOF);
    }
    while ((c = getchar()) != '\n' && c != EOF);

    // Promedio de km por año
    printf("Promedio de km por ano: ");
    while (scanf("%f", &v->promedio_km_por_ano) != 1 || v->promedio_km_por_ano <= 0) {
        printf("Valor invalido (debe ser >0). Ingrese nuevamente: ");
        while ((c = getchar()) != '\n' && c != EOF);
    }
    while ((c = getchar()) != '\n' && c != EOF);

    v->activo = 1;  //MARCA EL VEHICULO COMO ACTIVO
    printf("Vehiculo agregado exitosamente.\n");
}
    //FUNCION: listar_vehiculos()
    //Proposito: Muestra todos los vehiculos activos en forma de lista
    //1. Recorre el array
    //2. Muestra solo vehiculos con activo=1

void listar_vehiculos(Vehiculo vehiculos[]) {
    printf("Lista de vehiculos:\n");
    int count = 0;  // Contador para saber si hay vehículos

    //BUCLE FOR: examina cada slot del array
    for (int i = 0; i < MAX_VEHICULOS; i++) {
        if (vehiculos[i].activo) {  // Solo mostramos vehículos activos
            printf("[%d] Placa: %s, Marca: %s, Modelo: %s\n", i, vehiculos[i].placa, vehiculos[i].marca, vehiculos[i].modelo);
            count++;
    }
}
    //Manejo de lista vacia
    if (count == 0){ //Si no hay vehiculos
    printf("No hay vehiculos registrados.\n");

    }
}

//FUNCION: modificar_vehiculo()
//Proposito: Permite editar cualquier campo de un vehiculo existente
//1. Lista vehiculos dispobibles
//2. Selecciona vehiculo a modificar
//3. Para cada campo: Muestra valor actual y permite cambiarlo
//4. Conserva valores originales si usuario presiona Enter

void modificar_vehiculo(Vehiculo vehiculos[]) {
    //1. Mostrar opciones y seleccionar vehiculo
    listar_vehiculos(vehiculos);  // Mostramos la lista para que el usuario elija

    int index;
    char c; //para limpiar el buffer de entrada
    printf("Ingrese el numero del vehiculo a modificar: ");

    //Validacion completa del indice seleccionado:
    //scanf debe retornar 1 (lectura exitosa)
    //index debe estar en rango valido [0, MAX_VEHICULOS)
    //El vehiculo debe estar activo (no borrado)

    while (scanf("%d", &index) != 1 || index < 0 || index >= MAX_VEHICULOS || !vehiculos[index].activo){
        //Validacion de scanf e indice
        printf("Indice invalido. Ingrese nuevamente: ");
        while ((c = getchar()) != '\n' && c != EOF); //Limpia buffer en caso de error
    }
      while ((c = getchar()) != '\n' && c != EOF); //Limpia buffer despues de entrada valida

      //2. Configurar puntero para facilitar acceso al vehiculo
    Vehiculo *v = &vehiculos[index];  // Puntero al vehículo seleccionado
    char buffer[50];  // Buffer temporal para entradas de cadena

      // MODIFICACION DE PLACA
      //Muestra el valor actual
      //Si el usuario ingresa texto, lo actualiza
      //Si solo presiona enter, mantiene el valor original

    printf("Placa actual: %s. Nueva (Enter para mantener): ", v->placa);
    fgets(buffer, sizeof(buffer), stdin); //Lee linea completa
    buffer[strcspn(buffer, "\n")] = 0; //Elimina el salto de linea
    if (strlen(buffer) > 0) { //Solo actualiza ssi hay contenido
        strncpy(v->placa, buffer, sizeof(v->placa) - 1); //Copia segura
        v->placa[sizeof(v->placa) - 1] = '\0'; //Asegura terminacion
    }

    //MODIFICACION DE MARCA
    //Sigue el mismo patron
    printf("Marca actual: %s. Nueva (Enter para mantener): ", v->marca);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    if (strlen(buffer) > 0) {
        strncpy(v->marca, buffer, sizeof(v->marca) -1);
        v->marca[sizeof(v->marca) -1] = '\0';
    }

    //MODIFICACION DE MODELO
    printf("Modelo actual: %s. Nuevo (Enter para mantener): ", v->modelo);
     fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    if (strlen(buffer) > 0) {
        strncpy(v->modelo, buffer, sizeof(v->modelo) -1);
        v->modelo[sizeof(v->modelo) -1] = '\0';
    }

     //MODIFICACION DE TIPO DE COMBUSTIBLE
     //Muestra el valor actual traducido a textxo legible
     //Acepta 0 (gasolina), 1 (gasoil), o -1 (mantener)

    int tipo;
    printf("Tipo de combustible actual: %s. Nuevo (0 para Gasolina, 1 para Gasoil, -1 para mantener): ",
           v->tipo_combustible == GASOLINA ? "Gasolina" : "Gasoil");
    while (scanf("%d", &tipo) != 1 || (tipo != 0 && tipo != 1 && tipo != -1)) {
        printf("Entrada invalida. Ingrese nuevamente: ");
        while ((c = getchar()) != '\n' && c != EOF);
    }
    while ((c = getchar()) != '\n' && c != EOF); //Limpieza del buffer
    if (tipo == 0 || tipo == 1){ //Solo actualiza si no es -1 (mantener)
        v->tipo_combustible = (tipo == 0) ? GASOLINA : GASOIL;
    }

    //PATRON PARA MODIFICACION DE VALORES NUMERICOS
    //1. Muestra valor actual con formato %.2f
    //2. Solicita nuevo valor (0 significa mantener)
    //3. Valida que sea numero > 0
    //4. Solo actualiza si el valor ingresado es > 0

    //MODIFICACION: Km por galon en carretera
    float temp; //Variable temporal para nuevos valores
    printf("Km por galon carretera actual: %.2f. Nuevo (0 para mantener): ", v->km_por_galon_carretera);
   while (scanf("%f", &temp) != 1 || temp < 0)  {
            printf("Entrada invalida (debe ser >= 0). Ingrese nuevamente: ");
            while ((c = getchar()) != '\n' && c != EOF);
    }
    while ((c = getchar()) != '\n' && c != EOF);
    if (temp > 0){ //0 significa mantener valor actual
        v->km_por_galon_carretera = temp;
    }

    //MODIFICACION: km por galón en ciudad
    printf("Km por galon ciudad actual: %.2f. Nuevo (0 para mantener): ", v->km_por_galon_ciudad);
   while (scanf("%f", &temp) != 1 || temp < 0)  {
           printf("Entrada invalida (debe ser >= 0). Ingrese nuevamente: ");
            while ((c = getchar()) != '\n' && c != EOF);
    }
     while ((c = getchar()) != '\n' && c != EOF);
     if (temp > 0){
        v->km_por_galon_ciudad = temp;
     }


    // MODIFICACION: costo de gomas
    printf("Costo de gomas actual: %.2f. Nuevo (0 para mantener): ", v->costo_gomas);
    while (scanf("%f", &temp) != 1 || temp < 0) {
            printf("Entrada invalida (debe ser >= 0). Ingrese nuevamente: ");
            while ((c = getchar()) != '\n' && c != EOF);
    }
     while ((c = getchar()) != '\n' && c != EOF);
     if (temp > 0){
        v->costo_gomas = temp;
     }


    //MODIFICACION: km de vida útil de gomas
    printf("Km de vida util de gomas actual: %.2f. Nuevo (0 para mantener): ", v->km_vida_gomas);
    while (scanf("%f", &temp) != 1 || temp < 0) {
            printf("Entrada invalida (debe ser >= 0). Ingrese nuevamente: ");
            while ((c = getchar()) != '\n' && c != EOF);
    }
     while ((c = getchar()) != '\n' && c != EOF);
     if (temp > 0){
        v->km_vida_gomas = temp;
     }

    //MODIFICACION: costo de seguro anual
    printf("Costo de seguro anual actual: %.2f. Nuevo (0 para mantener): ", v->costo_seguro_anual);
    while (scanf("%f", &temp) != 1 || temp < 0) {
       printf("Entrada invalida (debe ser >= 0). Ingrese nuevamente: ");
            while ((c = getchar()) != '\n' && c != EOF);
    }
     while ((c = getchar()) != '\n' && c != EOF);
     if (temp > 0){
        v->costo_seguro_anual = temp;
     }

    //MODIFICACION: costo de mantenimiento
    printf("Costo de mantenimiento actual: %.2f. Nuevo (0 para mantener): ", v->costo_mantenimiento);
    while (scanf("%f", &temp) != 1 || temp < 0) {
             printf("Entrada invalida (debe ser >= 0). Ingrese nuevamente: ");
            while ((c = getchar()) != '\n' && c != EOF);
    }
     while ((c = getchar()) != '\n' && c != EOF);
     if (temp > 0){
        v->costo_mantenimiento = temp;
     }


    //MODIFICACION: km cubiertos por mantenimiento
    printf("Km cubiertos por mantenimiento actual: %.2f. Nuevo (0 para mantener): ", v->km_cubiertos_mantenimientos);
    while (scanf("%f", &temp) != 1 || temp < 0) {
            printf("Entrada invalida (debe ser >= 0). Ingrese nuevamente: ");
            while ((c = getchar()) != '\n' && c != EOF);
    }
     while ((c = getchar()) != '\n' && c != EOF);
     if (temp > 0){
        v->km_cubiertos_mantenimientos = temp;
     }


    //MODIFICACION: costo del vehículo
    printf("Costo del vehiculo actual: %.2f. Nuevo (0 para mantener): ", v->costo_vehiculo);
    while (scanf("%f", &temp) != 1 || temp < 0) {
           printf("Entrada invalida (debe ser >= 0). Ingrese nuevamente: ");
            while ((c = getchar()) != '\n' && c != EOF);
    }
     while ((c = getchar()) != '\n' && c != EOF);
     if (temp > 0){
        v->costo_vehiculo = temp;
     }

    //MODIFICACION: vida útil estimada
    printf("Vida util estimada actual (años): %.2f. Nuevo (0 para mantener): ", v->vida_util_estimada);
     while (scanf("%f", &temp) != 1 || temp < 0) {
            printf("Entrada invalida (debe ser >= 0). Ingrese nuevamente: ");
            while ((c = getchar()) != '\n' && c != EOF);
    }
     while ((c = getchar()) != '\n' && c != EOF);
     if (temp > 0){
        v->vida_util_estimada = temp;
     }


    //MODIFICACION ESPECIAL: depreciacion anual
    //Este campo puede ser 0 (sin depreciacion)
    //Por eso se usa mayor o igual a 0 en lugar de > 0 para aceptar el cambio

    printf("Depreciacion anual actual: %.2f. Nuevo (0 para mantener): ", v->depreciacion_anual);
    while (scanf("%f", &temp) != 1 || temp < 0) {
    printf("Entrada invalida (debe ser >= 0). Ingrese nuevamente: ");
    while ((c = getchar()) != '\n' && c != EOF);
}
     while ((c = getchar()) != '\n' && c != EOF);
     if (temp >= 0){ //Acepta 0 como valor valido para depreciacion
        v->depreciacion_anual = temp;
     }


    //MODIFICACION: promedio de km por año
    printf("Promedio de km por ano actual: %.2f. Nuevo (0 para mantener): ", v->promedio_km_por_ano);
    while (scanf("%f", &temp) != 1 || temp < 0) {
            printf("Entrada invalida (debe ser >= 0). Ingrese nuevamente: ");
            while ((c = getchar()) != '\n' && c != EOF);
    }
     while ((c = getchar()) != '\n' && c != EOF);
     if (temp > 0){
        v->promedio_km_por_ano = temp;
     }

    printf("Vehiculo modificado.\n"); //Confirmacion de modificacion exitosa

    }

    //FUNCION: borrar_vehiculo()
    //Proposito: Elimina logicamente un vehiculo del sistema
    //Utiliza borrado logico - marca activo=0 en lugar de eliminar fisicamente
    //1. Lista vehiculos disponibles
    //2. Usuario selecciona cual borrar
    //3. Valida seleccion
    //4. Marca como inactivo

    void borrar_vehiculo(Vehiculo vehiculos[]){
        //1. Mostrar opciones disponibles
        listar_vehiculos(vehiculos); //Muestra solo vehiculos activos

        //Variables para entrada y validacion
        int index;
        char c;

        printf("Ingrese el numero del vehiculo a borrar: ");

        //Validacion completa del indice a borrar:
        //Condiciones a cumplir:
        //scanf retorna 1 (lectura numerica exitosa)
        //index >= 0 (no negativo)
        //index < MAX_VEHICULOS (dentro del array)
        //vehiculos[index].activo = 1 (vehiculo existe y esta activo)
        //Si alguna condicion falla, pide entrada nuevamente

        while (scanf("%d", &index) != 1 || index < 0 || index >=
        MAX_VEHICULOS || !vehiculos[index].activo) {
            printf("Indice invalido. Ingrese nuevamente: ");
            while ((c = getchar()) != '\n' && c != EOF); //Limpia buffer
        }
        while ((c = getchar()) != '\n' && c != EOF); //Limpia buffer final

        //Borrado logico: En lugar de eliminar fisicamente el vehiculo del array,
        //simplemente marcamos activo = 0
        //Esto significa que el vehiculo sigue en memoria pero es invisible al usuario
        //listar_vehiculos() lo ignora porque activo=0
        //Su slot puede ser reutilizado por agregar_vehiculo()
        //Los indices de otros vehiculos no cambian

        vehiculos[index].activo = 0; //Marcamos como inactivo
        printf("Vehiculo borrado.\n"); //Confirmacion al usuario

    }
