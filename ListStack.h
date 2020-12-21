#ifndef _LISTSTACK_H
#define _LISTSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node{
    char* Data;
    struct _Node* NextNode;
}Node;

typedef struct _ListStack{
    Node* List; //first Node를 가리킴(Head)
    Node* Top; //Last Node를 가리킴(Tail)
}ListStack;

void LS_CreateStack(ListStack** Stack);
void LS_DestroyStack(ListStack* Stack);

Node* LS_CreateNode(char* NewData);
void LS_DestroyNode(Node* _Node);

void LS_Push(ListStack* Stack, Node* NewNode);
Node* LS_Pop(ListStack* Stack);

int LS_IsEmpty(ListStack* Stack);
int LS_GetSize(ListStack* Stack);
Node* LS_Top(ListStack* Stack);

#endif