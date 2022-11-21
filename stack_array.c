#include <stdio.h>

int stack[100],top=-1,choice,n,i,j;

void push()
{
    int val;
    if(top==n-1)
    {
        printf("overflow\n");
    }
    
    else
    {
        printf("enter the element which you want to insert\n");
        scanf("%d",&val);
        top=top+1;
        stack[top] = val;
    }
}

void pop()
{
    if(top==-1)
        printf("underflow\n");
    else
    {
        top = top - 1;
    }    
}

void show()
{
    for(i=0;i>=0;i--)
    {
        printf("%d\t",stack[i]);
    }
    if(top==-1)
    {
        printf("\nstack is empty\n");
    }
}

void peek()
{
    printf("%d",stack[top]);
}

void search()
{
    int val;
    printf("enter the value which you want to search\n");
    scanf("%d",&val);
    for(
        int i=0;i<n;i++)
    {
        if(stack[i]==val)
        {
            printf("element found at index %d",n-i-1);
            return;
        }
    }
    printf("element is not available in the stack");

}

int main()
{
    printf("enter no of elements you want in the stack\n");
    scanf("%d",&n);
    while(choice!=6)
    {
        
        printf("\nenter 1 to insert element in the stack\n");
        printf("enter 2 to pop an element from the stack\n");
        printf("enter 3 to display all the elements in the stack\n");
        printf("enter 4 to peek top of the stack\n");
        printf("enter 5 to search element\n");
        printf("enter 6 to quit this program\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                show();
                break;
            }
            case 4:
            {
                peek();
                break;
            }
            case 5:
            {
                search();
                break;
            }
        }
    }
}