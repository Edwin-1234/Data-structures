#include<stdio.h>
#define size 3
#define invalid -99999
int cq[20],f=-1,r=-1;
void insert(int item)
{
        if(f==(r+1)%size)
        {
                printf("Queue overflow");
        }
        else
        {
                if(f==-1)
                        f=0;
                r=(r+1)%size;
                cq[r]=item;
        }
}
int dequeue()
{
        int item;
        if(f==-1)
        {
                printf("Queue empty");
                return invalid;
        }
        else
        {
                item=cq[f];
                f=(f+1)%size;
                if(f==r)
                {
                        f=-1;
                        r=-1;
                }
                return item;
        }
}
void display()
{
        int i;
        if(f==-1)
        {
                printf("Queue is empty");
        }
        else if(f<=r)
        {
                for(i=f;i<=r;i++)
                        printf("%d ",cq[i]);
        }
        else
        {
                for(i=f;i<=size-1;i++)
                         printf("%d",cq[i]);
                for(i=0;i<=r;i++)
                         printf("%d ",cq[i]);
        }
}
void main()
{
        char ch;
        int choice,num;
        printf("1:Insert\t2:delete\t3:display\n");
        do
        {
                printf("Enter your choice(1/2/3)");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:printf("Enter the number to be inserted:");
                                scanf("%d",&num);
                                insert(num);
                                break;
                        case 2:printf("The removed element is:%d\n",dequeue());
                                break;
                        case 3:display();
                                break;
                        default:printf("Invalid choice");
                }
                printf("Do you want to repeat(y/n)?\n");
                scanf(" %c",&ch);
        }while(ch=='y'||ch=='Y');

}
