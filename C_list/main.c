#include <stdio.h>
#include<stdlib.h>

/*链表的节点结构定义*/
typedef struct list_node {
    int data;
    struct list_node *next;
}list_node;

/*有头链表的创建*/
int creat_list(list_node *head,int n)
{
    if(head!=NULL&&n>0)
    {
        list_node *p=head;
        int input_data;
        while(n>0)
        {
            p->next=(list_node *)malloc(sizeof (list_node));
            printf("please input data：\n");
            scanf("%d",&input_data);
            p->next->data=input_data;
            p=p->next;
            n--;
            head->data++;
        }
        p->next=NULL;//链表的尾部节点下个指向为空
        return 0;
    }
    else
    {
        printf("输入创建链表参数出错：\n");
        return -1;
    }
}

/*打印整个链表*/
void print_list(list_node *head)
{
    if(head!=NULL)
    {
        printf("sum node %d\n",head->data);
        list_node *p=head->next;
        while(p!=NULL)
        {
            printf("~~~~~~~~~~~%d\n",p->data);
            p=p->next;
        }
    }
}

/*第一个参数指定链表头，第二参数在哪一个位置之后插入值*/
void insert_data(list_node *head,int data,int n)
{
    if(n<0||head->data<n||head==NULL)
    {
        printf("插入参数出错\n");
    }
    else
    {
        list_node *p=head->next;
        list_node *pre=head;
        while(n>0)
        {
            pre=p;
            p=p->next;
            n--;
        }
        list_node *new_node=(list_node *)malloc(sizeof (list_node));
        new_node->data=data;
        new_node->next=p;
        pre->next=new_node;
        head->data++;
    }
}
/*第一个参数指定链表头，第二参数删除哪一个值*/
void delete_data(list_node *head,int n)
{
    if(n<=0||head==NULL)
    {
        printf("输入参数错误");
        return;
    }
    else
    {
        list_node *pre=NULL;
        list_node *current=head;
        list_node *next=head->next;
        while(n>0)
        {
            pre=current;
            current=next;
            next=next->next;
            n--;
        }
        pre->next=next;
        free(current);
    }
}

/*对整个链表进行删除*/
void delete_list(list_node *head)
{
    if(head!=NULL)
    {
        list_node *pre=NULL;
        list_node *current=head;
        list_node *next=head->next;
        while(current!=NULL)
        {
            pre=current;
            current=next;
            next=next->next;
            free(pre);
        }
        free(current);
    }
    else
    {
        printf("链表已经为空\n");
    }
}

/*链表的反转*/
void reversal_list(list_node *head)
{
    if(head!=NULL)
    {
        list_node *current=head->next;
        list_node *next=current->next;
        while(next!=NULL)
        {
            current->next=next->next;
            next->next=head->next;
            head->next=next;

            next=current->next;
        }
    }
    else
    {
        printf("链表为空\n");
    }
}

/*使用选择排序*/
void list_sort(list_node *head)
{
    /*头节点的data用来存储总共有多少节点*/
    if(head==NULL)
        return;
    int i=0;
    int k=0;
    list_node *p=head->next;
    for(i=0;i<head->data-1;i++)
    {
        list_node *s=p->next;
        for(k=i+1;k<head->data;k++)
        {
            if((s->data)<(p->data))
            {
                int tem=p->data;
                p->data=s->data;
                s->data=tem;
            }
            s=s->next;
        }
        p=p->next;
    }
}

int main()
{
    /*链表头的创建*/
    list_node *head=(list_node *)malloc(sizeof (list_node));
    if(head!=NULL)
    {
        /*对头节点的初始化*/
        head->data=0;
        head->next=NULL;
    }

    creat_list(head,5);
    insert_data(head,100,0);
    reversal_list(head);
//    list_sort(head);
    print_list(head);
//    delete_data(head,6);
//    delete_list(head);
    return 0;
}
