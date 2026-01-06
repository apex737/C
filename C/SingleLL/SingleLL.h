#ifndef SINGLE_LL_H
#define SINGLE_LL_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define LEN         20


Node* createNode(int id, const char* name, const char* phone);
void releaseNode(Node* pNode);

#endif