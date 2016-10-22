#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct{
    char titulo[50];
    char genero[20];
    int duracion;
    char descripcion[200];
    int puntaje;
    char linkImagen[50];
    int estado;
    int id;
}Movie;
/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(Movie* lista, int longitud);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(Movie* lista, int longitud);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(Movie lista[], char nombre[],int longitud);

int inicializarEstadoDePeliculas(Movie* lista, int longitud, int);

int buscarPrimerIndiceDePeliculas(Movie* lista,int longitud,int );

void pausa(char mensaje[]);

void getString (char message[],char entrada[]);

int validarRangoDeEntero(int x,int desde,int hasta);

int esAlfaNumerico(char str[],int limite);

int sonLetrasOEspacios(char letras[],int limite);

char reingresarDatos(char eMensaje[],char pregunta[]);

int menu(int* input);

void mostrarMenu (char opciones[][100]);

int obtenerTituloValidado(Movie* lista,int longitud,int vacio, char input[]);

int buscarTituloRepetido(Movie* lista,int longitud,int valor, char input[]);

int obtenerGeneroValidado(Movie* lista,int longitud, char input[]);

int obtenerDuracionValidada(Movie* lista,int longitud,int vacio,int* input);

int obtenerDescripcionValidada(Movie* lista,int longitud,int vacio, char input[]);

int obtenerLinkValidado(Movie* lista,int longitud, char input[]);

int buscarDescripcionRepetida(Movie* lista,int longitud,int valor, char input[]);

int imprimirTitulosDePelicula(Movie* lista, int longitud, int ocupado);

int actualizarId(Movie* lista,int longitud);

int obtenerIdPeliculaValidado(Movie* lista, int longitud);

int modificarPelicula(Movie* lista, int longitud);

void leerPelicula();

int cargarArchivosPeliculas(Movie* peli, int);

int guardarDatos(Movie* movie, int longitud);
#endif // FUNCIONES_H_INCLUDED
