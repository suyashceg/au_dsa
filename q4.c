//return fibonacci series
#include <stdio.h>

void main()
{
    int counter=0,n1=0,n2=1,n3,n;
    scanf("%d",&n);
    while(counter<n)
    {
        printf("%d\t",n1);
        int n3=n1+n2;
        n1=n2;
        n2=n3;
        counter+=1;
    }
}