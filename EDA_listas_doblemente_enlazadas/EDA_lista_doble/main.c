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
nodo* stackPush (nodo*, int nota);
nodo* stackPop(nodo*);
void stackDelete(nodo*);
void stackPrint(nodo*);
int stackIsEmpty(nodo*);
int stackIsFull(nodo*);

int main(){
    nodo* stack1=NULL;
    int a=4;
    stack1=stackPush(stack1, 1);
    stack1=stackPush(stack1, 4);
    stack1=stackPush(stack1, 5);
    printf("is Empty?: %d\n", a=stackIsEmpty(stack1));
    stackPrint(stack1);
    stack1=stackPop(stack1);
    stack1=stackPop(stack1);
    stack1=stackPop(stack1);
    stack1=stackPop(stack1);
    a=stackIsEmpty(stack1);
    printf("is empty??: %d\n", a);
}

nodo *stackPush(nodo *head, int nota){
    nodo *p_nuevo_nodo,*aux;
    
    p_nuevo_nodo=(nodo*)malloc(sizeof(nodo));
    p_nuevo_nodo->nombre[0]='\0';
    p_nuevo_nodo->apellido[0]='\0';
    p_nuevo_nodo->nota=nota;
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

int stackIsEmpty(nodo *s){
    if (s==NULL){
        return 0;
    }
    else{
        return 1;
    }
}
int stackIsFull(nodo *s){
    return 0; //al ser implementado como lista, siempre tendrá espacio mientras la memoria del computador no se llene.
}