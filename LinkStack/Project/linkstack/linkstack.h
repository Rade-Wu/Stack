#ifndef LINKSTACK_H_
#define LINKSTACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Ok 1
#define Error 0
typedef int Status;
typedef int Elemtype;
typedef struct StackNode
{
    Elemtype data;
    struct StackNode *next;
}StackNode,*LinkStackPtr;
typedef struct LinkStack
{
    LinkStackPtr top;
    int count;
}LinkStack;


#endif

