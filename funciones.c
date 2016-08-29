#include "funciones.h"
#ifndef FUNCIONES_C_INCLUDED
#define FUNCIONES_C_INCLUDED


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
float divisionNumeros(float x,float y)
{
    float division=(float)x/y;
    return division;
}
int factorialNumero1(int x)
{
    int i;
    float factorial=1;
    for(i=1;i<=x;i++)
            {
                factorial=factorial*i;
            }
    return factorial;
}
void todasLasOperaciones (int x,int y)
{
    sumaNumeros(x,y);
    restaNumeros(x,y);
    divisionNumeros(x,y);
    multiplicacionNumeros(x,y);
    factorialNumero1(x);
}
#endif // FUNCIONES_H_INCLUDED
