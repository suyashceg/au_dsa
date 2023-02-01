    #include <stdio.h>

    void insertion(int arr[],int n)
    {
        int temp,j=0;
        for(int i=1;i<n;i++)
        {
            temp=arr[i];
            j=i-1;
            while(arr[j]>arr[i] && j>=0)
                arr[j+1]=arr[j],j--;
            arr[j+1]=temp;
        }
        
    }

    int main()
    {
        int arr[] = {3,2,1,5,6,7};
        insertion(arr,6);
        for(int i=1;i<6;i++)
            printf("%d",arr[i]);
    }