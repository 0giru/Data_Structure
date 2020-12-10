#include "DoubleLinkedList.h"

//새로운 노드 생성
Node* DLL_CreateNode(int newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->Data = newData;
    newNode->nextNode = NULL;
    newNode->prevNode = NULL;
    return newNode;
}

void DLL_Destroy(Node* Node) {
    free(Node);
}

//리스트에 노드 추가
void DLL_AppendNode(Node** Head, Node* newNode) {
    if ((*Head) == NULL) {
        *Head = newNode;
    }
    else {
        Node* Tail = (*Head);
        while (Tail->nextNode != NULL) {
            Tail = Tail->nextNode;
        }
        Tail->nextNode = newNode;
        newNode->prevNode = Tail;

    }
}

Node* DLL_GetNodeAt(Node* Head, int Location) {
    Node* Current = Head;

    while ((Current != NULL) && ((--Location) >= 0)) {
        Current = Current->nextNode;
    }
    return Current;
}

void DLL_RemoveNode(Node** Head, Node* Remove) {
    if (*Head == Remove) {
        *Head = Remove->nextNode;
        if((*Head) != NULL){
            (*Head)->prevNode = NULL;
        }
        Remove -> nextNode = NULL;
        Remove -> prevNode = NULL;
    }
    else {
        Remove -> prevNode -> nextNode = Remove -> nextNode;
        if(Remove -> nextNode != NULL){
            Remove -> nextNode -> prevNode = Remove -> prevNode;
        }
        Remove -> prevNode = NULL;
        Remove -> nextNode = NULL;
    }
}

void DLL_InsertAfter(Node* Current, Node* newNode){
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

int DLL_GetNodeCount(Node* Head){
    unsigned int count = 0;
    Node* Current = Head;

    while(Current != NULL){
        Current = Current -> nextNode;
        count++;
    }
    return count;
}