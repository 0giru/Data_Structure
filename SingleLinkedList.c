#include "SingleLinkedList.h"

Node* SLL_CreateNode(ElementType NewData){
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->nextNode = NewData;
    NewNode->nextNode = NULL;
}

void SLL_DestroyNode(Node* Node){
    free(Node);
}

void SLL_AppendNode(Node** Head, Node* NewNode){
    //if list is NULL, New Node becomes Head
    if(*Head == NULL){
        *Head = NewNode;
    }
    else{
        Node* Tail = *Head;
        while(Tail->nextNode != NULL){
            Tail = Tail -> nextNode;
        }
        Tail -> nextNode = NewNode;
    }
}

void SLL_InsertNode(Node* Current, Node* NewNode){
    
}

