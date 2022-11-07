//matrix multiplication

#include <stdio.h>

int main()
{
    int r,c,a[10][10],b[10][10],res[10][10];
    printf("enter the dimension of the matrix\n");
    scanf("%d%d",&r,&c);
    printf("enter the values for the first matrix\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("enter the values for the second matrix\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            res[i][j]=0;
            for(int k=0;k<c;k++)
            {
                res[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d\t",res[i][j]);
        }
        printf("\n");
    }
}