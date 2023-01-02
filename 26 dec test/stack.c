#include <stdio.h>
#include <ctype.h>

char arr[5];
int top=-1;

void push()
{
    char tempt;
    tempt=getchar(); 
    printf("please enter the character you would like to add\n");
    scanf("%c",&tempt); 
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

void occur()
{
    printf("\nenter the character for which you want to check for the occurence");
    char t;
    int count=0;
    scanf("%c",&t);
    for(int i=0;i<=top;i++)
    {
        if(arr[i] == t)
            count++;
    }
    printf("\noccurence of character %c is %d",t,count);
}

int main() {
    int ch;
    while(1)
    {
    printf("\nenter 1 to add character");
    printf("\nenter 2 to display all the contents of the stack");
    printf("\nenter 3 to pop an element");
    printf("\nenter 4 to search for an element");
    printf("\nenter 9 to exit\n");
    scanf("%d",&ch);
    if(ch==1)
        push();
    else if(ch==2)
        display();
    else if(ch==3)
        pop();
    else if(ch==4)
        occur();
    else if(ch==9)
        return 0;
    }
    for(int i=0;i<=top;i++)
    printf("%c",arr[top]);

    return 0;
}
