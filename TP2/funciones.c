#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"

/** \brief Muestra un string de caracteres (message[]) y obtiene otro string de caracteres.
 ** \brief Al string obtenido, lo valida de manera que contenga solo numeros y que esos numeros esten dentro del 1 y 5.
 ** \brief En caso de que no se cumpla con los criterios de la validacion, se muestra un mensaje de error (errorMensaje[])
 ** \brief y obtiene un caracter (char). Si ese caracter tiene la letra 's', se le vuelve a mostrar un mensaje y se obtiene
 ** \brief nuevamente el string de caracteres a validar. Si no es la letra 's' retorna el numero 5.
 * \param message[] Es el string de caracteres que se muestra antes de obtener el string y validarlo.
 * \param errorMensaje[] Es el string de caracteres que se muestra en caso de que no se cumpla con la validacion.
 * \return El numero validado en caso de que se cumpla con los criterios establecidos. Sino retorna un 5.
 */
int validarMenu (char message[],char errorMensaje[])
{
    char auxiliar[257];
    int retorno;
    char respuesta;
    do
    {
        printf("%s\n",message);
        fflush(stdin);
        scanf("%s",auxiliar);
        if( validarEntero(atoi(auxiliar),1,5))
        {
            retorno=atoi(auxiliar);
            break;
        }
        system("cls");
        printf("%s\n",errorMensaje);
        fflush(stdin);
        respuesta=getche();
        printf("\n");
        if(respuesta!='s')
        {
            system("cls");
            printf("Adios!\n");
            retorno=5;
            break;
        }
        system("cls");
    }while(( ! validarNumero( auxiliar, 2 ) ) || ( ! validarEntero ( ( retorno=atoi ( auxiliar ) ) , 1 , 6 ) ));
return retorno;
}

/** \brief Obtiene un string de caracteres antecedidos por un string de caracteres mostrados.
 * \param message[] Es el string de caracteres mostrados.
 * \param entrada[] Es el string de caracteres a obtener.
 */
void getString (char message[],char entrada[])
{
    puts(message);
    fflush(stdin);
    gets(entrada);
}

/** \brief Valida que un array de caracteres este compuesto solo por numeros y tenga un maximo de caracteres.
 * \param numeros[] Es el array de caracteres a validar.
 * \param limite Es el entero que permite el maximo de caracteres dentro del array numeros[].
 * \return Un 1 en caso de que se cumpla con los criterios pautados. Sino retorna un 0.
 */
int validarNumero(char numeros[],int limite)
{
    int i=0;
    int verdad=1;
    int cantidad=strlen(numeros);
    while(numeros[i] != '\0')
    {
        if((cantidad>limite)||(numeros[i] < '0' || numeros[i] > '9'))
        {
            verdad= 0;
        }
        i++;
    }
    return verdad;
}

/** \brief Valida que un entero que se pasa por parametro este dentro de un rango (Entre el entero desde y el entero hasta).
 * \param x Es el entero a validar.
 * \param desde Es el entero minimo que se toma como valido dentro del rango.
 * \param hasta Es el entero maximo que se toma dentro del rango.
 * \return Un uno en caso de que se cumpla con los criterios de validacion y un 0 en caso de que no.
 */
int validarEntero(int x,int desde,int hasta)
{
    int verdad;
    if(x<desde||x>hasta)
    {
        verdad=0;
    }
    else
    {
        verdad=1;
    }
    return verdad;
}

/** \brief Valida que un string de caracteres este compuesto solo por letras y espacios y que posea un maximo de longitud
 * \param letras[] Es el string de tipo char a validar.
 * \param limite Es el maximo de caracteres permitidos en la validacion.
 * \return Un 0 si el string de caracteres ingresado no cumple con los requisitos de validacion. En caso de que cumpla retorna un 1.
 */
int validarLetras(char letras[],int limite)
{
   int i=0;
   int verdad=1;
   int longitud=strlen(letras);
   while(letras[i] != '\0')
   {
       if(longitud>limite||((letras[i] != ' ') && (letras[i] < 'a' || letras[i] > 'z') && (letras[i] < 'A' || letras[i] > 'Z')))
        {
            verdad= 0;
        }
       i++;
   }
   return verdad;
}

/** \brief A cada persona del array personas del tipo EPersona le asigna
 *  \brief un 0 al campo estado.
 * \param El array personas de EPersona.
 * \param Es la cantidad de caracteres que posee el array.
 * \param Es el valor que se le asigna a cada persona para indicar que esta vacio.
 */
void inicializaArrayPersonas(EPersona arrayPersonas[],int longitudArray, int valor)
{
    int i;
    for(i=0;i<longitudArray;i++)
    {
        arrayPersonas[i].estado=valor;
    }
}

/**\brief Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param longitudArray: Es la cantidad de arrays de tipo EPersonas que posee el parametro anterior.
 * @return El primer indice disponible en caso de que halla, sino retorna un -1.
 */
int obtenerEspacioLibre(EPersona lista[], int cantidadArray)
{
    int i;
    int retorno;
    for(i=0;i<cantidadArray;i++)
    {
        if(lista[i].estado==-1)
        {
            retorno = i;
            break;
        }
        else
        {
            retorno = -1;
        }
    }
    return retorno;
}

/**
 * \brief Obtiene el indice que coincide con el dni pasado por parametro, en caso de que halla coincidencia.
 * @param lista[] Es el array del tipo EPersona que se pasa como parametro.
 * @param dni Es el dni a ser buscado en el array.
 * @param cantidadLista Es la cantidad de arrays del tipo EPersona que se pasa como parametro
 * @return El indice en donde se encuentra el elemento que coincide con el parametro dni en caso de que lo encuentre. Sino, retorna -1.
 */
int buscarPorDni(EPersona lista[],int dni, int cantidadLista)
{
    int i;
    int retorno=-1;
    for(i=0;i<cantidadLista;i++)
    {
        if(lista[i].estado!=-1)
        {
            if(lista[i].dni==dni)
            {
                retorno=i;
                break;
            }
        }
    }
return retorno;
}



