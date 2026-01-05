#include <stdio.h>
#include <stdlib.h>
#include "myQ.h"

void test_osrq()
{
    for(int i = 0; i < 10; i++)
    {
        SORQ_enqueue(i);
    }

    for(int i = 0; i < 10; i++)
    {
        
        printf("SORQ_dequeue( %d )\n", SORQ_dequeue());
    }

    SORQ_enqueue(14);
    SORQ_enqueue(41);
    printf("SORQ_dequeue( %d )\n", SORQ_dequeue());
}

void test_cntq()
{
    for(int i = 0; i < 15; i++)
    {
        CNTQ_enqueue(i);
    }

    for(int i = 0; i < 10; i++)
    {
        
        printf("CNTQ_dequeue( %d )\n", CNTQ_dequeue());
    }

    CNTQ_enqueue(14);
    CNTQ_enqueue(41);
    printf("CNTQ_dequeue( %d )\n", CNTQ_dequeue());
}

void test_mskq()
{
    for(int i = 0; i < 15; i++)
    {
        MSKQ_enqueue(i);
    }

    for(int i = 0; i < 5; i++)
    {
        MSKQ_enqueue(i);
    }

    for(int i = 0; i < 10; i++)
    {
        
        printf("MSKQ_dequeue( %d )\n", MSKQ_dequeue());
    }

    MSKQ_enqueue(14);
    MSKQ_enqueue(41);
    printf("MSKQ_dequeue( %d )\n", MSKQ_dequeue());
}




int main()
{
    
  
    return 1;
}