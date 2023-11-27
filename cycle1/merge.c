#include<stdio.h>
void main()
{
        int a[20],b[20],c[40],m,n,i,j,p,k;
        printf("Enter no. of elements of first array");
        scanf("%d",&m);

        printf("Ente the numbers in ascending order");
        for(i=0;i<m;i++)
                scanf("%d",&a[i]);

        printf("Enter the number of elements of second array");
        scanf("%d",&n);
        printf("Enter the numbers in ascending order");
        for(j=0;j<n;j++)
                scanf("%d",&b[j]);
        i=0;j=0;k=0;
        while(i<m && j<n)
        {
                if(a[i]<b[j])
                {
                        c[k]=a[i];
                        k++;i++;
                }
                else
                {
                        c[k]=b[j];
                        k++;j++;
                }
        }

        for(p=i;p<m;p++,k++)
                c[k]=a[p];
        for(p=j;p<n;p++,k++)
                c[k]=b[p];
        printf("Merged array is\n");
        for(i=0;i<m+n;i++)
                printf("%d ",c[i]);
        printf("\n");
}

