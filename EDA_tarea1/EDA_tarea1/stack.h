/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   stack.h
 * Author: toman
 *
 * Created on June 19, 2020, 11:03 PM
 */

#ifndef STACK_H
#define STACK_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NLEN 30
#define STACK_MAX_SIZE 50

typedef struct nd{
    char nombre[NLEN];
    char apellido[NLEN];
    int nota;
    struct nd * previous; //equivalente a left en ABB
    struct nd * next; //equivalente a right en ABB
}nodo;

typedef struct stack_base{
    nodo* base;
    int stack_size;
    int stack_current_size;
}stack_base;

//PROTOTIPOS
int menu();
stack_base* getNewStack (int stack_size);
void stackPush(stack_base*,int,char*,char*);
void stackPop(stack_base*);
void stackDelete(stack_base*);
void stackPrint(stack_base*);
int stackIsEmpty(stack_base*);
int stackIsFull(stack_base*);


#ifdef __cplusplus
}
#endif

#endif /* STACK_H */

