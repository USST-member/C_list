#include <stdio.h>
#include<stdlib.h>
#include<string.h>

/*单向链表的数据类型*/
typedef struct list_node{
    int data;
    struct list_node *next;
} list_node,*p_listnode;

/*双向链表的数据类型*/
typedef struct t_listnode{
    int data;
    struct t_listnode *next;
    struct t_listnode *before;
} t_listnode,*p_t_listnode;

/* 创建一个单向链表
 * 其中头节点数据代表链表长度
 */
void creat_list(p_listnode head,int n)
{
    int i=0;
    if(n<1||head==NULL)
    {
        printf("the paremers is err\n");
        return;
    }
    else
    {
        p_listnode p=head;
        while(i<n)
        {
            p->next=(p_listnode)malloc(sizeof (list_node));
            if(p->next!=NULL)
            {
                p=p->next;
                printf("input current node data：\n");
                scanf("%d",&p->data);
                head->data++;
                i++;
            }
        }
        p->next=NULL;
    }
}

/*打印当前单向链表*/
void print_list(p_listnode head)
{
    if(head!=NULL)
    {
        p_listnode p=head;
        printf("current sum node is:%d\n",p->data);
        while (p->next!=NULL)
        {
            printf("current node data is:%d\n",p->next->data);
            p=p->next;
        }
    }
}

/*双向链表的创建*/
void creat_t_list(p_t_listnode head,int n)
{
    if(n<1||head==NULL)
    {
        printf("the paremers is err\n");
        return;
    }
    else
    {
        p_t_listnode p=head;
        int i=0;
        while (i<n)
        {
            p->next=(p_t_listnode)malloc(sizeof (t_listnode));
            if(p->next!=NULL)
            {
                p->next->before=p;
                p=p->next;
                printf("input current node data：\n");
                scanf("%d",&p->data);
                head->data++;
                i++;
            }
        }
        p->next=NULL;
    }
}

/*循环双向链表的创建*/
void creat_cir_list(p_t_listnode head,int n)
{
    int i=0;
    if(n<1||head==NULL)
    {
        printf("the paramers is erro\n");
        return;
    }
    else
    {
        p_t_listnode p=head;
        while(i<n)
        {
            p->next=(p_t_listnode)malloc(sizeof (t_listnode));
            if(p->next!=NULL)
            {
                p->next->before=p;
                p=p->next;
                printf("input node data:\n");
                scanf("%d",&p->data);
                head->data++;
                i++;
            }
        }
        p->next=head->next;
        head->before=p;
    }
}

/*打印双向链表*/
void print_t_list(p_t_listnode head)
{
    if(head!=NULL)
    {
        p_t_listnode p=head;
        printf("current sum node is:%d\n",p->data);
        while (p->next!=NULL)
        {
            printf("current node data is:%d\n",p->next->data);
            p=p->next;
        }
    }
}
/*打印循环双向链表*/
void print_cir_list(p_t_listnode head)
{
    if(head!=NULL)
    {
        p_t_listnode p=head->next;
        printf("current sum node is:%d\n",head->data);
        while (p->next!=head->next)
        {
            printf("current node data is:%d\n",p->data);
            p=p->next;
        }
        printf("current node data is:%d\n",p->data);
    }
}

/*双向链表节点的插入--头插法*/
void insert_t_node(p_t_listnode head,int value)
{
    if(head!=NULL)
    {
        p_t_listnode new_node=(p_t_listnode)malloc(sizeof (t_listnode));
        if(new_node!=NULL)
        {
            new_node->data=value;
            new_node->before=head;
            head->next->before=new_node;
            new_node->next=head->next;
            head->next=new_node;
            head->data++;
        }
    }
}

int main()
{
    p_t_listnode head=(p_t_listnode)malloc(sizeof (list_node));
    if(head!=NULL)
    {
        head->data=0;
        head->next=NULL;
        head->before=NULL;
    }
    creat_t_list(head,1);
    insert_t_node(head,5);
    insert_t_node(head,9);
    print_t_list(head);
    return 0;
}
