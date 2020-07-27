/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "stack.h"

void stackPush(stack_base* s, int nota, char* nombre, char* apellido){
    nodo *p_nuevo_nodo,*aux;
    
    p_nuevo_nodo=(nodo*)malloc(sizeof(nodo));
    strcpy(p_nuevo_nodo->nombre, nombre);
    strcpy(p_nuevo_nodo->apellido, apellido);
    p_nuevo_nodo->nota=nota;
    p_nuevo_nodo->previous=NULL;
    p_nuevo_nodo->next=NULL;
    
    if(s->base == NULL) //La lista esta vacia
        s->base = p_nuevo_nodo;
    else if(stackIsFull(s)){
        printf("ERROR: Stack is full\n");
        return;
    }
    else{
        s->stack_current_size++;
        aux = s->base;
        while(aux->next != NULL){
        aux = aux->next;
        } //recorre hasta el final del arreglo
        aux->next = p_nuevo_nodo;
        p_nuevo_nodo->previous = aux;  
    }
    return;
}

void stackPop(stack_base* s){

    if(stackIsEmpty(s)){
      s->base=NULL;
    }
    else if(s->base->next==NULL){
        free(s->base);
    }
    else{
        nodo* aux;
        nodo* todelete = s->base;
        
        while(todelete->next != NULL){
        todelete = todelete->next;
        } //llevar todelete al final
        aux=todelete->previous;

        free(todelete);
        aux->next=NULL;
        s->stack_current_size--;
    }
    return;
}

void stackPrint(stack_base* p){
    nodo *s;
    s = p->base;
    if (stackIsEmpty(p) || p->base == NULL){
        printf("STACK VACIADO");
        return;
    }
        
    else{
        while(s->next != NULL){
        s = s->next;
        } //recorre hasta el final del arreglo
        do{
            printf("nombre: %s\n",s->nombre);
            printf("apellido: %s\n",s->apellido);
            printf("nota: %d\n",s->nota);
            s = s->previous;
        }while(s != NULL);
    }
    printf("---\n");
}

void stackDelete(stack_base* s){
    while(s->base!=NULL){
        stackPop(s);
    }
    return;
}

int stackIsEmpty(stack_base* s){
    if(s->stack_current_size == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int stackIsFull(stack_base* s){
    if (s->stack_current_size >= s->stack_size){
        return 1;
    }
    else {
        return 0;
    }
}

stack_base* getNewStack (int stack_size){
    stack_base* pt = (stack_base*)malloc(sizeof(stack_base));
    pt->base=NULL;
    pt->stack_size = stack_size;
    pt->stack_current_size = 0;
    return pt;
}