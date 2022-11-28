#include <stdio.h>
#include <stdlib.h>

#define maxsize 5

int queue[maxsize],front=-1,rear=-1;

void enqueue(int val);
void dequeue();
void display();
void search(int value);

void main()
{
    int choice,value;
    while(choice!=5)
    {
        printf("enter choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("enter the value which you want to insert");
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

void enqueue(int val)
{
    if(rear==maxsize-1)
    {
        printf("overflow");
        return;
    }
    if(front==-1 && rear==-1)
    {
        front++;
        rear++;
    }
    else
    {
        rear++;
    }
    queue[rear] = val;
}

void dequeue()
{
    if(front==-1 || front>rear)
    {
        printf("\nunderflow");
    }
    else
    {
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front = front+1;
        }
    }
}

void display()
{
    if(rear==-1)
        printf("\nempty");
    else{
        for(int i=front;i<=rear;i++)
        {
            printf("%d\t",queue[i]);
        }
    }
}

void search(int value)
{
    int flag=0,i=0,count=0;
    for(i=front;i<=rear;i++)
        {

            if(queue[i]==value)
            {
                flag=1;
                break;
            }
            count++;
            
        }
    if(flag==0)
        printf("\nvalue was not found");
    else
    {
        printf("\nvalue was found at index %d\n",count);
    }
}