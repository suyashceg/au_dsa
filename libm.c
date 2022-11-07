#include <stdio.h>
#include <string.h>

struct book
{
    int isbn;
    char bookname[20];
    char bookauthr[20];
    int year;
    int copies;
};

struct book b[20];

void issuebook(int n)
{
    int isbn,flag=0,i=0;
    printf("enter the isbn of the book\n");
    scanf("%d",&isbn);
    for(i=0;i<n;i++)
    {
        if(b[i].isbn == isbn)
        {
            b[i].copies--;
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("wrong isbn no entered\n");
    }
    if(flag==1)
    {
        printf("no of copies has been updated to %d\n",b[i].copies);
    }
}

void returnbook(int n)
{
    int isbn,flag=0,i=0;
    printf("enter the isbn of the book\n");
    scanf("%d",&isbn);
    for(i=0;i<n;i++)
    {
        if(b[i].isbn == isbn)
        {
            b[i].copies++;
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("wrong isbn no entered\n");
    }
    if(flag==1)
    {
        printf("no of copies has been updated to %d\n",b[i].copies);
    }
}

void listbook(int n)
{
    int i=0,year=0,flag=0;
    printf("enter the year: \n");
    scanf("%d",&year);
    for(i=0;i<n;i++)
    {
        if(b[i].year==year)
        {
            printf("ISBN:%d",b[i].isbn);
            printf("\tbookname:%d",b[i].bookname);
            printf("\tbookauthr:%d",b[i].bookauthr);
            printf("\tcopies:%d",b[i].copies);
            printf("\tyear:%d",b[i].year);
            printf("\n");
        }
    }
}

void listallbook(int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
            printf("ISBN:%d",b[i].isbn);
            printf("\tbookname:%s",b[i].bookname);
            printf("\tbookauthr:%s",b[i].bookauthr);
            printf("\tcopies:%d",b[i].copies);
            printf("\tyear:%d",b[i].year);
            printf("\n");
    }
}

void listcopies(int n)
{
    char name[20];
    int i=0,result;
    printf("enter the name of the book\n");
    scanf("%s",name);
    for(i=0;i<n;i++)
    {
        result = strcmp(name, b[i].bookname);
        if(result==0)
        {
            printf("number of copies is %d\n",b[i].copies);
        }
    }
}


int main()
{
    int n,ch;
    
    printf("how many books you want to enter in the record\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter the isbn no of the book\n");
        scanf("%d",&b[i].isbn);
        printf("enter the name of the book\n");
        scanf("%s",b[i].bookname);
        printf("enter the name of the author\n");
        scanf("%s",b[i].bookauthr);
        printf("enter the year of publication of the book\n");
        scanf("%d",&b[i].year);
        printf("enter the total number of copies of the book\n");
        scanf("%d",&b[i].copies);
        printf("--------------\n");
    }
    while(ch!=0)
    {
        printf("enter 0 to exit\n");
        printf("enter 1 to issue a book to a member\n");
        printf("enter 2 to accept a book from a member\n");
        printf("enter 3 to list books based on year of publication\n");
        printf("enter 4 to list all the books\n");
        printf("enter 5 to search copies of a book by name\n");
        scanf("%d",&ch);
        if(ch==0)
            return 0;
        else if(ch==1)
            issuebook(n);    
        else if(ch==2)
            returnbook(n);
        else if(ch==3)
            listbook(n);    
        else if(ch==4)
            listallbook(n);
        else if(ch==5)
            listcopies(n);    
    }

}