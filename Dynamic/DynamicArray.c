#include "DynamicArray.h"


DyArr* createArr(int capInit)
{
    // DyArr ret;
    // ret.data = (int*)calloc(LEN, sizeof(int));
    // ret.size = 0;
    // ret.capacity = LEN;
    // 주의: 동적할당은 각각 따로 받아야함
    DyArr* ret = (DyArr*)malloc(sizeof(DyArr));
    ret->data = (int*)calloc(capInit, sizeof(int));
    ret->size = 0;
    ret->capacity = capInit;
    return ret;
}

void freeArr(DyArr* pDy)
{
    free(pDy->data);
    free(pDy);
    pDy->size = 0;
    pDy->capacity = 0;
}

void reallocate(DyArr* pDy, int cap)
{
    // 포인터 받아서 일단 백업
    int* pTemp = pDy->data;
    // 재할당
    pDy->data = (int*)malloc(sizeof(int)*cap);
    pDy->capacity = cap;
    // 백업 데이터에서 값복사
    for(int i = 0; i < pDy->size; i++)
    {
        pDy->data[i] = pTemp[i];
    }
    // 기존 포인터 해제
    free(pTemp);
}

void insertItem(DyArr* pDy, int idx, int val)
{
    if(pDy->capacity <= pDy->size) 
    // 경계값 처리; 둘이 같을 때 full 
    {   
        // 이중 포인터를 넘기지 않아도 업데이트가 가능할까? 
        // 메모리 재할당 실패 시 핸들링 방법?
        reallocate(pDy, 2*pDy->capacity);
    }   
    
    // 삽입 위치 포함 >>
    // 새롭게 메모리 할당 받았는데 어떻게 삽입/삭제?
    // 일단 할당받았으니까 새로운 공간을 덮어쓰면 됨
    // 현재 인덱스는 pDy->size - 1
    for(int i = pDy->size; i > idx; i--)
    // 끝에서부터 내 오른쪽을 overwrite 하면서 idx로 접근
    {
        pDy->data[i] = pDy->data[i-1];
    }
    pDy->data[idx] = val;
    pDy->size++;
}

void push(DyArr* pDy, int val)
{
    if(pDy->capacity <= pDy->size) 
    {   
        reallocate(pDy, 2*pDy->capacity);
    }   

    pDy->data[pDy->size++] = val;   // index off by one 조심 
}

int pop(DyArr* pDy)
{
    if(pDy->size <= 0){
        printf("No Element\n");
        return -1;
    }
    int ret = pDy->data[pDy->size-1];
    pDy->size--;
    return ret;
}

