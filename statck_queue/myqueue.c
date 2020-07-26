#include"myqueue.h"
#include<stdio.h>
#include<stdlib.h>


/*对队列的初始化*/
int queue_init(void)
{
    queue.pop=queue_pop;
    queue.back=queue_back;
    queue.push=queue_push;
    queue.size=queue_size;
    queue.empty=queue_empty;
    queue.front=queue_front;


    queue.head.next=NULL;
    queue.head.val=0;
    queue.end=NULL;

    return 0;
}
/*返回队尾部元素*/
int queue_back(void)
{
    if(queue.head.next==NULL)
    {
        printf("queue is empty\n");
        exit(-1);
    }
    return queue.head.next->val;
}
/*返回队首部元素*/
int queue_front(void)
{
    if(queue.head.next==NULL)
    {
        printf("queue is empty\n");
        exit(-1);
    }
    return queue.end->val;
}
/*往队列添加元素*/
int queue_push(int x)
{

    if(queue.head.next==NULL)
    {
        listnode *p=(listnode *)malloc(sizeof (listnode));
        p->val=x;
        p->next=NULL;
        queue.head.next=p;
        queue.end=p;
    }
    else
    {
        listnode *p=(listnode *)malloc(sizeof (listnode));
        p->val=x;
        p->next=queue.head.next;
        queue.head.next=p;
    }
    return 0;
}
/*队列是否为空，空返回1，不为空返回0*/
int queue_empty(void)
{
    return queue.head.val==0;
}

/*返回队列的有多少元素*/
int queue_size(void)
{
    return queue.head.val;
}

/*删除队列首个元素*/
int queue_pop(void)
{
    if(queue.head.next==NULL)
    {
        printf("queue is empty\n");
        exit(-1);
    }
    listnode *p=queue.head.next;
    while(p->next!=queue.end)
    {
        p=p->next;
    }
    queue.end=p;
    free(p->next);
    return 0;
}
