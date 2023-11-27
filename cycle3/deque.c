#include<stdio.h>
#define size 10
int dq[10],f=-1,r=-1,item;
void insert_f(int item)
{
        if(f==0 && r==(size-1)||f==r+1)
        {
                printf("Queue overflow");
        }
        else if(f==-1)
        {
                f=r=0;
                dq[f]=item;
        }
        else if(f==0)
        {
                f=size-1;
                dq[f]=item;
        }
        else
        {
                f--;
                dq[f]=item;
        }
}
void delete_f()
{
        if(f==-1&&r==-1)
                printf("Queue underflow");
        else if(f==r)
        {
                printf("deleted item is=%d",dq[f]);
                f=r=-1;
        }
        else if(f==size-1)
        {
                printf("deleted item is=%d",dq[f]);
                f=0;
        }
        else
        {
                printf("deleted item is=%d",dq[f]);
                f++;
        }
}
void insert_r(int item)
{
        if(f==(r+1)%size)
        {
                printf("Deque is full");
        }
        else if(f==-1&&r==-1)
        {
                f=r=0;
                dq[r]=item;
        }
        else if(r==size-1)
        {
                r=0;
                dq[r]=item;
        }
        else
        {
                r++;
                dq[r]=item;
        }
}
void delete_r()
{
        if(f==-1&&r==-1)
        {
                printf("Queue is empty");
        }
        else if(f==r)
        {
                printf("deleted item is=%d",dq[r]);
                f=r=-1;
        }
        else if(r==0)
        {
                printf("deleted item is=%d",dq[f]);
                r=size-1;
        }
        else
        {
                printf("deleted item is=%d",dq[f]);
                r--;
        }
}
void display()
{
    int i;
    if (f == -1)
    {
        printf("DOUBLE ENDED QUEUE IS EMPTY\n");
    }
    else
    {
        printf("Double Ended Queue Elements: ");
        if (f <= r)
        {
            for (i = f; i <= r; i++)
            {
                printf("%d ", dq[i]);
            }
        }
        else
        {
            for (i = f; i < size; i++)
            {
                printf("%d ", dq[i]);
            }
            for (i = 0; i <= r; i++)
            {
                printf("%d ", dq[i]);
            }
        }
        printf("\n");
    }
}


void main()
{
    int item,value;
    char ch='y';
    while(ch=='y' || ch=='Y')
    {
        printf("1 :Insert at front\n2 :Insert at rear\n3 :Delete from front\n4 :Delete from rear\n5 : DISPLAY\n");
        printf("Enter your choice : ");
        scanf("%d",&value);
        switch(value)
        {
            case 1: printf("Enter the element to be added : ");
                    scanf("%d",&item);
                    insert_f(item);
                    break;
            case 2: printf("Enter the element to be added : ");
                    scanf("%d",&item);
                    insert_r(item);
                    break;
            case 3: delete_f();
                    break;
            case 4: delete_r();
                    break;
            case 5: display();
                    break;

            default : printf("Invalid choice\n");
                      break;

        }
        printf("Do you want to continue?(y/n) : ");
        scanf(" %c",&ch);
    }
}

