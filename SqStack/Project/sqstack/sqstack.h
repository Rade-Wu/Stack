#ifndef SQSTACK_H_
#define SQSTACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Ok 1
#define Error 0
#define STACK_INIT_SIZE  100
#define STACK_NEW_SIZE   10
typedef int Status;
typedef int Elemtype;

typedef struct 
{
    Elemtype *top;
    Elemtype *base;
    int stackSize;
}SqStack;

Status InitSqStack(SqStack *s);
bool SqStackIsEmpty(SqStack *s);
void ClearSqStack(SqStack *s);
void DestroySqStack(SqStack *s);
int SqStackLength(SqStack s);
Status PushSqStack(SqStack *s,Elemtype e);
Status PopSqStack(SqStack *s,Elemtype *e);

#endif