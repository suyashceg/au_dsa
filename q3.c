//greatest of 3 elements
#include <stdio.h>

void main()
{
    int max,arr[3],i;
    for(i=0;i<3;i++)
    {
        scanf("%d",&arr[i]);
    }
    max=arr[0];
    for(i=0;i<3;i++)
    {
        if(max<arr[i])
            max=arr[i];
    }
    printf("greatest element: %d",max);
}