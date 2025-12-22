#include "myQ.h"
int rpos = 0, wpos = 0, cnt = 0;
int q[MAX_LEN];
int PowerQ[POWER_OF_TWO_LEN];
 /* Slot 1 Open 방식 
    1. rpos와 wpos가 같으면 Empty 또는 Full이다.
    2. Full이면 더이상 쓰지 않고, Empty이면 더이상 읽지 않는다.
    3. 다음 쓸 위치가 읽을 위치이면 Full
    4. rpos만이 wpos == rpos를 만들수 있도록 함 
    5. MAX_LEN - 1 이 REAL_LEN에 해당함 (Slot 1개 희생)
*/
bool q1_isFull()
{
    return (wpos + 1) % MAX_LEN == rpos; 
}

bool q1_isEmpty()
{
    return wpos == rpos;
}

void q1_enqueue(int val)
{
    if(q1_isFull()) return;
    // q[wpos++ % MAX_LEN] = val;
    q[wpos] = val;
    wpos = (wpos + 1) % MAX_LEN; // wpos ovf 방지
}

int q1_dequeue()
{
    if(q1_isEmpty()) return INT_MIN;
    int ret = q[rpos];
    rpos = (rpos + 1) % MAX_LEN;
    return ret;
}


// Cnt 도입하여 전체 사용
bool q2_isFull()
{
    return cnt == MAX_LEN; 
}

bool q2_isEmpty()
{
    return cnt == 0;
}

void q2_enqueue(int val)
{
    if(q2_isFull()) return;
    // q[wpos++ % MAX_LEN] = val;
    q[wpos] = val;
    wpos = (wpos + 1) % MAX_LEN; // wpos ovf 방지
    cnt++;
}

int q2_dequeue()
{
    if(q2_isEmpty()) return INT_MIN;
    int ret = q[rpos];
    rpos = (rpos + 1) % MAX_LEN;
    cnt--;
    return ret;
}


// 비트 마스킹 방법
// 제약조건: MAX_LEN이 2^n
/*  기존: index = wpos % 8; (나머지 연산)
    변경: index = wpos & 7; (비트 AND 연산)
*/
bool q3_isFull()
{
    // return ((wpos + 1) & MASK) == rpos;
    // wpos/rpos 무한 증가 방식
    return wpos - rpos == MAX_LEN;
}

bool q3_isEmpty()
{
    return wpos == rpos;
}

void q3_enqueue(int val)
{
    if(q3_isFull()) return;
    PowerQ[wpos++ & MASK] = val;
}

int q3_dequeue()
{
    if(q3_isEmpty()) return -1;
    return PowerQ[rpos++ & MASK];
}