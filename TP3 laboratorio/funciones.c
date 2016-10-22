#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"
int inicializarEstadoDePeliculas(Movie* lista, int longitud,int valor)
{
    int retorno=1;
    if(lista==NULL||longitud<1)
    {
        retorno=0;
        pausa("ERROR DE PASAJE DE PARAMETROS EN LA FUNCION inizializarEstadoDePeliculas");
    }
    else
    {
        int i;
        for(i=0;i<longitud;i++)
        {
            lista[i].estado=valor;
        }
    }
    return retorno;
}

int buscarPrimerIndiceDePeliculas(Movie* lista,int longitud,int valor)
{
    int i;
    int retorno=-1;
    for(i=0;i<longitud;i++)
    {
        if(lista[i].estado==valor)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

void getString (char message[],char entrada[])
{
    puts(message);
    fflush(stdin);
    gets(entrada);
}

int sonLetrasOEspacios(char letras[],int limite)
{
   int i=0;
   int verdad=1;
   int longitud=strlen(letras);
   if(limite<1)
   {
       pausa("ERROR DE PASAJE DE PARAMETROS EN FUNCION validarLetras");
       system("cls");
       verdad=0;
   }
   if(verdad)
   {
        while(letras[i] != '\0' || longitud==0)
        {
           if((longitud>limite)||((letras[i] != ' ') && (letras[i] < 'a' || letras[i] > 'z') && (letras[i] < 'A' || letras[i] > 'Z')))
            {
                verdad= 0;
                break;
            }
            i++;
        }
   }
   return verdad;
}

int esAlfaNumerico(char str[],int limite)
{
   int i=0;
   int retorno=1;
   int longitud;
   longitud=strlen(str);
   while(str[i] != '\0'||longitud==0)
   {
       if(longitud>limite||((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9')))
        {
            retorno= 0;
            break;
        }
       i++;
   }
   return retorno;
}

void pausa(char mensaje[])
{
    system("cls");
    puts(mensaje);
    system("pause");
    system("cls");
}

int esNumeroNatural(char numeros[],int limite)
{
    int i=0;
    int verdad=1;
    int cantidad=strlen(numeros);
    if(limite<1)
    {
        verdad=0;
        pausa("ERROR DE PROGRAMACION EN LA FUNCION validarNumero");
        system("cls");
    }
    if(verdad)
    {
        while(numeros[i] != '\0'|| cantidad==0)
        {
            if((cantidad>limite)||(numeros[i] < '0' || numeros[i] > '9'))
            {
                verdad= 0;
                break;
            }
            i++;
        }
    }
    return verdad;
}

int validarRangoDeEntero(int x,int desde,int hasta)
{
    int verdad=1;
    if(x<desde||x>hasta)
    {
        verdad=0;
    }
    return verdad;
}

void mostrarMenu (char opciones[][100])
{
    int i = 0;
    char opcion[100];
    while (opciones[i][0] != '\0')
    {
        strcpy(opcion, opciones[i]);
        i++;
        printf("%d)- %s\n", i, opcion);
    }
}

int menu(int* input)
{
    int retorno=1;
    if(input==NULL)
    {
        pausa("ERROR EN EL PASAJE DE PARAMETROS EN LA FUNCION menu");
        retorno=0;
    }
    else
    {
        char opciones[11][100] = {{"Agregar Pelicula"},{"Modificar Pelicula"},{"Borrar Pelicula"},{"Generar pagina web"},{"Salir"},{'\0'}};
        char aux[256];
        mostrarMenu(opciones);
        gets(aux);
        while((!esNumeroNatural(aux,1))||(!validarRangoDeEntero(atoi(aux),1,5)))
        {
            system("cls");
            if(reingresarDatos("Error debe ingresar un numero entre 1 y 4.","Desea reingresar opcion del menu?\nPresione 's' para reingresar.Otra tecla para salir del programa")=='s')
            {
                system("cls");
                mostrarMenu(opciones);
                getString("Ingrese una opcion del menu por favor",aux);
            }
            else
            {
                system("cls");
                aux[0]='5';
                retorno=0;
                break;
            }
        }
        *input=atoi(aux);
    }
    return retorno;
}

char reingresarDatos(char eMensaje[],char pregunta[])
{
    char retorno;
    puts(eMensaje);
    puts(pregunta);
    retorno=getche();
    printf("\n");
    retorno=tolower(retorno);
    return retorno;
}

int obtenerTituloValidado(Movie* lista,int longitud,int vacio, char input[])
{
    int retorno=1;

    system("cls");
    getString("Ingrese el Titulo de la pelicula por favor.",input);
    while(strlen(input)>50||buscarTituloRepetido(lista,longitud,vacio,input))
    {
        system("cls");
        if(reingresarDatos("Error. El Titulo debe tener menos de 50 caracteres y no estar repetido","Desea volver a ingresar el titulo de la pelicula?\nPresione 's' para reingresar, otra tecla para volver al menu")=='s')
        {
            system("cls");
            getString("Reingrese el titulo de la pelicula por favor\n",input);
        }
        else
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int buscarTituloRepetido(Movie* lista,int longitud,int valor, char input[])
{
    int i;
    int retorno=0;
    if(lista==NULL||longitud<1)
    {
        pausa("ERROR DE PASAJE DE PARAMETROS EN LA FUNCION buscarTituloRepetido");
        retorno=1;
    }
    else
    {
        for(i=0;i<longitud;i++)
        {
            if(lista[i].estado==valor)
            {
                continue;
            }
            if(stricmp(lista[i].titulo,input)==0)
            {
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}

int obtenerGeneroValidado(Movie* lista,int longitud, char input[])
{
    int retorno=1;
    if(lista==NULL||longitud<1)
    {
        retorno=0;
    }
    if(retorno)
    {
        system("cls");
        getString("Ingrese genero de pelicula",input);
        while(!sonLetrasOEspacios(input,20))
        {
            if(reingresarDatos("Error, para el genero solo se permiten letras o espacios","Desea reingresar el genero de la pelicula?\nPresione 's' para reingresar, otra tecla para regresar al menu.")=='s')
            {
                system("cls");
                getString("Reingrese genero de la pelicula",input);
            }
            else
            {
                system("cls");
                retorno=0;
            }
        }
    }
    return retorno;
}

int obtenerLinkValidado(Movie* lista,int longitud, char input[])
{
    int retorno=1;
    if(lista==NULL||longitud<1)
    {
        retorno=0;
    }
    if(retorno)
    {
        system("cls");
        getString("Ingrese link de imagen de pelicula",input);
        while(strlen(input)>100||strlen(input)<1)
        {
            if(reingresarDatos("Error, al cargar el link de la imagen","Desea reingresar el link de imagen de la pelicula?\nPresione 's' para reingresar, otra tecla para regresar al menu.")=='s')
            {
                system("cls");
                getString("Reingrese link de imagen de la pelicula",input);
            }
            else
            {
                system("cls");
                retorno=0;
            }
        }
    }
    return retorno;
}

int obtenerDuracionValidada(Movie* lista,int longitud,int vacio,int* input)
{
    int retorno=1;
    char aux[256];
    if(lista==NULL||longitud<1)
    {
        retorno=0;
    }
    if(retorno)
    {
        getString("Ingrese la duracion de la pelicula en minutos por favor",aux);
        while(!esNumeroNatural(aux,3))
        {
            system("cls");
            if(reingresarDatos("Error. Solo se permiten numeros para la duracion","Desea reingresar los datos?\nPresione 's' para reingresar, otra tecla para regresar al menu.")=='s')
            {
                getString("Ingrese la duracion de la pelicula en minutos por favor",aux);
            }
            else
            {
                system("cls");
                retorno=0;
            }
        }
        if(esNumeroNatural(aux,3))
        *input=atoi(aux);
    }
    return retorno;
}

int obtenerDescripcionValidada(Movie* lista,int longitud,int vacio, char input[])
{
    int retorno=1;
    system("cls");
    getString("Ingrese la descripcion de la pelicula por favor.",input);
    while(buscarDescripcionRepetida(lista,longitud,vacio,input)||strlen(input)>200)
    {
        system("cls");
        if(reingresarDatos("Error. La descripcion debe tener menos de 200 caracteres y no estar repetida","Desea volver a ingresar la descripcion?\nPresione 's' para reingresar, otra tecla para volver al menu")=='s')
        {
            system("cls");
            getString("Reingrese la descripcion de la pelicula por favor\n",input);
        }
        else
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int buscarDescripcionRepetida(Movie* lista,int longitud,int valor, char input[])
{
    int i;
    int retorno=0;
    if(lista==NULL||longitud<1)
    {
        pausa("ERROR DE PASAJE DE PARAMETROS EN LA FUNCION buscarTituloRepetido");
        retorno=1;
    }
    else
    {
        for(i=0;i<longitud;i++)
        {
            if(lista[i].estado==valor)
            {
                continue;
            }
            if(stricmp(lista[i].descripcion,input)==0)
            {
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}

int obtenerPuntajeValidado(Movie* lista, int longitud, int* input)
{
    int retorno=1;
    char aux[256];
    if(lista==NULL||longitud<1)
    {
        retorno=0;
    }
    if(retorno)
    {
        system("cls");
        getString("Ingrese el puntaje de la pelicula por favor",aux);
        while(!esNumeroNatural(aux,2)||!validarRangoDeEntero(atoi(aux),1,10))
        {
            system("cls");
            if(reingresarDatos("Error, el puntaje debe tener numeros del 1 al 10","Desea reingresar los datos?\n Presione 's' para reingresar, otra tecla para retornar al menu.")=='s')
            {
                getString("Reingrese el puntaje por favor",aux);
            }
            else
            {
                system("cls");
                retorno=0;
            }
        }
        if((esNumeroNatural(aux,2))&&(validarRangoDeEntero(atoi(aux),1,10)))
        *input=atoi(aux);
    }
    return retorno;
}

int imprimirTitulosDePelicula(Movie* lista, int longitud, int ocupado)
{
    int i;
    int retorno=1;
    if(lista==NULL||longitud<1)
    {
        retorno=0;
    }
    if(retorno)
    {
        for(i=0;i<longitud;i++)
        {
            if(lista[i].estado==ocupado)
            {
                printf("%d)- Titulo : %s\n",lista[i].id,lista[i].titulo);
            }
        }
    }
    return retorno;
}

int actualizarId(Movie* lista,int longitud)
{
    int i,j;
    int retorno=1;
    if(lista==NULL||longitud<1)
    {
        retorno=0;
    }
    else
    {
        for(i=0,j=1;i<longitud;i++)
        {
            if(lista[i].estado==1)
            {
                lista[i].id=j;
                j++;
            }
        }
    }
    return retorno;
}

int agregarPelicula(Movie* lista, int longitud)
{
    int retorno=1;
    Movie auxiliar;
    int indicePelicula;
    if(lista==NULL||longitud<1)
    {
        retorno=0;
    }
    if(retorno)
    {
        indicePelicula=buscarPrimerIndiceDePeliculas(lista,longitud,0);
        if(indicePelicula==-1)
        {
            printf("Estan todas las peliculas ocupadas, de de baja una para seguir por favor.\n");
            retorno=0;
        }
    }
    if(retorno)
    {
        if(!obtenerTituloValidado(lista,longitud,0,auxiliar.titulo))
        retorno=0;
    }
    if(retorno)
    {
        if(!obtenerGeneroValidado(lista,longitud,auxiliar.genero))
            retorno=0;
    }
    if(retorno)
    {
        if(!obtenerDescripcionValidada(lista,longitud,0,auxiliar.descripcion))
            retorno=0;
    }
    if(retorno)
    {
        if(!obtenerLinkValidado(lista,longitud,auxiliar.linkImagen))
            retorno=0;
    }
    if(retorno)
    {
        if(!obtenerDuracionValidada(lista,longitud,0,&auxiliar.duracion))
            retorno=0;
    }
    if(retorno)
    {
        if(!obtenerPuntajeValidado(lista,longitud,&auxiliar.puntaje))
            retorno=0;
        else
        {
            strcpy(lista[indicePelicula].descripcion,auxiliar.descripcion);
            strcpy(lista[indicePelicula].titulo,auxiliar.titulo);
            strcpy(lista[indicePelicula].genero,auxiliar.genero);
            strcpy(lista[indicePelicula].linkImagen,auxiliar.linkImagen);
            lista[indicePelicula].duracion=auxiliar.duracion;
            lista[indicePelicula].puntaje=auxiliar.puntaje;
            lista[indicePelicula].estado=1;
        }
    }
    return retorno;
}

int borrarPelicula(Movie* lista, int longitud)
{
    int retorno=1;
    int indice;
    if(lista==NULL||longitud<1)
    {
        pausa("ERROR EN EL PASAJE DE PARAMETROS EN LA FUNCION bajaDePelicula");
        retorno=0;
    }
    if(retorno)
    {
        indice=buscarPrimerIndiceDePeliculas(lista,longitud,1);
        if(indice==-1)
        {
            pausa("No hay ninguna pelicula agregada hasta el momento");
            retorno=0;
        }
    }
    if(retorno)
    {
        actualizarId(lista,longitud);
        system("cls");
        indice=obtenerIdPeliculaValidado(lista,longitud);
        if(indice==-1)
        {
            system("cls");
            retorno=0;
        }
    }
    if(retorno)
    {
        printf("Usted va a eliminar a la pelicula de titulo: %s",lista[indice].titulo);
        if(reingresarDatos("Esta seguro de eliminarla?","Presione 's' para eliminarla otra tecla para regresar al menu")=='s')
        {
            lista[indice].estado=0;
        }
        else
        {
            system("cls");
            puts("Accion cancelada");
            retorno=0;
        }
    }

    return retorno;
}

int buscarIndicePorId(Movie* lista, int longitud, int id)
{
    int i;
    int retorno;
    if(lista==NULL||longitud<1)
    {
        pausa("ERROR DE PASAJE DE PARAMETROS EN LA FUNCION buscarIndicePorId");
        retorno=-1;
    }
    else
    {
        retorno=-1;
        for(i=0;i<longitud;i++)
        {
            if(lista[i].estado==0) continue;
            if(lista[i].id==id)
            {
                retorno=i;
            }
        }
    }
    return retorno;
}

int obtenerIdPeliculaValidado(Movie* lista, int longitud)
{
    char aux[256];
    if(lista==NULL||longitud<1)
    {
        pausa("ERROR DE PASAJE DE PARAMETROS EN LA FUNCION obtenerIdPeliculaValidado");
    }
    else
    {
        imprimirTitulosDePelicula(lista,longitud,1);
        getString("Ingrese el numero que acompaña al titulo de la pelicula por favor",aux);
        while(!esNumeroNatural(aux,10)||(buscarIndicePorId(lista,longitud,atoi(aux))==-1))
        {
            if(reingresarDatos("ERROR. Debe ingresar un numero que pertenezca a la lista impresa en pantalla","Desesa reingresar? S/N")=='s')
            {
                imprimirTitulosDePelicula(lista,longitud,1);
                getString("Reingrese el numero que acompaña al titulo de la pelicula por favor",aux);
            }
            else
            {
                system("cls");
                break;
            }
        }
    }
    return buscarIndicePorId(lista,longitud,atoi(aux));
}

int modificarPelicula(Movie* lista, int longitud)
{
    int retorno=1;
    int indice;
    Movie auxiliar;
    if(lista==NULL||longitud<1)
    {
        puts("ERROR EN EL PASAJE DE PARAMETROS EN FUNCION modificarPelicula");
        retorno=0;
    }
    if(retorno)
    {
        indice=buscarPrimerIndiceDePeliculas(lista,longitud,1);
        if(indice==-1)
        {
            pausa("No hay ninguna pelicula agregada hasta el momento");
            retorno=0;
        }
    }
    if(retorno)
    {
        actualizarId(lista,longitud);
        indice=obtenerIdPeliculaValidado(lista,longitud);
        if(indice==-1)  retorno=0;
    }
    if(retorno)
    {
        printf("Usted va a modificar a la pelicula de titulo: %s",lista[indice].titulo);
        if(reingresarDatos("Esta seguro de modificarla?","Presione 's' para confirmar otra tecla para regresar al menu")=='s')
        {
                    if(!obtenerTituloValidado(lista,longitud,0,auxiliar.titulo))
                    retorno=0;
                    if(retorno)
                    {
                        if(!obtenerGeneroValidado(lista,longitud,auxiliar.genero))
                            retorno=0;
                    }
                    if(retorno)
                    {
                        if(!obtenerDescripcionValidada(lista,longitud,0,auxiliar.descripcion))
                            retorno=0;
                    }
                    if(retorno)
                    {
                        if(!obtenerDuracionValidada(lista,longitud,0,&auxiliar.duracion))
                            retorno=0;
                    }
                    if(retorno)
                    {
                        if(!obtenerLinkValidado(lista,longitud,auxiliar.linkImagen))
                            retorno=0;
                    }
                    if(retorno)
                    {
                        if(!obtenerPuntajeValidado(lista,longitud,&auxiliar.puntaje))
                            retorno=0;
                        else
                        {
                            strcpy(lista[indice].descripcion,auxiliar.descripcion);
                            strcpy(lista[indice].titulo,auxiliar.titulo);
                            strcpy(lista[indice].genero,auxiliar.genero);
                            strcpy(lista[indice].linkImagen,auxiliar.linkImagen);
                            lista[indice].duracion=auxiliar.duracion;
                            lista[indice].puntaje=auxiliar.puntaje;
                        }
                    }
        }
        else
        {
            puts("Accion cancelada");
            retorno=0;
        }
    }
    return retorno;
}

void generarPagina(Movie lista[], char nombre[],int longitud)
{
    FILE* archivo;
    int i;
        archivo=fopen(nombre,"wb");
        fprintf(archivo,"<!DOCTYPE html>\n<html>\n<head>\n<title>Trabajo Practico Nº3</title>\n</head>\n<body><article class='col-md-4 article-intro'>");
        for(i=0;i<longitud;i++)
        {
            if(lista[i].estado!=1)
            {
                continue;
            }
            fprintf(archivo,"<a href='#'><h3>%s</h3></a>",lista[i].titulo);
            fprintf(archivo," <img class='img-responsive img-rounded' src=' %s 'alt=''>",lista[i].linkImagen);
            fprintf(archivo,"<ul><li>Genero:%s</li>",lista[i].genero);
            fprintf(archivo,"<li>Puntaje:%d</li>",lista[i].puntaje);
            fprintf(archivo,"<li>Duracion:%d minutos</li></ul>",lista[i].duracion);
            fprintf(archivo,"<p>%s</p>",lista[i].descripcion);
        }
        fprintf(archivo,"</article></body></html>");
        fclose(archivo);
}

int cargarArchivosPeliculas(Movie* peli, int longitud)
{
	FILE* archivo;
	int i=0, retorno=0;
	archivo = fopen("ArchivoPelis.dat", "rb");
	if(archivo==NULL)
    {
		printf("\n No existe el archivo %s.\n\n","ArchivoPelis.dat");
		system("pause");
		//exit(1);
		//retorno== NULL;
        retorno=-1;
	}
	if(retorno!=-1)
	{
	    while(!feof(archivo))
        {
            fread(&peli[i], sizeof(Movie), 1,archivo);
//            fscanf(archivo,"%d[^\n]\n",&peli[i].estado);
//            if(peli[i].estado==1)
//            {
//                fscanf(archivo,"%[^\n]\n",peli[i].titulo);
//                fscanf(archivo,"%[^\n]\n",peli[i].genero);
//                fscanf(archivo,"%[^\n]\n",peli[i].descripcion);
//                fscanf(archivo,"%[^\n]\n",peli[i].linkImagen);
//                fscanf(archivo,"%d[^\n]\n",&peli[i].duracion);
//                fscanf(archivo,"%d[^\n]\n",&peli[i].puntaje);
//                peli[i].estado=1;
//            }
                i++;
        }
        fclose(archivo);
	}

	return retorno;
}

int guardarDatos(Movie* movie, int longitud)
{
	FILE* archivo;
	int i;
	archivo = fopen("ArchivoPelis.dat", "wb");
	if(archivo==NULL)
    {
		printf("\n No se pudo guardar el archivo %s.\n\n", "ArchivoPelis.dat");
		system("pause");
		exit(1);
		return 0;
	}
	for(i=0;i<longitud;i++)
    {
        if(movie[i].estado==1)
        {fwrite(&movie[i], sizeof(Movie), 1, archivo);}
//        fprintf(archivo,"%d\n",movie[i].estado);
//        fprintf(archivo,"%s\n",movie[i].titulo);
//        fprintf(archivo,"%s\n",movie[i].genero);
//        fprintf(archivo,"%s\n",movie[i].descripcion);
//        fprintf(archivo,"%s\n",movie[i].linkImagen);
//        fprintf(archivo,"%d\n",movie[i].duracion);
//        fprintf(archivo,"%d\n",movie[i].puntaje);
   }
    fclose(archivo);
	return 1;
}
