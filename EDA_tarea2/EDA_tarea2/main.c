/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: toman
 *
 * Created on July 21, 2020, 7:10 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME_TXT "output.txt"
#define N_RANDOM_NUMBERS 100
#define N_TO_READ 10
#define MAX_RANDOM_N 1000000
#define MAX_DIGITS 7
/*
 * 
 */

void txt_random_create(char* name, int size);
void txt_read_length(char* name, int length);

int main() {
    txt_random_create(FILENAME_TXT, N_RANDOM_NUMBERS);
    txt_read_length(FILENAME_TXT, N_TO_READ);
    
    return (EXIT_SUCCESS);
}


/*
 * csv_random_create() crea y llena un TXT con N_RANDOM_NUMBERS numeros al azar entre 0 y MAX_RANDOM_N
 * 
 * NOTAS: en este computador, en este stdlib.h, MAX_RAND marca 0x7fffffff, lo que nos dice que podemos usar
 *       rand() % 1.000.000 sin complicaciones. Revisa esto cuando lo pases a aragorn, porque podría causar
 *       un error poco visible
 * FUENTES: basado en el codigo en https://www.youtube.com/watch?v=J3j04JrROFo&t=378s
 */
void txt_random_create(char* name, int size){
    FILE *fp;
    fp = fopen(name, "w");
    if (fp == NULL ){
        printf("no se pudo abrir\n");
        return;
    }
    for (int i = 0; i<size; i++){
        fprintf(fp, "%d\n", rand() % MAX_RANDOM_N);
    }
    fclose(fp);
    fp = 0;
    return;
}

void txt_read_length(char* name, int length){
    FILE *fp;
    int nota;
    fp = fopen(name, "r");
    
    char buffer_linea[MAX_DIGITS];
    for(int i=0; i<length && !(feof(fp)); i++){ //hasta que se acabe el archivo o se lean la cantidad pedida de numeros  
        if(fscanf(fp,"%s",&buffer_linea) == EOF){ //toma una nueva linea y la guarda en buffer_linea
            break; //saca del while si el ultimo \n causa error
        }
        nota = atoi(buffer_linea);
            /*
             * AQUI AGREGAR A A LA COLA
            */
        printf("%d\n", nota);
    }
}