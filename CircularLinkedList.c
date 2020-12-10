#include "CircularLinkedList.h"

Node* CLL_CreateNode(int newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->Data = newData;
    newNode->nextNode = NULL;
    newNode->prevNode = NULL;
    return newNode;
}

void CLL_Destroy(Node* Node) {
    free(Node);
}

void CLL_AppendNode(Node** Head, Node* newNode) {
    if ((*Head) == NULL) {
        (*Head) = newNode;
        (*Head) -> nextNode = (*Head);
        (*Head) -> prevNode = (*Head);
    }
    else {
        Node* Tail = (*Head);
        while (Tail->nextNode != (*Head)) {
            Tail = Tail->nextNode;
        }
        Tail->nextNode = newNode;
        newNode -> prevNode = Tail;
        newNode -> nextNode = (*Head);
        (*Head) -> prevNode = newNode;
    }
}

Node* CLL_GetNodeAt(Node* Head, int Location) {
    Node* Current = Head;

    while ((Current != NULL) && ((--Location) >= 0)) {
        Current = Current->nextNode;
    }
    return Current;
}

void CLL_RemoveNode(Node** Head, Node* Remove) {
    if (*Head == Remove) {
        (*Head) -> nextNode -> prevNode = (*Head) -> prevNode;
        (*Head) -> prevNode -> nextNode = (*Head) -> nextNode;

        (*Head) = Remove -> nextNode;

        Remove -> nextNode = NULL;
        Remove -> prevNode = NULL;
    }
    else {
        Remove -> prevNode -> nextNode = Remove -> nextNode;
        Remove -> nextNode -> prevNode = Remove -> prevNode;

        Remove -> nextNode = NULL;
        Remove -> prevNode = NULL;
    }
}

void CLL_InsertAfter(Node* Current, Node* newNode){
    newNode -> nextNode = Current -> nextNode;
    newNode -> prevNode = Current;

    if(Current -> nextNode != NULL){
        Current -> nextNode -> prevNode = newNode;
        Current -> nextNode = newNode;
    }
    else{
        Current -> nextNode = newNode;
    }
}

int CLL_GetNodeCount(Node* Head){
    unsigned int count = 0;
    Node* Current = Head;

    while(Current != NULL){
        Current = Current -> nextNode;
        count++;
        if(Current == Head){
            break;
        }
    }
    return count;
}