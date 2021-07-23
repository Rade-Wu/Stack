#include <stdio.h>
#include <math.h>
#include "sqstack.h"

int main(void)
{
    Elemtype c;  /*二进制数用char型一个一个入栈*/
    SqStack s;
    int len,i,sum=0;
    InitSqStack(&s);
    printf("请输入二进制数，输入#符号表示结束！\n");
    while((c=getchar())!='#')
    {
       PushSqStack(&s,c);
    }
    len=SqStackLength(s);
    printf("栈的当前容量是：%d\n",len);
    for(i=0;i<len;i++)
    {
       PopSqStack(&s,&c);
       sum = sum+(c-48)*pow(2,i);
    }
    printf("转换为十进制数是：%d的\n",sum);
    return 0;
}
