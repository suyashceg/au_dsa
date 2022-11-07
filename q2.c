//return maximum and minimum element in an array
#include <stdio.h>

void main()
{
    int i,max,min,arr[5];
    for(i=0;i<5;i++)
    {
        scanf("%d",&arr[i]);
    }
    max=arr[0];
    min=arr[0];
    for(i=0;i<5;i++)
    {
        if(arr[i]>max)
            max=arr[i];
        if(arr[i]<min)
            min=arr[i];    
    }
    printf("maximum element: %d",max);
    printf("\nminimum element: %d",min);

}