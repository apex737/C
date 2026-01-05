#ifndef D_ARRAY_H
#define D_ARRAY_H
#include <stdbool.h>
#include <stdio.h>   // NULL이 여기에 정의되어 있습니다.
#include <stdlib.h>  // 혹은 여기에도 정의되어 있습니다.
#define LEN         10
typedef struct {
    int* data;
    int size;       // element 수
    int capacity;   // maximum
} DyArr;


DyArr* createArr(int capInit);
void freeArr(DyArr* pDy);
void reallocate(DyArr* pDy, int cap);
void insertItem(DyArr* pDy, int idx, int val);
void push(DyArr* pDy, int val);
int pop(DyArr* pDy);

#endif