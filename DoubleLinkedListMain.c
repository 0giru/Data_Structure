#include "DoubleLinkedList.h"

int main(){
    
    int Count = 0;
    Node* List = NULL;
    Node* NewNode = NULL;
    Node* Current = NULL;

    for(int i=0;i<5;i++){
        NewNode = DLL_CreateNode(i);
        DLL_AppendNode(&List, NewNode);
    }

    Count = DLL_GetNodeCount(List);

    for(int i=0;i<Count;i++){
        Current = DLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current -> Data);
    }

    printf("Insert 2000 after Node [2]\n");

    Current = DLL_GetNodeAt(List, 2);
    NewNode = DLL_CreateNode(2000);
    DLL_InsertAfter(Current, NewNode);

    Count = DLL_GetNodeCount(List);

    for(int i=0;i<Count;i++){
        Current = DLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current -> Data);
    }

    printf("Destroy all Nodes in List\n");

    Count = DLL_GetNodeCount(List);

    for(int i=0;i<Count;i++){
        Current = DLL_GetNodeAt(List, 0);
        if(Current != NULL){
            DLL_RemoveNode(&List, Current);
            DLL_Destroy(Current);
            printf("Node Destroyed\n");
        }
    }
    return 0;
}