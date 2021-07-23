#include "linkstack.h"

LinkStackPtr bottom = NULL;

/*初始化一个空栈*/
Status InitLStack(LinkStack *s)
{
    s->count = 0;
    s->top = (StackNode*)malloc(sizeof(StackNode));
    if((s->top)==NULL)
    {
      puts("Memory allocation failed.Goodbye!");
      exit(EXIT_FAILURE);
    }
    s->top->next =NULL;
    bottom = s->top;
    puts("Successfully initialize the stack!");
    return Ok;
}

/*判断栈是否为空*/
bool LStackIsEmpty(LinkStack *s)
{
    if(s->count==0)
    {
        puts("Stack is empty!");
        return true;
    }
    else
    {
        puts("Stack is not empty!");
        return false;
    }
}

/*得到栈顶元素的值*/
Status GetTopStack(LinkStack *s,Elemtype *e)
{
    if((s->top)==NULL)
    {
        puts("There is no stack!");
        return Error;
    }
    *e = s->top->data;
    return  Ok;
}

/*清空一个栈*/
Status ClearLStack(LinkStack *s)
{
    LinkStackPtr p; /*创建一个指向结点的指针*/
    s->count =0;
    s->top = bottom;
    p =bottom = bottom->next;
    while(p)
    {
       p = bottom->next; 
       free(bottom);
       bottom = p;    
    }
    return Ok;
}

/*销毁一个栈*/
Status DestoryLStack(LinkStack *s)
{
    LinkStackPtr p;
    s->count = 0;
    s->top =NULL;
    while(p)
    {
        p = bottom->next;
        free(bottom);
        bottom = p;
    }
    return Ok;
}

/*测量栈的长度*/
Status LStackLength(LinkStack *s,int *Length)
{
    if((s->top)=NULL)
    {
        puts("There is no stack!");
        return Error;
    }
    *Length=s->count;
    return Ok;
}

/*进栈*/
/*插入元素e为新的栈顶元素*/
Status PushLStack(LinkStack *s,Elemtype e)
{
    LinkStackPtr p;
    p = (LinkStackPtr)malloc(sizeof(StackNode));
    p->data = e;
    p->next = s->top;/*将当前栈顶元素赋值给新结点的后继*/
    s->top = p; /*将新结点p赋值给栈顶指针*/
    s->count++;
    return Ok;
}

/*出栈*/
/*删除s的栈顶元素，用e返回其值*/
Status PopLStack(LinkStack *s,Elemtype *e)
{
    LinkStackPtr p;
    if(LStackIsEmpty(s))
    return Error;
    *e=s->top->data;
    p=s->top;
    s->top=s->top->next;
    free(p);
    s->count--;
    return Ok;
}



