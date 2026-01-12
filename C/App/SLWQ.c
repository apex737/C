#include "SLWQ.h"

// 슬라이딩 윈도우 큐
// 최신 ROW를 덮어쓰면서 총합과 평균을 갱신
void initVector(VectorQueue* vq)
{
    vq->wpos = 0;
    vq->totalSum = 0;
    memset(vq->frame, 0, sizeof(vq->frame));
}

void pushVector(VectorQueue* vq, uint16_t vec[COL])
{
    // 누산값 업데이트
    for(int i = 0; i < COL; i++)
    {
        // old-row (vector)를 기존 누산에서 제거
        vq->totalSum -= vq->frame[vq->wpos][i];
        // new-row (vector)를 누산
        vq->totalSum += vec[i]; 
        // 새로운 row 덮어쓰기
        vq->frame[vq->wpos][i] = vec[i];
    }
    // ROW 포인터 업데이트
    vq->wpos = (vq->wpos + 1) & MSK;
}

float getAvg(VectorQueue* vq)
{
   return (float)vq->totalSum / (float)(ROW * COL);
}

int main(){

    return 0;
}