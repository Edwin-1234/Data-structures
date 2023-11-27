#include<stdio.h>
int q[50],pr[50],f=-1,r=-1;
#define N 20
void display();
void enqueue(int data,int pr);
void dequeue();
void main()
{
    int n,c,num,i,p;
    char ch;
    printf("1:Insert\n2:Delete\n3:Display\n");
    do
    {
        printf("Enter your choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 1:printf("Enter the number of data:");
                    scanf("%d",&num);
                    for(i=0;i<num;i++)
                    {
                        printf("Enter the data and priority:");
                        scanf("%d %d",&n,&p);
                        enqueue(n,p);
                    }    
                    break;
            case 2:dequeue();
                    break;
            case 3:display();
                    break;
            default:printf("Enter a valid choice\n");
        }
        printf("Do you want to repeat(y/n)?");
        scanf(" %c",&ch);
    }while(ch=='y'||ch=='Y');
}
void enqueue(int data,int p)
{
    if(r==N-1)
    {
        printf("Queue overflow");
    }
    else if(f==-1)
    {
        f=r=0;
        q[r]=data;
        pr[r]=p;
    }
    else
    {
        r++;
        int i=r;
        while(p>0&&p<pr[i-1])
        {
            q[i]=q[i-1];
            pr[i]=pr[i-1];
            i--;
        }
        q[i]=data;
        pr[i]=p;
    }
}
void dequeue()
{
    if(f==-1)
    {
        printf("Queue underflow");
    }
    else
    {
        printf("Deleted element:%d Priority:%d\n",q[f],pr[f]);
        if(f==r)
        {
            f=r=-1;
        }
        else
        {
            f++;
        }
    }
}
void display()
{
    if(f==-1)
    {
        printf("Queue underflow\n");
    }
    else
    {
        int i;
        for(i=f;i<=r;i++)
        {
            printf("Element:%d Priority:%d\n",q[i],pr[i]);
        }
    }
}
