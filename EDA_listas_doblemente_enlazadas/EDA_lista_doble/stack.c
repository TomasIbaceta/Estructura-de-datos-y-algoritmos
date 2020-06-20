/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "stack.h"

void stackPush(stack_base* s1, int nota){
    nodo *p_nuevo_nodo,*aux;
    
    p_nuevo_nodo=(nodo*)malloc(sizeof(nodo));
    p_nuevo_nodo->nombre[0]='\0';
    p_nuevo_nodo->apellido[0]='\0';
    p_nuevo_nodo->nota=nota;
    p_nuevo_nodo->previous=NULL;
    p_nuevo_nodo->next=NULL;
    
    if(s1->base == NULL) //La lista esta vacia
        s1->base = p_nuevo_nodo;
    else{
        aux = s1->base;
        while(aux->next != NULL){
        aux = aux->next;
        } //recorre hasta el final del arreglo
        aux->next = p_nuevo_nodo;
        p_nuevo_nodo->previous = aux;  
    }
    return;
}

void stackPop(stack_base* s1){
    if(s1->base==NULL){
        printf("\nLISTA VACIA\n");
    }
    else if(s1->base->next==NULL){
        free(s1->base);
        printf("\nlista ahora vacía\n");
    }
    else{
        nodo* aux;
        nodo* todelete = s1->base;
        
        while(todelete->next != NULL){
        todelete = todelete->next;
        } //llevar todelete al final
        aux=todelete->previous;

        free(todelete);
        aux->next=NULL;
        //stackPrint(s1);
    }
    return;
}

void stackPrint(stack_base* p){
    nodo *s;
    s = p->base;
    if (p->base == NULL)
        printf("LISTA VACIA");
    else
        while(s->next != NULL){
        s = s->next;
        } //recorre hasta el final del arreglo
        do{
            printf("%d\n",s->nota);
            s = s->previous;
        }while(s != NULL);
    
        printf("---\n");
}

void stackDelete(stack_base* p){
    while(p->base!=NULL){
        stackPop(p);
    }
    free(p);
    return;
}

int stackIsEmpty(stack_base* s){
    return -1;
}

int stackIsFull(stack_base *s){
    return -1;
}

stack_base* getNewStack (int stack_size){
    stack_base* pt = (stack_base*)malloc(sizeof(stack_base));
    pt->base=NULL;
    pt->stack_size = stack_size;
    pt->stack_current_size = 0;
    return pt;
}