#include <stdio.h>

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
    int cant_caracteres = 0;

    texto = carga(&cant_caracteres);

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
        (*cant_caracteres)++;
    }

    texto[i] = '\0';

    printf("\n * TEXTO CARGADO * \n");

    return texto;
}
