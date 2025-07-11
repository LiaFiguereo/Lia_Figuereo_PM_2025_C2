#include <stdio.h>
#include <stdlib.h>
#define SALIR 0
#define SUMAR 1
#define MULTIPLICAR 2
#define DIVIDIR 3
#define RESTAR 4
#define ERR_OK 0
#define ERR_DbyZ 1

int sumar(float n1,float n2,float *result);//prototipo o declaracion de la funcion
int restar (float n1, float n2, float *result);
int multiplicar (float n1, float n2, float *result);
int dividir(float numerador,float denominador,float *result);

    //& - operador de direccion
    //* - Operador de in-direccion
int main(void)
{
    float resultado = 0.0;
    float numero1 = 0.0;
    float numero2 = 0.0;
    int menu = SALIR;
    int Err_Cod = ERR_OK;
    printf("CALCULADORA\n");

    do
    {
        printf("\n0-Salir\n1-Sumar\n2-Multiplicar\n3-Dividir\n4-Restar\n");
        scanf("%i",&menu);
        if(menu >= 0 && menu <= 4)
        {
            if(menu == SUMAR)
            {
                printf("\nIngrese el numero1:");
                scanf("%f",&numero1);
                printf("\nIngrese el numero2:");
                scanf("%f",&numero2);
                Err_Cod = sumar(numero1,numero2,&resultado);
                printf("La suma de %f y %f es:%f",numero1,numero2,resultado);
            }

            if(menu == DIVIDIR)
            {
                printf("\nIngrese el numerador:");
                scanf("%f",&numero1);
                printf("\nIngrese el denominador:");
                scanf("%f",&numero2);
                Err_Cod = dividir(numero1,numero2,&resultado);
                if(Err_Cod != ERR_OK)
                {
                   if(Err_Cod == ERR_DbyZ)
                   {
                       printf("\nError divicion por zero");
                   }else
                   {
                       printf("\nError desconocido");
                   }
                }else
                {
                    printf("\nLa divicion entre %f y %f es:%f",numero1, numero2,resultado);
                }
            }
            if (menu == MULTIPLICAR)
            {
                 printf("\nIngrese el numero1:");
                scanf("%f",&numero1);
                printf("\nIngrese el numero2:");
                scanf("%f",&numero2);
                Err_Cod = multiplicar (numero1,numero2,&resultado);
                if(Err_Cod != ERR_OK)
                {
                    printf("\nLa multiplicacion de %f y %f es:%f", numero1, numero2, resultado);
                }
                else
                {
                       printf("\nError desconocido");

                }
            {


            }
            if (menu == RESTAR)
            {
                printf("\nIngrese minuendo:");
                scanf("%f",&numero1);
                printf("\nIngrese sustraendo:");
                scanf("%f",&numero2);
                Err_Cod = restar(numero1,numero2,&resultado);

                if(Err_Cod == ERR_OK)
                {
                    printf("\nLa resta de %f a %f es:%f", numero2,numero1,resultado);
                }else
                {
                    printf("\nError desconocido:%i",Err_Cod);
                }
            }
        }
    }
    while(menu != SALIR);

    return 0;
}

int sumar(float n1,float n2,float *result)
{
    *result = n1 + n2;//uso operador de in direccion
    return ERR_OK;
}

int multiplicar(float n1,float n2,float *result)
{
    *result = n1 * n2;
    return ERR_OK;
}

int dividir(float numerador,float denominador,float *result)
{
    if(denominador == 0)
    {
       return ERR_DbyZ;
    }else
    {
        *result = numerador / denominador;
        return ERR_OK;
    }
}
    int restar(float n1, float n2, float *result)
{
     *result = n1 - n2;
    return ERR_OK;
}
