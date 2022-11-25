#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int val;
    struct node *next;
};

void addbeg(struct node **);
void append(struct node **);
void addatpos(struct node **);
void addbeforepos(struct node **,int);
void delbeg(struct node **);
void delend(struct node **);
void delatpos(struct node **);
void display(struct node **);

void main()
{
    struct node *head;
    head = (struct node *)(malloc(sizeof(struct node)));
    int choice=0;
    while(1)
    {
        printf("\nEnter 1 to insert element at the beginning\n");
        printf("\nEnter 2 to insert element at the last\n");
        printf("\nEnter 3 to insert element at specific position\n");
        printf("\nEnter 4 to delete element at the beginning\n");
        printf("\nEnter 5 to delete element at the end\n");
        printf("\nEnter 6 to delete element at specific position\n");
        printf("\nEnter 7 to display all elements\n");
        printf("\nEnter 8 to exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            
            case 1:
                addbeg(&head);
                break;
            case 2:
                append(&head);
                break;
            case 3:
                addatpos(&head);
                break;
            case 4:
                delbeg(&head);
                break;
            case 5:
                delend(&head);
                break;
            case 6:
                delatpos(&head);
                break;
            case 7:
                display(&head);
                break;
            case 8:
                return;
        }
    }
    
    
}

void addbeg(struct node **p)
{
        int a;
        scanf("%d",&a);
        struct node *temp;
        temp = (struct node *)malloc(sizeof(struct node));
        temp->val = a;
        temp->next = *p;
        *p = temp;
   
}

void append(struct node **p)
{
    int v;
    struct node *temp,*r;
    printf("\nEnter the value which you want to insert in the node\n");
    scanf("%d",&v);
    if(*p==NULL)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->val = v;
        temp->next = NULL;
        *p = temp;
        printf("temp");
    }
    else
    {
        temp = *p;
        while(temp->next !=NULL)
        {
            temp = temp->next;
        }
        r = (struct node *)malloc(sizeof(struct node));
        r->val = v;
        r->next = NULL;
        temp->next = r;
    }
}

void addatpos(struct node **p)
{
    struct node *temp,*r;
    int v,pos;
    printf("\nEnter the value which you want to insert in the node(pos insertion)\n");
    scanf("%d",&v);
    printf("\nenter the position at which you want to insert\n");
    scanf("%d",&pos);
    temp = *p;
    for(int i=0;i<pos-1;i++)
    {
        temp = temp->next;
        if(temp==NULL)
        {
            printf("underflow");
            return;
        }
        

    }
    r = (struct node *)malloc(sizeof(struct node));
    r->val = v;
    r->next = temp->next;
    temp->next = r;
}

void addbeforepos(struct node **p,int pos)
{
    struct node *temp,*r;
    int v;
    printf("\nEnter the value which you want to insert in the node\n");
    scanf("%d",&v);
    temp = *p;
    for(int i=0;i<pos-1;i++)
    {
        temp = temp->next;
        if(temp==NULL)
        {
            printf("underflow");
            return;
        }
        

    }
    r = (struct node *)malloc(sizeof(struct node));
    r->val = v;
    r->next = temp->next;
    temp->next = r;
}

void delbeg(struct node **p)
{
    struct node *temp = *p,*first = *p;
    temp = temp->next;
    *p = temp;
    free(first);
}

void delend(struct node **p)
{
    struct node *temp = *p,*secondlast;
    while(temp->next->next!=NULL)
    {
        temp = temp->next;
    }
    secondlast = temp;
    secondlast->next = NULL;
    free(temp->next);
}

void delatpos(struct node **p)

{
    struct node *temp,*posnode;
    int pos;
    printf("\nenter the position at which you want to delete\n");
    scanf("%d",&pos);
    temp =*p;
    for(int i=0;i<pos-1;i++)
    {
        temp = temp->next;
        if(temp==NULL)
        {
            printf("underflow");
            return;
        }

    }
    posnode = temp->next;
    temp->next = temp->next->next;
    free(posnode);
}

void display(struct node **p)
{
    struct node *temp = *p;
    while(temp!=NULL)
    {
        printf("%d",temp->val);
        temp = temp->next;
    }
    
}
