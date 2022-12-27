#include <stdio.h>
#include <ctype.h>

char arr[5];
int top=-1;

void push()
{
    char tempt;
    tempt=getchar(); //to clear the enter key press input which got stored in the input buffer
    printf("please enter the character you would like to add\n");
    scanf("%c",&tempt);  //this line will get clean input
    if(isalpha(tempt)==0)
    {
        printf("please enter a valid character");
        return;
    }
    if(top!=-1 && tempt == arr[top])
    {
        printf("\nplease dont enter repeat characters");
        return;
    }
    if(top==4) {
        printf("\nthe stack is full");
        return; }
    else
    {
        top++;
    }
    arr[top] = tempt;
    
}

void display()
{
    for(int i=0;i<=top;i++)
    {
        printf("%c\t",arr[i]);
    }
}

void pop()
{
    if(top==-1)
    {
        printf("\nstack is empty, cannot delete");
        return;
    }
    else
    {
        top--;
    }
}

int main() {
    // Write C code here
    int ch;
    while(1)
    {
    printf("\nenter 1 to add character");
    printf("\nenter 2 to display all the contents of the stack");
    printf("\nenter 3 to pop an element");
    printf("\nenter 9 to exit\n");
    scanf("%d",&ch);
    if(ch==1)
        push();
    else if(ch==2)
        display();
    else if(ch==3)
        pop();
    else if(ch==9)
        return;
    }
    for(int i=0;i<=top;i++)
    printf("%c",arr[top]);

    return 0;
}
