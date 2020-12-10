#include "CircularLinkedList.h"

int main(){

    int Count = 0;
    Node* List = NULL;
    Node* Current = NULL;
    Node* NewNode = NULL;

    for(int i=0;i<5;i++){
        NewNode = CLL_CreateNode(i);
        CLL_AppendNode(&List, NewNode);
    }

    Count = CLL_GetNodeCount(List);

    for(int i=0;i<Count;i++){
        Current = CLL_GetNodeAt(List, i);
        printf("List[%d] is %d\n", i, Current -> Data); 
    }

    printf("\nInsert 3000 after Node[2]\n\n");

    Current = CLL_GetNodeAt(List, 2);
    NewNode = CLL_CreateNode(3000);
    CLL_InsertAfter(Current, NewNode);

    Count = CLL_GetNodeCount(List);

    for(int i=0;i<Count;i++){
        Current = CLL_GetNodeAt(List, i);
        printf("List[%d] is %d\n", i, Current -> Data);   
    }

    printf("\nChecking List's Circularity\n\n");

    for(int i=0;i<3*Count;i++){
        Current = CLL_GetNodeAt(List, i);
        printf("List[%d] is %d\n", i, Current -> Data);   
    }

    printf("\nDestroy all Nodes is list");

    Count = CLL_GetNodeCount(List);

    for(int i=0;i<Count;i++){
        Current = CLL_GetNodeAt(List, 0);
        CLL_RemoveNode(&List, Current);
        CLL_Destroy(Current);
    }

    return 0;
}