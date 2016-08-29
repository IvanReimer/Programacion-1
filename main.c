#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float num1=0;
    float num2=0;
    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=%f)\n",num1);
        printf("2- Ingresar 2do operando (B=%f)\n",num2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");
        printf("Indique que opcion desea ejecutar\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                printf("Ingrese el primer numero por favor:\n");
                scanf("%f",&num1);
                system("cls");
                break;
            case 2:
                printf("Ingrese el segundo numero por favor:\n");
                scanf("%f",&num2);
                system("cls");
                break;
            case 3:
                system("cls");
                printf("La suma de los numeros es: \n %f \n",sumaNumeros(num1,num2));
                break;
            case 4:
                system("cls");
                printf("La resta de los numeros es: \n %f \n",restaNumeros(num1,num2));
                break;
            case 5:
               system("cls");
               printf("La multiplicacion de los numeros es: \n %f \n",divisionNumeros(num1,num2));
                break;
            case 6:
                system("cls");
                printf("La multiplicacion de los numeros es: \n %f \n",multiplicacionNumeros(num1,num2));
                break;
            case 7:
                system("cls");
                printf("El factorial del numero A es: \n %d \n",factorialNumero1(num1));
                break;
            case 8:
                system("cls");
                todasLasOperaciones(num1,num2);
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }

    return 0;
}


