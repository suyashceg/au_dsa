#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a=*b;
    *b=temp;
}

void bsort(int arr[],int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

int main()
{
    int i,arr[5];
    for(i=0;i<5;i++)
    {
        scanf("%d",&arr[i]);
    }
    bsort(arr,5);
    printf("%d",arr[0]);   
    return 0;
}