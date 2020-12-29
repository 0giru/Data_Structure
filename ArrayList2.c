#include "ArrayList2.h"

void ListInit(List* plist){
    plist->num_of_data = 0;
    plist->cur_position = -1; //-1 means iterator is pointing nothing
}

void ListInsert(List* plist, LData data){
    if(plist->num_of_data >= LIST_LEN){
        printf("List Memory Error");
        exit(-1);
    }
    plist->arr[plist->num_of_data] = data;
    (plist->num_of_data)++;
}

//외부의 pdata 변수에 참조한 첫번째 값을 저장하는 듯?
int ListFirst(List* plist, LData* pdata){
    if(plist->num_of_data == 0){
        return FALSE;
    }
    plist->cur_position = 0;
    *pdata = plist->arr[0];
    return TRUE;
}

int ListNext(List* plist, LData* pdata){
    //더이상 참조할 
    if(plist->cur_position >= (plist->num_of_data)-1){
        return FALSE;
    }
    plist->cur_position++;
    *pdata = plist->arr[plist->cur_position];
    return TRUE;
}

LData ListRemove(List* plist){
    int r_pos = plist->cur_position;
    LData rdata = plist->arr[r_pos];

    for(int i=r_pos;i<(plist->num_of_data)-1;i++){
        plist->arr[i] = plist->arr[i+1];
    }
    plist->num_of_data--;
    plist->cur_position--;
    return rdata;
}

int ListCount(){

}