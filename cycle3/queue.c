#include<stdio.h>
#define size 20
int q[20],f=-1,r=-1,item;
void enqueue(int item)
{
        if(r==(size-1))
        {
                printf("Queue overflow");
        }
        else
        {
                if(f==-1)
                        f=0;
                r=r+1;
                q[r]=item;
        }
}
int dequeue()
{
        if(f==-1)
                printf("Queue underflow");
        else
        {
                item=q[f];
                f=f+1;
                if(f==(r+1))
                        f=r=-1;
        }
        return item;
}
void display()
{       int i;
        printf("Current elements of queue is:");
        for(i=f;i<=r;i++)
                printf("%d ",q[i]);
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
                                enqueue(num);
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
