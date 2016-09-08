#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int validar;
    while(seguir=='s')
    {
        validar=validaropcion(validar);
        switch(validar)
        {
            case 1:
                printf("1\n\n\n");
                break;
            case 2:
                printf("2\n");
                break;
            case 3:
                printf("3\n");
                break;
            case 4:
                printf("4\n");
                break;
            case 5:
                printf("5\n");
                break;
            case 6:
                printf("6\n");
                break;
            case 7:
                printf("7\n");
                break;
            case 8:
                printf("8\n");
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }
    return 0;
}

