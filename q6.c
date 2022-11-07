//del at index 2 and shift elements

#include <stdio.h>

void main()
{
    int i,arr[10];
    for(i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }
    arr[2]=0;
    for(i=2;i<9;i++)
    {
        arr[i]=arr[i+1];
    }
    for(i=0;i<9;i++)
    {
        printf("%d\t",arr[i]);
    }
}