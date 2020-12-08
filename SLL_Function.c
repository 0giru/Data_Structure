#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int Data;
    struct _Node* nextNode;
}Node;

//Function Create New Node
Node* SLL_CreateNode(int newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    newNode->Data = newData;
    newNode->nextNode = NULL;

    return newNode; //위의 동작을 마치고 Node 구조체 포인터(새로운 노드의 주소) 반환
}

//Function Destroy Node
void SLL_Destroy(Node* Node) {
    free(Node);
 }

//Function Append Node to List
void SLL_AppendNode(Node** Head, Node* newNode) {
    if ((*Head) == NULL) {
        *Head = newNode;
    }
    else {
        Node* Tail = (*Head);
        while (Tail->nextNode != NULL) {
            Tail = Tail->nextNode;
        }
        Tail->nextNode = newNode;
    }
}

//Search Node
Node* SLL_GetNodeAt(Node* Head, int Location) {
    Node* Current = Head;

    while ((Current != NULL) && ((--Location) >= 0)) {
        Current = Current->nextNode;
    }
    return Current;
}

//Delete Node
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

//Insert Node
void SLL_InsertAfter(Node* Current, Node* newNode) {
    newNode->nextNode = Current->nextNode;
    Current->nextNode = newNode;

}

//Calculate Node Number
int SLL_GetNodeCount(Node* Head) {
    int count = 0;
    Node* Current = Head;
    while (Current != NULL) {
        Current = Current->nextNode;
        count++;
    }
    return count;
}