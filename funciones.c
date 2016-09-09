#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

/** \brief Valida que en el menu de operaciones se ingrese un numero dentro del 1 y 9.
 *  \brief Ademas, se le asignan a las primeras dos opciones los dos numeros inicializados dentro del main.
 *  En caso de que el usuario no quiera realizar ninguna operacion una vez ingresado mal el numero, se le pregunta si quiere seguir, si aprieta cualquier tecla que no sea 's' se va de la funcion. Si es 's' vuelve a mostrarle el menu.
 * \param x es la opcion a validar.
 * \param y es el primer numero inicializado en 0.
 * \param z es el segundo numero inicializado en 0.
 * \return Retorna la opcion validada dentro del rango ( 1 y 9).
 */
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
            printf("\n1- Ingresar 1er operando (A=%f)\n2- Ingresar 2do operando (B=%f)\n3- Calcular la suma (A+B)\n4- Calcular la resta (A-B)\n5- Calcular la division (A/B)\n6- Calcular la multiplicacion (A*B)\n7- Calcular el factorial (A!)\n8- Calcular todas las operacione\n9- Salir\n",y,z);
            scanf("%d",&x);
        }
    }
    return x;
}
/** \brief Pide un numero imprimiendo un mensaje a eleccion del usuario.
 *
 * \param numeros[] Es el mensaje que se imprime. Se debe escribir cuando se llama a esta funcion o ingresar una variable de strings cuando se llama a la funcion.
 * \return El numero que se pide.
 */
float pedirnumero(char numeros[])
{
    float y;
    printf("%s",numeros);
    scanf("%f",&y);
    return y;
}
/** \brief Suma dos numeros tipo float asignados cuando se llama a la funcion.
 * \param x Es el primer sumando, que es un numero float.
 * \param y Es el segundo sumando, que es un numero float.
 * \return Retorna la suma entre los dos numeros cuando se llama a la funcion.
 */
float sumaNumeros (float x,float y)
{
    float suma;
    suma=x+y;
    return suma;
}
/** \brief Resta dos numeros tipo float asignados cuando se llama a la funcion.
 * \param x Es el minuendo, que es un numero float.
 * \param y Es el sustraendo, que es un numero float.
 * \return Retorna la diferencia entre x e y.
 */
float restaNumeros(float x,float y)
{
    float resta;
    resta=x-y;
    return resta;
}
/** \brief Multiplica dos numeros tipo float asignados cuando se llama a la funcion.
 * \param x Es el primer factor.
 * \param y Es el segundo factor.
 * \return El producto entre x e y.
 */

float multiplicacionNumeros(float x,float y)
{
    float multiplicacion;
    multiplicacion=x*y;
    return multiplicacion;
}
/** \brief Valida que el segundo numero sea distinto a 0 y despues realiza la division entre dos numeros float que se asignan cuando se llama a la funcion.
 * \param x Es el numerador.
 * \param y Es el denominador que se va a validar.
 * \return Retorna el cociente entre el numerador y el denominador, una vez que el denominador se valido (sea distinto a 0).
 */

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
/** \brief Valida que el numero que se asigna como parametro una vez llamada a la funcion, sea natural.
 * En caso de que no sea natural, se imprime un mensaje diciendole que el numero A debe ser natural y se llama a la funcion pedirnumero poniendole como parametro un mensaje para que ingrese el numero de nuevo.
 * \param x Es el numero a validar.
 * \return Un numero natural.
 */
float validacionfactorial(float x)
{
    while(x<0||ceilf(x)!=x)
    {
        printf("Error, el numero A debe ser natural\n");
        x=pedirnumero("Ingrese un numero nuevo para realizar el factorial\n");
    }
    return x;
}
/** \brief Realiza el factorial de un numero que se asigna cuando se llama a la funcion.
 * \param x Es el numero float al que se le realiza el factorial. Se debe validar anteriormente para que la funcion retorne el factorial.
 * \return En caso de que se valide anteriormente o el numero sea entero, retorna el factorial del numero float.
 *
 */
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
/** \brief Realiza la suma, resta, multiplicacion, division y factorial (del primer numero, en el ultimo caso). De dos numeros float asignados cuando se llama a la funcion.
 *
 * \param x va a ser un float, que va a ser el primer sumando, el minuendo, el primer factor, el numerador y el numero al que se le va a realizar el factorial a la vez.
 * \param y va a ser un float, que va a ser el segundo sumando, el sustraendo, el segundo factor y el denominador a la vez.
 * \return Como la funcion es void, no retorna nada, solo imprime en pantalla los resultados de las operaciones a realizar.
 * OBSERVACION: Cabe aclarar, que como se pidio que se valide la division y el factorial, en caso de que el primer numero sea
 * flotante y el segundo numero sea 0. En la suma, resta y multiplicacion, el resultado va a ser entre esos dos numeros, pero
 * en el caso de la division, se va a pedir que el segundo numero sea distinto de 0, por lo tanto no va a realizar la division
 * de los mismos numeros que se realizan en las operaciones anteriores. Lo mismo es el caso del factorial, en el caso de que el
 * primer numero no sea natural, se va a realizar la operacion de otro numero.
 */
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
