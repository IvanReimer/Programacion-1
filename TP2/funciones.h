#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;
int validarMenu (char message[],char errorMensaje[]);
float getFloat (char message[]);
char getChar (char message[]);
void getString (char message[],char entrada[]);
int validarNumero(char numeros[],int limite);
int validarLetras(char letras[],int limite);
int validarEntero(int x,int desde,int hasta);

/** \brief A cada persona del array personas le asigna
 *  \brief un 0 al campo estado.
 * \param El array personas de EPersona.
 * \param Es la cantidad de caracteres que posee el array.
 * \param Es el valor que se le asigna a cada persona para indicar que esta vacio.
 */
void inicializaArrayPersonas(EPersona arrayPersonas[], int longitudArray, int vacio);
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int longitudArray);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista Es el array se pasa como parametro.
 * @param dni Es el dni a ser buscado en el array.
 * @param longitudLista Es la cantidad de caracteres que posee el array que se pasa como parametro
 * @param vacio Es el valor que retorna en caso de que no exista el dni a ser buscado.
 * @return El indice en donde se encuentra el elemento que coincide con el parametro dni en caso de que lo encuentre. Sino, retorna el valor vacio.
 */
int buscarPorDni(EPersona lista[],int dni, int longitudLista);

#endif // FUNCIONES_H_INCLUDED
