#ifndef _ARRAYSTACK_H
#define _ARRAYSTACK_H

#include <stdio.h>
#include <stdlib.h>

//Stack 공간을 따로 만들고, Stack 공간에 Node를 차례로 쌓아 나가는 방식
typedef int ElementType;

typedef struct _Node{
    ElementType Data;
}Node;

typedef struct _ArrayStack{
    int Capacity; //스택의 크기
    int Top; //최상위 노드의 위치
    Node* Nodes; //노드 배열(에서 첫번째 요소를 가리키는 포인터)
}ArrayStack;

void AS_CreateStack(ArrayStack** Stack, int Capacity);
void AS_DestroyStack(ArrayStack* Stack);
void AS_Push(ArrayStack* Stack, ElementType Data);
ElementType AS_Pop(ArrayStack* Stack);
ElementType AS_Top(ArrayStack* Stack);
int AS_GetSize(ArrayStack* Stack);
int AS_IsEmpty(ArrayStack* Stack);

#endif