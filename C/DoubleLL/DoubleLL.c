#include "DoubleLL.h"

static Node g_HeadNode = {0, "dumHead", "dumPhone", NULL, NULL};
static Node g_TailNode = {0, "dumTail", "dumPhone", NULL, NULL};

void initDLL()
{
    // Head, Tail이 서로를 가리키고 사이의
    // 동적 할당 노드는 없는 상황
    g_HeadNode.pNext = &g_TailNode;
    g_TailNode.pPrev = &g_HeadNode;
}

Node* createNode(int id, const char* name, const char* phone)
{
    Node* pNewNode = (Node*)malloc(sizeof(Node));
    if(pNewNode == NULL){
        perror("Node Creation Failed");
        return NULL;
    }
    pNewNode->id = id;
    // snprintf는 입력받은 문자열 길이를 반환
    if(snprintf(pNewNode->name, sizeof(pNewNode->name),
        "%s", name) > LEN)
    {
        fprintf(stderr, "Out of Bound! (Name too long)\n");
        goto err;
    }

    if(snprintf(pNewNode->phone, sizeof(pNewNode->phone),
        "%s", phone) > LEN)
    {
        fprintf(stderr, "Out of Bound! (Phone too long)\n");
        goto err;
    }

    return pNewNode;
    err:
        free(pNewNode);
        return NULL; 
}

void insertTail(int id, const char* name, const char* phone)
{
    Node* pNewNode = createNode(id, name, phone);
    if(pNewNode == NULL){
        puts("InsertTail() Failed");
        return;
    }
    // Q. Dummy Head/Tail도 첫 노드를 다르게 처리해야할까?
    // A. 노드가 없다면 prevTail은 g_HeadNode; 예외처리 불필요
    Node* pPrevTail = g_TailNode.pPrev;
    pNewNode->pNext = &g_TailNode;
    pPrevTail->pNext = pNewNode;
    pNewNode->pPrev = pPrevTail;
    g_TailNode.pPrev = pNewNode; 
}

void insertHead(int id, const char* name, const char* phone)
{
    Node* pNewNode = createNode(id, name, phone);
    // Seg Fault 방지
    if(pNewNode == NULL){
        puts("InsertHead() Failed");
        return;
    }
    Node* pNextHead = g_HeadNode.pNext;
    pNewNode->pNext = pNextHead;    // Segmentation fault
    pNewNode->pPrev = &g_HeadNode;
    g_HeadNode.pNext = pNewNode;
    pNextHead->pPrev = pNewNode;
}

int popTail(void)
{
    Node* pDelete = g_TailNode.pPrev;
    if(pDelete == &g_HeadNode){
        puts("No Info");
        return -1;
    }
    Node* pNewTail = pDelete->pPrev;
    pNewTail->pNext = &g_TailNode;
    g_TailNode.pPrev = pNewTail;
    int deleteID = pDelete->id;
    printf("[DELETE] Id: %d, Name: %s, Phone: %s\n",
        pDelete->id, pDelete->name, pDelete->phone);
    free(pDelete);
    return deleteID;
}

int popHead(void)
{
    Node* pDelete = g_HeadNode.pNext;
    if(pDelete == &g_TailNode){
        puts("No Info");
        return -1;
    }
    Node* pNewHead = pDelete->pNext;
    pNewHead->pPrev = &g_HeadNode;
    g_HeadNode.pNext = pNewHead;
    int deleteID = pDelete->id;
    printf("[DELETE] Id: %d, Name: %s, Phone: %s\n",
        pDelete->id, pDelete->name, pDelete->phone);
    free(pDelete);
    return deleteID;
}

void releaseNode(void)
{
    Node* pTemp = g_HeadNode.pNext;
    Node* pDelete = NULL;
    while(pTemp != &g_TailNode)
    {
        pDelete = pTemp;
        pTemp = pTemp->pNext;
        printf("[DELETE] Id: %d, Name: %s, Phone: %s\n",
            pDelete->id, pDelete->name, pDelete->phone);
        free(pDelete);
    }
}

void searchByName(const char* name)
{
    Node* pTemp = g_HeadNode.pNext;
    while(pTemp != &g_TailNode)
    {
        // 흔한 실수 if(pTemp->name == name)
        if(strcmp(pTemp->name, name) == 0)
        {
            printf("[FOUND] Id: %d, Name: %s, Phone: %s\n",
                pTemp->id, pTemp->name, pTemp->phone);
            // 중복이름 고려해서 return은 안함
        }
        pTemp = pTemp->pNext;
    }
}

void test(void)
{
    initDLL();
    // 2 -> 1 -> 3 -> 4 -> 5
    insertHead(1, "Hoon", "010-1234-1234");
    insertHead(2, "Joon", "010-4321-1234");
    insertTail(3, "Koon", "010-1234-4321");
    insertTail(4, "Poon", "010-1234-1234");
    insertTail(5, "Koon", "010-1234-4321");
    
    searchByName("Koon");
    popHead();
    popTail();
    releaseNode();
}


int main()
{
    test();
    return 0;
}