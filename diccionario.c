#include <stdio.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>

struct palabras{
    char pal[20];
    int pos;
};

char * carga(int*);
struct palabras * separa(char*,int,int*);
int diccionario(char[500][20]);
struct palabras * corrector(struct palabras*,int,char dic[500][20],int);

int main(){
    char *texto;
    int cant_caracteres = 0, cant_palabras_separadas = 0,i;
    struct palabras *todas_las_palabras;

    texto = carga(&cant_caracteres);
    todas_las_palabras = separa(texto,cant_caracteres,&cant_palabras_separadas);

   /* for(i = 0; i < cant_palabras_separadas; i++){
        printf("\n Palabra: %s",todas_las_palabras[i].pal);
        printf("\n Posicion: %i",todas_las_palabras[i].pos);
        printf("\n");
    }*/


    return 0;
}

char * carga(int *cant_caracteres){
    char caracter;
    static char texto[1000];
    int i = 0;

    printf("\n - CARGA DEL TEXTO - \n");
    printf("\n");
    printf("\n + Escriba aqui su texto <Presione crtl + c para finzalizar> : ");
    while((caracter = getchar()) != EOF && i < 1000){
        texto[i] = caracter;
        i++;
        (*cant_caracteres)++;
    }

    texto[i] = '\0';

    printf("\n * TEXTO CARGADO * \n");
    return texto;
}

struct palabras * separa(char *texto,int cant_caracteres,int *cant_palabras_separadas){
    static struct palabras todas_las_palabras[500];
    char palabra[20] = {0};
    int i,pos = 1,j = 0,k;

    for(i = 0; i < cant_caracteres; i++){
        if(texto[i] != ',' && texto[i] != '.' && texto[i] != ' ' && texto[i] != '\n' && texto[i] != '\0'){
            palabra[j] = texto[i];
            j++;
        } else{
            palabra[j] = '\0';
            j = 0;
            if(strcmp(palabra, "") != 0){
                strcpy(todas_las_palabras[*cant_palabras_separadas].pal,palabra);
                todas_las_palabras[*cant_palabras_separadas].pos = pos;
                (*cant_palabras_separadas)++;
                pos++; // a la primera palabra formada luego de asignar la primera posicion se incrementa
            }

            // reinicializa el arreglo de palabra para volver a utilizarlo
            for (k = 0; k < 20; k++) {
                palabra[k] = 0;
            }

            pos++; // en caso de que no se cumpla la condicion igualmente se incrementa, esto incrementa por posicion
        }
    }

    printf("\n SEPARANDO EL TEXTO EN PALABRAS...\n");
    Sleep(2000);
    printf("\n * TEXTO SEPARADO CON EXITO * \n");

    return todas_las_palabras;
}
