#include<stdio.h>
#include"myqueue.h"
int main()
{
    queue_init();
    queue.push(1);
    queue.push(2);
    printf("queue_front=%d",queue.front());
    queue.pop();
    printf("queue_front=%d",queue.front());
    queue.pop();
    printf("queue_front=%d",queue.front());
	return 0;
}
