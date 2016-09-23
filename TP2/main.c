#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"
#define CANT 20
#define ALTA 1

int main()
{
    system("color F0");
    char seguir='s';
    int opcion=0;
    EPersona personas[CANT];
    EPersona auxiliarPersona;
    inicializaArrayPersonas(personas, CANT,-1);
    int indiceEspacioLibre;
    int posicion,flag1=0,flag2=0,flag3=0,flag4=0;
    char confirmacion, respuesta1, respuesta2,respuesta3,respuesta4;
    char auxiliarEdadArray[256];
    char auxiliarNombre[256];
    char auxiliarDniArray[256];
    int auxiliarEdad;
    int auxiliarDni;
    int i, j;
    int menores_De_Edad=0, adultosJovenes=0, adultosMayores=0, mayorCantidad=0, flag=0;
    while(seguir=='s')
    {
        opcion=validarMenu("1- Agregar persona\n2- Borrar persona\n3- Imprimir lista ordenada por nombre\n4- Imprimir grafico de edades\n5- Salir\n","Error. Para realizar una accion debe ingresar un numero del 1 al 5.\nDesea seguir?\nPresione la tecla 's' para volver a intentar. Cualquier otra tecla para salir\n");
        switch(opcion)
        {
            case 1:
                indiceEspacioLibre=obtenerEspacioLibre(personas,CANT);
                if(indiceEspacioLibre==-1)
                {
                    printf("Estan todos los lugares ocupados.\n");
                    break;
                }
                system("cls");
                getString("Ingrese su nombre por favor:\n",auxiliarNombre);
                while(!validarLetras(auxiliarNombre,49))
                {
                    system("cls");
                    printf("Para ingresar el nombre solo se aceptan letras y/o espacios.\nAdemas debe tener menos de 49 caracteres.\n");
                    printf("Desea volver a ingresar el nombre?\nPresione la tecla 's'. Sino quiere presione cualquier otra tecla\n");
                    respuesta1=getche();
                    if(respuesta1=='s')
                    {
                        system("cls");
                        getString("Ingrese su nombre por favor:\n",auxiliarNombre);
                    }
                    else
                    {
                        flag1=1;
                        break;
                    }
                }
                if(flag1)
                {
                    printf("\n");
                    break;
                }
                getString("Ingrese su edad por favor:\n",auxiliarEdadArray);
                while((!validarNumero(auxiliarEdadArray,4))||(!validarEntero(atoi(auxiliarEdadArray),0,125)))
                {
                    system("cls");
                    printf("Para ingresar la edad solo se aceptan numeros desde 0 hasta 125.\n");
                    printf("Desea volver a ingresarle la edad?\nPresione 's' por si. Cualquier otra tecla para salir\n");
                    respuesta2=getche();
                    if(respuesta2=='s')
                    {
                        system("cls");
                        getString("Ingrese su edad por favor:\n",auxiliarEdadArray);
                    }
                    else
                    {
                        flag2=1;
                        break;
                    }
                }
                if(flag2)
                {
                    printf("\n");
                    break;
                }
                auxiliarEdad=atoi(auxiliarEdadArray);/**-LE IMPRIMO EL NUMERO DEL ARRAY AUXILIARNUMERO CONVERTIDO EN ENTERO AL ENTERO AUXILIAREDAD-*/
                getString("Ingrese su DNI por favor:\n",auxiliarDniArray);
                while((!validarNumero(auxiliarDniArray,11))||(buscarPorDni(personas,atoi(auxiliarDniArray),CANT)!=-1))
                {
                    if(!validarNumero(auxiliarDniArray,11))
                    {
                        system("cls");
                        printf("Para ingresar el DNI solo se aceptan numeros.\nPresione 's' para reingresar DNI.\nCualquier otra tecla para salir:\n");
                        respuesta3=getche();
                        if(respuesta3=='s')
                        {
                            system("cls");
                            getString("Ingrese su DNI por favor:\n",auxiliarDniArray);
                        }
                        else
                        {
                            flag3=1;
                            break;
                        }
                    }
                    if(buscarPorDni(personas,atoi(auxiliarDniArray),CANT)!=-1)
                    {
                        system("cls");
                        printf("El DNI ingresado ya existe.\nPresione 's' para reingresar, otra tecla para volver al menu\n");
                        respuesta4=getche();
                        if(respuesta4=='s')
                        {
                            system("cls");
                            getString("Ingrese su DNI por favor:\n",auxiliarDniArray);
                        }
                        else
                        {
                            flag4=1;
                            break;
                        }
                    }
                }
                if(flag3||flag4)
                {
                    printf("\n");
                    break;
                }
                system("cls");
                auxiliarDni=atoi(auxiliarDniArray);/**-LE IMPRIMO EL NUMERO DEL ARRAYAUXILIARDNI CONVERTIDO EN ENTERO AL ENTERO AUXILIARDNI-*/
                personas[indiceEspacioLibre].dni=auxiliarDni;/**-LE IMPRIMO AL CAMPO DNI DEL ARRAY PERSONAS[OCUPADO] EL ENTERO AUXILIARDNI -*/
                personas[indiceEspacioLibre].edad=auxiliarEdad;/**-LE IMPRIMO AL CAMPO EDAD DEL ARRAY PERSONAS[OCUPADO] EL ENTERO AUXILIAREDAD -*/
                strcpy(personas[indiceEspacioLibre].nombre,auxiliarNombre);/**-LE IMPRIMO AL CAMPO NOMBRE DEL ARRAY PERSONAS[OCUPADO] EL ARRAY AUXILIARNOMBRE -*/
                printf("\nNombre de persona %d : %s\n",indiceEspacioLibre+1,personas[indiceEspacioLibre].nombre);
                printf("\nEdad persona %d : %d\n",indiceEspacioLibre+1,personas[indiceEspacioLibre].edad);
                printf("\nDNI persona %d : %d\n",indiceEspacioLibre+1,personas[indiceEspacioLibre].dni);
                personas[indiceEspacioLibre].estado=ALTA;/**DECLARO EL CAMPO ESTADO DEL PERSONAS[OCUPADO] DE ALTA (1)*/
                printf("\nEstado de persona %d : %d \n\n",indiceEspacioLibre+1,personas[indiceEspacioLibre].estado);
                break;
            case 2:
                system("cls");
                getString("Indique el DNI de la persona que desea borrar por favor:\n",auxiliarDniArray);
                if(!validarNumero(auxiliarDniArray,11))
                {
                    system("cls");
                    printf("Se debe indicar el numero de DNI.\n");
                    break;
                }
                auxiliarDni=atoi(auxiliarDniArray);
                posicion=buscarPorDni(personas,auxiliarDni,CANT);
                if(posicion==-1)
                {
                    system("cls");
                    printf("No existe el numero de DNI ingresado\n");
                    break;
                }
                printf("Usted va a borrar a %s de %d anios de DNI %d.\n Esta seguro de borrarlo?\nPresione la tecla s para borrar, cualquier otra tecla para volver al menu.\n",personas[posicion].nombre,personas[posicion].edad,personas[posicion].dni);
                confirmacion=getche();
                confirmacion=tolower(confirmacion);
                printf("\n");
                if(confirmacion=='s')
                {
                    personas[posicion].estado=-1;
                    system("cls");
                    printf("Se han borrado los datos de la persona indicada.\n");
                }
                else
                {
                    system("cls");
                    break;
                }
                break;
            case 3:
                for(i=0;i<CANT-1;i++)
                {
                    for(j=i+1;j<CANT;j++)
                    {
                        if((personas[i].estado==1)&&(personas[j].estado==1))
                        {
                            if(stricmp(personas[i].nombre,personas[j].nombre)>0)
                            {
                                auxiliarPersona=personas[i];
                                personas[i]=personas[j];
                                personas[j]=auxiliarPersona;
                            }
                        }
                    }
                }
                system("cls");
                for(i=0;i<CANT;i++)
                {
                    if(personas[i].estado!=-1)
                    {
                        printf("Nombre : %s DNI : %d Edad : %d\n", personas[i].nombre,personas[i].dni,personas[i].edad);

                    }
                }
                break;
            case 4:
                for(i=0;i<CANT;i++)
                {
                    if(personas[i].estado!=-1)
                    {
                        if(personas[i].edad<=18)
                            {
                                menores_De_Edad++;
                            }
                        if(personas[i].edad>=19&&personas[i].edad<=35)
                            {
                                adultosJovenes++;
                            }
                        if(personas[i].edad>35)
                            {
                                adultosMayores++;
                            }
                    }
                }
                if(menores_De_Edad>=adultosJovenes&&menores_De_Edad>=adultosMayores)
                {
                    mayorCantidad=menores_De_Edad;
                }
                else
                {
                    if(adultosJovenes>=menores_De_Edad&&adultosJovenes>=adultosMayores)
                    {
                        mayorCantidad=adultosJovenes;
                    }
                    else
                    {
                        mayorCantidad=adultosMayores;
                    }

                }
                if(mayorCantidad!=0)
                {
                    system("cls");
                    for(i=mayorCantidad; i>0; i--)
                    {

                        printf("%02d|",i);

                        if(i<=menores_De_Edad)
                        {
                            printf("*");
                        }
                        if(i<=adultosJovenes)
                        {
                            flag=1;
                            printf("\t*");
                        }
                        if(i<=adultosMayores)
                        {
                            if(flag==0)
                            printf("\t\t*");
                            if(flag==1)
                            printf("\t*");
                        }
                            printf("\n");//Bajo una linea luego de cada iteracion
                    }
                    printf("--+-----------------");
                    printf("\n  |<18\t19-35\t>35");
                    printf("\n   %d\t%d\t%d\n", menores_De_Edad, adultosJovenes, adultosMayores);
                    mayorCantidad=0;
                    menores_De_Edad=0;
                    adultosJovenes=0;
                    adultosMayores=0;
                }
                else
                {
                    system("cls");
                    printf("Perdon, pero usted no ingreso ninguna persona menor de edad ni entre 19 y 35 ni mayor a 35\n");
                }
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
