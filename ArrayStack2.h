#ifndef _ARRAYSTACK2_H
#define _ARRAYSTACK2_H

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100

#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct _Stack{
    Data stackArr[STACK_LEN];
    int topIndex;
}Stack;

void StackInit(Stack* pstack);
int IsEmpty(Stack* pstack);

void Push(Stack* pstack, Data data);
Data Pop(Stack* pstack);
Data Peek(Stack* pstack);

#endif