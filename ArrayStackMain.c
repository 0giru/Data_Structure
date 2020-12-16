#include "ArrayStack.h"

int main(){
    ArrayStack* Stack = NULL;

    AS_CreateStack(&Stack, 10);

    AS_Push(Stack, 3);
    AS_Push(Stack, 37);
    AS_Push(Stack, 11);
    AS_Push(Stack, 12);

    printf("Capacity: %d, Size : %d, Top is : %d\n\n",
    Stack -> Capacity, Stack -> Top, AS_Top(Stack));

    int count = AS_GetSize(Stack);

    for(int i = 0;i<count;i++){
        if(AS_IsEmpty(Stack)){
            break;
        }

        printf("Popped : %d, ", AS_Pop(Stack));

        if(!AS_IsEmpty(Stack)){
            printf("Current Top is : %d\n", AS_Top(Stack));
        }
        else{
            printf("Stack is Empty");
        }
    }
    AS_DestroyStack(Stack);

    return 0;
}