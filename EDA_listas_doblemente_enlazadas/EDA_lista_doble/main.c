
#include<stdio.h>
#include<stdlib.h>
#include "stack.h"




int main(){
    int a=4;
    stack_base* h = getNewStack(STACK_MAX_SIZE);
    stackPush(h, 1);
    stackPush(h, 4);
    stackPush(h, 5);
    stackPush(h, 9);
    stackPrint(h);
    stackPush(h, 7);
    stackPrint(h);

    stackPop(h);
    printf("pase el stackpop\n");
    stackPrint(h);
    stackPop(h);
    stackPrint(h);
    stackPop(h);
    stackPrint(h);
    stackPop(h);
    stackPrint(h);
    stackPop(h);
    stackPrint(h);
    a=stackIsEmpty(h);
    printf("is empty??: %d\n", a);
    return 0;
}

