#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion;
    float num1=0;
    float num2=0;
    while(seguir=='s')
    {
        opcion=validaropcion(num1,num2);
        switch(opcion)
        {
            case 1:
                num1=pedirnumero("Ingrese numero A por favor:\n");
                system("cls");
                break;
            case 2:
                num2=pedirnumero("Ingrese numero B por favor:\n");
                system("cls");
                break;
            case 3:
                system("cls");
                printf("La suma de %f y %f es: \n %f \n",num1,num2,sumaNumeros(num1,num2));
                num1=0;
                num2=0;
                break;
            case 4:
                system("cls");
                printf("La resta de %f y %f es: \n %f \n",num1,num2,restaNumeros(num1,num2));
                num1=0;
                num2=0;
                break;
            case 5:
                system("cls");
                num2 = validaciondivision(num2);
                system("cls");
                printf("El cociente entre %f y %f es :\n%f\n",num1,num2,divisionNumero(num1,num2));
                num1=0;
                num2=0;
                break;
            case 6:
                system("cls");
                printf("La multiplicacion de %f y %f es: \n %f \n",num1,num2,multiplicacionNumeros(num1,num2));
                num1=0;
                num2=0;
                break;
            case 7:
                system("cls");
                num1=validacionfactorial(num1);
                system("cls");
                printf("El factorial de %f es:\n%f\n",num1,factorial(num1));
                num1=0;
                num2=0;
                break;
            case 8:
                system("cls");
                todasLasOperaciones(num1,num2);
                num1=0;
                num2=0;
                break;
            case 9:
                system("cls");
                printf("Adios maestro matematico!");
                seguir = 'n';
                break;
        }
    }

    return 0;
}
