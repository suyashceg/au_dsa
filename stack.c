#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};
struct Node* top = NULL;


void push(int value) {
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value; 
    if (top == NULL) {
        newNode->next = NULL;
    } else {
        newNode->next = top; 
    }
    top = newNode; 
    
}

void pop() {
    if (top == NULL) {
        printf("\nStack Underflow\n");
    } else {
        struct Node *temp = top;
        top = top->next;
        free(temp);
        
    }
}

void display() {
    
    if (top == NULL) {
        printf("\nStack Underflow\n");
    } else {
        printf("The stack is \n");
        struct Node *temp = top;
        while (temp != NULL) {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        
    }
}

void findloc()
{
    int val;
    printf("\n enter the number for which you want to find the index\n");
    scanf("%d",&val);
    struct Node *temp = top;
    int count=0,flag=0;
    while(temp!=NULL)
    {
        if(temp->data == val)
        {
            flag=1;
            break;
        }
        count=count+1;
        temp=temp->next;
    }
    if(flag==0)
        printf("\nvalue was not found\n");
    else
    {
        printf("%d",count);
    }    

}

int main() {
    int choice, value;
    printf("\nImplementation of Stack using Linked List\n");
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Find location\n5.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            findloc();
            break;
        case 5:
            return 0;    
        default:
            printf("\nWrong Choice\n");
        }
    }
}