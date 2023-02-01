#include <stdio.h>

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[],int lb, int ub)
{
    int start = lb;
    int end = ub;
    int pivot = arr[ub];
    while(start<end)
    {
        while(arr[start]<=pivot)
            start++;
        while(arr[end]>pivot)
            end--;
        if(start<end)
            swap(&arr[start],&arr[end]);
    }
    swap(&arr[lb],&arr[end]);
    return end;
}

int quicksort(int arr[],int lb,int ub)
{
    if(lb<ub)
    {
        int loc = partition(arr,lb,ub);
        quicksort(arr,lb,loc);
        quicksort(arr,loc+1,ub);
    }
}

int main()
{
    int arr[] = {3,2,1,5,6,7,9};
    quicksort(arr,0,6);
    for(int i=0;i<7;i++)
        printf("%d\n",arr[i]);
    
    return 0;
}