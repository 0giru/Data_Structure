#include "SingleLinkedList.h"

Node* SLL_CreateNode(ElementType NewData) {
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->nextNode = NULL;

    return NewNode;
}

void SLL_DestroyNode(Node* Node) {
    free(Node);
}

void SLL_AppendNode(Node** Head, Node* NewNode) {
    //if list is NULL, New Node becomes Head
    if (*Head == NULL) {
        *Head = NewNode;
    }
    else {
        Node* Tail = *Head;
        while (Tail->nextNode != NULL) {
            Tail = Tail->nextNode;
        }
        Tail->nextNode = NewNode;
    }
}

void SLL_InsertNode(Node* Current, Node* NewNode) {
    NewNode->nextNode = Current->nextNode;
    Current->nextNode = NewNode;
}

void SLL_InsertNewHead(Node** Head, Node* NewHead) {
    if (*Head == NULL) {
        *Head = NewHead;
    }
    else {
        NewHead->nextNode = *Head;
        *Head = NewHead;
    }
}

Node* SLL_GetNodeAt(Node* Head, int Location) {
    Node* Current = Head;

    while ((Current != NULL) && ((--Location) >= 0)) {
        Current = Current->nextNode;
    }
    return Current;
}

int SLL_GetNodeCount(Node* Head) {
    int count = 0;
    Node* Current = Head;

    while (Current != NULL) {
        Current = Current->nextNode;
        count++;
    }
    return count;
}

void SLL_RemoveNode(Node** Head, Node* Remove) {
    if (*Head == Remove) {
        *Head = Remove->nextNode;
    }
    else {
        Node* Current = *Head;
        while (Current != NULL && Current->nextNode != Remove) {
            Current = Current->nextNode;
        }
        if (Current != NULL) {
            Current->nextNode = Remove->nextNode;
        }
    }
}
