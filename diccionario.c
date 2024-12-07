#include <stdio.h>
#include <windows.h>
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
    char *texto, diccionario_completo[500][20];
    int cant_caracteres = 0, cant_palabras_separadas = 0,cantidad_palabras_diccionario,i;
    struct palabras *todas_las_palabras;
    struct palabras *palabras_no_encontradas;

    texto = carga(&cant_caracteres);
    todas_las_palabras = separa(texto,cant_caracteres,&cant_palabras_separadas);
    cantidad_palabras_diccionario = diccionario(diccionario_completo);
    palabras_no_encontradas = corrector(todas_las_palabras,cant_palabras_separadas,diccionario_completo,cantidad_palabras_diccionario);

    system("cls");

    printf("\n *** LISTADO DE TODAS LAS PALABRAS NO ENCONTRADAS EN EL DICCIONARIO ***");
    printf("\n ======================================================================\n");
    for(i = 0; strcmp(palabras_no_encontradas[i].pal,"*****") != 0; i++){
        printf(" - Palabra: %s",palabras_no_encontradas[i].pal);
        printf(" - Posicion: %i",palabras_no_encontradas[i].pos);
        printf("\n ------------------------------------------------- \n");
    }

    system("pause");

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
                pos++; // a la primera palabra formada luego de asignar la primera posicion se la incrementa nuevamente
            }

            // reinicializa el arreglo de palabra para volver a utilizarlo
            for (k = 0; k < 20; k++) {
                palabra[k] = 0;
            }

            pos++; // en caso de que no se cumpla la condicion igualmente se incrementa otra vez, esto incrementa por posicion
        }
    }

    printf("\n SEPARANDO EL TEXTO EN PALABRAS...\n");
    Sleep(2000);
    printf("\n * TEXTO SEPARADO CON EXITO * \n");
    printf("\n");


    system("pause");
    system("cls");

    return todas_las_palabras;
}

int diccionario(char diccionario_completo[500][20]){
    int i,contador_palabras_cargadas = 0;
    char palabra[20];

    for(i = 0; i < 500; i++){
        system("cls");
        fflush(stdin);
        printf("\n # Para dejar la carga, solamente ingrese '*' # \n");
        printf("\n - Carga del diccionario - \n");
        printf("\n");
        printf("\n - Palabra nro %i",i + 1);
        printf("\n + Escriba la palabra: ");
        scanf("%s",palabra);
        if(strcmp(palabra,"*") != 0){
            strcpy(diccionario_completo[i],palabra);
            contador_palabras_cargadas++;
        } else{
            break;
        }
    }

    printf("\n * DICCIONARIO CARGADO * \n");

    return contador_palabras_cargadas;

}

struct palabras * corrector(struct palabras *todas_las_palabras,int cant_palabras_separadas,char diccionario_completo[500][20], int cantidad_palabras_diccionario){
    int i, pos, flag, cant_pal_no_enc_guardada = 0;
    static struct palabras palabras_no_encontradas[500];
    for(i = 0; i < cant_palabras_separadas; i++){
        flag = 0;
        pos = 0;
        do{
            if(strcmp(todas_las_palabras[i].pal,diccionario_completo[pos]) == 0){
                flag = 1;
                break;
            } else{
                pos++;
            }
        } while(pos < cantidad_palabras_diccionario && flag == 0);
        if(flag == 1){
            Sleep(1000);
            printf("\n x Palabra encontrada x \n");
        } else{
            Sleep(1000);
            printf("\n * Palabra no encontrada. Se la almacenara * \n");
            strcpy(palabras_no_encontradas[cant_pal_no_enc_guardada].pal,todas_las_palabras[i].pal);
            palabras_no_encontradas[cant_pal_no_enc_guardada].pos = todas_las_palabras[i].pos;
            cant_pal_no_enc_guardada++;
        }
    }

    strcpy(palabras_no_encontradas[cant_pal_no_enc_guardada].pal,"*****");

    printf("\n");
    printf("\n * TODAS LAS PALABRAS NO ENCONTRADAS YA FUERON GUARDADAS CON EXITO! * \n");
    printf("\n");

    return palabras_no_encontradas;
}

