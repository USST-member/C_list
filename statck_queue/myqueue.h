#ifndef MYQUEUE_H
#define MYQUEUE_H

/* 参考C++容器中栈的函数接口，然后使用C语言创建对应的数据结构
 * queue_back 返回最后一个元素
 * queue_empty 如果队列空则返回真
 * queue_front 返回第一个元素
 * queue_pop 删除第一个元素
 * queue_push 在末尾加入一个元素
 * queue_size 返回队列中元素的个数
 */
 int queue_back(void);
 int queue_front(void);
 int queue_push(int x);
 int queue_empty(void);
 int queue_size(void);
 int queue_pop(void);



typedef struct listnode{
    struct listnode *next;
    int val;
}listnode;


typedef struct myqueue{
    int (*back)(void);
    int (*front)(void);
    int (*pop)(void);
    int (*empty)(void);
    int (*size)(void);
    int (*push)(int);
    listnode *end;
    listnode head;
} myqueue;

 myqueue queue;

 int queue_init(void);

#endif // MYQUEUE_H
