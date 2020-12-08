#include "SingleLinkedList.h"

int main()
{

    int Count = 0;
    Node* List = NULL; //Declare 'Node' pointer type
    Node* Current = NULL;
    Node* NewNode = NULL;

    //Create 5 Nodes
    for (int i = 0; i < 5; i++)
    {
        NewNode = SLL_CreateNode(i);
        SLL_AppendNode(&List, NewNode);
    }

    //Create Node that has -1 as Data
    NewNode = SLL_CreateNode(-1);
    SLL_InsertNewHead(&List, NewNode);

    //Create Node that has -2 as Data
    NewNode = SLL_CreateNode(-2);
    SLL_InsertNewHead(&List, NewNode);

    //Get Number of Nodes in List
    Count = SLL_GetNodeCount(List);

    //Print each Node's Data
    for (int i = 0; i < Count; i++)
    {
        Current = SLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }

    printf("Insert Node after Third Node\n");

    //Get Third Node first
    Current = SLL_GetNodeAt(List, 2);
    NewNode = SLL_CreateNode(2000);

    SLL_InsertNode(Current, NewNode);

    //print ths list
    Count = SLL_GetNodeCount(List);

    for (int i = 0; i < Count; i++)
    {
        Current = SLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }

    printf("Destroy List");

    for (int i = 0; i < Count; i++) {
        Current = SLL_GetNodeAt(List, 0);
        if (Current != NULL) {
            SLL_RemoveNode(&List, Current);
            SLL_DestroyNode(Current);
        }
    }
    return 0;
}