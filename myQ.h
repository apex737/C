#ifndef MYQ_H
#define MYQ_H

#include <limits.h>
#include <stdbool.h>
#define MAX_LEN 10
#define POWER_OF_TWO_LEN 16
#define MASK (POWER_OF_TWO_LEN - 1)
extern int q[MAX_LEN];
extern int PowerQ[POWER_OF_TWO_LEN];
extern int rpos, wpos;
extern int cnt;

bool q1_isFull();
bool q1_isEmpty();
void q1_enqueue(int val);
int q1_dequeue();

bool q2_isFull();
bool q2_isEmpty();
void q2_enqueue(int val);
int q2_dequeue();

bool q3_isFull();
bool q3_isEmpty();
void q3_enqueue(int val);
int q3_dequeue();

#endif