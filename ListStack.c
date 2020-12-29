// ListStack ver.1
#include "ListStack.h"

void LS_CreateStack(ListStack** Stack){
    (*Stack) = (ListStack*)malloc(sizeof(ListStack));
    (*Stack) -> List = NULL;
    (*Stack) -> Top = NULL;
}

void LS_DestroyStack(ListStack* Stack){
    while(!LS_IsEmpty(Stack)){
        Node* Popped = LS_Pop(Stack);
        LS_DestroyNode(Popped);
    }
    free(Stack);
}

Node* LS_CreateNode(char* NewData){
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode -> Data = (char*)malloc(strlen(NewData) + 1);
    strcpy(NewNode -> Data, NewData);
    NewNode -> NextNode = NULL;
    return NewNode;
}

void LS_DestroyNode(Node* _Node){
    free(_Node -> Data);
    free(_Node);
}

void LS_Push(ListStack* Stack, Node* NewNode){
    if(Stack -> List == NULL){
        Stack -> List = NewNode;
    }
    else{
        Node* Old = Stack -> List;
        while(Old -> NextNode != NULL){
            Old = Old -> NextNode;
        }
        Old -> NextNode = NewNode;
    }
    Stack -> Top = NewNode;
}

Node* LS_Pop(ListStack* Stack){
    Node* TopNode = Stack -> Top;

    if(Stack -> List == Stack -> Top){
        Stack -> Top == NULL;
        Stack -> List == NULL;
    }
    else{
        Node* CurTop = Stack -> List;
        while(CurTop != NULL && CurTop -> NextNode != Stack -> Top){
            CurTop = CurTop -> NextNode;
        }
        Stack -> Top = CurTop;
        CurTop -> NextNode = NULL;
    }
    return TopNode;
}

int LS_IsEmpty(ListStack* Stack){
    return (Stack -> List == NULL);
}

int LS_GetSize(ListStack* Stack){
    int count = 0;
    Node* Current = Stack -> List;

    while(Current != NULL){
        Current = Current -> NextNode;
        count++;
    }
    return count;
}

Node* LS_Top(ListStack* Stack){
    return Stack -> Top;
}