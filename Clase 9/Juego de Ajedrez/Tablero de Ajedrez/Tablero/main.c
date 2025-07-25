#include <stdio.h> //Biblioteca para entrada/salida
#include <stdlib.h> //Biblioteca para funciones generales
#include <ctype.h> //Biblioteca para manejar caracteres como tolower e isupper
#include <windows.h> // Biblioteca para colores en la consola de Windows
#include <string.h> //Biblioteca para manejar cadenas
#include <stdbool.h> //Biblioteca para usar el tipo bool true/false
#include <math.h> //Biblioteca para funciones matematicas

//Declaracion de funciones a utilizar
int esCasillaValida(int fila, int col);
int caminoDespejado(char tablero[8][8], int fila_origen, int col_origen, int fila_destino, int col_destino);
int estaEnJaque(char tablero[8][8], bool esBlanca, int* fila_rey, int* col_rey);
int esJaqueMate(char tablero[8][8], bool esBlanca);
//Agregamos variable global para controlar los turnos del juego
bool turnoBlancas = true; //true = turno blancas, false = turno negras


// Función para establecer colores de texto y fondo
void setColor(int backgroundColor, int textColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, backgroundColor * 16 + textColor);
}

// Función para restablecer los colores a los predeterminados
void resetColor() {
    setColor(0, 7); // Fondo negro, texto blanco
}

// Función para limpiar la pantalla
void clearScreen() {
    system("cls"); //Ejecuta el comando "cls" en Windows para limpiar la pantalla
}

// Función que muestra el tablero con colores alternos para las casillas
void mostrarTablero(char tablero[8][8]) {
    // Colores para las casillas y piezas
    int colorBlanco = 15;  // Blanco brillante para las casillas blancas
    int colorNegro = 0;    // Negro para casillas negras
    int colorPiezaBlanca = 8; // Gris Oscuro para las piezas blancas
    int colorPiezaNegra = 12;  // Rojo para las piezas negras

    //Imprime las letras de las columnas (a-h)
    printf("   ");
    for (char c = 'a'; c <= 'h'; c++) {
        printf(" %c", c);
    }
    printf("\n");

    printf("  +-----------------+\n");

    for(int i = 0; i < 8; i++) //Imprime cada fila del tablero (8 a 1)
        {
        printf("%d |", 8 - i); //Numero de fila (8-1)
        for(int j = 0; j < 8; j++) {
            //Se elige el color del texto
            int textColor = (tablero[i][j] != '\0') ? (isupper(tablero[i][j]) ? colorPiezaBlanca : colorPiezaNegra) : ((i + j) % 2 == 0 ? colorBlanco : colorNegro);
            setColor((i + j) % 2 == 0 ? colorBlanco : colorNegro, textColor); // Alterna colores de fondo.
            printf(" %c", tablero[i][j] == '\0' ? ' ' : tablero[i][j]); // Imprime pieza o espacio.
            resetColor();
        }
        printf(" | %d\n", 8 - i);
    }
    printf("  +-----------------+\n");
    // Imprime letras de columnas nuevamente.
    printf("   ");
    for (char c = 'a'; c <= 'h'; c++) printf(" %c", c);
    printf("\n");
}

// Verifica si el movimiento de una pieza es valido segun las reglas del ajedrez.
int moverPieza(char tablero[8][8], int fila_origen, int col_origen, int fila_destino, int col_destino) {
    if (!tablero[fila_origen][col_origen]) return 0; //No hay pieza en la casilla inicial.
    char pieza = tolower(tablero[fila_origen][col_origen]); //Convierte la pieza a minuscula
    int df = abs(fila_destino - fila_origen); //Diferencia de filas
    int dc = abs(col_destino - col_origen); //Diferencia de columnas
    bool esBlanca = isupper(tablero[fila_origen][col_origen]); //True si la pieza es blanca (mayuscula)

    if (!esCasillaValida(fila_destino, col_destino)) return 0; //Casilla destino invalida
    if (tablero[fila_destino][col_destino] &&
    (isupper(tablero[fila_destino][col_destino]) == esBlanca)) {
    return 0; //No puede capturar pieza del mismo color.
}

    switch (pieza) {
        case 'p': //Peon
            if (col_origen == col_destino) { //Movimiento recto
                int dir = esBlanca ? -1 : 1; //Blancas suben (-1), negras bajan (+1)
                if (df == 1 && !tablero[fila_destino][col_destino]) return 1; //Avanza 1 casilla vacia.
                if (df == 2 && (fila_origen == (esBlanca ? 6 : 1)) && //Avanza 2 desde su posicion inicial.
                    !tablero[fila_origen + dir][col_origen] && !tablero[fila_destino][col_destino]) return 1;
            } else if (df == 1 && dc == 1) { //Captura diagonal
                return tablero[fila_destino][col_destino] != '\0';
            }
            break;
        case 't': //Torre
            if ((fila_origen == fila_destino || col_origen == col_destino) && //Horizonal o vertical
                caminoDespejado(tablero, fila_origen, col_origen, fila_destino, col_destino)) return 1;
            break;
        case 'c': //Caballo
            return (df == 2 && dc == 1) || (df == 1 && dc == 2); //Movimiento en L
        case 'a': //Alfil
            if (df == dc && caminoDespejado(tablero, fila_origen, col_origen, fila_destino, col_destino)) return 1; //Diagonal
            break;
        case 'q': //Reina
            if (((df == dc) || (fila_origen == fila_destino) || (col_origen == col_destino)) && //Diagonal, hroizontal o vertical.
                caminoDespejado(tablero, fila_origen, col_origen, fila_destino, col_destino)) return 1;
            break;
        case 'k': //Rey
            return df <= 1 && dc <= 1; //Maximo 1 casilla en cualquier direccion
    }
    return 0; //Movimiento no valido
}

// Convierte notacion algebraica (ej. "e2) a coordenadas en el tablero (fila, columna)
void notacionACoordenadas(char* movimiento, int* fila, int* col) {
    *col = tolower(movimiento[0]) - 'a';
    *fila = 8 - (movimiento[1] - '0');
}

//Agregamos funciones auxiliares
//Verifica si una casilla esta dentro del tablero (0-7 para fila y columnas)
int esCasillaValida(int fila, int col) {
return fila >= 0 && fila < 8 && col >= 0 && col < 8;  // Faltaba col >= 0
}
//Verifica si el camino entre dos casillas esta despejado para torre, alfil y reina.
int caminoDespejado(char tablero[8][8], int fila_origen, int col_origen, int fila_destino, int col_destino) {
    int df = fila_destino - fila_origen, dc = col_destino - col_origen; //Diferencias
    int pasos = fmax(abs(df), abs(dc)); //Numero de casillas a recorrer
    int paso_fila = df ? df / abs(df) : 0, paso_col = dc ? dc / abs(dc) : 0; //Direccion del movimiento
    for (int i = 1; i < pasos; i++) { //Revisa casillas intermedias
        if (tablero[fila_origen + i * paso_fila][col_origen + i * paso_col] != '\0') return 0;
    }
    return 1; //Camino libre
}
//Verifica si el rey de un color esta en jaque (si se ve amenazado por una pieza enemiga)
int estaEnJaque(char tablero[8][8], bool esBlanca, int* fila_rey, int* col_rey) {
    *fila_rey = -1; //Inicializa la posicion del rey como no encontrada
    *col_rey = -1;
    char rey = esBlanca ? 'K' : 'k'; //K para blancas y k para negras.
    //Busca el rey en el tablero
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (tablero[i][j] == rey) {
                *fila_rey = i;
                *col_rey = j;
                break;
            }
        }
        if (*fila_rey != -1) break; //Sale si encuentra el rey
    }
    if (*fila_rey == -1) return 0; //Si no hay rey, no esta en jaque.
//Revisa si alguna pieza enemiga puede atacar al rey.
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (tablero[i][j] != '\0' && isupper(tablero[i][j]) != esBlanca) { //Pieza enemiga.
                if (moverPieza(tablero, i, j, *fila_rey, *col_rey)) { //Puede atacar al rey.
                    return 1;
                }
            }
        }
    }
    return 0; //No esta en jaque.
}
//Verifica si es jaque mate
int esJaqueMate(char tablero[8][8], bool esBlanca) {
    int fila_rey, col_rey;
    if (!estaEnJaque(tablero, esBlanca, &fila_rey, &col_rey))
        return 0; //No esta en jaque.
// Prueba mover el rey a las 8 casillas vecinas.
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            if (di == 0 && dj == 0) continue; // Ignora la casilla actual.
            int nueva_fila = fila_rey + di;
            int nueva_col = col_rey + dj;
            if (esCasillaValida(nueva_fila, nueva_col) && // Casilla válida.
                (!tablero[nueva_fila][nueva_col] || isupper(tablero[nueva_fila][nueva_col]) != esBlanca)) { // Casilla vacía o con pieza enemiga.
                char temp = tablero[nueva_fila][nueva_col]; // Guarda la pieza destino.
                tablero[nueva_fila][nueva_col] = esBlanca ? 'K' : 'k'; // Mueve el rey.
                tablero[fila_rey][col_rey] = '\0'; // Libera la casilla original.
                int dummy_fila, dummy_col;
                int no_jaque = !estaEnJaque(tablero, esBlanca, &dummy_fila, &dummy_col); // Verifica si escapa del jaque.
                tablero[fila_rey][col_rey] = esBlanca ? 'K' : 'k'; // Restaura el rey.
                tablero[nueva_fila][nueva_col] = temp; // Restaura la casilla destino.
                if (no_jaque) return 0; // Puede escapar, no es jaque mate.
            }
        }
    }
    return 1; //No puede escapar, es jaque mate.
}
//Funcion principal que ejecuta el juego
int main() {
    char tablero[8][8]; //Matriz 8x8 para el tablero

    // Inicializar el tablero (blancas en mayúsculas, negras en minúsculas)
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(i == 6) tablero[i][j] = 'P'; // Peones blancos en fila 2
            else if(i == 1) tablero[i][j] = 'p'; // Peones negros en fila 7
            else if(i == 7) { // Piezas blancas en fila 1
                if(j == 0 || j == 7) tablero[i][j] = 'T'; //Torre
                else if(j == 1 || j == 6) tablero[i][j] = 'C'; //Caballo
                else if(j == 2 || j == 5) tablero[i][j] = 'A'; //Alfil
                else if(j == 3) tablero[i][j] = 'Q'; //Reina
                else if(j == 4) tablero[i][j] = 'K'; //Rey
            }
            else if(i == 0) { // Piezas negras en fila 8
                if(j == 0 || j == 7) tablero[i][j] = 't';
                else if(j == 1 || j == 6) tablero[i][j] = 'c';
                else if(j == 2 || j == 5) tablero[i][j] = 'a';
                else if(j == 3) tablero[i][j] = 'q';
                else if(j == 4) tablero[i][j] = 'k';
            }
            else {
                tablero[i][j] = '\0'; //Casillas vacias
            }
        }
    }

    // Mensaje de bienvenida al juegoo
    printf("¡Bienvenido al juego de ajedrez!\n");
    printf("Use notacion algebraica (ej. 'e2 e4') para mover piezas.\n");
    printf("Las Blancas (MAYUSCULAS) juegan primero. Escriba 'salir' para terminar.\n");
    system("pause"); //Pausa para que el usuario pueda leer

    // Bucle principal del juego
    char entrada[10]; //Almacena la entrada del usuario (ej. "e2 e4")
    while (1) {
        clearScreen();
        mostrarTablero(tablero); //Muestra el tablero actual
        //Muestra de quien es el turno
        printf("\nTurno de las %s (piezas %s)\n",
               turnoBlancas ? "blancas" : "negras",
               turnoBlancas ? "MAYUSCULAS" : "minusculas");

        printf("\nIngrese movimiento (ej. 'e2 e4') o 'salir' para terminar: ");
        fgets(entrada, sizeof(entrada), stdin); //Lee la entrada del usuario
        entrada[strcspn(entrada, "\n")] = '\0'; //Elimina el salto de linea

        if (strlen(entrada) == 0) { //Entrada vacia
            printf("Entrada vacía. Use 'e2 e4' o 'salir'.\n");
            system("pause");
            continue;
        }
        if (strncmp(entrada, "salir", 5) == 0) { //Termina el juego
            break;
        }
        //Verifica que la entrada tenga el formato correcto
        if (strlen(entrada) >= 5 &&
            (tolower(entrada[0]) < 'a' || tolower(entrada[0]) > 'h' ||
             entrada[1] < '1' || entrada[1] > '8' ||
             entrada[2] != ' ' ||
             tolower(entrada[3]) < 'a' || tolower(entrada[3]) > 'h' ||
             entrada[4] < '1' || entrada[4] > '8')) {
            printf("Formato incorrecto. Use 'e2 e4' (letras a-h, numeros 1-8).\n");
            system("pause");
            continue;
        }
        //Divide la entrada del juego en origen (ej. e2) y destino (ej. e4)
        char origen[3], destino[3];
        strncpy(origen, entrada, 2);
        origen[2] = '\0';
        strncpy(destino, entrada + 3, 2);
        destino[2] = '\0';

        //Convierte notacion a coordenadas
        int fila_origen, col_origen, fila_destino, col_destino;
        notacionACoordenadas(origen, &fila_origen, &col_origen);
        notacionACoordenadas(destino, &fila_destino, &col_destino);

        if (fila_origen == fila_destino && col_origen == col_destino) {
            printf("No te puedes mover a la misma casilla!\n");
            system("pause");
            continue;
        }

        char pieza = tablero[fila_origen][col_origen];
        if (pieza == '\0') {
            printf("No hay pieza en esa casilla!\n");
        } else if (isupper(pieza) && !turnoBlancas) {
            printf("Es turno de las NEGRAS (minusculas)!\n");
        } else if (!isupper(pieza) && turnoBlancas) {
            printf("Es turno de las BLANCAS (MAYUSCULAS)!\n");
        } else {
            if (moverPieza(tablero, fila_origen, col_origen, fila_destino, col_destino)) {
                //Simula el movimiento para verificar si es valido
                char temp = tablero[fila_destino][col_destino]; //Guarda la pieza destino
                tablero[fila_destino][col_destino] = tablero[fila_origen][col_origen];
                tablero[fila_origen][col_origen] = '\0';

                //Verifica si el movimiento deja al propio rey en jaque.
                int fila_rey, col_rey;
                if (estaEnJaque(tablero, turnoBlancas, &fila_rey, &col_rey)) {
                    printf("Movimiento invalido: deja al rey en jaque!\n");
                    tablero[fila_origen][col_origen] = tablero[fila_destino][col_destino];
                    tablero[fila_destino][col_destino] = temp; //Revierte el movimiento
                    system("pause");
                    continue;
                }

                 //Verifica si se capturo el rey enemigo indicando finalizacion del juego
                if (tolower(temp) == 'k'){
                    printf("El juego ha terminado, tu rey ha sido capturado! %s ganan.\n",
                           turnoBlancas ? "Negras" : "Blancas");
                           break;
                }

                //Maneja la promocion de peones (en la fila 1 o 8)
                if (tolower(tablero[fila_destino][col_destino]) == 'p' && (fila_destino == 0 || fila_destino == 7)) {
                    char promocion[10];
                  printf("Promocionar peon a (q/t/a/c): ");
                  fgets(promocion, sizeof(promocion), stdin);
                promocion[0] = tolower(promocion[0]);
                    if (promocion[0] == 'q' || promocion[0] == 't' || promocion[0] == 'a' || promocion[0] == 'c') {
                        tablero[fila_destino][col_destino] = isupper(tablero[fila_destino][col_destino]) ? toupper(promocion[0]) : promocion[0];
                    } else {
                        printf("Opcion invalida, se promociona a reina por defecto.\n");
                        tablero[fila_destino][col_destino] = isupper(tablero[fila_destino][col_destino]) ? 'Q' : 'q';
                    }
                }

                //Verifica si el movimiento causa jaque o jaque mate al enemigo.
                int dummy_fila, dummy_col;
                if (esJaqueMate(tablero, !turnoBlancas)) {
                    printf("¡Jaque mate! %s ganan.\n", turnoBlancas ? "Blancas" : "Negras");
                    break;
                } else if (estaEnJaque(tablero, !turnoBlancas, &dummy_fila, &dummy_col)) {
                    printf("¡Jaque!\n");
                }

                printf("Movimiento realizado: %s a %s\n", origen, destino);
                turnoBlancas = !turnoBlancas; //Cambia el turno
            } else {
                printf("Movimiento invalido segun reglas del ajedrez!\n");
            }
        }
        system("pause");
    }

    return 0; //Fin del programa
}
