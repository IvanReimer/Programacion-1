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
int validaropcion(float y,float z)
{
    int x;
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
            system("cls");
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
/** \brief Realiza la division de los numeros.
 * \param x Es el numerador.
 * \param y Es el denominador.
 * \return Retorna el cociente entre el numerador y el denominador.
 */

float divisionNumero(float x,float y)
{
    float division= x/y;
    return division;
}
/** \brief Valida que un numero flotante sea distinto a 0.
 * \param y Es el flotante que se va a validar
 * \return Un numero flotante que sea distinto a 0.
 */

float validaciondivision(float y)
{
    while(y==0)
    {
        printf("No existe solucion dentro de los reales.\n");
        y=pedirnumero("Reingrese numero distinto para realizar la division.\n");
    }
    return y;
}
/** \brief Valida que el numero que se asigna como parametro una vez llamada a la funcion, sea natural.
 * En caso de que no sea natural, se imprime un mensaje diciendole que el numero debe ser natural y se llama a la funcion pedirnumero poniendole como parametro un mensaje para que ingrese el numero de nuevo.
 * \param x Es el numero a validar.
 * \return Un numero natural.
 */
float validacionfactorial(float x)
{
    while(x<0||ceilf(x)!=x)
    {
        printf("Error, el numero %f debe ser natural\n",x);
        x=pedirnumero("Ingrese un numero nuevo para realizar el factorial\n");
    }
    return x;
}
/** \brief Realiza el factorial de un numero que se asigna cuando se llama a la funcion.
 * \param x Es el numero float al que se le realiza el factorial.
 * \return Retorna el factorial del numero float.
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

    return valor;
}
/** \brief Realiza la suma, resta, multiplicacion, division y factorial (del primer numero, en el ultimo caso). De dos numeros float asignados cuando se llama a la funcion.
 * \param x va a ser un float, que va a ser el primer sumando, el minuendo, el primer factor, el numerador y el numero al que se le va a realizar el factorial a la vez.
 * \param y va a ser un float, que va a ser el segundo sumando, el sustraendo, el segundo factor y el denominador a la vez.
 * \return Como la funcion es void, no retorna nada, solo imprime en pantalla los resultados de las operaciones a realizar.
 */
void todasLasOperaciones (float x,float y)
{
    float resultadoSuma, resultadoResta, resultadoMultiplicacion,resultadoDivision , resultadoFactorial;
    resultadoSuma = sumaNumeros(x,y);
    printf("La suma entre %f y %f es:\n%f\n",x,y,resultadoSuma);
    resultadoResta = restaNumeros(x,y);
    printf("La diferencia entre %f y %f es:\n%f\n",x,y,resultadoResta);
    resultadoMultiplicacion=multiplicacionNumeros(x,y);
    printf("El producto entre %f y %f es:\n%f\n",x,y,resultadoMultiplicacion);
    if(y==0)
    {
        printf("El numero B es 0, no se puede realizar la division.\n\n");
    }
    else
    {
        resultadoDivision=divisionNumero(x,y);
        printf("El cociente entre %f y %f es:\n%f\n",x,y,resultadoDivision);
    }
    if (x<0||ceilf(x)!=x)
    {
        printf("No se puede realizar el factorial de A porque no es natural\n\n");
    }
    else
    {
        resultadoFactorial=factorial(x);
        printf("El factorial de %f es:\n%f\n",x,resultadoFactorial);
    }
}
