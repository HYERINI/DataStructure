#include <stdio.h>
#include <stdlib.h>

#include "DynamicArray.h"

#define INCREMENT_SIZE 5

//구조체 동적할당하기 졸라 어려워요.
DynamicArray* DACreate()
{
    DynamicArray* resizableArray = (DynamicArray*) malloc (sizeof(DynamicArray));
    if(resizableArray) {
        //다음 작업 -> arr 할당
        resizableArray -> arr = (Element*) malloc (sizeof(Element) * INCREMENT_SIZE);
        if(resizableArray -> arr) {
            resizableArray -> count = 0;
            resizableArray -> size = INCREMENT_SIZE;
            return resizableArray;
            //구조체 반환
        }
        else{
            free(resizableArray);
            return NULL;
        }
    }
    return NULL;
}

int DAGetCount(const DynamicArray* resizableArray)
{
    if (resizableArray) {
        return resizableArray->count;
    }
    return -1;
}

int DAGetSize(const DynamicArray* resizableArray)
{
    if (resizableArray) {
        return resizableArray->size;
    }
    return -1;
}

int DAAdd(DynamicArray* resizableArray, Element value)
{   
    if(resizableArray && resizableArray -> arr){
        if(resizableArray -> count > 0 && resizableArray -> count % 5 == 0){
            resizableArray -> size += INCREMENT_SIZE;
            resizableArray -> arr = (Element*)realloc(resizableArray->arr, resizableArray->size * sizeof(Element));
            if(resizableArray -> arr == NULL){
                free(resizableArray);
                return 0;
            }
        }
        resizableArray -> arr[resizableArray->count] = value;
        resizableArray -> count ++;
        return 1;
    }
    return 0;
}

int DAPut(DynamicArray* resizableArray, int idx, Element value)
{
    if(resizableArray && resizableArray -> arr && idx >= 0 && idx < resizableArray -> size){
        resizableArray -> arr[idx] = value;
        return 1;
    }
    return 0;
}

int DAGet(const DynamicArray* resizableArray, int idx, Element* value)
{
    if(resizableArray && resizableArray -> arr && idx >= 0 && idx < resizableArray -> size){
        *value = resizableArray -> arr[idx];
        return 1;
    }
    return 0;
}


int DADestroy(DynamicArray* resizableArray)
{
    if(resizableArray && resizableArray -> arr){
       //메모리 해제
        free(resizableArray -> arr);
        free(resizableArray);
        return 1;
    }
    return 0;
}

int DAPrint(const DynamicArray* resizableArray, PrintFunc printFunc)
{
    if (resizableArray && resizableArray->arr) {
        for (int i = 0; i < resizableArray->count; i++) {
            //printf("%d\n", resizableArray->arr[i]);
            printFunc(resizableArray->arr[i]);
        }
        return 1;
    }
    return 0;
}