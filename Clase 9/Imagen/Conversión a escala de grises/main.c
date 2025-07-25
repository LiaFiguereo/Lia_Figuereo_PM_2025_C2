#include <stdio.h>
#include <stdlib.h>

//Definimos las librerias stb
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h" //libreria para cargar imagenes
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h" //Liberia para guardar imagenes

int main() {
    int width, height, channels; //estas variables almacenan las dimensiones de la imagen y el numero de canales de color

    // Cargamos la iamgen desde un archivo
    //stbi_load carga la imagen desde el disco y devuelve un puntero a su contenido en memoria
    unsigned char *img = stbi_load("input.jpg", &width, &height, &channels, 0);

   //Verificamos si la imagen cargo correctamente
    if (img == NULL) {
        printf("Error al cargar la imagen. Razón: %s\n", stbi_failure_reason());
        return 1;
    }
    //Muestra info sobre la imagen cargada
    printf("Imagen cargada. Dimensiones: %dx%d, Canales: %d\n", width, height, channels);

    // Se reserva memoria para almacenar la imagen convertida a grises
    unsigned char *gray_img = (unsigned char*)malloc(width * height);

    //Verificamos si la memoria fue asignada correctamente
    if (gray_img == NULL) {
        printf("Error al reservar memoria.\n");

        //Liberamos la memoria previamente asignada por stbi_load
        stbi_image_free(img);
        return 1;
    }

    // Convertimos la imagen de color a escala de grises
    //Usamos dos bucles for anidados para recorrer cada pixel de la img original
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            // Calculamos el índice del píxel actual en la imagen original (img)
            // Cada píxel tiene 'channels' bytes (R, G, B)
            int idx = (y * width + x) * channels;

        //Accedemos a cada componente del color
        //img es un puntero a unsigned char, cada componente es un byte de 0 a 255
            unsigned char r = img[idx];
            unsigned char g = img[idx + 1];
            unsigned char b = img[idx + 2];

            //Se calcula el valor en escala de grises aplicando la formula de luminancia
            //Esto simula como el ojo humano percibe el brillo
            gray_img[y * width + x] = (unsigned char)(0.299f * r + 0.587f * g + 0.114f * b);
        }
    }

    // Guardamos la imagen nueva a disco
    const char *output_path = "output_gray.jpg";  // Se guardará en la misma carpeta que el programa

    //1: numero de canales (1 = escala de grises) y el 90 es la calidad de compresion JPG 0-100
    if (!stbi_write_jpg(output_path, width, height, 1, gray_img, 90))

    {
        printf("Error al guardar. Razón: %s\n", stbi_failure_reason());
    } else {
        printf("¡Imagen guardada como '%s'!\n", output_path);
    }

    // Liberamos la memoria
    stbi_image_free(img); //libera la img original cargada con stbi_load
    free(gray_img); //libera la img en grises creada con malloc
    return 0;
}
