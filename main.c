#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion;
    float num1=0;
    float num2=0;
    //char etexto[]="Usted ingreso un numero no comprendido dentro del rango.\nPresione s si quiere reingresar una opcion y n si no quiere realizar nada\n";
    while(seguir=='s')
    {
        opcion=validaropcion(opcion,num1,num2);
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
                printf("La suma de los numeros es: \n %f \n",sumaNumeros(num1,num2));
                num1=0;
                num2=0;
                break;
            case 4:
                system("cls");
                printf("La resta de los numeros es: \n %f \n",restaNumeros(num1,num2));
                num1=0;
                num2=0;
                break;
            case 5:
                /*system("cls");
                validaciondivision(num2);
                printf("La division de los numeros es: \n %f \n",divisionNumeros(num1,num2));*/
                num2 = divisionNumero(num1,num2);
                num1=0;
                num2=0;
                break;
            case 6:
                system("cls");
                printf("La multiplicacion de los numeros es: \n %f \n",multiplicacionNumeros(num1,num2));
                num1=0;
                num2=0;
                break;
            case 7:
                system("cls");
                num1=validacionfactorial(num1);
                printf("El factorial de A es:\n%f\n",factorial(num1));
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
                seguir = 'n';
                break;
        }
    }

    return 0;
}
