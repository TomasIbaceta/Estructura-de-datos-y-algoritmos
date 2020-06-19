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
void * push (void * );
void * eliminar(void * );
void mostrarasc(void * );

int main(){
    void *p=NULL; //cabeza
    int eleccion;
    do{
        eleccion=menu();
        switch(eleccion){
            case 1:p=push(p);continue;
            case 2:p=eliminar(p);break;
            case 3:mostrarasc(p);continue;
            default:printf("FIN DE LAS OPERACIONES");
        }
    }while(eleccion<4);
    return 0;
}

int menu(){
    int eleccion;
    do{
        printf("\n\t\tMENU PRINCIPAL\n");
        printf("\t1.-Push on stack\n");
        printf("\t2.-Eliminar un elemento de la lista\n");
        printf("\t3.-Mostrar ascendente\n");
        printf("\t4.-Salir\n");
        scanf("%d",&eleccion);
    }while(eleccion<1||eleccion>5);
    printf("\n--------------\n");
    
    return(eleccion);
}

void *push(void *head){
    nodo *nuevo_nodo,*aux;
    int x;
    putchar('\n');
    printf("Indica el valor a introducir a la lista=>");
    scanf("%d",&x);
    nuevo_nodo=(nodo*)malloc(sizeof(nodo));
    nuevo_nodo->nombre[0]='\0';
    nuevo_nodo->apellido[0]='\0';
    nuevo_nodo->nota=x;
    nuevo_nodo->izq=NULL;
    nuevo_nodo->der=NULL;
    
    if(head==NULL) //La lista esta vacia
        head=nuevo_nodo;
    else{
        aux=(nodo*)head;
        nuevo_nodo->der=aux;
        aux->izq=nuevo_nodo;
        head=nuevo_nodo;   
    }
    return(head);
}

void * eliminar(void * s){
    if(s==NULL)
        printf("\nLISTA VACIA\n");
    else{
        nodo *p,* aux,*aux1;
        int x;
        printf("Da el elemento a eliminar=>");
        scanf("%d",&x);
        aux=p=(nodo*)s;
        if(p->der==NULL && aux->nota==x) //solo hay un elemento en la lista
            s=NULL;
        else {
            while(p->der!=NULL && p->nota<x){
                aux=p;
                p=p->der;
            }
            if (p!=NULL){
                if (p->nota==x && p==s){ //No existio movimiento
                    s=aux1=p->der;
                    if(aux1!=NULL)
                        aux1->izq=NULL;
                }
                else if(p->nota==x){
                    aux1=aux->der=p->der;
                    if (aux1!=NULL)
                        aux1->izq=aux;
                }
                else
                    printf("DATO NO LOCALIZADO\n");
            }
            else
                printf("DATO NO ENCOTRADO\n");
        }
    free(p);
    }
    
    return(s);
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