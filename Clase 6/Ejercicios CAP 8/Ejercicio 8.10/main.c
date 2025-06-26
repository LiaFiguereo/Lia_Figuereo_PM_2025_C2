##include <stdio.h>
#include <string.h>

/* Vendedores de art�culos dom�sticos en Ciudad de M�xico */

typedef struct {
    char noba[11];  // Nombre del banco (+1 para el '\0')
    char nucu[11];  // N�mero de cuenta
} banco;

typedef union {
    banco che;   // Cheque
    banco nomi;  // N�mina
    char venta;  // Ventanilla
} fpago;

typedef struct {
    char cnu[21];  // Calle y n�mero
    char col[21];  // Colonia
    char cp[6];    // C�digo Postal
    char ciu[16];  // Ciudad
} domicilio;

typedef struct {
    int num;           // N�mero de vendedor
    char nom[21];      // Nombre
    float ven[12];     // Ventas del a�o
    domicilio domi;    // Domicilio
    float sal;         // Salario
    fpago pago;        // Forma de pago
    int cla;           // Clave forma de pago (1, 2, 3)
} vendedor;

void Lectura(vendedor *, int);
void F1(vendedor *, int);
void F2(vendedor *, int);
void F3(vendedor *, int);
void F4(vendedor *, int);

int main(void) {
    vendedor VENDEDORES[100];
    int TAM;

    do {
        printf("Ingrese el n�mero de vendedores: ");
        scanf("%d", &TAM);
    } while (TAM > 100 || TAM < 1);

    Lectura(VENDEDORES, TAM);
    F1(VENDEDORES, TAM);
    F2(VENDEDORES, TAM);
    F3(VENDEDORES, TAM);
    F4(VENDEDORES, TAM);

    printf("\n\tFIN DEL PROGRAMA\n");
    return 0;
}

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void Lectura(vendedor A[], int T) {
    int I, J;
    for (I = 0; I < T; I++) {
        printf("\n\tIngrese datos del vendedor %d\n", I + 1);

        printf("N�mero de vendedor: ");
        scanf("%d", &A[I].num);
        limpiarBuffer();

        printf("Nombre del vendedor: ");
        fgets(A[I].nom, sizeof(A[I].nom), stdin);
        A[I].nom[strcspn(A[I].nom, "\n")] = '\0';

        printf("Ventas del a�o:\n");
        for (J = 0; J < 12; J++) {
            printf("\tMes %d: ", J + 1);
            scanf("%f", &A[I].ven[J]);
        }
        limpiarBuffer();

        printf("Domicilio del vendedor:\n");

        printf("\tCalle y n�mero: ");
        fgets(A[I].domi.cnu, sizeof(A[I].domi.cnu), stdin);
        A[I].domi.cnu[strcspn(A[I].domi.cnu, "\n")] = '\0';

        printf("\tColonia: ");
        fgets(A[I].domi.col, sizeof(A[I].domi.col), stdin);
        A[I].domi.col[strcspn(A[I].domi.col, "\n")] = '\0';

        printf("\tC�digo Postal: ");
        fgets(A[I].domi.cp, sizeof(A[I].domi.cp), stdin);
        A[I].domi.cp[strcspn(A[I].domi.cp, "\n")] = '\0';

        printf("\tCiudad: ");
        fgets(A[I].domi.ciu, sizeof(A[I].domi.ciu), stdin);
        A[I].domi.ciu[strcspn(A[I].domi.ciu, "\n")] = '\0';

        printf("Salario del vendedor: ");
        scanf("%f", &A[I].sal);
        limpiarBuffer();

        printf("Forma de Pago (Banco-1 N�mina-2 Ventanilla-3): ");
        scanf("%d", &A[I].cla);
        limpiarBuffer();

        switch (A[I].cla) {
            case 1:
                printf("\tNombre del banco: ");
                fgets(A[I].pago.che.noba, sizeof(A[I].pago.che.noba), stdin);
                A[I].pago.che.noba[strcspn(A[I].pago.che.noba, "\n")] = '\0';

                printf("\tN�mero de cuenta: ");
                fgets(A[I].pago.che.nucu, sizeof(A[I].pago.che.nucu), stdin);
                A[I].pago.che.nucu[strcspn(A[I].pago.che.nucu, "\n")] = '\0';
                break;
            case 2:
                printf("\tNombre del banco: ");
                fgets(A[I].pago.nomi.noba, sizeof(A[I].pago.nomi.noba), stdin);
                A[I].pago.nomi.noba[strcspn(A[I].pago.nomi.noba, "\n")] = '\0';

                printf("\tN�mero de cuenta: ");
                fgets(A[I].pago.nomi.nucu, sizeof(A[I].pago.nomi.nucu), stdin);
                A[I].pago.nomi.nucu[strcspn(A[I].pago.nomi.nucu, "\n")] = '\0';
                break;
            case 3:
                A[I].pago.venta = 'S';
                break;
        }
    }
}

void F1(vendedor A[], int T) {
    int I, J;
    float SUM;
    printf("\n\t\tVentas Totales de los Vendedores");
    for (I = 0; I < T; I++) {
        SUM = 0.0;
        for (J = 0; J < 12; J++)
            SUM += A[I].ven[J];
        printf("\nVendedor: %d\nVentas: %.2f\n", A[I].num, SUM);
    }
}

void F2(vendedor A[], int T) {
    int I, J;
    float SUM;
    printf("\n\t\tIncremento a los Vendedores con Ventas > 1,500,000$");
    for (I = 0; I < T; I++) {
        SUM = 0.0;
        for (J = 0; J < 12; J++)
            SUM += A[I].ven[J];
        if (SUM > 1500000.00) {
            A[I].sal *= 1.05;
            printf("\nN�mero de empleado: %d\nVentas: %.2f\nNuevo salario: %.2f",
                   A[I].num, SUM, A[I].sal);
        }
    }
}

void F3(vendedor A[], int T) {
    int I, J;
    float SUM;
    printf("\n\t\tVendedores con Ventas < 300,000");
    for (I = 0; I < T; I++) {
        SUM = 0.0;
        for (J = 0; J < 12; J++)
            SUM += A[I].ven[J];
        if (SUM < 300000.00)
            printf("\nN�mero de empleado: %d\nNombre: %s\nVentas: %.2f",
                   A[I].num, A[I].nom, SUM);
    }
}

void F4(vendedor A[], int T) {
    int I;
    printf("\n\t\tVendedores con Cuenta en el Banco");
    for (I = 0; I < T; I++) {
        if (A[I].cla == 1) {
            printf("\nN�mero de vendedor: %d", A[I].num);
            printf("\nBanco: %s", A[I].pago.che.noba);
            printf("\nCuenta: %s\n", A[I].pago.che.nucu);
        }
    }
}
