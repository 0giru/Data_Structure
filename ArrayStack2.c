#include "ArrayStack2.h"

void StackInit(Stack* pstack){
    pstack->topIndex = -1; //-1 means stack is empty
}

int IsEmpty(Stack* pstack){
    if(pstack->topIndex == -1){
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void Push(Stack* pstack, Data data){
    pstack->topIndex++;
    pstack->stackArr[pstack->topIndex] = data;
}

Data Pop(Stack* pstack){
    int rIdx;

    if(IsEmpty(pstack)){
        printf("Stack Memory Error");
        exit(-1);
    }
    rIdx = pstack->topIndex;
    pstack->topIndex--;

    return pstack->stackArr[rIdx];
}

Data Peek(Stack* pstack){
    if(IsEmpty(pstack)){
        printf("Stack Memory Error");
        exit(-1);
    }
    int ptr = pstack->topIndex;

    return pstack->stackArr[ptr];
}