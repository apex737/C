
#include "Dynamic/DynamicArray.h"


/* Dynamic Array
    동적 배열이면.. malloc/free?
    CNT가 LEN 이상이면 2배를 동적할당
*/

int main()
{
    DyArr* pDy = createArr(LEN);
    for(int i = 0; i < 5; i++)
    {
        push(pDy, i);
    }
    insertItem(pDy, 5, 100);

    freeArr(pDy);
    
    return 1;
}