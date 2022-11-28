#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;

void addbeg(int val);
void display();
void addlast(int val);
void addatloc(int val,int loc);
void delbeg();
void dellast();
void delatpos(int loc);
int count();

void main()
{
    int choice,value,location;
    while(choice!=8)
    {
        printf("enter 1 to add at beginning\n");
        printf("enter 2 to add at last\n");
        printf("enter 3 to add at position\n");
        printf("enter 4 to delete at position\n");
        printf("enter 5 to delete at beginning\n");
        printf("enter 6 to delete at last\n");
        printf("enter 7 to display all the elements\n");
        printf("enter 8 to end the program\n");
        printf("\nenter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("\nenter value to be added:");
            scanf("%d",&value);
            addbeg(value);
            break;
            case 2:
            printf("\nenter value to be added:");
            scanf("%d",&value);
            addlast(value);
            break;
            case 3:
            printf("\nenter value to be added:");
            scanf("%d",&value);
            printf("\nEnter the location:");
            scanf("%d",&location);
            addatloc(value,location);
            break;
            case 4:
            printf("\nEnter the location:");
            scanf("%d",&location);
            delatpos(location);
            break;
            case 5:
            delbeg();
            break;
            case 6:
            dellast();
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
    }
    newnode->next = temphead->next; 
    temphead->next = newnode;
}

void delbeg()
{
    struct node *temp=head;
    head = head->next;
    free(temp);
}

void dellast()
{
    if (head == NULL)
        return;
 
    if (head->next == NULL) {
        struct node *temp = head;
        free(temp);
        head=NULL;
    }
    struct node *second_last = head;
    while (second_last->next->next != NULL)
        second_last = second_last->next;
    
    free(second_last->next);
    second_last->next = NULL;
}

void delatpos(int pos)
{
    struct node *temp = head;       
    int i;                    
    if(pos==0)
    {
        head=head->next;        
        temp->next=NULL;
        free(temp);             
    }
    else
    {
        for(i=0;i<pos-1;i++) {
            temp=temp->next;
        }
        
        struct node *del =temp->next;       
        temp->next=temp->next->next;   
        del->next=NULL;
        free(del);                          
    }
    
}

void display()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp = temp->next;
    }
    printf("\n%d\n",count());
}

int count()
{
    int count=0;
    struct node *temp = head;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    return count;
}
