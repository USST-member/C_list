#ifndef MYSTACK_H
#define MYSTACK_H

/* 参考C++容器中栈的函数接口，然后使用C语言创建对应的数据结构
 * 1.stack.push(); //往栈头添加元素
 * 2.stack.pop();      //从栈头移除第一个元素
 * 3.stack.top();      //返回栈顶元素
 * 4.stack.empty();    //判断堆栈是否为空
 * 5.stack.size();     //返回堆栈的大小
 */
 int stack_pop(void);
 int stack_top(void);
 int stack_push(int x);
 int stack_empty(void);
 int stack_size(void);

typedef struct listnode{
    struct listnode *next;
    int val;
}listnode;


typedef struct mystack{
    int (*pop)(void);
    int (*top)(void);
    int (*empty)(void);
    int (*size)(void);
    int (*push)(int);
    listnode head;
} mystack;

 mystack stack;

 int stack_init(void);

#endif // MYSTACK_H
