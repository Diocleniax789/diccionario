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



    return 0;
}
