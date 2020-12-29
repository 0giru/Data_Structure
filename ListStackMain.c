// ListStack ver.1
#include "ListStack.h"

int main(){
    int Count = 0;
    Node* Popped;

    ListStack* Stack;

    LS_CreateStack(&Stack);

    LS_Push(Stack, LS_CreateNode("abc"));
    LS_Push(Stack, LS_CreateNode("def"));
    LS_Push(Stack, LS_CreateNode("ghi"));
    LS_Push(Stack, LS_CreateNode("jkl"));

    Count = LS_GetSize(Stack);
    
    printf("List Size is : %d, Top is %s\n\n", Count, LS_Top(Stack) -> Data);

    for(int i = 0; i < Count ;i++){
        if(LS_IsEmpty(Stack)){
            break;
        }
        Popped = LS_Pop(Stack);
        printf("Popped is %s, ", Popped -> Data);

        LS_DestroyNode(Popped);

        if(!LS_IsEmpty(Stack)){
            printf("Current Top is : %s\n", LS_Top(Stack) -> Data);
        }
        else{
            printf("Stack is Empty\n");
        }
    }
    LS_DestroyStack(Stack);

    return 0;
}
