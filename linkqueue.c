#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front;
struct node *rear;

void enqueue(int value);
void dequeue();
void display();
void search(int value);

void main()
{
    int choice,value;
    while(choice!=5)
    {
        printf("\nenter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("\nenter the value which you want to insert:");
            scanf("%d",&value);
            enqueue(value);
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            case 4:
            printf("\nenter the value which you want tot search for:");
            scanf("%d",&value);
            search(value);
            break;
        }
    }
}

void enqueue(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next=NULL;
    if(front==NULL)
    {
        front = newnode;
        rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        rear->next=NULL;
    }
}

void dequeue()
{
    if(front==NULL)
    {
        return;
    }
    else
    {
        struct node *temp = front;
        front = front->next;
        free(temp);
    }
}

void display()
{
    if(front==NULL)
    {
        printf("\nthe queue is empty\n");
    }
    else
    {
        struct node * temp = front;
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp = temp->next;
        }
    }
}

void search(int value)
{
    int flag=0,count=0;
    struct node *temp = front;
    while(temp!=NULL)
    {
        if(temp->data==value)
        {
            flag=1;
            break;
        }
        temp =temp->next;
        count++;
    }
    if(flag==0)
        printf("\nvalue was not found");
    else
    {
        printf("value was found at location %d",count);
    }
}