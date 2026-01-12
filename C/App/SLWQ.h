#ifndef SLWQ_H
#define SLWQ_H

#include "../def.h"
#define SHAMT       5
#define ROW         (1 << SHAMT)
#define MSK         ROW - 1
#define COL         20
typedef struct 
{
    uint16_t frame[ROW][COL];
    uint16_t wpos;
    uint32_t totalSum;
} VectorQueue;

void initVector(VectorQueue* vq);
void pushVector(VectorQueue* vq, uint16_t vec[COL]);
float getAvg(VectorQueue* vq);

#endif