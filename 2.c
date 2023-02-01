#include <stdio.h>

void swap(int *a,int *b)
{
    int temp;
    temp =*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int beg,int end)
{
    int flag,left,right,loc;
    left=beg;
    loc=beg;
    right = end;
    flag=0;
    while(flag!=1)
    {
        while(arr[loc]<=arr[right] && right!=loc)
            right--;
        if(right==loc)
            flag=1;
        else if(arr[loc]>arr[right])
            swap(&arr[right],&arr[loc]),loc=right;
        while(arr[loc]>=arr[left] && left!=loc)
            left++;
        if(left==loc)
            flag=1;
        else if(arr[left]>arr[loc])
            swap(&arr[left],&arr[loc]),loc=left;
    }
    return loc;
}

void quicksort(int a[],int beg,int end)
{
    int loc;
    if(beg<end)
    {
        loc=partition(a,beg,end);
        quicksort(a,beg,loc-1);
        quicksort(a,loc+1,end);
    }
}

int main()
{
    int a[] = {3,2,1,5,6,7};
    quicksort(a,0,5);
    for(int i=0;i<6;i++)
        printf("%d",a[i]);
}