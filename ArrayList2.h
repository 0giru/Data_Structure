#ifndef __ARRAY_LIST_H
#define __ARRAY_LIST_H

#define TRUE 1
#define FALSE 0
#define LIST_LEN 100

#include <stdio.h>
#include <stdlib.h>

typedef int LData;

typedef struct _ArrayList{
    LData arr[LIST_LEN];
    int num_of_data;
    int cur_position; //참조 위치를 지정하기 위한 변수
}List;

void ListInit(List* plist);
void ListInsert(List* plist, LData data);

int ListFirst(List* plist, LData* pdata);
int ListNext(List* plist, LData* pdata);

LData ListRemove(List* plist);
int ListCount(List* plist);

#endif