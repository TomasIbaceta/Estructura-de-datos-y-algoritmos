#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"
#define MAX_STRING_SIZE 50

void encrypt(char* str, char*);

int main() {
    char buffer_linea[MAX_STRING_SIZE];
    char nombre[MAX_STRING_SIZE];
    char apellido[MAX_STRING_SIZE];
    int nota;
    char buffer_encriptacion[MAX_STRING_SIZE];
    
    stack_base* s1 = getNewStack(STACK_MAX_SIZE);
    
    // Se extrae una linea del archivo
    FILE *fp;
    fp = fopen("C:/Users/toman/OneDrive/Documents/GitHub/Estructura-de-datos-y-algoritmos/EDA_tarea1/notas-EDA-C1.txt","r"); //abre el archivo
    if(fp == NULL) {
      printf("Error in opening file");
      return(-1);
   }
   
    while(!feof(fp)){ //lee todo el archivo hasta el EOF
        fscanf(fp,"%s",&buffer_linea); //toma una nueva linea y la guarda en buffer_linea
        char* token = NULL;
        
        token = strtok(buffer_linea,","); //prepara la linea para analisis
        for(int i = 1; token!=NULL; i++){ //analiza la linea
            if (i == 1){ //si token es el nombre, guardalo en nombre
                encrypt(token, buffer_encriptacion);
                strcpy(nombre, buffer_encriptacion);
            }
            else if(i == 2){ //si token es el apellido, guardalo en apellido
                encrypt(token, buffer_encriptacion);
                strcpy(apellido, buffer_encriptacion);
            }
            else if(i==3){ //token es la nota, guardalo en nota
                nota = atoi(token);
                stackPush(s1,nota,nombre,apellido); //una vez que tenemos nombre, apellido y nota, subimos los datos al stack. 
            }
            token = strtok(NULL,",");
        }    
    }

    stackPrint(s1); //muestra todo el stack en pantalla.
    fclose(fp);
    return 0;
}

void encrypt(char* str, char* buffer_encriptacion){

    
    /****************************************
        1	2	3	4	5 (col)
    1	A	B	C	D	E
    2	F	G	H	(I, J)	K
    3	L	M	N	O	P
    4	Q	R	S	T	U
    5	V	W	X	Y	Z
    (row)
    ******************************************/
    char cuadrado_de_polibio[5][5] = {
        {'A','B','C','D','E'},
        {'F','G','H','I','K'},
        {'L','M','N','O','P'},
        {'Q','R','S','T','U'},
        {'V','W','X','Y','Z'},
    };
    
    if(strlen(str) >= MAX_STRING_SIZE){ //prevencion error de overflow.
        printf("error (encrypt): overflow string buffer");
        return;
    }
    int mensaje_encriptado[MAX_STRING_SIZE];
    for (int i=0; i<MAX_STRING_SIZE;i++){ //inicializa el arreglo en -1
        mensaje_encriptado[i] = -1;
    } 
       
    for(int i=0; i<strlen(str);i++){ //recorre cada letra de str
        for (int j=0; j<5; j++){ //por cada fila
            for(int k=0; k<5; k++){ //por cada columna
                if( (char)toupper(str[i]) == cuadrado_de_polibio [j][k]){
                    mensaje_encriptado[i] = ((j+1)*10 + (k+1)); //(4,5) a (40+5) a 45
                }
            }
        }
        if (mensaje_encriptado[i] == -1){
            mensaje_encriptado[i] = 0;
        }
    }
    
    strcpy(buffer_encriptacion,"");
    char snum[8];
    for (int i=0; mensaje_encriptado[i] != -1;i++){
        snprintf(snum,4,"%d", mensaje_encriptado[i]);
        strcat(buffer_encriptacion, snum);
    }     
}

