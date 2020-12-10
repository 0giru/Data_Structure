#ifndef _CIRCULARLINKEDLIST_H
#define _CIRCULARLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct _Node{
    ElementType Data;
    struct _Node* nextNode;
    struct _Node* prevNode;
}Node;

Node* CLL_CreateNode(int newData);
void CLL_Destroy(Node* Node);
void CLL_AppendNode(Node** Head, Node* newNode);
Node* CLL_GetNodeAt(Node* Head, int Location);
void CLL_RemoveNode(Node** Head, Node* Remove);
void CLL_InsertAfter(Node* Current, Node* newNode);
int CLL_GetNodeCount(Node* Head);

#endif