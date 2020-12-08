#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;

typedef struct _Node{
    int Data;
    struct _Node* nextNode;
}Node;

Node* SLL_CreateNode(ElementType NewData);
void SLL_DestroyNode(Node* Node);
void SLL_AppendNode(Node** Head, Node* NewNode);
void SLL_InsertNode(Node* Current, Node* NewNode);
Node* SLL_GetNodeAt(Node* Head, int Location);
void RemoveNode(Node** Head, Node* Remove);
int SLL_GetNodeCount(Node* Head);

#endif 

//git commit test