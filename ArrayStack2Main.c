#include "ArrayStack2.h"

int main(){
    //Create Stack And Initialize
    Stack stack;
    StackInit(&stack);

    //Insert Data into Stack 'stack'
    Push(&stack, 1);
    Push(&stack, 2);
    Push(&stack, 3);
    Push(&stack, 4);
    Push(&stack, 5);

    //Popping Data
    while(!IsEmpty(&stack)){
        printf("%d", Pop(&stack));
    }

    return 0;   
}