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

typedef struct nd{
    char nombre[NLEN];
    char apellido[NLEN];
    int nota;
    struct nd * previous; //equivalente a left en ABB
    struct nd * next; //equivalente a right en ABB
}nodo;

//PROTOTIPOS
int menu();
nodo* stackPush (nodo*);
nodo* stackPop(nodo*);
void stackDelete(nodo*);
void stackPrint(nodo*);

int main(){
    nodo* p=NULL; //cabeza
    int eleccion;
    do{
        eleccion=menu();
        switch(eleccion){
            case 1:p=stackPush(p);continue;
            case 2:p=stackPop(p);break;
            case 3:stackPrint(p);continue;
            case 4:stackDelete(p);continue;
            default:printf("FIN DE LAS OPERACIONES");
        }
    }while(eleccion<5);
    return 0;
}

int menu(){
    int eleccion;
    do{
        printf("\n\tMENU PRINCIPAL: ");
        printf("\t1.-Push stack /");
        printf("\t2.-Pop stack /");
        printf("\t3.-Stack print/");
        printf("\t4.-Stack delete/");
        printf("\t5.-Salir\n\t");
        scanf("%d",&eleccion);
    }while(eleccion<1||eleccion>5);
    printf("--------------\n");
    
    return(eleccion);
}

nodo *stackPush(nodo *head){
    nodo *p_nuevo_nodo,*aux;
    int x;
    putchar('\n');
    printf("Indica el valor a introducir a la lista=>");
    scanf("%d",&x);
    
    p_nuevo_nodo=(nodo*)malloc(sizeof(nodo));
    p_nuevo_nodo->nombre[0]='\0';
    p_nuevo_nodo->apellido[0]='\0';
    p_nuevo_nodo->nota=x;
    p_nuevo_nodo->previous=NULL;
    p_nuevo_nodo->next=NULL;
    
    if(head==NULL) //La lista esta vacia
        head=p_nuevo_nodo;
    else{
        aux = head;
        p_nuevo_nodo->next=aux;
        aux->previous=p_nuevo_nodo;
        head=p_nuevo_nodo;   
    }
    return(head);
}

nodo* stackPop(nodo* s){
    if(s==NULL)
        printf("\nLISTA VACIA\n");
    else{
        nodo *p;
        p=s;
        if((p->next) == NULL){
            p=NULL;
            free(s);
            printf("lista ahora vacía\n");
            return p;
        }
        else{
            p=p->next;
            free(s);
            stackPrint(p);
        }   
        return(p);
    }
}

void stackPrint(nodo* p){
    nodo *s;
    s=(nodo *)p;
    if (p==NULL)
        printf("LISTA VACIA");
    else
        do{
            printf("%d\n",s->nota);
            s=s->next;
        }while(s!=NULL);
        printf("---\n");
}

void stackDelete(nodo* p){
    while(p!=NULL){
        p=stackPop(p);
    }
    return;
}