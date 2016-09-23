#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

int validarMenu (char message[],char errorMensaje[]);

void getString (char message[],char entrada[]);

int validarNumero(char numeros[],int limite);

int validarLetras(char letras[],int limite);

int validarEntero(int x,int desde,int hasta);

void inicializaArrayPersonas(EPersona arrayPersonas[], int longitudArray, int vacio);

int obtenerEspacioLibre(EPersona lista[], int cantidadArray);

int buscarPorDni(EPersona lista[],int dni, int cantidadLista);

#endif // FUNCIONES_H_INCLUDED
