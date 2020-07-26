#include"mystack.h"
#include<stdio.h>
#include<stdlib.h>

/*栈的初始化*/
int stack_init(void)
{
    stack.pop=stack_pop;
    stack.top=stack_top;
    stack.push=stack_push;
    stack.empty=stack_empty;
    stack.size=stack_size;
    stack.head.next=NULL;
    stack.head.val=0;


    return 0;
}

/*删除栈的首个元素*/
int stack_pop(void)
{
    if(stack.head.val==0)
    {
        printf("the stack is empty\n");
        exit(-1);
    }
    else
    {
        listnode *p=stack.head.next;
        stack.head.next=stack.head.next->next;
        free(p);
        stack.head.val--;
    }
    return 0;
}

/*返回的首个元素*/
int stack_top(void)
{
    if(stack.head.val==0)
    {
        printf("the stack is empty\n");
        exit(-1);
    }
    else
    {
        return stack.head.next->val;
    }
}
/*栈中添加元素*/
int stack_push(int x)
{
    if(stack.head.val==0)
    {
        stack.head.next=(listnode *)malloc(sizeof (listnode));
        stack.head.next->val=x;
        stack.head.next->next=NULL;
        stack.head.val++;
    }
    else
    {
        /*使用头插法向链表中插入元素*/
        listnode *p=(listnode *)malloc(sizeof (listnode));
        p->val=x;
        p->next=stack.head.next;
        stack.head.next=p;
        stack.head.val++;
    }
    return 0;
}

/* stack_empty为空时返回1，否则返回0 */
int stack_empty(void)
{
    if(stack.head.val==0)
        return 1;
    else
        return 0;
}
/*返回栈的大小*/
int stack_size(void)
{
    return stack.head.val;
}
