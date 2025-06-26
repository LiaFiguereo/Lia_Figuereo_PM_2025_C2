#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char p1;

    // Primer an�lisis: �Es un d�gito?
    printf("\nIngrese un caracter para analizar si �ste es un d�gito: ");
    p1 = getchar();

    if (isdigit(p1))
        printf("%c es un d�gito\n", p1);
    else
        printf("%c no es un d�gito\n", p1);

    while (getchar() != '\n'); // Limpiar b�fer

    // Segundo an�lisis: �Es una letra?
    printf("\nIngrese un caracter para examinar si �ste es una letra: ");
    p1 = getchar();

    if (isalpha(p1))
        printf("%c es una letra\n", p1);
    else
        printf("%c no es una letra\n", p1);

    while (getchar() != '\n'); // Limpiar b�fer

    // Tercer an�lisis: �Es letra min�scula?
    printf("\nIngrese un caracter para examinar si �ste es una letra min�scula: ");
    p1 = getchar();

    if (isalpha(p1))
    {
        if (islower(p1))
            printf("%c es una letra min�scula\n", p1);
        else
            printf("%c no es una letra min�scula\n", p1);
    }
    else
    {
        printf("%c no es una letra\n", p1);
    }

    while (getchar() != '\n'); // Limpiar b�fer

    // Cuarto an�lisis: conversi�n a min�scula
    printf("\nIngrese una letra para convertirla de may�scula a min�scula: ");
    p1 = getchar();

    if (isalpha(p1))
    {
        if (isupper(p1))
            printf("%c fue convertida de may�scula a min�scula\n", tolower(p1));
        else
            printf("%c es una letra min�scula\n", p1);
    }
    else
    {
        printf("%c no es una letra\n", p1);
    }

    return 0;
}
