#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;

void addbeg(int val);
void addlast(int val);
void addatloc(int val,int loc);
void delbeg();
void dellast();
void delatloc();
void display();

void main()
{
    int choice,data,location;
    while(choice!=8)
    {
    printf("\nEnter 1 to add at beginning\n");
    printf("\nEnter 2 to add at last\n");
    printf("\nEnter 7 to display the link list\n");
    printf("\nEnter 8 to exit");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("\nenter the data:");
            scanf("%d",&data);
            addbeg(data);
            break;
        case 2:
            printf("\nenter the data:");
            scanf("%d",&data);
            addlast(data);
            break;
        case 3:
            printf("\nEnter the data:");
            scanf("%d",&data);
            printf("\nEnter the location:");
            scanf("%d",&location);
            addatloc(data,location);
            break;
        case 7:
            display();
            break;
    }
    }

}

void addbeg(int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = head;
    head = newnode;
}

void addlast(int val)
{
    struct node *temphead = head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    if(head==NULL)
    {
        
        head = newnode;
    }
    else
    {
        while(temphead->next!=NULL)
        {
            temphead=temphead->next;
        }
        temphead->next = newnode;
    }
}

void addatloc(int val,int loc)
{
    loc = loc -1;
    struct node *temphead = head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    for(int i=0;i<loc;i++)
    {
        temphead = temphead->next;
        if(temphead==NULL)
        {
            printf("overflow");
            return;
        }
    }
    newnode->next = temphead->next; 
    temphead->next = newnode;
}

void display()
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
