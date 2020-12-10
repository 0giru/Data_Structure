#ifndef _DOUBLELINKEDLIST_H
#define _DOUBLELINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct _Node{
    ElementType Data;
    struct _Node* prevNode;
    struct _Node* nextNode;
}Node;

Node* DLL_CreateNode(int newData);
void DLL_Destroy(Node* Node);
void DLL_AppendNode(Node** Head, Node* newNode);
Node* DLL_GetNodeAt(Node* Head, int Location);
void DLL_RemoveNode(Node** Head, Node* Remove);
void DLL_InsertAfter(Node* Current, Node* newNode);
int DLL_GetNodeCount(Node* Head);

#endif