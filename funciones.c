#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int validaropcion(int x,float y,float z)
{
    printf("\n1- Ingresar 1er operando (A=%f)\n2- Ingresar 2do operando (B=%f)\n3- Calcular la suma (A+B)\n4- Calcular la resta (A-B)\n5- Calcular la division (A/B)\n6- Calcular la multiplicacion (A*B)\n7- Calcular el factorial (A!)\n8- Calcular todas las operacione\n9- Salir\n",y,z);
    scanf("%d",&x);
    char respuesta;
    while(x>9||x<1)
    {
        system("cls");
        printf("Ingreso un caracter no valido.\nSi quiere reintentar hacer una operacion presione s\nSi quiere salir, cualquier otra tecla.\n");
        respuesta=getche();
        fflush(stdin);
        if(respuesta!='s')
        {
            x=9;
            break;
        }
        else
        {
            printf("\n1- Ingresar 1er operando (A=x)\n2- Ingresar 2do operando (B=y)\n3- Calcular la suma (A+B)\n4- Calcular la resta (A-B)\n5- Calcular la division (A/B)\n6- Calcular la multiplicacion (A*B)\n7- Calcular el factorial (A!)\n8- Calcular todas las operacione\n9- Salir\n");
            scanf("%d",&x);
        }
    }
    return x;
}


float pedirnumero(char numeros[])
{
    float y;
    printf("%s",numeros);
    scanf("%f",&y);
    return y;
}
float sumaNumeros (float x,float y)
{
    float suma;
    suma=x+y;
    return suma;
}
float restaNumeros(float x,float y)
{
    float resta;
    resta=x-y;
    return resta;
}
float multiplicacionNumeros(float x,float y)
{
    float multiplicacion;
    multiplicacion=x*y;
    return multiplicacion;
}
float divisionNumero(float x,float y)
{
    int flag=0;
    while(y==0)
    {
        printf("No existe solucion dentro de los reales.\n");
        y=pedirnumero("Reingrese numero distinto para realizar la division.\n");
        flag=1;
    }
    float division= x/ y;
        system("cls");
        if(flag==1)
            {
                printf("La division de el numero A ( %f ) y el numero nuevo ( %f ) es:\n%f\n",x,y,division);
            }
        else
        {
            printf("La division de el numero A ( %f ) y el numero B ( %f ) es:\n%f\n",x,y,division);
        }
    return division;
}
/*float validaciondivision(float x)
{
    if(x==0)
    {


    }
    return x;
}*/
float validacionfactorial(float x)
{
    while(x<0||ceilf(x)!=x)
    {
        printf("Error, el numero A debe ser natural\n");
        x=pedirnumero("Ingrese un numero nuevo\n");
    }
    return x;
}
float factorial(float x)
{
    float valor;
    if(x==0)
    {
        valor=1.00;
    }
    else
    {
        valor=x*factorial(x-1);
    }
    system("cls");
    return valor;
}
void todasLasOperaciones (float x,float y)
{
    float resultadoSuma, resultadoResta, resultadoMultiplicacion,resultadoDivision , resultadoFactorial;
    resultadoSuma = sumaNumeros(x,y);
    resultadoResta = restaNumeros(x,y);
    resultadoMultiplicacion=multiplicacionNumeros(x,y);
    resultadoDivision=divisionNumero(x,y);
    system("cls");
    resultadoFactorial=factorial(validacionfactorial(x));
    printf("La suma es:\n%f\nLa resta es:\n%f\nLa multiplicacion es:\n%f\nLa division es:\n%f\nEl factorial es:\n%f\n",resultadoSuma,resultadoResta,resultadoMultiplicacion,resultadoDivision,resultadoFactorial);

}
