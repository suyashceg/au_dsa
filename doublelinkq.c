#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    struct node *next;
    int data;
};

struct node *front;
struct node *rear;

void enqueue(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    if(front==NULL)
    {
        front = newnode;
        rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear->prev = rear;
        rear = rear->next;
        rear->next = NULL;
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
        front->prev=NULL;
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

int main()
{
    int choice,value;
    while(choice!=5)
    {
        printf("\nenter your choice:");
        printf("\nEnter 1 to enter data into the queue");
        printf("\nEnter 2 to remove data from the queue");
        printf("\nEnter 3 to display all the elements in the queue");
        printf("\nEnter 4 to search for an element");
        printf("\nEnter 5 to quit the program");
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
    return 0;
}