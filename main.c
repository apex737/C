#include <stdio.h>
#include <stdlib.h>
#include "myQ.h"

void test_q1()
{
    for(int i = 0; i < 10; i++)
    {
        q1_enqueue(i);
    }

    for(int i = 0; i < 10; i++)
    {
        
        printf("q1_dequeue( %d )\n", q1_dequeue());
    }

    q1_enqueue(14);
    q1_enqueue(41);
    printf("q1_dequeue( %d )\n", q1_dequeue());
}

void test_q2()
{
    for(int i = 0; i < 15; i++)
    {
        q2_enqueue(i);
    }

    for(int i = 0; i < 10; i++)
    {
        
        printf("q2_dequeue( %d )\n", q2_dequeue());
    }

    q2_enqueue(14);
    q2_enqueue(41);
    printf("q2_dequeue( %d )\n", q2_dequeue());
}

void test_q3()
{
    for(int i = 0; i < 15; i++)
    {
        q3_enqueue(i);
    }

    for(int i = 0; i < 5; i++)
    {
        q3_enqueue(i);
    }

    for(int i = 0; i < 10; i++)
    {
        
        printf("q3_dequeue( %d )\n", q3_dequeue());
    }

    q3_enqueue(14);
    q3_enqueue(41);
    printf("q3_dequeue( %d )\n", q3_dequeue());
}


int main()
{

   test_q3();
    
    
    return 1;
}