#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
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
void getString (char message[],char entrada[])
{
    puts(message);
    fflush(stdin);
    gets(entrada);
}
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



void inicializaArrayPersonas(EPersona arrayPersonas[],int longitudArray, int valor)
{
    int i;
    for(i=0;i<longitudArray;i++)
    {
        arrayPersonas[i].estado=valor;
    }
}
int obtenerEspacioLibre(EPersona lista[], int longitudArray)
{
    int i;
    int retorno;
    for(i=0;i<longitudArray;i++)
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
int buscarPorDni(EPersona lista[],int dni, int longitudLista)
{
    int i;
    int retorno=-1;
    for(i=0;i<longitudLista;i++)
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
