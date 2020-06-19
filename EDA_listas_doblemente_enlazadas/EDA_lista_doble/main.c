/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListasDoblementeEnlazadasOrdenadas.c
 * Author: ferna
 *
 * Created on 12 de mayo de 2020, 22:21
 */

#include<stdio.h>
#include<stdlib.h>
#define NLEN 10

typedef struct Elemento{
    char nombre[NLEN];
    char apellido[NLEN];
    int nota;
    struct Elemento * izq;
    struct Elemento * der;
}nodo;


/*
typedef struct nd {
char nombre[NLEN];
char apellido[NLEN];
int nota;
struct nd *previous; //equivalente a left en ABB
struct nd *next; //equivalente a right en ABB
}nodo2;
*/

//PROTOTIPOS
int menu();
nodo *push (nodo *);
nodo *pop(nodo*);
void mostrarasc(void *);

int main(){
    nodo* p=NULL; //cabeza
    int eleccion;
    do{
        eleccion=menu();
        switch(eleccion){
            case 1:p=push(p);continue;
            case 2:p=pop(p);break;
            case 3:mostrarasc(p);continue;
            default:printf("FIN DE LAS OPERACIONES");
        }
    }while(eleccion<4);
    return 0;
}

int menu(){
    int eleccion;
    do{
        printf("\n\t\tMENU PRINCIPAL: ");
        printf("\t1.-Push stack /");
        printf("\t2.-pop stack /");
        printf("\t3.-Mostrar ascendente /");
        printf("\t4.-Salir\n");
        scanf("%d",&eleccion);
    }while(eleccion<1||eleccion>5);
    printf("\n--------------\n");
    
    return(eleccion);
}

nodo *push(nodo *head){
    nodo *p_nuevo_nodo,*aux;
    int x;
    putchar('\n');
    printf("Indica el valor a introducir a la lista=>");
    scanf("%d",&x);
    
    p_nuevo_nodo=(nodo*)malloc(sizeof(nodo));
    p_nuevo_nodo->nombre[0]='\0';
    p_nuevo_nodo->apellido[0]='\0';
    p_nuevo_nodo->nota=x;
    p_nuevo_nodo->izq=NULL;
    p_nuevo_nodo->der=NULL;
    
    if(head==NULL) //La lista esta vacia
        head=p_nuevo_nodo;
    else{
        aux = head;
        p_nuevo_nodo->der=aux;
        aux->izq=p_nuevo_nodo;
        head=p_nuevo_nodo;   
    }
    return(head);
}

nodo* pop(nodo* s){
    if(s==NULL)
        printf("\nLISTA VACIA\n");
    else{
        nodo *p;
        p=s;
        p=p->der;
        free(s);
        return(p);
    }
}

void mostrarasc(void *p){
    nodo *s;
    s=(nodo *)p;
    if (p==NULL)
        printf("LISTA VACIA");
    else
        do{
            printf("%d\n",s->nota);
            s=s->der;
        }while(s!=NULL);
        printf("---\n");
}