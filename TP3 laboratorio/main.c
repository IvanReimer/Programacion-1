#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"
#define CANTPELIS 10
int main()
{
    char seguir='s';
    int opcion=0;
    Movie movies[CANTPELIS];
    inicializarEstadoDePeliculas(movies,CANTPELIS,0);
    cargarArchivosPeliculas(movies,CANTPELIS);
    while(seguir=='s')
    {
        menu(&opcion);
        switch(opcion)
        {
            case 1:
                if(agregarPelicula(movies,CANTPELIS))
                {
                    system("cls");
                    puts("Pelicula cargada exitosamente.");
                }
                break;
            case 2:
                modificarPelicula(movies,CANTPELIS);
                break;
            case 3:
                system("cls");
                if(borrarPelicula(movies,CANTPELIS)==1)
                {
                    system("cls");
                    puts("Pelicula eliminada exitosamente");
                }
               break;
            case 4:
                guardarDatos(movies, CANTPELIS);
                generarPagina(movies,"PaginaWebTP3.html",CANTPELIS);
                pausa("Pagina generada correctamente");
                break;
            case 5:
                guardarDatos(movies, CANTPELIS);
                seguir = 'n';
                break;
        }
    }
    return 0;
}
