#include "sqstack.h"

/*新建一个空栈*/
Status InitSqStack(SqStack *s)
{
    s->base=(Elemtype*)malloc(STACK_INIT_SIZE * sizeof(Elemtype));
    if((s->base)==NULL)
    {
      puts("Memory allocation failed.Goodbye!");
      exit(EXIT_FAILURE);
    }
    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
    return Ok;
}

/*判断是否为空栈*/
bool SqStackIsEmpty(SqStack *s)
{
    if(s->top == s->base)
    return true;
    else
    return false;
}

/*清空一个栈*/
void ClearSqStack(SqStack *s)
{
    s->top = s->base;
}

/*销毁一个栈*/
void DestroySqStack(SqStack *s)
{
  int i,len;
  len=s->stackSize;
  for(i=0;i<len;i++)
  {
      free(s->base);
      s->base++;
  }
  s->base=s->top=NULL;
  s->stackSize=0;
}

/*计算栈的当前容量*/
int SqStackLength(SqStack s)
{
    return(s.top-s.base); /*类型相同的指针相减得到两者之间相差的元素个数*/
}


/*进栈*/
Status PushSqStack(SqStack *s,Elemtype e)
{
    if(s->top - s->base >= s->stackSize)  /*栈已满需要再申请空间扩容*/
    {
        s->base=(Elemtype *)realloc(s->base,(s->stackSize+STACK_NEW_SIZE)*sizeof(Elemtype));
        if(s->base == NULL)
        {
            puts("Memory increase failed.Goodbye!");
            exit(EXIT_FAILURE);
        }
        s->top = s->base + s->stackSize;
        s->stackSize = s->stackSize + STACK_NEW_SIZE;
    }
    *(s->top)=e;
    s->top++;
}

/*出栈*/
Status PopSqStack(SqStack *s,Elemtype *e)
{
    if(s->top == s->base)
    {
        return Error;
    }
    *e = *(s->top);
    s->top--;
    return Ok;
}

